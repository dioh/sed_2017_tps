
from modulosXMILE.Equation import *
from modulosXMILE.Outflow import *
from modulosXMILE.Inflow import *


class Stock(object):
    def __init__(self, stock_element, source_xmlns, parent, debug):
        self.debug = debug
        self.parent = parent
        self.source_xmlns = source_xmlns
        self.stock_element = stock_element
        self.name = self.getName()
        self.access = self.getAccess()
        self.equation = self.getEquation()
        self.outflows = self.getOutflows()
        self.inflows = self.getInflows()
        self.nonNegative = self.getNonNegative()
        
    def __repr__(self):
        return str({
            'parent' : self.parent,
            'name' : self.name,
            'access' : self.access,
            'equation' : self.equation,
            'outflows' : self.outflows,
            'inflows' : self.inflows,
            'nonNegative' : self.nonNegative
        })
    
    def __str__(self):
        return str({
            'parent' : self.parent,
            'name' : self.name,
            'access' : self.access,
            'equation' : self.equation,
            'outflows' : self.outflows,
            'inflows' : self.inflows,
            'nonNegative' : self.nonNegative
        })
        
    def getName(self):
        name = self.stock_element.get('name')
        if name is None:
            raise Exception('Error: todos los stocks deben tener nombre')
        return name
    
    def getAccess(self):
        access = self.stock_element.get('access')
        if access is None:
            return None
        if self.debug:
            print('El stock ' + self.parent + '.' + self.name + ' es de acceso tipo ' + access)
        return access
    
    def getEquation(self):
        equation = self.stock_element.find(self.source_xmlns + 'eqn').text
        if equation == '':
            raise Exception('Error: hay una ecuacion definida sin ningun simbolo (invalida) en' + self.name)
        return Equation(equation, self.debug)
    
    def getOutflows(self):
        outflows = self.stock_element.findall(self.source_xmlns + 'outflow')
        return list(map(lambda x : Outflow(x, self.source_xmlns, self.debug), outflows))
    
    def getInflows(self):
        inflows = self.stock_element.findall(self.source_xmlns + 'inflow')
        return list(map(lambda x : Inflow(x, self.source_xmlns, self.debug), inflows))
    
    def getNonNegative(self):
        nonNegative = self.stock_element.find('non_negative')
        if nonNegative is None:
            return False
        return True

    def getEquationVariables(self):
        return self.equation.getVariables()