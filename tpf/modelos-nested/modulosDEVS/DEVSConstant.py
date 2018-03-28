
from modulosDEVS.DEVSComponent import *
from modulosDEVS.DEVSPort import *

class DEVSConstant(DEVSAtomicComponent):
    def __init__(self, xmile_aux, xmile_model):
        self.xmile_model = xmile_model
        self.xmile_constant = xmile_aux
        self.access = self.xmile_constant.getAccess()
        self.name = self.xmile_constant.getName()
        self.equation = self.xmile_constant.getEquation()
        self.parent = self.xmile_constant.getParent()
        self.input_ports  = self.setInputPorts()
        self.output_ports = [DEVSPort(self.getName(), self, 'out')]
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

    # Setters
    def setInputPorts(self):
        input_ports = [DEVSPort(self.name, self, 'in')]
        variables = self.equation.getVariables()
        for var in variables:
            input_ports.append(DEVSPort(var, self, 'in'))
        # Agrego inputs correspondientes a funciones especiales
        for special_func_obj in self.equation.getSpecialFunctions():
            input_ports.append(DEVSPort(special_func_obj.getName(), self, 'in'))
        return list(set(input_ports))

    # Getters
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