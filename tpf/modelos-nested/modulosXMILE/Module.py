
from modulosXMILE.ModuleConnection import *

class Module(object):
    def __init__(self, module_element, source_xmlns, parent, debug):
        self.debug = debug
        self.parent = parent
        self.source_xmlns = source_xmlns
        self.module_element = module_element
        self.name = self.getName()
        self.connections = self.getConnections()
        
    def __repr__(self):
        return str({
            'parent' : self.parent,
            'name' : self.name,
            'connections' : self.connections
        })
    
    def __repr__(self):
        return str({
            'parent' : self.parent,
            'name' : self.name,
            'connections' : self.connections
        })
        
    def getName(self):
        name = self.module_element.get('name')
        if name is None:
            raise Exception('Error: los modulos deben tener nombre')
        return name
    
    def getConnections(self):
        connections = self.module_element.findall(self.source_xmlns + 'connect')
        if len(connections) == 0:
            if self.debug:
                print 'Alerta: el modelo ' + self.name + ' no tiene niguna conexion'
        return list(map(lambda x : ModuleConnection(x, self.source_xmlns, self.debug), connections))