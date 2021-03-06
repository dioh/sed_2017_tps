
import sys
import os
import shutil
cwd = os.getcwd()
if cwd not in sys.path:
    sys.path.append(cwd + '/modulosDEVS/')
    sys.path.append(cwd + '/modulosXMILE/')
import xml.etree.ElementTree as etree
import vkbeautify as vkb
from modulosDEVS.DEVSGenerator import *
from modulosDEVS.CellDEVSGenerator import *
from modulosCDPP.cdpp_model import CdppModel
from modulosCDPP.cdpp_model_to_ma_file import CdppModelToMaConverter
from modulosCDPP.preprocessing import preprocessing_devsml_for_ma
import logging

###################################################################################################################
# Configuraciones
logging.basicConfig(filename='logs/traductor.log', filemode='w', level=logging.DEBUG)

###################################################################################################################

DEVSML_TEMPLATE_FILENAME = 'template-devsml.xml'
CPP_H_TEMPLATES_FILENAMES = {
    'reg': 'template-reg.cpp',
    'DEVSFtot': 'template-Ftot',
    'Fplus': 'template-Aux-Fpm',
    'Fminus': 'template-Aux-Fpm',
    'DEVSAux': 'template-Aux-Fpm',
    'DEVSConstant': 'template-Cte',
    'events': 'template-ev.ev',
    'DEVSPulse': 'template-Pulse',
    'DEVSIntegrator': 'qss1'
}

params_traducciones = {
    'teacup': {
        'DIR_XMILE': 'modelos/cell/cell-teacup/teacup.xmile',
        'DEVSML_CPP_H_DIRECTORY': 'modelos/cell/cell-teacup/atomics/',
        'DEVSML_EVENTS_FILENAME': 'modelos/cell/cell-teacup/events.ev',
        'DEVSML_MA_FILENAME': 'modelos/cell/cell-teacup/mafile.ma',

        'DEVSML_TOP_FILENAME': 'modelos/cell/cell-teacup/top.xml',
        'DIR_CELL_DEVS': 'modelos/cell/cell-teacup/cell_devs.xml',
        'DIR_MA_CELL_DEVS': 'modelos/cell/cell-teacup/cell_devs.ma'
    }
}

for model, params in params_traducciones.items():
    DIR_XMILE = params['DIR_XMILE']
    DEVSML_CPP_H_DIRECTORY = params['DEVSML_CPP_H_DIRECTORY']
    DEVSML_TOP_FILENAME = params['DEVSML_TOP_FILENAME']
    DEVSML_EVENTS_FILENAME = params['DEVSML_EVENTS_FILENAME']
    DEVSML_MA_FILENAME = params['DEVSML_MA_FILENAME']

    DIR_CELL_DEVS = params['DIR_CELL_DEVS']
    DIR_MA_CELL_DEVS = params['DIR_MA_CELL_DEVS']

    try:
        shutil.rmtree(DEVSML_CPP_H_DIRECTORY)
        os.makedirs(DEVSML_CPP_H_DIRECTORY)
    except Exception:
        os.makedirs(DEVSML_CPP_H_DIRECTORY)
    # Initialize directory
    shutil.copyfile('templates/Makefile', DEVSML_CPP_H_DIRECTORY + '/Makefile')
    shutil.copyfile('templates/macros.inc', DEVSML_CPP_H_DIRECTORY + '/macros.inc')
    shutil.copyfile('templates/tuple_to_real.h', DEVSML_CPP_H_DIRECTORY + '/tuple_to_real.h')
    shutil.copyfile('templates/tuple_to_real.cpp', DEVSML_CPP_H_DIRECTORY + '/tuple_to_real.cpp')

    # Generate .devsml file
    generateDEVSML(DIR_XMILE, DEVSML_TEMPLATE_FILENAME, DEVSML_TOP_FILENAME)

    # Generate Cell-Devs xml
    generateCellDEVSML(DIR_CELL_DEVS)
    # Generation of .ma file corresponding to only the cell-devs
    devs_ml_model = preprocessing_devsml_for_ma(etree.parse(DIR_CELL_DEVS))
    cdpp_model = CdppModel.from_devsml_xml(devs_ml_model)
    mafile = CdppModelToMaConverter.parse_model(cdpp_model)
    with open(DIR_MA_CELL_DEVS, 'w') as f:
        f.write(str(mafile))

    # Combinar top.xml con cell_devs.xml
    with open(DEVSML_TOP_FILENAME, 'r') as top:
        parser1 = etree.XMLParser(encoding="utf-8")
        xml_top = etree.parse(top, parser=parser1)
        root_xml_top = xml_top.getroot()
        with open(DIR_CELL_DEVS, 'r') as cell_devs:
            parser2 = etree.XMLParser(encoding="utf-8")
            xml_cell_devs = etree.parse(cell_devs, parser=parser2)
            root_xml_cell_devs = xml_cell_devs.getroot()
            
            # Combine
            root_xml_top.find('./components').append(root_xml_cell_devs)

            # Save top-modified
            x = etree.tostring(root_xml_top)
            os.remove(DEVSML_TOP_FILENAME)
            vkb.xml(x, DEVSML_TOP_FILENAME)

    # Generate .ma, .ev, .cpp, .h, reg.cpp 
    generateHCPP(DEVSML_TOP_FILENAME, DEVSML_CPP_H_DIRECTORY, CPP_H_TEMPLATES_FILENAMES, DEVSML_EVENTS_FILENAME,
                 DEVSML_MA_FILENAME)