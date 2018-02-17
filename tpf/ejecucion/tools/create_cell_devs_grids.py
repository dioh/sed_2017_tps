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
from collections import deque

logger = logging.getLogger(__name__)


def get_config(config_file_path):
    with config_file_path.open() as config_file:
        config = configparser.ConfigParser()
        config.read_file(config_file)
        logger.info('Config readed. Sections %s', config.sections())
        return config


def get_dimensions(config):
    if 'grid' in config:
        return list(map(lambda d: int(d), config['grid']['dimensions'].split(' ')))
    else:
        raise KeyError('grid section not found. Sections: {0}'.format(config.sections()))

def get_group_names(config):
    sections = config.sections()
    sections.remove('grid')
    return sections


def get_groups(config, dimensions):
    total_cells = functools.reduce(lambda x, y: x*y, dimensions)
    group_names = get_group_names(config)
    logger.debug('Group names: %s', group_names)
    groups = dict()
    for group_name in group_names:
        groups[group_name] = {'min': config.getfloat(group_name, 'min value'),
                              'max': config.getfloat(group_name, 'max value'),
                              'porcentage': config.getfloat(group_name, 'porcentage'),
                              'quantity':
                                round(config.getfloat(group_name, 'porcentage') *
                                      total_cells / 100)}

    return groups


def generate_group_values(group):
    values = []
    logger.debug('group: %s', group)
    for i in range(0, group['quantity']):
        logger.debug('i: %i', i)
        values.append(random.uniform(group['min'], group['max']))
    
    return values


def get_shuffled_group_values(groups):
    values = []
    for group in groups.values():
        values = values + generate_group_values(group)

    random.shuffle(values)

    return values


def create_cells(dimensions):
    cells = deque(['('] * dimensions[0])
    logger.debug('dimensions first value: %s', dimensions[0])
    logger.debug('cells: %s', cells)
    for dimension in dimensions:
        for i in range(0, len(cells)):
            cell = cells.popleft()
            for j in range(0, dimension):
                new_cell = '{0}{1},'.format(cell, j)
                logger.debug('dimension: %i; iteration: %i, cell: %s', i, j, new_cell)
                cells.append(new_cell)

    return list(map(lambda cell: cell[:-1]+')', list(cells)))


def create_grid_file(dimensions, groups, file_path):

    cells = create_cells(dimensions)
    logger.debug('len cells: %i', len(cells))
    values = get_shuffled_group_values(groups)
    logger.debug('len values: %i', len(values))

    with open(file_path, 'w') as outfile:
        for cell, value in map(lambda x, y: (x, y), cells, values):
            outfile.write('{0}={1}\n'.format(cell, value))


def create_groups_str(groups):
    group_strs = []
    for group in groups.keys():
        logger.debug('group: %s', group)
        logger.debug('group values: %s', groups[group])
        group_strs.append('{0}_{1}'.format(group,
                                           groups[group]['porcentage']))

    return '_'.join(group_strs)


def build_file_path(output_dir, outfiles_prefix, i, dimensions, groups):
    dimensions_str = '_'.join(list(map(lambda d: d.__str__(), dimensions)))
    groups_str = create_groups_str(groups)
    filename = '{0}_{1}_{2}_{3}.val'.format(outfiles_prefix, i,
                                            dimensions_str, groups_str)
    return Path(output_dir) / filename


def create_grids(config_file_path, args):

    config = get_config(config_file_path)
    dimensions = get_dimensions(config)
    groups = get_groups(config, dimensions)

    for i in range(args.cases):
        file_path = build_file_path(args.outdir, args.outfile_prefix,
                                    i, dimensions, groups)
        create_grid_file(dimensions, groups,
                         file_path)


def config_logging():
    handler = logging.StreamHandler()
    formatter = logging.Formatter(
            '%(asctime)s %(name)-12s %(levelname)-8s %(message)s')
    handler.setFormatter(formatter)
    logger.addHandler(handler)
    logger.setLevel(logging.DEBUG)


def main():
    """
    Bloque principal
    """
    config_logging()
    parser = argparse.ArgumentParser(
        description="Crea un archivo .val de valores iniciales de una grilla Cell-DEVS.")
    parser.add_argument("-c", "--config",
                        help="Archivo de configuracion de los parametros de la grilla")
    parser.add_argument("-p", "--outfile_prefix",
                        help="Prefijo de los archivos de salida")
    parser.add_argument("-q", "--cases", type=int, default=1,
                        help="Cantidad de grillas a generar. Por defecto 1.")
    parser.add_argument("-d", "--outdir", default='.',
                        help="Directorio de salida de los archivos")
    args = parser.parse_args()

    config_file = Path(args.config)
    if config_file.is_file():
        create_grids(config_file, args)
    else:
        print("Error!")
        print("Archivo {0} no encontrado".format(args.config))


if __name__ == "__main__":
    main()
