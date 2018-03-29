
from modulosDEVS.DEVSPort import *
from modulosDEVS.DEVSComponent import DEVSAtomicComponent


class DEVSFtot(DEVSAtomicComponent):
    def __init__(self, xmile_stock):
        self.stock = xmile_stock
        # TODO : con o sin el 'Tot' ?
        self.name = 'Tot' + xmile_stock.getName()
        self.access = xmile_stock.getAccess()
        self.equation = xmile_stock.getEquation()
        self.input_ports = [DEVSPort('minus', self, 'in'),
                            DEVSPort('plus', self, 'in')]
        self.output_ports = [DEVSPort(self.name, self, 'out')]
        self.type = 'DEVSFtot'

    def __repr__(self):
        return str({
            'name': self.name,
            'access': self.access,
            'equation': self.equation,
            'input_ports': self.input_ports,
            'output_ports': self.output_ports
        })

    def __str__(self):
        return str({
            'name': self.name,
            'access': self.access,
            'equation': self.equation,
            'input_ports': self.input_ports,
            'output_ports': self.output_ports
        })

    def getType(self):
        return self.type

    def getName(self):
        return self.name

    def getDEVSInputPorts(self):
        return self.input_ports

    def getDEVSOutputPorts(self):
        return self.output_ports

    def getEquation(self):
        return self.equation

    def parameters(self):
        return {'equation': self.equation.getEquation()}