"""
Script de punto de entrada para la traduccion xmile a devsml
"""

import math
import argparse
import logging
try:
    from pathlib import Path
    Path().expanduser()
except (ImportError, AttributeError):
    from pathlib2 import Path
import configparser
from builtins import map
import numpy as np

logger = logging.getLogger('create_ev_file')


def config_logging():
    handler = logging.StreamHandler()
    formatter = logging.Formatter(
            '%(asctime)s %(name)-12s %(levelname)-8s %(message)s')
    handler.setFormatter(formatter)
    logger.addHandler(handler)
    logger.setLevel(logging.INFO)


def get_config(config_file_path):
    with config_file_path.open() as config_file:
        config = configparser.ConfigParser()
        config.read_file(config_file)
        logger.info('Config readed. Sections %s', config.sections())

    return config

def remove_comments(aString):
    comment = aString.find('#')
    if comment != -1:
        return aString[:comment]
    else:
        return aString
    

def get_events(config):

    event_str = remove_comments(config['main']['events'])
    logger.info('events: %s', event_str)
    event_str_no_comment_split = event_str.split(' ')
    logger.info('split: %s', list(filter(None, event_str_no_comment_split)))
    return list(map(lambda s: s.strip(),
                    filter(None, event_str_no_comment_split)))


def get_ports(config, event):
    ports_str = config[event]['ports'].split(' ')
    return list(map(lambda s: s.strip(), ports_str))


def get_event_config(config, event):
    return (float(config[event]['frequency']),
            config[event]['value'],
            get_ports(config, event))


def get_events_interval(config):
    return (float(config['main']['init_time']),
            float(config['main']['end_time']))


def events_by_time(config, events):
    events_by_time = dict()

    for event in events:
        init_time, end_time = get_events_interval(config)
        frequency, value, ports = get_event_config(config, event)
        for t in np.arange(init_time, end_time, frequency):
            events_in = []
            if t in events_by_time:
                events_in = events_by_time[t]

            for port in ports:
                events_in.append((event, value, port))
            events_by_time[t] = events_in

    return events_by_time


def seconds_to_timestring(t):
    hours = int(math.floor(t / 3600))
    minutes = int(math.floor((t - hours) / 60))
    seconds = int(math.floor((t - hours - minutes)))
    miliseconds = int((t - hours - minutes - seconds) * 1000)
    return "{0:02d}:{1:02d}:{2:02d}:{3:03d}".format(hours,
                                                    minutes,
                                                    seconds,
                                                    miliseconds)


def event_string(t, event):
    time_str = seconds_to_timestring(t)
    return "{0} {1} [{2}]\n".format(time_str, event[2], event[1])


def write_evfile(filename, events_by_time):
    logger.info('filename: %s', filename)
    # logger.info('events by time: %s', events_by_time)
    
    time_line = list(events_by_time.keys())
    time_line.sort()
    logger.info('time_line: %s', list(events_by_time.keys()))
    
    with open(filename, mode='w') as outfile:
        for t in time_line:
            events = events_by_time[t]
            for event in events:
                outfile.write(event_string(t, event))


def create_evfile(config_file, args):
    config = get_config(config_file)
    events = get_events(config)
    logger.info('Events: {0}'.format(events))
    write_evfile(args.evfile, events_by_time(config, events))


def main():
    """
    Bloque principal
    """
    config_logging()
    parser = argparse.ArgumentParser(description="Crea archivos .ev de eventos")
    parser.add_argument("config", help="Archivo de configuracion para generar los eventos")
    parser.add_argument("evfile", help="Nombre del archivo a escribir")

    args = parser.parse_args()

    config_file = Path(args.config)
    if config_file.is_file():
        create_evfile(config_file, args)
    else:
        print("Error!")
        print("Archivo {0} no encontrado".format(args.config))

if __name__ == "__main__":
    main()
