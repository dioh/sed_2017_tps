
from modulosXMILE.Equation import *

class Aux(object):
    def __init__(self, aux_element, source_xmlns, parent, debug):
        self.debug = debug
        self.parent = parent
        self.source_xmlns = source_xmlns
        self.aux_element = aux_element
        self.name = self.setName()
        self.equation = self.setEquation()
        self.access = self.setAccess()
    
    def __repr__(self):
        return str({
            'parent' : self.parent,
            'name' : self.name,
            'equation' : self.equation,
            'access' : self.access
        })
    
    def __str__(self):
        return str({
            'parent' : self.parent,
            'name' : self.name,
            'equation' : self.equation,
            'access' : self.access
        })

    def getParent(self):
        return self.parent
    
    def setName(self):
        name = self.aux_element.get('name')
        if name is None:
            raise Exception('Error: todos los auxs deben tener nombre')
        return name
    def getName(self):
        return self.name

    def setAccess(self):
        access = self.aux_element.get('access')
        if access is None:
            return None
        if self.debug:
            print 'El aux ' + self.parent + '.' + self.name + ' es de acceso tipo ' + access
        return access
    def getAccess(self):
        return self.access

    def setEquation(self):
        equation = self.aux_element.find(self.source_xmlns + 'eqn').text
        if equation == '':
            raise Exception('Error: hay una ecuacion definida sin ningun simbolo (invalida) en ' + self.name)
        return Equation(equation, self.debug)
    def getEquation(self):
        return self.equation

    def getEquationVariables(self):
        return self.equation.getVariables()