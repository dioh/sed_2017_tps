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

def dag_from_xmile_model(doc):
    """
    Devuelve el DAG asociado al modelo
    """
    return nx.DiGraph()