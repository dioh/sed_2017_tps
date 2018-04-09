
import sys
import os
cwd = os.getcwd()
if cwd not in sys.path:
    sys.path.append(cwd + '/modulosDEVS/')

import logging
from jinja2 import Environment, FileSystemLoader
from modulosDEVS.DEVSAtomic.CellDevs import Cell


###################################################################################################################
# Configuraciones
logging.basicConfig(filename='traductor_cell_devs.log', filemode='w', level=logging.DEBUG)
# Jinja2
PATH = './'
PATH_TEMPLATES = 'templates'
TEMPLATE_ENVIRONMENT = Environment(
    autoescape=False,
    loader=FileSystemLoader(os.path.join(PATH, PATH_TEMPLATES)),
    trim_blocks=False
)


def render_template(template_filename, context):
    return TEMPLATE_ENVIRONMENT.get_template(template_filename).render(context)
###################################################################################################################


cell_devs = Cell('opinion')
# Generate Cell Devs
cell_devs.set_dim((3, 3, 3))
cell_devs.set_delay(4.3)
cell_devs.set_default_delay_time(5.0)
cell_devs.set_border_type('unwrapped')
cell_devs.set_neighbors([])
cell_devs.set_initial_value(0)
cell_devs.set_local_transition('zzz-rule')
cell_devs.set_rules({
    'zzz-rule': [
        '{ t } 0 100'
    ]
})
cell_devs.set_neighbors([
    (0, 0, -1), (0, 0, 1), (0, -1, 0), (0, 1, 0)
])

# Output Cell Devs
for extension in ['.xml', '.ma']:
    with open('cell_devs' + extension, 'w+') as f:
        f.write(render_template('template-cell-devs' + extension, {
            'name': cell_devs.get_name(),
            'macro': 'macros.inc',

            'type': cell_devs.get_type(),
            'dim': cell_devs.get_dim(),
            'delay': cell_devs.get_delay(),
            'default_delay_time': cell_devs.get_default_delay_time(),
            'border_type': cell_devs.get_border_type(),
            'neighbors': cell_devs.get_neighbors(),
            'initial_value': cell_devs.get_initial_value(),

            'local_transition': cell_devs.get_local_transition(),
            'rules': cell_devs.get_rules(),
            'neighbors': cell_devs.get_neighbors()
        }))
