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
    name= node.attrib['name']
    attrib= dict()
    attrib['eqn']= node.find('eqn')

    return name, attrib

def flow_from_xml_node(node):
    """
    Devuelve un nodo de tipo aux para el grafo
    """
    name= node.attrib['name']
    attrib= dict()
    attrib['eqn']= node.find('eqn').text
    variables= attrib['eqn'].split('"')[1::2]
    edges= []
    for variable in variables:
        edges.append((variable,name))

    return name, attrib, edges

def stock_from_xml_node(node):
    """
    Devuelve un nodo de tipo aux para el grafo
    """
    name= node.attrib['name']
    attrib= dict()
    attrib['eqn']= node.find('eqn')
    inflows= []
    outflows= []
    edges= []
    for inflow in node.findall('inflow'):
        inflow_name= inflow.text.strip('"')
        inflows.append(inflow_name)
        edges.append((inflow_name,name)) 

    for outflow in node.findall('outflow'):
        outflow_name= outflow.text.strip('"')
        outflows.append(outflow_name)
        edges.append((outflow_name,name)) 

    return name, attrib,edges

def dag_from_xmile_model(doc):
    """
    Devuelve el DAG asociado al modelo
    """

    dag= nx.DiGraph()
    edges= []
    #Procesar seccion variables 
    variables= doc.find('variables')
    for child in variables:
        if child.tag == 'aux':
            node_name, node_atrribs= aux_from_xml_node(child)
            dag.add_node(node_name,**node_atrribs)
        if child.tag == 'flow':
            node_name, node_atrribs, new_edges= flow_from_xml_node(child)
            edges= edges + new_edges
            dag.add_node(node_name, **node_atrribs)
        if child.tag == 'stock':
            node_name, node_atrribs,new_edges= stock_from_xml_node(child)
            edges= edges + new_edges
            dag.add_node(node_name, **node_atrribs)
    
    print(edges)
    for u, v in edges:
        dag.add_edge(u,v)

    return dag