"""
Script de punto de entrada para la traduccion xmile a devsml
"""

import argparse
import logging
try:
    from pathlib import Path
    Path().expanduser()
except (ImportError, AttributeError):
    from pathlib2 import Path

logger = logging.getLogger(__name__)


def addInterval(timeString, interval):
    timeStringSplt = timeString.split(':')
    hours = int(timeStringSplt[0])
    minutes = int(timeStringSplt[1])
    seconds = int(timeStringSplt[2])
    miliseconds = int(timeStringSplt[3]) + interval

    if miliseconds > 999:
        added_seconds = miliseconds / 1000
        miliseconds = miliseconds % 1000
        seconds += added_seconds
        if seconds > 59:
            added_minutes = seconds / 60
            seconds = seconds % 60
            minutes = minutes + added_minutes
            if minutes > 59:
                added_hours = minutes / 60
                minutes = minutes % 60
                hours = hours + added_hours

    return '{0}:{1}:{2}:{3}'.format(hours, minutes,
                                    seconds, miliseconds)


def compareTimeStrings(timeString, otherTimeString):
    timeStringSplt = timeString.split(':')
    totalSeconds = int(timeStringSplt[0]) * 3600 + \
        int(timeStringSplt[1]) * 60 + \
        int(timeStringSplt[2]) + \
        (int(timeStringSplt[3]) / 1000)

    timeStringSplt = otherTimeString.split(':')
    totalOtherSeconds = int(timeStringSplt[0]) * 3600 + \
        int(timeStringSplt[1]) * 60 + \
        int(timeStringSplt[2]) + \
        (int(timeStringSplt[3]) / 1000)

    return totalOtherSeconds - totalOtherSeconds


def main():
    """
    Bloque principal
    """
    parser = argparse.ArgumentParser(description="Crea archivos .ev del los envios de shock")
    parser.add_argument("shockers", help="Cantidad de shockers del modelo")
    parser.add_argument("shock_value", help="Valor a enviar con el shock")
    parser.add_argument("maxtime", help="Tiempo maximo que envian los shocks")
    parser.add_argument("interval", help="Intervalo de tiempo (ms) cada cuanto envian shock")
    parser.add_argument("evfile", help="Nombre del archivo a escribir")

    args = parser.parse_args()

    with open(args.evfile, 'w', encoding='utf-8') as evfile:
        initialTime = addInterval('00:00:00:00', args.interval)
        # TODO mientras no superemos el tiempo maximo
        # escribir lla linea de envio para todos los shockers
        # inN donde N es el numero de shocker

if __name__ == "__main__":
    main()
