'''
Funciones para convertir archivo xmile en devsml
'''

import xml.etree.ElementTree as ET
import networkx as nx
from .xml_utils import read_xml

DEVS_ML_BASE_DOC = '''<?xml version="1.0" encoding="utf-8"?>
                    <devs>
                    <scenario>
                      <coupled name="top" model="Coupled" >
                        <inputs />
                       <outputs />
                        <components />
                        <internal_connections />
                        <external_input_connections />
                        <external_output_connections />
                      </coupled>
                    </scenario>
                    <models />
                    </devs>'''


def aux_from_xml_node(node, ns=None):
    """
    Devuelve un nodo de tipo aux para el grafo
    """
    name = node.attrib['name']
    attrib = dict()
    attrib['type'] = 'aux'
    attrib['eqn'] = node.find('eqn').text

    return name, attrib


def flow_from_xml_node(node, ns=None):
    """
    Devuelve un nodo de tipo aux para el grafo
    """
    name = node.attrib['name']
    attrib = dict()
    attrib['eqn'] = node.find('eqn').text
    attrib['type'] = 'flow'
    variables = attrib['eqn'].split('"')[1::2]
    edges = []
    for variable in variables:
        edges.append((variable, name))

    return name, attrib, edges


def stock_from_xml_node(node, ns=None):
    """
    Devuelve un nodo de tipo aux para el grafo
    """
    name = node.attrib['name']
    attrib = dict()
    attrib['type'] = 'stock'
    attrib['eqn'] = node.find('eqn', ns).text
    inflows = []
    outflows = []
    edges = []
    for inflow in node.findall('inflow', ns):
        inflow_name = inflow.text.strip('"')
        inflows.append(inflow_name)
        edges.append((inflow_name, name))

    for outflow in node.findall('outflow', ns):
        outflow_name = outflow.text.strip('"')
        outflows.append(outflow_name)
        edges.append((outflow_name, name))

    attrib['inflows'] = inflows
    attrib['outflows'] = outflows

    return name, attrib, edges


def add_namespace_to_tag(tag, ns_uri, ns):
    """
    Agrega el namespace asociado al uri al nombre del tag
    """
    if ns is None:
        return tag

    for namespace, uri in ns.items():
        if uri == ns_uri:
            return namespace + ':' + tag

    # TODO: Revisar. Posiblemente lo mejor sea lanzar excepcion
    return tag


def add_xmile_namespace_to_tag(tag, ns=None):
    """
    Agrega el namespace de xmile al tag
    """
    xmile_ns_uri = 'http://docs.oasis-open.org/xmile/ns/XMILE/v1.0'
    return add_namespace_to_tag(tag, xmile_ns_uri, ns)


def add_devml_namespace_to_tag(tag, ns=None):
    """
    Agrega el namespace de devsml al tag
    """
    return add_namespace_to_tag(tag, 'http://tempuri.org/devs-coupled', ns)


def dag_from_xmile_model(doc, ns=None):
    """
    Devuelve el DAG asociado al modelo
    """

    dag = nx.DiGraph()
    edges = []
    # Procesar seccion variables
    variables = doc.find(add_xmile_namespace_to_tag('variables', ns), ns)
    for child in variables:
        if child.tag == add_xmile_namespace_to_tag('aux', ns):
            node_name, node_atrribs = aux_from_xml_node(child, ns)
            dag.add_node(node_name, **node_atrribs)
        if child.tag == add_xmile_namespace_to_tag('flow', ns):
            node_name, node_atrribs, new_edges = flow_from_xml_node(child, ns)
            edges = edges + new_edges
            dag.add_node(node_name, **node_atrribs)
        if child.tag == add_xmile_namespace_to_tag('stock', ns):
            node_name, node_atrribs, new_edges = stock_from_xml_node(child, ns)
            edges = edges + new_edges
            dag.add_node(node_name, **node_atrribs)

    for node_u, node_v in edges:
        dag.add_edge(node_u, node_v)

    return dag


def conv_xmile_aux_to_devs_atomic(xmile_data):
    """
    Convierte un aux de un model xmile en un atomico devs
    """
    data = dict()
    data['model'] = 'ConstantFunction'
    data['default_value'] = xmile_data['eqn']
    return data


def conv_xmile_flow_to_devs_atomic(xmile_data):
    """
    Convierte un flow de un model xmile en un atomico devs
    """
    data = dict()
    data['model'] = 'Function'
    data['function'] = xmile_data['eqn']
    return data


def devs_flows_adder_from_xmile_stock(xmile_node, xmile_data):
    """
    Crea un nodo Flows Adder a partir de un stock de SD en formato xmile
    """
    data = dict()
    data['model'] = 'FlowsAdder'
    data['inflows'] = xmile_data['inflows']
    data['outflows'] = xmile_data['outflows']

    return (xmile_node + ' Flows Adder', data)


def devs_integrator_from_xmile_stock(xmile_node, xmile_data):
    """
    Crea un nodo integrador QSS1 a partir de un stock DS
    """
    data = dict(xmile_data)
    data['model'] = 'QSS1'
    return (xmile_node + ' Integrator', data)


def conv_xmile_stock_to_devs_atomics(xmile_node, xmile_data):
    """
    Crea los nodos atomicos devs a partir de un stock SD
    """
    return [devs_flows_adder_from_xmile_stock(xmile_node, xmile_data),
            devs_integrator_from_xmile_stock(xmile_node, xmile_data)]


def conv_stock_edges_to_devs_edges(node, edges):
    """
    Convierte las conexiones de un stock SD
    en conecciones entre nodos de un la traduccin en DEVS
    """
    conv_edges = []
    for node_u, node_v in edges:
        if node_u == node:
            conv_edges.append((node + ' Integrator', node_v))
        elif node_v == node:
            conv_edges.append((node_u, node + ' Flows Adder'))
        else:
            conv_edges.append((node_u, node_v))

    conv_edges.append((node + ' Flows Adder', node + ' Integrator'))
    return conv_edges


def xmile_model_dag_to_devsml(xmile_dag):
    """
    Transforma un dag de un model xmile a un dag de un modelo devsml
    """
    devs_dag = nx.DiGraph()
    new_edges = xmile_dag.edges()

    for node, data in xmile_dag.nodes(data=True):
        if data['type'] == 'aux':
            new_data = conv_xmile_aux_to_devs_atomic(data)
            devs_dag.add_node(node, **new_data)
        if data['type'] == 'flow':
            new_data = conv_xmile_flow_to_devs_atomic(data)
            devs_dag.add_node(node, **new_data)
        if data['type'] == 'stock':
            devs_nodes = conv_xmile_stock_to_devs_atomics(node, data)
            new_edges = conv_stock_edges_to_devs_edges(node, new_edges)
            for node_name, node_data in devs_nodes:
                devs_dag.add_node(node_name, **node_data)

    devs_dag.add_edges_from(new_edges)

    return devs_dag


def add_components(devsml_doc, devsml_dag, ns=None):
    """
    Agrega los nodos del dag de devs a los componentes del doc devsml
    """
    components_element = devsml_doc.find('.//' +
                                         add_devml_namespace_to_tag(
                                             'components',
                                             ns),
                                         ns)
    for component_name, component_attribs in devsml_dag.nodes(data=True):
        component = ET.Element(add_devml_namespace_to_tag('atomicRef',
                                                          ns),
                               {'name': component_name,
                                'model': component_attribs['model']})
        components_element.append(component)

    return devsml_doc


def add_internal_connections(devsml_doc, devsml_dag, ns=None):
    """
    Agrega las conecciones entre puertos de los componentes del doc
    devsml a partir del dag del devs
    """
    internal_conns_element = devsml_doc.find('.//' +
                                             add_devml_namespace_to_tag(
                                                 'internal_connections',
                                                 ns),
                                             ns)
    for node_u, node_v in devsml_dag.edges:
        attribs = {'component_from': node_u,
                   'port_from': 'out',
                   'component_to': node_v,
                   'port_in': node_u}
        internal_conns_element.append(ET.Element('connection', attribs))

    return devsml_doc


def devsml_from_xmile(filename):
    """
    Crea un doc devsml a partir de un doc xmile
    """
    # TODO: Ver tema de namespaces.
    # Trae muchos problemas a la hora del generar el xml
    # xmile_ns={'xmile':'http://docs.oasis-open.org/xmile/ns/XMILE/v1.0'}
    # devsml_ns={'ns0' : 'http://tempuri.org/devs-coupled'}
    doc = read_xml(filename)
    devsml_doc = ET.fromstring(str(DEVS_ML_BASE_DOC))

    xmile_model_dag = dag_from_xmile_model(doc.find('model', None), None)
    devsml_dag = xmile_model_dag_to_devsml(xmile_model_dag)

    add_components(devsml_doc, devsml_dag, None)
    add_internal_connections(devsml_doc, devsml_dag, None)

    return devsml_doc
