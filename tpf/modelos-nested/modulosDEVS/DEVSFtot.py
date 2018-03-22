
from modulosDEVS.DEVSPort import *
from modulosDEVS.DEVSComponent import *

class DEVSFtot(DEVSComponent):
    def __init__(self, xmile_stock):
        self.stock = xmile_stock
        self.name = xmile_stock.getName() # TODO : ver si aca le agrego un 'Tot' al final o no
        self.access = xmile_stock.getAccess()
        self.equation = xmile_stock.getEquation()
        self.input_ports  = [DEVSPort('minus', self, 'in'), DEVSPort('plus', self, 'in')]
        self.output_ports = [DEVSPort(self.name, self, 'out')]
        self.type = 'Ftot'

    def __repr__(self):
        return str({
            'name' : self.name,
            'access' : self.access,
            'equation' : self.equation,
            'input_ports' : self.input_ports,
            'output_ports' : self.output_ports
        })
    def __str__(self):
        return str({
            'name' : self.name,
            'access' : self.access,
            'equation' : self.equation,
            'input_ports' : self.input_ports,
            'output_ports' : self.output_ports
        })

    def getType(self):
        return self.type
    def getName(self):
        return self.name