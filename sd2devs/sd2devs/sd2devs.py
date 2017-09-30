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
    attrib['eqn']= node.find('eqn')

    return name, attrib

def stock_from_xml_node(node):
    """
    Devuelve un nodo de tipo aux para el grafo
    """
    name= node.attrib['name']
    attrib= dict()
    attrib['eqn']= node.find('eqn')

    return name, attrib

def dag_from_xmile_model(doc):
    """
    Devuelve el DAG asociado al modelo
    """

    dag= nx.DiGraph()
    #Procesar seccion variables 
    variables= doc.find('variables')
    for child in variables:
        if child.tag == 'aux':
            node_name, node_atrribs= aux_from_xml_node(child)
            dag.add_node(node_name,**node_atrribs)
        if child.tag == 'flow':
            node_name, node_atrribs= flow_from_xml_node(child)
            dag.add_node(node_name,**node_atrribs)
        if child.tag == 'stock':
            node_name, node_atrribs= stock_from_xml_node(child)
            dag.add_node(node_name,**node_atrribs)
    
    return dag