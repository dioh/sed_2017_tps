'''
Funciones para convertir archivo xmile en devsml
'''

import xml.etree.ElementTree as ET

def read_xml(filename):
    '''
    Parsea el archivo xmile pasado como parametro
    '''
    return ET.parse(filename)