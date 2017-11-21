# coding: utf-8
import xml.etree.ElementTree as ET
from future.utils import iteritems, lfilter
from jinja2 import DictLoader, Environment, FileSystemLoader
import os
import re

# Parametros para funciones generadoras
PATH = './'
TEMPLATE_ENVIRONMENT = Environment(
    autoescape=False,
    loader=FileSystemLoader(os.path.join(PATH, 'templates')),
    trim_blocks=False)
TEMPLATE_DEVSML = 'template-devsml.xml'

# archivoXmile  = 'modelos traducidos/sir.xmile'
# archivoDevsml = 'sir/sir-devsml-traduccion-2.xml'

# archivoXmile  = 'modelos traducidos/teacup.xmile'
# archivoDevsml = 'teacup/teacup-devsml-traduccion-2.xml'


def render_template(template_filename, context):
    return TEMPLATE_ENVIRONMENT.get_template(template_filename).render(context)


def convert_xmile_to_devsml(archivoDevsml, archivoXmile):
    tree = ET.parse(archivoXmile)
    root = tree.getroot()

    model = root.find('model')
    variables = model.find('variables')
    flows = variables.findall('flow')
    auxs = variables.findall('aux')
    stocks = variables.findall('stock')

    flows_, auxs_, ctes_, stocks_ = {}, {}, {}, {}
    # Obtengo inflows y Outflows de cada Stock
    # Obtengo origen y destino de cada Flow
    for stock in stocks:
        stockName = stock.get('name').replace('"', '')
        initialValue = stock.find('eqn').text
        stocks_[stockName] = {'inflows': [],
                              'outflows': [],
                              'initialValue': initialValue}

        if stock.find('inflow') is not None:
            for inflow in stock.findall('inflow'):
                stocks_[stockName]['inflows'].append(inflow.text)
                if inflow.text not in flows_.keys():
                    flows_[inflow.text.replace('"', '')] = {'orig': None,
                                                            'dest': stockName}
                else:
                    flows_[inflow.text.replace('"', '')]['dest'] = stockName
        if stock.find('outflow') is not None:
            for outflow in stock.findall('outflow'):
                stocks_[stockName]['outflows'].append(outflow.text)
                if outflow.text not in flows_.keys():
                    flows_[outflow.text.replace('"', '')] = {'orig': stockName,
                                                             'dest': None}
                else:
                    flows_[outflow.text.replace('"', '')]['orig'] = stockName

    # Genero auxs_ y ctes_
    for aux in auxs:
        auxName = aux.get('name').replace('"', '')
        assert(aux.find('eqn') is not None)

        if(re.search('[a-zA-Z]', aux.find('eqn').text) is None):
            ctes_[auxName] = {'eqn': aux.find('eqn').text, 'units': None}
            if aux.find('units') is not None:
                ctes_[auxName]['units'] = aux.find('units').text
        else:
            auxs_[auxName] = {'eqn': aux.find('eqn').text, 'units': None}
            if aux.find('units') is not None:
                auxs_[auxName]['units'] = aux.find('units').text

    ###
    # Completo informacion sobre cada Flow en 'flows_'
    for flow in flows:
        flowName = flow.get('name').replace('"', '')
        flows_[flowName]['eqn'] = flow.find('eqn').text
        flows_[flowName]['units'] = None
        if flow.find('units') is not None:
            flows_[flowName]['units'] = flow.find('units').text
        flows_[flowName]['params_eqn'] = lfilter(lambda x: x != '',
                                                 re.split("[-+*/()]+",
                                                          flow.find('eqn').text))

        for auxName, _ in ctes_.items():
            for flowName, flowAttr in flows_.items():
                if auxName in flowAttr['params_eqn']:
                    if flowAttr['orig'] is not None:
                    if flowAttr['dest'] is not None:

    for stockName, attr in iteritems(stocks_):
        for i, flow in enumerate(attr['outflows']):
            val = stocks_[stockName]['outflows'][i].replace('"', '')
            stocks_[stockName]['outflows'][i] = (val, flows_[val]['dest'])
        for i, flow in enumerate(attr['inflows']):
            val = stocks_[stockName]['inflows'][i]
            stocks_[stockName]['inflows'][i] = (val, flows_[val]['orig'])

    context = {
        'stocks_': stocks_,
        'flows_': flows_,
        'auxs_': auxs_,
        'ctes_': ctes_
    }
    # print render_template(TEMPLATE_DEVSML,context)
    # Guardar el .devsml en output
    with open(archivoDevsml, 'w') as f:
        f.write(render_template(TEMPLATE_DEVSML, context))

    return True
