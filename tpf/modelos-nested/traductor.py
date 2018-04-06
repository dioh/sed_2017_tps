
import sys
import os
import shutil
cwd = os.getcwd()
if cwd not in sys.path:
    sys.path.append(cwd)
from modulosDEVS.DEVSGenerator import *

DEVSML_TEMPLATE_FILENAME = 'template-devsml.xml'
CPP_H_TEMPLATES_FILENAMES = {
    'reg'              : 'template-reg.cpp',
    'DEVSFtot'         : 'template-Ftot',
    'Fplus'            : 'template-Aux-Fpm',
    'Fminus'           : 'template-Aux-Fpm',
    'DEVSAux'          : 'template-Aux-Fpm',
    'DEVSConstant'     : 'template-Cte',
    'events'           : 'template-ev.ev',
    'DEVSPulse'        : 'd',
    'DEVSPulse'        : 'd',
    'DEVSIntegrator'   : 'qss1'
}

params_traducciones = {
    'lotka-volterra-nested' : {
        'DIR_XMILE' : 'lotka-volterra-nested/lotka-volterra-nested-2.xmile',
        'DEVSML_CPP_H_DIRECTORY' : 'lotka-volterra-nested/atomics/',
        'DEVSML_EVENTS_FILENAME' : 'lotka-volterra-nested/events.ev',
        'DEVSML_TOP_FILENAME' : 'lotka-volterra-nested/top.xml'
    },
    'teacup' : {
        'DIR_XMILE' : 'teacup/teacup.xmile',
        'DEVSML_CPP_H_DIRECTORY' : 'teacup/atomics/',
        'DEVSML_EVENTS_FILENAME' : 'teacup/events.ev',
        'DEVSML_TOP_FILENAME' : 'teacup/top.xml'
    }
}

for model, params in params_traducciones.items():
    DIR_XMILE = params['DIR_XMILE']
    DEVSML_CPP_H_DIRECTORY = params['DEVSML_CPP_H_DIRECTORY']
    DEVSML_TOP_FILENAME = params['DEVSML_TOP_FILENAME']
    DEVSML_EVENTS_FILENAME = params['DEVSML_EVENTS_FILENAME']

    try:
        shutil.rmtree(DEVSML_CPP_H_DIRECTORY)
        os.makedirs(DEVSML_CPP_H_DIRECTORY)
    except Exception:
        os.makedirs(DEVSML_CPP_H_DIRECTORY)

    # Generate .devsml file
    generateDEVSML(DIR_XMILE, DEVSML_TEMPLATE_FILENAME, DEVSML_TOP_FILENAME)
    # Generate .ma, .ev, .cpp, .h, reg.cpp 
    generateHCPP(DEVSML_TOP_FILENAME, DEVSML_CPP_H_DIRECTORY, CPP_H_TEMPLATES_FILENAMES, DEVSML_EVENTS_FILENAME)