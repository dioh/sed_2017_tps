
from modulosDEVS.DEVSComponent import *
from modulosDEVS.DEVSPort import *

class DEVSConstant(DEVSComponent):
    def __init__(self, xmile_aux, xmile_model):
        self.xmile_model = xmile_model
        self.xmile_constant = xmile_aux
        self.access = self.xmile_constant.getAccess()
        self.name = self.xmile_constant.getName()
        self.equation = self.xmile_constant.getEquation()
        self.parent = self.xmile_constant.getParent()
        self.input_ports  = [DEVSPort(self.name, self, 'in')]
        self.output_ports = self.setOutputPorts()
        self.type = 'DEVSConstant'
    
    def __repr__(self):
        return str({
            'access' : self.access,
            'name' : self.name,
            'equation' : self.equation,
            'parent' : self.parent,
            'type' : self.type
        })
    def __str__(self):
        return str({
            'access' : self.access,
            'name' : self.name,
            'equation' : self.equation,
            'parent' : self.parent,
            'type' : self.type
        })

    def setOutputPorts(self):
        # TODO 
        # '*' : el output de Cte podria ir a un DEVSCoupledComponent (si va a flows en xmile) o a un DEVSAux (si va a un aux en xmile), o a ambos
        return [DEVSPort(self.getName(), self, 'out')]

    def getAccess(self):
        return self.access
    def getName(self):
        return self.name
    def getEquation(self):
        return self.equation
    def getParent(self):
        return self.parent
    def getDEVSInputPorts(self):
        return self.input_ports
    def getDEVSOutputPorts(self):
        return self.output_ports
    def getType(self):
        return self.type