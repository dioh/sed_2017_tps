
from modulosDEVS.DEVSComponent import *
from modulosDEVS.DEVSPort import *

class DEVSAux(DEVSAtomicComponent):
    def __init__(self, xmile_aux, xmile_model, xmile_dependencies):
        self.xmile_model = xmile_model
        self.xmile_aux = xmile_aux
        self.access = self.xmile_aux.getAccess()
        self.name = self.xmile_aux.getName()
        self.equation = self.xmile_aux.getEquation()
        self.parent = self.xmile_aux.getParent()
        self.input_ports  = self.setInputPorts(xmile_dependencies)
        self.output_ports = self.setOutputPorts()
        self.type = "DEVSAux"
        
    def __repr__(self):
        return str({
            'access' : self.access,
            'name' : self.name,
            'equation' : self.equation,
            'parent' : self.parent,
            'input_ports' : self.input_ports,
            'type' : self.type
        })
    def __str__(self):
        return str({
            'access' : self.access,
            'name' : self.name,
            'equation' : self.equation,
            'parent' : self.parent,
            'input_ports' : self.input_ports,
            'type' : self.type
        })

    # Un aux puede recibir : Cte's / Aux's / Acoplados (Stock's)
    def setInputPorts(self, xmile_dependencies):
        # Para cada dependencia, buscar en el modelo xmile si es Cte / Aux / Stock
        input_ports = []
        variables = self.equation.getVariables()
        for var in variables:
            input_ports.append(DEVSPort(var, self, 'in'))
        # Agrego inputs correspondientes a funciones especiales
        for special_func_obj in self.equation.getSpecialFunctions():
            input_ports.append(DEVSPort(special_func_obj.getName(), self, 'in'))
        return list(set(input_ports))

    def setOutputPorts(self):
        # '*' : el output de Aux podria ir a un DEVSCoupledComponent (si va a flows en xmile) o a un DEVSAux (si va a un aux en xmile), o a ambos
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