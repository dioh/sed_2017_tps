# coding: utf-8
import xml.etree.ElementTree as ET
from jinja2 import DictLoader, Environment, FileSystemLoader
import os
import re
import numpy as np
# Parametros para funciones generadoras
PATH = './'
TEMPLATE_ENVIRONMENT = Environment(
    autoescape=False,
    loader=FileSystemLoader(os.path.join(PATH, 'templates')),
    trim_blocks=False)

TEMPLATE_MA = 'template-ma.ma'
TEMPLATE_FTOT_H = 'template-Ftot.h'
TEMPLATE_FTOT_CPP = 'template-Ftot.cpp'
TEMPLATE_FPM_H = 'template-Fpm.h'
TEMPLATE_FPM_CPP = 'template-Fpm.cpp'
TEMPLATE_REG_CPP = 'template-reg.cpp'
TEMPLATE_EV = 'template-ev.ev'


def render_template(template_filename, context):
    return TEMPLATE_ENVIRONMENT.get_template(template_filename).render(context)


def stock2integrator(stockName):
    return (stockName[0].lower() + stockName[1:] + 'Integrator').replace(' ', '')


def flow2coupledTot(flowName):
    return 'ft' + flowName.split(' - ')[0][2:].replace(' ', '')


def flow2fm(flowName):
    return (flowName.split(' - ')[0] + flowName.split(' - ')[1]).replace(' ', '')


def flow2fp(flowName):
    return (flowName.split(' - ')[0] + flowName.split(' - ')[1]).replace(' ', '')


def flow2ft(flowName):
    return flowName.replace(' ', '') + 'Integrator'


def cte2cte(cteName):
    return (cteName[0].lower() + cteName[1:]).replace(' ', '')


def aux2aux(auxName):
    return auxName


def getFunctionParams(function):
    return filter(lambda x: x != '', re.split('[-+*/()]+',function))

def processFunction(function, integradores_, auxs_, ctes_):
    result = function
    stockNames = [integradores_[intName]['stockName'] 
                  for intName, attr in integradores_.iteritems()]

    cteNames = [ctes_[cteName]['cteName']
                for cteName, attr in ctes_.iteritems()]

    auxsNames = [auxs_[auxName]['auxName'] 
                 for auxName, attr in auxs_.iteritems()]

    for stockName in stockNames:
        if stockName in result:
            result = result.replace(stockName, stock2integrator(stockName))

    for cteName in cteNames:
        if cteName in result:
            result = result.replace(cteName, cte2cte(cteName))

    for auxName in auxsNames:
        if auxName in result:
            result = result.replace(auxName, aux2aux(auxName))
    return result


def devsml2cdpp(archivoDevsml, archivoMa, archivoEv, srcFolder):
    tree = ET.parse(archivoDevsml)
    root = tree.getroot()

    coupled = root.find('scenario').find('coupled')
    inputPorts = coupled.find('inputs').findall('port')
    outputPorts = coupled.find('outputs').findall('port')
    atomicos = coupled.find('components').findall('atomicRef')
    links_internal = coupled.find('internal_connections').findall('connection')
    links_external = coupled.find('external_input_connections').findall('connection')

    # Atomicos
    integradores, fms, fps, fts, auxs, ctes = [], [], [], [], [], []
    for atomico in atomicos:
        if atomico.get('model') == 'QSS1':
            integradores.append(atomico)
        if atomico.get('model') == 'Ftot':
            fts.append(atomico)
        if atomico.get('model') == 'Fminus':
            fms.append(atomico)
        if atomico.get('model') == 'Fplus':
            fps.append(atomico)
        if atomico.get('model') == 'Cte':
            ctes.append(atomico)
        if atomico.get('mode') == 'Aux':
            auxs.append(atomico)

    # Integradores
    integradores_ = {}
    for integrador in integradores:
        intName = stock2integrator(integrador.get('name'))
        integradores_[intName] = { 
            'stockName': integrador.get('name'),
            'ftName': 'ft' + intName[0].upper() + intName[1:]
        }
        integradores_[intName]['model'] = integrador.get('model')
        for param in integrador.findall('parameter'):
            integradores_[intName][param.get('name')] = param.get('value')
    
    # ctes
    ctes_ = {}
    for cte in ctes:
        cteName = cte2cte(cte.get('name'))
        ctes_[cteName] = {'params': {}, 
                          'ports': [],
                          'cteName': cte.get('name')}

        ctes_[cteName]['model'] = cte.get('model')

        assert(len(cte.find('parameter')) <= 1)
        param = cte.find('parameter')
        ctes_[cteName]['params']['name'] = param.get('name')
        ctes_[cteName]['params']['value'] = param.get('value')
        ctes_[cteName]['params']['unit'] = param.get('unit')
        for port in cte.find('port'):
            ctes_[cteName]['ports'].append({ 'type' : port.get('type'), 'name' : port.get('name') })

    # auxs (TODO)
    auxs_ = {}

    #####
    # fts
    fts_ = {}
    for ft in fts:
        ftName = flow2ft(ft.get('name'))
        fts_[ftName] = {'params': [],
                        'ports': []}
        fts_[ftName]['model'] = ft.get('model') + ftName[2:]
        for param in ft.findall('parameter'):
            fts_[ftName]['params'].append({param.get('name'): param.get('value')})

        for port in ft.findall('port'):
            if '-' in port.get('name'):
                portName = (port.get('name').split(' - ')[0] + '_' + port.get('name').split(' - ')[1]).replace(' ', '')
            else:
                portName = port.get('name')
            fts_[ftName]['ports'].append({'type': port.get('type'),
                                          'name': portName})
    
    # fms
    fms_ = {}
    for fm in fms:
        fmName = flow2fm(fm.get('name'))
        fms_[fmName] = { 
            'ports' : [] , 'flowName' : fm.get('name').split(' - ')[1].replace(' ', ''),
            'params_ports' : {}
        }
        # Nombre del integrador con el que se acopla
        fms_[fmName]['coupledTot'] = flow2coupledTot(fm.get('name'))
        
        # Nombre modelo atomico
        fms_[fmName]['model'] = fm.get('model') + \
            fm.get('name').split(' - ')[0][2:].replace(' ', '') + \
            fm.get('name').split(' - ')[1].replace(' ', '')
        
        #
        assert(len(fm.findall('parameter')) == 1)
        param = fm.find('parameter')
        
        assert(param.get('name') == 'function')
        assert(param.get('value') is not None)
        function = processFunction(param.get('value'), integradores_, auxs_, ctes_)
        function_params = getFunctionParams(function)
        fms_[fmName]['function'] = function
        fms_[fmName]['function_params'] = function_params
        
        for param in fms_[fmName]['function_params']:
            fms_[fmName]['ports'].append('in_' + param)
            fms_[fmName]['params_ports'][param] = 'in_' + param
    
    # fps
    fps_ = {}
    for fp in fps:
        fpName = flow2fp(fp.get('name'))
        fps_[fpName] = { 
            'ports' : [], 'flowName' : fp.get('name').split(' - ')[1].replace(' ', ''),
            'params_ports' : {}
        }
        # Nombre del integrador con el que se acopla
        fps_[fpName]['coupledTot'] = flow2coupledTot(fp.get('name'))
        # Nombre modelo atomico
        fps_[fpName]['model'] = fp.get('model') + \
            fp.get('name').split(' - ')[0][2:].replace(' ', '') + \
            fp.get('name').split(' - ')[1].replace(' ', '')

        #
        assert(len(fp.findall('parameter')) == 1)
        param = fp.find('parameter')

        assert(param.get('name') == 'function')
        assert(param.get('value') is not None)
        function = processFunction(param.get('value'), integradores_, auxs_, ctes_)
        function_params = getFunctionParams(function)
        fps_[fpName]['function'] = function
        fps_[fpName]['function_params'] = function_params

        for param in fps_[fpName]['function_params']:
            fps_[fpName]['ports'].append('in_' + param)
            fps_[fpName]['params_ports'][param] = 'in_' + param

    #####
    # Normalizacion de los datos en cada objeto (ej. : la inicializacion de los integradores)
    for intName, intAttr in integradores_.iteritems():
        integradores_[intName]['x0'] = cte2cte(intAttr['x0'])

        x0 = intAttr['x0']
        # AUX (TODO)

        # CTE 
        for cteName, cteAttr in ctes_.iteritems():
            x0 = x0.replace(cteName, cteAttr['params']['value'])
        integradores_[intName]['x0'] = x0

    #####
    context = {
        'integradores_': integradores_,
        'fts_': fts_,
        'fms_': fms_,
        'fps_': fps_,
        'ctes_': ctes_,
        'auxs_': auxs_
    }
    # print context

    #####
    fileGenParams = []

    #####
    # Guardar el .ma en output
    with open(archivoMa, 'w') as f:
        f.write(render_template(TEMPLATE_MA, context))

    # ############## GENERATE .H's AND .CPP's ############## #

    # Ftot's
    for ftName, ftAttr in fts_.iteritems():
        ft_inPorts = []
        ft_outPorts = []
        for port in ftAttr['ports']:
            if port['type'] == 'in':
                ft_inPorts.append(port['name'])
            if port['type'] == 'out':
                ft_outPorts.append(port['name'])
        ft_context = {
            'ft_inPorts': ft_inPorts, 'ft_outPorts': ft_outPorts,
            'model': ftAttr['model'], 'modelUpper': ftAttr['model'].upper()}
        # #################
        # GUARDAR FTOT'S
        with open(srcFolder + ftAttr['model'] + '.h', 'w') as f:
            f.write(render_template(TEMPLATE_FTOT_H, ft_context))
        with open(srcFolder + ftAttr['model'] + '.cpp', 'w') as f:
            f.write(render_template(TEMPLATE_FTOT_CPP, ft_context))

    # Fm's + Fp's
    for fmName, fmAttr in fms_.iteritems():
        fm_context = { 
            'model': fmAttr['model'], 'modelUpper': fmAttr['model'].upper(),
            'ports': fmAttr['ports'], 'params_ports': fmAttr['params_ports'],
            'function': fmAttr['function']
        }
        ##################
        # GUARDAR FMINUS'S
        with open(srcFolder + fmAttr['model'] + '.h', 'w') as f:
            f.write(render_template(TEMPLATE_FPM_H, fm_context))
        with open(srcFolder + fmAttr['model'] + '.cpp', 'w') as f:
            f.write(render_template(TEMPLATE_FPM_CPP, fm_context))
            
    for fpName, fpAttr in fps_.iteritems():
        fp_context = {
            'model': fpAttr['model'], 'modelUpper': fpAttr['model'].upper(),
            'ports': fpAttr['ports'], 'params_ports': fpAttr['params_ports'],
            'function': fpAttr['function']
        }
        ##################
        # GUARDAR FPLUS'S
        with open(srcFolder + fpAttr['model'] + '.h', 'w') as f:
            f.write(render_template(TEMPLATE_FPM_H, fp_context))
        with open(srcFolder + fpAttr['model'] + '.cpp', 'w') as f:
            f.write(render_template(TEMPLATE_FPM_CPP, fp_context))
    #######
    # Cte's
    # OK
    # Aux's
    # (TODO)

    #######
    # Generate 'Register File'
    reg_context = {'models': {}}
    for ftName, ftAttr in fts_.iteritems():
        reg_context['models'][ftAttr['model']] = {'modelUpper': ftAttr['model'].upper()}
    for fpName, fpAttr in fps_.iteritems():
        reg_context['models'][fpAttr['model']] = {'modelUpper': fpAttr['model'].upper()}
    for fmName, fmAttr in fms_.iteritems():
        reg_context['models'][fmAttr['model']] = {'modelUpper': fmAttr['model'].upper()}
    with open(srcFolder + 'reg.cpp', 'w') as f:
        f.write(render_template(TEMPLATE_REG_CPP, reg_context))
  
    #######
    # Generate 'Events (.ev) File'
    ev_context = {'inputs': {}}
    for cteName, cteAttr in ctes_.iteritems():
        ev_context['inputs']['in_' + cteName] = cteAttr['params']['value']
    # print(ev_context)
    with open(archivoEv, 'w') as f:
        f.write(render_template(TEMPLATE_EV, ev_context))


# Generador de archivo .ma
# archivoDevsml = 'teacup/teacup-devsml-traduccion-2.xml'
# archivoMa = 'teacup/teacup-ma-traduccion-2.ma'
# archivoEv = 'teacup/teacup-2.ev'
# devsml2cdpp(archivoDevsml, archivoMa, archivoEv, 'teacup/src/')

# archivoDevsml = 'sir/sir-devsml-traduccion-2.xml'
# archivoMa = 'sir/sir-ma-traduccion-2.ma'
# archivoEv = 'sir/sir-2.ev'
# devsml2cdpp(archivoDevsml, archivoMa, archivoEv, 'sir/src/')

