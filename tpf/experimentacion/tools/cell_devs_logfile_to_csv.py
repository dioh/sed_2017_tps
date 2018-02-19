#!/usr/bin/env python
"""
Script para transformar archivos de log de Cell-DEVS a csv
"""

import argparse
import logging
try:
    from pathlib import Path
    Path().expanduser()
except (ImportError, AttributeError):
    from pathlib2 import Path
import csv
import re
from builtins import map
from collections import OrderedDict

logger = logging.getLogger(__name__)

TIME_FIELD = 3
CELL_FIELD = 4
VALUE_FIELD = 6
OUT_CELL_FIELD = 7

cell_re = re.compile(r"(?P<cell_type>\w+)\((?P<coords>.*)\)\((?P<cell_id>.*)\)")
out_cell_re = re.compile(r"(?P<cell_type>\w+)\((?P<cell_id>.*)\)")


def config_logging():
    handler = logging.StreamHandler()
    formatter = logging.Formatter(
            '%(asctime)s %(name)-12s %(levelname)-8s %(message)s')
    handler.setFormatter(formatter)
    logger.addHandler(handler)
    logger.setLevel(logging.DEBUG)


def is_out_line(line):
    return line.find("/ out /") != -1


def to_seconds(time):
    time_split = list(map(lambda t: float(t), time.split(':')))
    return (time_split[0] * 3600 +
            time_split[1] * 60 +
            time_split[2] +
            time_split[3] / 1000.0)


def transform_to_csv_line(line):
    out_dict = OrderedDict()
    split_line = list(map(lambda part: part.strip(), line.split('/')))
    out_dict['time'] = split_line[TIME_FIELD]
    out_dict['seconds'] = to_seconds(split_line[TIME_FIELD])
    # logger.debug('cell field: \'%s\'', split_line[CELL_FIELD])
    match = cell_re.match(split_line[CELL_FIELD])
    out_dict['cell_type'] = match.group('cell_type')
    i = 1
    for coord in match.group('coords').split(','):
        name = 'coord_{0}'.format(i)
        out_dict[name] = coord
        i += 1

    out_dict['cell_id'] = match.group('cell_id')
    out_dict['value'] = split_line[VALUE_FIELD]

    out_match = out_cell_re.match(split_line[OUT_CELL_FIELD])
    out_dict['out_cell_type'] = out_match.group('cell_type')
    out_dict['out_cell_id'] = out_match.group('cell_id')

    return out_dict


def parse_log(log_file, args):
    with log_file.open() as log:
        out_filename = '{0}.csv'.format(args.outfile)
        with open(out_filename, 'w') as out_file:
            writer = csv.writer(out_file)
            for line in log:
                if is_out_line(line):
                    writer.writerow(transform_to_csv_line(line).values())


def main():
    """
    Bloque principal
    """
    config_logging()
    parser = argparse.ArgumentParser(
        description="Transforma mensajes de out de un log Cell-DEVS en csv")
    parser.add_argument("logfilename",
                        help="Nombre del archivo de log")
    parser.add_argument("outfile",
                        help="Nombre del .csv de salida")
    args = parser.parse_args()

    log_file = Path(args.logfilename)
    if log_file.is_file():
        parse_log(log_file, args)
    else:
        print("Error!")
        print("Archivo {0} no encontrado".format(args.logfilename))


if __name__ == "__main__":
    main()
