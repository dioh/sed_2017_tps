
import sys
import os
cwd = os.getcwd()
if cwd not in sys.path:
    sys.path.append(cwd + '/modulosDEVS/')

import xml.etree.ElementTree as etree
import vkbeautify as vkb
import logging
from jinja2 import Environment, FileSystemLoader

from modulosCDPP.cdpp_model import CdppModel
from modulosCDPP.cdpp_model_to_ma_file import CdppModelToMaConverter
from modulosCDPP.preprocessing import preprocessing_devsml_for_ma
from modulosDEVS.DEVSAtomic.CellDevs import Cell


###################################################################################################################
# Configuraciones
logging.basicConfig(filename='logs/traductor_cell_devs.log', filemode='w+', level=logging.DEBUG)
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


####### Generate CellDEVS object ##########
cell_devs = Cell('cell')
# Generate Cell Devs
cell_devs.set_dim((3, 3, 3))
cell_devs.set_delay(4.3)
cell_devs.set_default_delay_time(5.0)
cell_devs.set_border_type('unwrapped')
cell_devs.set_neighbors([])
cell_devs.set_initial_value(0)
cell_devs.set_local_transition('zzz-rule')
cell_devs.set_neighbors([
    (0,0,-1),(0,0,1),(0,-1,0),(0,1,0)
])
cell_devs.set_input_ports([
    'in1', 'in2', 'in3'
])
cell_devs.set_output_ports([
    'out1', 'out2', 'out3'
])
cell_devs.set_internal_input_connections([
    {'port_from': 'in1', 'component_to': (0,0,0), 'port_to': 'in', "component_from": 'self', "type": 'in'},
    {'port_from': 'in2', 'component_to': (0,1,2), 'port_to': 'in', "component_from": 'self', "type": 'in'},
    {'port_from': 'in3', 'component_to': (2,2,2), 'port_to': 'in', "component_from": 'self', "type": 'in'}
])
cell_devs.set_internal_output_connections([
    {'component_from': (0,0,0), 'port_from': 'out', 'port_to': 'out1', "component_to": 'self', "type": 'in'},
    {'component_from': (0,1,2), 'port_from': 'out', 'port_to': 'out2', "component_to": 'self', "type": 'in'},
    {'component_from': (2,2,2), 'port_from': 'out', 'port_to': 'out3', "component_to": 'self', "type": 'in'}
])
cell_devs.set_rules({
    'zzz-rule': [
        {'action': '(0,0,0) + 10', 'delay': '100', 'condition': 't'},
        {'action': '(0,0,0) + (0,0,1)', 'delay': '100', 'condition': "(0,0,0) > 10"}
    ],
    'xxx-rule': [
        {'action': 'uniform(-3,-2)', 'delay': '0', 'condition': 'portValue(thisPort) = 5'}
    ]
})
cell_devs.set_ports_in_transition([
    {'input_port': 'in', 'component': (0,0,0), 'rule': 'xxx-rule'}
])

########### Generate XML (object => xml) ###########
for extension in ['.xml']:
    with open('tmp_file.xml', 'w+') as f:
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
            'neighbors': cell_devs.get_neighbors(),
            'input_ports': cell_devs.get_input_ports(),
            'output_ports': cell_devs.get_output_ports(),
            'internal_input_connections': cell_devs.get_internal_input_connections(),
            'internal_output_connections': cell_devs.get_internal_output_connections(),
            'ports_in_transition': cell_devs.get_ports_in_transition()
        }))
    # Pretty print (> => &gt;) (< => &lt;)
    with open('tmp_file.xml', 'r') as xml_file_new:
        parser = etree.XMLParser(encoding="utf-8")
        xml_tree_new = etree.parse(xml_file_new, parser=parser)
        root = xml_tree_new.getroot()
        x = etree.tostring(root)
        vkb.xml(x, 'cell_devs.xml')
    os.remove('tmp_file.xml')

########## Generate .ma (.xml => .ma) #############
# Generation of .ma file
devs_ml_model = preprocessing_devsml_for_ma(etree.parse('cell_devs.xml'))
cdpp_model = CdppModel.from_devsml_xml(devs_ml_model)
mafile = CdppModelToMaConverter.parse_model(cdpp_model)
with open('cell_devs.ma', 'w+') as f:
    f.write(str(mafile))