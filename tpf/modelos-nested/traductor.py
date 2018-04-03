
import sys
import os
cwd = os.getcwd()
if cwd not in sys.path:
    sys.path.append(cwd)
from modulosDEVS.DEVSGenerator import *


DIR_XMILE = 'lotka-volterra-nested/lotka-volterra-nested-2.xmile'
DEVSML_CPP_H_DIRECTORY = 'lotka-volterra-nested/atomics/'
DEVSML_TEMPLATE_FILENAME = 'template-devsml.xml'
CPP_H_TEMPLATES_FILENAMES = {
    'reg.cpp'            : 'template-reg.cpp',
    'Ftot.cpp'           : 'a',
    'Ftot.h'             : 'a',
    'Fplus.cpp'          : 'b',
    'Fplus.h'            : 'b',
    'Fminus.cpp'         : 'c',
    'Fminus.h'           : 'c',
    'DEVSPulse.cpp'      : 'd',
    'DEVSPulse.h'        : 'd',
    'DEVSAux.cpp'        : 'e',
    'DEVSAux.h'          : 'e',
    'DEVSIntegrator.cpp' : 'f',
    'DEVSIntegrator.h'   : 'f',
    'DEVSConstant.cpp'   : 'template-Cte.cpp',
    'DEVSConstant.h'     : 'template-Cte.h'
}
DEVSML_TOP_FILENAME = 'lotka-volterra-nested/top.xml'

# Generate devsml
generateDEVSML(DIR_XMILE, DEVSML_TEMPLATE_FILENAME, DEVSML_TOP_FILENAME)
# Generate ma
#
# Generate h's and cpp's for atomic components
generateHCPP(DEVSML_TOP_FILENAME, DEVSML_CPP_H_DIRECTORY, CPP_H_TEMPLATES_FILENAMES)