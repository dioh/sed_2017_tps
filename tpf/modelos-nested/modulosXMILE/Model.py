
from modulosXMILE.Module import *
from modulosXMILE.Stock import *
from modulosXMILE.Flow import *
from modulosXMILE.Auxiliary import Aux
from modulosXMILE.Dependency import *


class Model(object):

    def __init__(self, model_element, debug):
        self.source_xmlns      = "{http://docs.oasis-open.org/xmile/ns/XMILE/v1.0}"
        self.source_xmlns_isee = "{http://iseesystems.com/XMILE}"
        self.debug = debug
        self.model_element = model_element
        self.name      = self.setName()
        self.variables = self.setVariables()
        self.modules   = self.setModules()
        self.auxs      = self.setAuxs()
        self.stocks    = self.setStocks()
        self.flows     = self.setFlows()
        self.dependencies = self.setDependencies()

    def __repr__(self):
        return str({
            'name' : self.name,
            'modules' : self.modules,
            'auxs' : self.auxs,
            'stocks' : self.stocks,
            'flows' : self.flows,
            'dependencies' : self.dependencies
        })
    
    def __str__(self):
        return str({
            'name' : self.name,
            'modules' : self.modules,
            'auxs' : self.auxs,
            'stocks' : self.stocks,
            'flows' : self.flows,
            'dependencies' : self.dependencies
        })

    def setName(self):
        name = self.model_element.get('name')
        if name is None:
            return 'top'
        return name

    def getName(self):
        return self.name

    def setVariables(self):
        variables = self.model_element.find(self.source_xmlns + 'variables')
        if variables is None:
            raise Exception('Error: hay un modelo que no contiene ninguna variable')
        variables_list = self.model_element.findall(self.source_xmlns + 'variables')
        if len(variables_list) > 1:
            raise Exception('Error: estamos asumiendo que solo puede haber 1 elemento de variables por modelo')
        return variables
    
    def setModules(self):
        modules = self.variables.findall(self.source_xmlns + 'module')
        return list(map(lambda x : Module(x, self.source_xmlns, self.name, self.debug), modules))

    def getModules(self):
        return self.modules

    def setAuxs(self):
        auxs = self.variables.findall(self.source_xmlns + 'aux')
        return list(map(lambda x : Aux(x, self.source_xmlns, self.name, self.debug), auxs))

    def getAuxs(self):
        return self.auxs

    def setStocks(self):
        stocks = self.variables.findall(self.source_xmlns + 'stock')
        return list(map(lambda x : Stock(x, self.source_xmlns, self.name, self.debug), stocks))

    def getStocks(self):
        return self.stocks

    def setFlows(self):
        flows = self.variables.findall(self.source_xmlns + 'flow')
        return list(map(lambda x : Flow(x, self.source_xmlns, self.name, self.debug), flows))
    
    def getFlows(self):
        return self.flows

    def setDependencies(self):
        dependencies    = self.variables.find(self.source_xmlns_isee + 'dependencies')
        if dependencies is None:
            return []
        return list(map(lambda x : Dependency(x, self.source_xmlns, self.name, self.debug), 
                        dependencies.findall(self.source_xmlns + 'var')))
    
    def getDependencies(self):
        return self.dependencies
