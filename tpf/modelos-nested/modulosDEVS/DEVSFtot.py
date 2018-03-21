
class DEVSFtot(object):
    def __init__(self, xmile_stock):
        self.stock = xmile_stock
        self.name = xmile_stock.getName() # TODO : ver si aca le agrego un 'Tot' al final o no
        self.access = xmile_stock.getAccess()
        self.equation = xmile_stock.getEquation()
        self.inputs  = ['minus', 'plus']
        self.outputs = ['out']
        self.type = 'Ftot'

    def __repr__(self):
        return str({
            'name' : self.name,
            'access' : self.access,
            'equation' : self.equation,
            'inputs' : self.inputs,
            'outputs' : self.outputs
        })
    def __str__(self):
        return str({
            'name' : self.name,
            'access' : self.access,
            'equation' : self.equation,
            'inputs' : self.inputs,
            'outputs' : self.outputs
        })

    def getType(self):
        return self.type
    def getName(self):
        return self.name