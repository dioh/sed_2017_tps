
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
            'x0': self.equation,  # TODO : verificar que esto sea un numero (requiere previa normalizacion)
            'dQRel': '0.001',
            'dQMin': '0.001'
        }
        self.type = 'DEVSIntegrator'
        self.input_ports  = self.setInputPorts()
        self.output_ports = [DEVSPort(self.name, self, 'out')]

    def __repr__(self):
        return str({
            'name': self.name,
            'access': self.access,
            'equation': self.equation,
            'integrator_type': self.integrator_type,
            'integrator_parameters': self.integrator_parameters
        })

    def __str__(self):
        return str({
            'name': self.name,
            'access': self.access,
            'equation': self.equation,
            'integrator_type': self.integrator_type,
            'integrator_parameters': self.integrator_parameters
        })

    # Setters
    def setInputPorts(self):
        # Nota : appendeo 'Tot' como sufijo
        input_ports = [DEVSPort('Tot' + self.name, self, 'in')]
        # TODO : hacer uso de estos puertos (que se consideren los inputs provenientes de special functions tambien en 'Stocks')
        variables = self.equation.getVariables()
        for var in variables:
            input_ports.append(DEVSPort(var, self, 'in'))
        # Agrego inputs correspondientes a funciones especiales
        for special_func_obj in self.equation.getSpecialFunctions():
            input_ports.append(DEVSPort(special_func_obj.getName(), self, 'in'))
        return list(set(input_ports))

    # Getters
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
