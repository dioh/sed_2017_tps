#!/usr/bin/env python
"""
Script para transformar archivos csv de logs de output a
csv contabilizador por grupos
"""

import sys
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
import random
from collections import OrderedDict
import copy
import io

logger = logging.getLogger(__name__)
variables = ['A', 'B', 'I']


def config_logging():
    handler = logging.StreamHandler()
    formatter = logging.Formatter(
            '%(asctime)s %(name)-12s %(levelname)-8s %(message)s')
    handler.setFormatter(formatter)
    logger.addHandler(handler)
    logger.setLevel(logging.DEBUG)


def get_value_set(value):
    value_as_float = float(value)
    if value_as_float < -1.0 and value_as_float >= -3:
        return 'A'
    elif value_as_float > 1.0 and value_as_float <= 3:
        return 'B'
    elif value_as_float >= -1.0 and value_as_float <= 1.0:
        return 'I'
    else:
        return None


def new_value(row):
    value = {'A': set(), 'B': set(), 'I': set()}
    row_set = get_value_set(row['value'])
    if row_set is not None:
        value[row_set] = value[row_set].add(row['id'])
        return value


def get_actual_set(sets, id_value):
    for var in variables:
        if id_value in sets[var]:
            return var

    return None


def update(actual_value, row):
    row_set = get_value_set(row['value'])
    if row_set is not None:
        actual_set = get_actual_set(actual_value, row['id'])
        if actual_set is not None:
            if actual_set != row_set:
                actual_value[actual_set].remove(row['id'])
                actual_value[row_set].add(row['id'])
        else:
            actual_value[row_set].add(row['id'])

        return actual_value


def get_var(time_dict, varname):
    rv = []
    for key, value in time_dict.items():
        rv.append((key, len(value[varname])))

    return rv


def process_file(filename):
    time_set_q = OrderedDict()
    time_set_q[0.0] = {'A': set(), 'B': set(), 'I': set()}
    with filename.open() as csvfile:
        reader = csv.DictReader(csvfile, ['time', 'sec', 'cell_type',
                                          'x', 'y', 'z', 'id', 'value',
                                          'out_model_type', 'out_model_id'])
        actual_sec = 0.0
        for row in reader:
            if row['z'] == '1':
                continue
            sec = float(row['sec'])
            if sec in time_set_q:
                time_set_q[sec] = update(time_set_q[sec], row)
            else:
                time_set_q[sec] = update(copy.deepcopy(time_set_q[actual_sec]),
                                         row)
                actual_sec = sec
    return time_set_q


def parse_csv_logfile(log_file, args):
    transformed_rows = process_file(log_file)
    kwargs = {"mode": 'w', "newline": '', "encoding": 'utf-8'}
    if sys.version_info.major < 3:
        kwargs["mode"] = 'wb'
        del kwargs["newline"]
        del kwargs["encoding"]

    with io.open(args.outputfile, **kwargs) as out_file:
        writer = csv.DictWriter(out_file, fieldnames=['time', 'A', 'I', 'B'], )
        writer.writeheader()
        for key, value in transformed_rows.items():
            row = {'time': key}
            for group in ['A', 'I', 'B']:
                row.update({group: len(value[group])})
            writer.writerow(row)


def main():
    """
    Bloque principal
    """
    config_logging()
    parser = argparse.ArgumentParser(
        description="Transforma archivos csv de logs de output a csv contabilizador por grupos.")
    parser.add_argument("inputfile",
                        help="Nombre del archivo de csv de log")
    parser.add_argument("outputfile",
                        help="Nombre del .csv de salida")
    args = parser.parse_args()

    log_file = Path(args.inputfile)
    if log_file.is_file():
        parse_csv_logfile(log_file, args)
    else:
        print("Error!")
        print("Archivo {0} no encontrado".format(args.inputfile))


if __name__ == "__main__":
    main()
