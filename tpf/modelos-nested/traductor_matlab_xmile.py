
import sys
import os
import shutil
cwd = os.getcwd()
if cwd not in sys.path:
    sys.path.append(cwd + '/modulosMATLAB/')
from modulosMATLAB.XMILEGenerator import XMILEGenerator
import logging

###################################################################################################################
# Configuraciones
logging.basicConfig(filename='logs/traductor_matlab.log', filemode='w', level=logging.DEBUG)

###################################################################################################################

XMILE_TEMPLATE_FILENAME = 'template-xmile.xml'

params_traducciones = {
	"loanable-funds": {
		"matlab_file": 'modelos/loanable-funds-matlab/loanable-funds.m',
		"xmile_output_file": 'modelos/loanable-funds-matlab/loanable-funds.xmile'
	},
	"goodwin-minsky-with-names": {
		"matlab_file": 'modelos/goodwin-minsky-matlab/goodwin-minsky-with-names.m',
		"xmile_output_file": 'modelos/goodwin-minsky-matlab/goodwin-minsky-with-names.xmile'
	}
}

for model, params in params_traducciones.items():
	with open(params['matlab_file'], 'rb') as f:
		matlab_code = f.read()
		xmile_generator = XMILEGenerator(matlab_code, XMILE_TEMPLATE_FILENAME)
		xmile_generator.generate_xmile(params['xmile_output_file'])