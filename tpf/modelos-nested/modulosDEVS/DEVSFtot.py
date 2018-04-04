
from modulosDEVS.DEVSPort import *
from modulosDEVS.DEVSComponent import DEVSAtomicComponent


class DEVSFtot(DEVSAtomicComponent):
    def __init__(self, xmile_stock, parent_name):
        self.stock = xmile_stock
        self.parent = parent_name
        # TODO : con o sin el 'Tot' ?
        self.name = 'Tot' + xmile_stock.getName()
        self.access = xmile_stock.getAccess()
        self.equation = xmile_stock.getEquation()
        self.input_ports = []
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

    # Setters
    def addPlusPort(self, port_name):
        new_port = DEVSPort(port_name, self, 'in_plus')
        self.input_ports.append(new_port)
        return new_port

    def addMinusPort(self, port_name):
        new_port = DEVSPort(port_name, self, 'in_minus')
        self.input_ports.append(new_port)
        return new_port

    # Getters
    def getType(self):
        return self.type

    def getName(self):
        return self.name
        
    def getParentName(self):
        return self.parent

    def getDEVSInputPorts(self):
        return self.input_ports
    def getDEVSInputPortsNames(self):
        return list(map(lambda x : x.getName(), self.input_ports))

    def getDEVSOutputPorts(self):
        return self.output_ports

    def getEquation(self):
        return self.equation

    def parameters(self):
        return {'equation': self.equation.getEquation()}