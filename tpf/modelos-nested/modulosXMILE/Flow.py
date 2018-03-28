
from modulosXMILE.Equation import *

class Flow(object):
    def __init__(self, flow_element, source_xmlns, parent, debug):
        self.debug = debug
        self.parent = parent
        self.source_xmlns = source_xmlns
        self.flow_element = flow_element
        self.name = self.getName()
        self.equation = self.getEquation()
        self.nonNegative = self.getNonNegative()
        
    def __repr__(self):
        return str({
            'parent' : self.parent,
            'name' : self.name,
            'equation' : self.equation,
            'nonNegative' : self.nonNegative
        })
    
    def __str__(self):
        return str({
            'parent' : self.parent,
            'name' : self.name,
            'equation' : self.equation,
            'nonNegative' : self.nonNegative
        })
    
    def getName(self):
        name = self.flow_element.get('name')
        if name is None:
            raise Exception('Error: todos los flows deben tener nombre')
        return name
    
    def getEquation(self):
        equation = self.flow_element.find(self.source_xmlns + 'eqn').text
        if equation == '':
            raise Exception('Error: hay una ecuacion definida sin ningun simbolo (invalida) en ' + self.name)
        return Equation(equation, self.debug)
        
    def getNonNegative(self):
        nonNegative = self.flow_element.find('non_negative')
        if nonNegative is None:
            return False
        return True