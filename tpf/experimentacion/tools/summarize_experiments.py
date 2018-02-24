#!/usr/bin/env python
"""
Script para transformar archivos csv de logs de output a
csv contabilizador por grupos
"""

import sys
import glob
import os
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
import pandas as pd

logger = logging.getLogger(__name__)


def config_logging():
    handler = logging.StreamHandler()
    formatter = logging.Formatter(
            '%(asctime)s %(name)-12s %(levelname)-8s %(message)s')
    handler.setFormatter(formatter)
    logger.addHandler(handler)
    logger.setLevel(logging.DEBUG)


def get_last_reg_info(dataframe):
    rv = dict()
    interval_ended = False
    time_index = 1
    A_index = 2
    I_index = 3
    B_index = 4

    for row in dataframe[::-1].itertuples():
        if 'last_reg_time' not in rv:
            rv['last_reg_time'] = row[time_index]
            rv['last_reg_A'] = row[A_index]
            rv['last_reg_B'] = row[B_index]
            rv['last_reg_I'] = row[I_index]
        else:
            if not(interval_ended):
                if (rv['last_reg_A'] == row[A_index] and
                    rv['last_reg_B'] == row[B_index] and
                    rv['last_reg_I'] == row[I_index]):
                    rv['last_reg_interval_init'] = row[time_index]
                else:
                    interval_ended = True
                    if 'last_reg_interval_init' not in rv:
                        rv['last_reg_interval_init'] = rv['last_reg_time']

            elif ('last_reg_previous_aparition' not in rv and
                  (rv['last_reg_A'] == row[A_index] and
                   rv['last_reg_B'] == row[B_index] and
                   rv['last_reg_I'] == row[I_index])):
                rv['last_reg_previous_aparition'] = row[time_index]

    if 'last_reg_previous_aparition' not in rv:
        rv['last_reg_previous_aparition'] = -1

    return rv


def summarize_file(filename):
    rv = {'file': filename}

    df = pd.read_csv(filename)
    desc = df.describe()
    rv['A_mean'] = desc['A']['mean']
    rv['A_std'] = desc['A']['std']
    rv['B_mean'] = desc['B']['mean']
    rv['B_std'] = desc['B']['std']
    rv['I_mean'] = desc['I']['mean']
    rv['I_std'] = desc['I']['std']
    rv.update(get_last_reg_info(df))

    return rv


def summarize_files(filenames):
    rv = []
    for filename in filenames:
        rv.append(summarize_file(filename))

    return rv


def get_open_kwargs():
    rv = {"mode": 'w', "newline": '', "encoding": 'utf-8'}
    if sys.version_info.major < 3:
        rv["mode"] = 'wb'
        del rv["newline"]
        del rv["encoding"]

    return rv


def write_summarize_to_file(summarize, outputfile):
    kwargs = get_open_kwargs()

    with io.open(outputfile, **kwargs) as out_file:
        writer = csv.DictWriter(out_file,
                                fieldnames=['file', 'last_reg_time',
                                            'last_reg_interval_init',
                                            'last_reg_previous_aparition',
                                            'last_reg_A',
                                            'last_reg_I',
                                            'last_reg_B',
                                            'A_mean',
                                            'A_std',
                                            'I_mean',
                                            'I_std',
                                            'B_mean',
                                            'B_std'])

        writer.writeheader()
        for row in summarize:
            writer.writerow(row)


def process(args):
    path = args.path
    all_files = glob.glob(os.path.join(path, args.file_pattern))

    summarize = summarize_files(all_files)
    write_summarize_to_file(summarize, args.outputfile)


def main():
    """
    Bloque principal
    """
    config_logging()
    parser = argparse.ArgumentParser(
        description="Transforma archivos csv de contabilizador por grupo en un csv sumarizado.")
    parser.add_argument("path",
                        help="Path con los archivos")
    parser.add_argument("file_pattern",
                        help="Patron de los archivos a sumarizar")
    parser.add_argument("outputfile",
                        help="Nombre del .csv de salida")
    args = parser.parse_args()

    process(args)


if __name__ == "__main__":
    main()
