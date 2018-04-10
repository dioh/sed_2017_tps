
import sys
import os
import shutil
cwd = os.getcwd()
if cwd not in sys.path:
    sys.path.append(cwd + '/modulosDEVS/')
    sys.path.append(cwd + '/modulosXMILE/')
from modulosDEVS.DEVSGenerator import *
import logging

###################################################################################################################
# Configuraciones
logging.basicConfig(filename='DEVSGenerator.log', filemode='w', level=logging.DEBUG)

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
    'DEVSPulse': 'd',
    'DEVSPulse': 'd',
    'DEVSIntegrator': 'qss1'
}

params_traducciones = {
    #'lotka-volterra-nested' : {
    #    'DIR_XMILE': 'lotka-volterra-nested/lotka-volterra-nested-2.xmile',
    #    'DEVSML_CPP_H_DIRECTORY': 'lotka-volterra-nested/atomics/',
    #    'DEVSML_EVENTS_FILENAME': 'lotka-volterra-nested/events.ev',
    #    'DEVSML_TOP_FILENAME': 'lotka-volterra-nested/top.xml',
    #    'DEVSML_MA_FILENAME': 'lotka-volterra-nested/mafile.ma'
    #},
    'teacup' : {
        'DIR_XMILE': 'teacup/teacup.xmile',
        'DEVSML_CPP_H_DIRECTORY': 'teacup/atomics/',
        'DEVSML_EVENTS_FILENAME': 'teacup/events.ev',
        'DEVSML_TOP_FILENAME': 'teacup/top.xml',
        'DEVSML_MA_FILENAME': 'teacup/mafile.ma'
    }
}

for model, params in params_traducciones.items():
    DIR_XMILE = params['DIR_XMILE']
    DEVSML_CPP_H_DIRECTORY = params['DEVSML_CPP_H_DIRECTORY']
    DEVSML_TOP_FILENAME = params['DEVSML_TOP_FILENAME']
    DEVSML_EVENTS_FILENAME = params['DEVSML_EVENTS_FILENAME']
    DEVSML_MA_FILENAME = params['DEVSML_MA_FILENAME']

    try:
        shutil.rmtree(DEVSML_CPP_H_DIRECTORY)
        os.makedirs(DEVSML_CPP_H_DIRECTORY)
    except Exception:
        os.makedirs(DEVSML_CPP_H_DIRECTORY)
    shutil.copyfile('templates/Makefile', DEVSML_CPP_H_DIRECTORY + '/Makefile')
    #shutil.copyfile('templates/qss1.h', DEVSML_CPP_H_DIRECTORY + '/qss1.h')
    #shutil.copyfile('templates/qss1.cpp', DEVSML_CPP_H_DIRECTORY + '/qss1.cpp')

    # Generate .devsml file
    generateDEVSML(DIR_XMILE, DEVSML_TEMPLATE_FILENAME, DEVSML_TOP_FILENAME)
    # Generate .ma, .ev, .cpp, .h, reg.cpp 
    generateHCPP(DEVSML_TOP_FILENAME, DEVSML_CPP_H_DIRECTORY, CPP_H_TEMPLATES_FILENAMES, DEVSML_EVENTS_FILENAME,
                 DEVSML_MA_FILENAME)