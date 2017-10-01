'''
Funciones para convertir archivo xmile en devsml
'''

import xml.etree.ElementTree as ET
import networkx as nx

def read_xml(filename):
    '''
    Parsea el archivo xmile pasado como parametro
    '''
    return ET.parse(filename)

def aux_from_xml_node(node):
    """
    Devuelve un nodo de tipo aux para el grafo
    """
    name = node.attrib['name']
    attrib = dict()
    attrib['type'] = 'aux'
    attrib['eqn'] = node.find('eqn').text

    return name, attrib

def flow_from_xml_node(node):
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
        edges.append((variable,name))

    return name, attrib, edges

def stock_from_xml_node(node):
    """
    Devuelve un nodo de tipo aux para el grafo
    """
    name = node.attrib['name']
    attrib = dict()
    attrib['type'] = 'stock'
    attrib['eqn'] = node.find('eqn').text
    inflows = []
    outflows = []
    edges = []
    for inflow in node.findall('inflow'):
        inflow_name = inflow.text.strip('"')
        inflows.append(inflow_name)
        edges.append((inflow_name, name)) 

    for outflow in node.findall('outflow'):
        outflow_name = outflow.text.strip('"')
        outflows.append(outflow_name)
        edges.append((outflow_name, name)) 


    return name, attrib, edges

def dag_from_xmile_model(doc):
    """
    Devuelve el DAG asociado al modelo
    """

    dag = nx.DiGraph()
    edges = []
    #Procesar seccion variables 
    variables = doc.find('variables')
    for child in variables:
        if child.tag == 'aux':
            node_name, node_atrribs = aux_from_xml_node(child)
            dag.add_node(node_name,**node_atrribs)
        if child.tag == 'flow':
            node_name, node_atrribs, new_edges = flow_from_xml_node(child)
            edges = edges + new_edges
            dag.add_node(node_name, **node_atrribs)
        if child.tag == 'stock':
            node_name, node_atrribs, new_edges = stock_from_xml_node(child)
            edges = edges + new_edges
            dag.add_node(node_name, **node_atrribs)
    
    for node_u, node_v in edges:
        dag.add_edge(node_u, node_v)

    return dag

def conv_xmile_aux_to_devs_atomic(xmile_data):
    """
    Convierte un aux de un model xmile en un atomico devs
    """
    data = dict(xmile_data)
    data['model'] = 'ConstantFunction'
    return data

def conv_xmile_flow_to_devs_atomic(xmile_data):
    """
    Convierte un flow de un model xmile en un atomico devs
    """
    data = dict(xmile_data)
    data['model'] = 'Function'
    return data

def devs_flows_adder_from_xmile_stock(xmile_node, xmile_data):
    data = dict(xmile_data)
    data['model'] = 'FlowsAdder'
    return  (xmile_node + ' Flows Adder', data)    

def devs_integrator_from_xmile_stock(xmile_node, xmile_data):
    data = dict(xmile_data)
    data['model'] = 'QSS1'
    return  (xmile_node + ' Integrator', data)    

def conv_xmile_stock_to_devs_atomics(xmile_node, xmile_data):
     return [devs_flows_adder_from_xmile_stock(xmile_node, xmile_data), devs_integrator_from_xmile_stock(xmile_node, xmile_data) ]   

def conv_stock_edges_to_devs_edges(node, edges):
    conv_edges= []
    for node_u, node_v in edges:
        if node_u == node:
            conv_edges.append((node + ' Integrator',node_v))
        elif node_v == node:
            conv_edges.append((node_u,node + ' Flows Adder'))
        else:
            conv_edges.append((node_u,node_v))
    
    conv_edges.append((node + ' Flows Adder', node + ' Integrator'))
    return conv_edges

def xmile_model_dag_to_devsml(xmile_dag):
    """
    Transforma un dag de un model xmile a un dag de un modelo devsml
    """
    devs_dag = nx.DiGraph()
    new_edges= xmile_dag.edges()

    for node, data in xmile_dag.nodes(data=True):
        if data['type'] == 'aux':
            new_data = conv_xmile_aux_to_devs_atomic(data)
            devs_dag.add_node(node, **new_data)
        if data['type'] == 'flow':
            new_data = conv_xmile_flow_to_devs_atomic(data)
            devs_dag.add_node(node, **new_data)
        if data['type'] == 'stock':
            devs_nodes = conv_xmile_stock_to_devs_atomics(node, data)
            new_edges= conv_stock_edges_to_devs_edges(node, new_edges)
            for node_name, node_data in devs_nodes:
                devs_dag.add_node(node_name, **node_data)
            

    devs_dag.add_edges_from(new_edges)

    return devs_dag


