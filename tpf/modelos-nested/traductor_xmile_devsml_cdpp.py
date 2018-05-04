
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
    #'teacup': {
    #    'DIR_XMILE': 'modelos/teacup/teacup.xmile',
    #    'DEVSML_CPP_H_DIRECTORY': 'modelos/teacup/atomics/',
    #    'DEVSML_EVENTS_FILENAME': 'modelos/teacup/events.ev',
    #    'DEVSML_TOP_FILENAME': 'modelos/teacup/top.xml',
    #    'DEVSML_MA_FILENAME': 'modelos/teacup/mafile.ma'
    #},
    #'lotka-volterra': {
    #    'DIR_XMILE': 'modelos/lotka-volterra/lotka-volterra.xmile',
    #    'DEVSML_CPP_H_DIRECTORY': 'modelos/lotka-volterra/atomics/',
    #    'DEVSML_EVENTS_FILENAME': 'modelos/lotka-volterra/events.ev',
    #    'DEVSML_TOP_FILENAME': 'modelos/lotka-volterra/top.xml',
    #    'DEVSML_MA_FILENAME': 'modelos/lotka-volterra/mafile.ma'
    #},
    #'lotka-volterra-nested-1': {
    #    'DIR_XMILE': 'modelos/lotka-volterra-nested-1/lotka-volterra-nested-1.xmile',
    #    'DEVSML_CPP_H_DIRECTORY': 'modelos/lotka-volterra-nested-1/atomics/',
    #    'DEVSML_EVENTS_FILENAME': 'modelos/lotka-volterra-nested-1/events.ev',
    #    'DEVSML_TOP_FILENAME': 'modelos/lotka-volterra-nested-1/top.xml',
    #    'DEVSML_MA_FILENAME': 'modelos/lotka-volterra-nested-1/mafile.ma'
    #},
    #'lotka-volterra-nested-2' : {
    #    'DIR_XMILE': 'modelos/lotka-volterra-nested-2/lotka-volterra-nested-2.xmile',
    #    'DEVSML_CPP_H_DIRECTORY': 'modelos/lotka-volterra-nested-2/atomics/',
    #    'DEVSML_EVENTS_FILENAME': 'modelos/lotka-volterra-nested-2/events.ev',
    #    'DEVSML_TOP_FILENAME': 'modelos/lotka-volterra-nested-2/top.xml',
    #    'DEVSML_MA_FILENAME': 'modelos/lotka-volterra-nested-2/mafile.ma'
    #},
    #,
    #'loanable-funds': {
    #    'DIR_XMILE': 'modelos/loanable-funds-matlab/loanable-funds.xmile',
    #    'DEVSML_CPP_H_DIRECTORY': 'modelos/loanable-funds-matlab/atomics/',
    #    'DEVSML_EVENTS_FILENAME': 'modelos/loanable-funds-matlab/events.ev',
    #    'DEVSML_TOP_FILENAME': 'modelos/loanable-funds-matlab/top.xml',
    #    'DEVSML_MA_FILENAME': 'modelos/loanable-funds-matlab/mafile.ma'
    #},
    #'goodwin-minsky-with-names': {
    #    'DIR_XMILE': 'modelos/goodwin-minsky-matlab/goodwin-minsky-with-names.xmile',
    #    'DEVSML_CPP_H_DIRECTORY': 'modelos/goodwin-minsky-matlab/atomics/',
    #    'DEVSML_EVENTS_FILENAME': 'modelos/goodwin-minsky-matlab/events.ev',
    #    'DEVSML_TOP_FILENAME': 'modelos/goodwin-minsky-matlab/top.xml',
    #    'DEVSML_MA_FILENAME': 'modelos/goodwin-minsky-matlab/mafile.ma'
    #},

    #'pulse2': {
    #    'DIR_XMILE': 'modelos/builtin/pulse2/pulse1.xmile',
    #    'DEVSML_CPP_H_DIRECTORY': 'modelos/builtin/pulse2/atomics/',
    #    'DEVSML_EVENTS_FILENAME': 'modelos/builtin/pulse2/events.ev',
    #    'DEVSML_TOP_FILENAME': 'modelos/builtin/pulse2/top.xml',
    #    'DEVSML_MA_FILENAME': 'modelos/builtin/pulse2/mafile.ma'
    #},
    'pulse3': {
        'DIR_XMILE': 'modelos/builtin/pulse3/pulse3.xmile',
        'DEVSML_CPP_H_DIRECTORY': 'modelos/builtin/pulse3/atomics/',
        'DEVSML_EVENTS_FILENAME': 'modelos/builtin/pulse3/events.ev',
        'DEVSML_TOP_FILENAME': 'modelos/builtin/pulse3/top.xml',
        'DEVSML_MA_FILENAME': 'modelos/builtin/pulse3/mafile.ma'
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

    # Generate .devsml file
    generateDEVSML(DIR_XMILE, DEVSML_TEMPLATE_FILENAME, DEVSML_TOP_FILENAME)

    # Generate .ma, .ev, .cpp, .h, reg.cpp 
    generateHCPP(DEVSML_TOP_FILENAME, DEVSML_CPP_H_DIRECTORY, CPP_H_TEMPLATES_FILENAMES, DEVSML_EVENTS_FILENAME,
                 DEVSML_MA_FILENAME)