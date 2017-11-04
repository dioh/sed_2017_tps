#!/usr/bin/env python
from jinja2 import DictLoader, Environment, FileSystemLoader
import os
import numpy as np
import random as rd

PATH = './'
TEMPLATE_ENVIRONMENT = Environment(
    autoescape=False,
    loader=FileSystemLoader(os.path.join(PATH, 'templates')),
    trim_blocks=False)

def render_template(template_filename, context):
    return TEMPLATE_ENVIRONMENT.get_template(template_filename).render(context)

def generateRegFile(template, atomicClass):
    templateReg = template
    context = {
        'atomicClass' : atomicClass,
        'atomicClassConstant' : atomicClass.upper()
    }
    regFile = render_template(templateReg, context)
    return regFile

def generateMAFile(template, valFile, N, M, atomicos, inputs, links_internal, links_external, inputs_external, links_external_atomic, rules):
    templateMA = template
    context = {
        'N' : N,
        'M' : M,
        'valFile'  : valFile,
        'atomicos' : atomicos,
        'inputs_internal'   : inputs,
        'inputs_external'   : inputs_external,
        'links_external_atomic' : links_external_atomic,
        'links_internal'    : links_internal,
        'links_external'    : links_external,
        'rules' : rules
    }
    maFile = render_template(templateMA, context)
    return maFile

def generateAtomicFile(templateH, templateCPP, atomicClass, outPorts, numberOfChosenOutputPorts):
    context = {
        'atomicClass': atomicClass,
        'atomicClassConstant' : atomicClass.upper(),
        'outPorts'   : outPorts,
        'numberOfOutputPorts' : len(outPorts),
        'numberOfChosenOutputPorts' : numberOfChosenOutputPorts
    }
    hFile   = render_template(templateH, context)
    cppFile = render_template(templateCPP, context)
    return {
        'h'   : hFile,
        'cpp' : cppFile
    }
    return 0

def generateInputAndLinks(N,M,numGroups,modelName,atomicName,atomicClass):
    # Celdas
    cells  = [(n,m) for n in range(0,N) for m in range(0,M)]
    assign = []
    val = 0
    while len(cells) > 0:
        i = rd.randint(0,len(cells)-1)
        assign.append((cells[i][0], cells[i][1], val))
        cells.pop(i)
        val = (val + 1) % numGroups

    # Inputs + Links external
    inputs_external = ['in' + str(i) for i in range(0,numGroups)]
    links_external_atomic = ['link : in' + str(i) + ' ' + 'in@' + atomicName + str(i) for i in range(0,numGroups)]

    # Mapeo conexiones de atomicos 0..numGroups a las celdas correspondientes
    outputsPerAtomic = int(N * M / numGroups)
    assert(outputsPerAtomic * numGroups == N * M)

    outputsAtomicos = [[] for i in range(0,numGroups)]
    numOutAssigned  = [0] * numGroups

    inputsModelo  = []
    linksInternos = []
    linksExternos = []
    for assignation in assign:
        inputCellNumber = str(assignation[0]) + str(assignation[1])

        # Inputs modelo
        inputsModelo.append('in' + inputCellNumber)

        # Links internos
        linksInternos.append('link : in' + inputCellNumber + ' in@' + modelName +
                             '(' + str(assignation[0]) + ',' + str(assignation[1]) + ',0)')
        # Links externos
        outputAtomicNumber = str(assignation[2])
        linksExternos.append('link : out' + str(numOutAssigned[assignation[2]]) +
                             '@' + atomicName + str(assignation[2]) + ' ' + 'in' + inputCellNumber +
                             '@' + modelName)

        # Mapa Outputs <==> Atomicos
        outputsAtomicos[assignation[2]].append('out' + str(numOutAssigned[assignation[2]]))

        # Instancias de atomicos
        atomicos = [atomicName + str(i) + '@' + atomicClass for i in range(0,numGroups)]

        # actualizo valores
        numOutAssigned[assignation[2]] += 1

    return {'inputsModelo'  : sorted(inputsModelo),
            'linksInternos' : sorted(linksInternos),
            'linksExternos' : sorted(linksExternos),
            'atomicos'      : atomicos,
            'outputsAtomicos' : outputsAtomicos[0],
            'inputs_external' : inputs_external,
            'links_external_atomic' : links_external_atomic}

############ Genero archivos para correr tests ############
# Parametros
N = 10
M = 10
numGroups = 5
modelName  = 'opinion'
atomicName = 'shocker'
atomicClass= 'Shocker'

# Genero archivo .ma
inputsLinks = generateInputAndLinks(N,M,numGroups,modelName,atomicName,atomicClass)
inputsModelo    = inputsLinks['inputsModelo']
links_externos  = inputsLinks['linksExternos']
links_internos  = inputsLinks['linksInternos']
atomicos        = inputsLinks['atomicos']
outputsAtomicos = inputsLinks['outputsAtomicos']
inputs_external = inputsLinks['inputs_external']
links_external_atomic = inputsLinks['links_external_atomic']

# Reglas de reaccion ante los 'shockers'
rules = [
    # polarizador
    '{ if ( (0,0,0) < 0 , uniform(-3, -2), uniform(2, 3) ) } 0 { (0,0,0) = 5 }',
    # despolarizador
    '{ if ( (0,0,0) < 0 , uniform(-1, 0), uniform(0, 1) ) } 0 { (0,0,0) = 6 }'
]

# Parametros (defino a cuantas celdas el 'shocker' redirije el valor que le pasamos)
# Por default, lo redirije a (1/2)*(cantidad de celdas con las que esta conectado)
outPorts = outputsAtomicos
nChosenOutports = int(len(outPorts) / 2)

maFilename = 'Influmodel.ma'
mafile = generateMAFile('model_template.ma', 'valfile.val', N, M,
                        atomicos, inputsModelo,
                        links_internos, links_externos, inputs_external, links_external_atomic,
                        rules)

# Genero archivo .ma
folder = './'
with open(folder + maFilename, 'w') as f:
        f.write(mafile)

# Genero archivos .h y .cpp
folder = 'src/'
atomic = generateAtomicFile('atomic_template.h', 'atomic_template.cpp',
                                atomicClass, outPorts, nChosenOutports)

with open(folder + atomicClass + '.h', 'w') as f:
    hFile   = atomic['h']
    f.write(hFile)

with open(folder + atomicClass + '.cpp', 'w') as f:
    cppFile = atomic['cpp']
    f.write(cppFile)

# Genero reg.cpp file
## TODO

# Genero 'event file'
# Por default, genero 







