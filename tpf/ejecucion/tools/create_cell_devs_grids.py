#!/usr/bin/env python
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
import configparser
import random
import functools

logger = logging.getLogger(__name__)


def get_config(config_file_path):
    with config_file_path.open() as config_file:
        config = configparser.ConfigParser()
        config.read(config_file)
        return config


def get_dimensions(config):
    return config['grid']['dimensions'].split(' ')


def get_groups(config, dimensions):
    total_cells = functools.reduce(lambda x, y: x*y, dimensions)
    groups = dict()
    for group in config.sections().remove('grid'):
        groups[group] = {'min': config.getfloat(group, 'min value'),
                         'max': config.getfloat(group, 'max value'),
                         'porcentage': config.getfloat(group, 'porcentage'),
                         'quantity':
                         round(config.getfloat(group, 'porcentage') *
                               total_cells)}

    return groups


def generate_group_values(group):
    values = []
    for _ in range(0, group['quantity']):
        values.append(random.uniform(group['min'], group['max']))


def get_shuffled_group_values(groups):
    values = []
    for group in groups.values:
        values.append(generate_group_values(group))

    random.shuffle(values)

    return values


def create_cells(dimensions):
    cells = ['(']
    for dimension in dimensions:
        for i in range(0, dimension):
            cell = cells.pop()
            cell = '{0}{1},'.format(cell, i)

    return list(map(lambda cell: cell[:-1]+')', cells))


def create_grid_file(dimensions, groups, file_path):

    cells = create_cells(dimensions)
    values = get_shuffled_group_values(groups)

    with open(file_path, 'w') as outfile:
        for cell, value in map(lambda x, y: (x, y), cells, values):
            outfile.write('{0}={1}\n'.format(cell, value))


def create_groups_str(groups):
    group_strs = []
    for group in groups.keys():
        group_strs.append('{0}_{1}'.format(group,
                                           groups[groups]['porcentage']))

    return '_'.join(group_strs)


def build_file_path(output_dir, outfiles_prefix, i, dimensions, groups):
    dimensions_str = '_'.join(dimensions)
    groups_str = create_groups_str(groups)
    filename = '{0}_{1}_{2}_{3}.val'.format(outfiles_prefix, i,
                                            dimensions_str, groups_str)
    return Path(output_dir) / filename


def create_grids(config_file_path, args):

    config = get_config(config_file_path)
    dimensions = get_dimensions(config)
    groups = get_groups(config, dimensions)

    for i in range(args.cases):
        file_path = build_file_path(args.output_dir, args.outfiles_prefix,
                                    i, dimensions, groups)
        create_grid_file(dimensions, groups,
                         file_path)


def main():
    """
    Bloque principal
    """
    parser = argparse.ArgumentParser(
        description="Crea un archivo .val de valores iniciales de una grilla Cell-DEVS.")
    parser.add_argument("config_file",
                        help="Archivo de configuracion de los parametros de la grilla")
    parser.add_argument("outfiles_prefix",
                        help="Prefijo de los archivos de salida")
    parser.add_argument("cases",
                        help="Cantidad de grillas a generar")
    parser.add_argument("output_dir",
                        help="Directorio de salida de los archivos")
    args = parser.parse_args()

    config_file = Path(args.config_file)
    if config_file.is_file():
        create_grids(config_file, args)
    else:
        print("Error!")
        print("Archivo {0} no encontrado".format(args.config_file))


if __name__ == "__main__":
    main()
