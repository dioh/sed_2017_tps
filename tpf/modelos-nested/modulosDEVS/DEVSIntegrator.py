
from modulosDEVS.DEVSPort import *
from modulosDEVS.DEVSComponent import *

class DEVSIntegrator(DEVSAtomicComponent):
    def __init__(self, xmile_stock):
        self.stock = xmile_stock
        self.name = xmile_stock.getName()
        self.access = xmile_stock.getAccess()
        self.equation = xmile_stock.getEquation()
        self.integrator_type = 'QSS1'
        self.integrator_parameters = {
            'x0'    : self.equation, # TODO : verificar que esto sea un numero (requiere previa normalizacion)
            'dQRel' : '0.001',
            'dQMin' : '0.001'
        }
        self.type = 'DEVSIntegrator'
        self.input_ports  = [DEVSPort(self.name, self, 'in')]
        self.output_ports = [DEVSPort(self.name, self, 'out')]
        
    def __repr__(self):
        return str({
            'name' : self.name,
            'access' : self.access,
            'equation' : self.equation,
            'integrator_type' : self.integrator_type,
            'integrator_parameters' : self.integrator_parameters
        })
    def __str__(self):
        return str({
            'name' : self.name,
            'access' : self.access,
            'equation' : self.equation,
            'integrator_type' : self.integrator_type,
            'integrator_parameters' : self.integrator_parameters
        })

    def getType(self):
        return self.type
    def getName(self):
        return self.name
    def getAccess(self):
        return self.access
    def getEquation(self):
        return self.equation
    def getIntegratorType(self):
        return self.integrator_type
    def getIntegratorParameters(self):
        return self.integrator_parameters
    def getDEVSInputPorts(self):
        return self.input_ports
    def getDEVSOutputPorts(self):
        return self.output_ports
    