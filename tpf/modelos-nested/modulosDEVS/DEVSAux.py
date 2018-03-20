
class DEVSAux(object):
    def __init__(self, xmile_aux, xmile_dependencies):
        self.xmile_aux = xmile_aux
        self.access = self.xmile_aux.getAccess()
        self.name = self.xmile_aux.getName()
        self.equation = self.xmile_aux.getEquation()
        self.parent = self.xmile_aux.getParent()
        self.inputs = xmile_dependencies
        self.type = "DEVSAux"
        
    def __repr__(self):
        return str({
            'access' : self.access,
            'name' : self.name,
            'equation' : self.equation,
            'parent' : self.parent,
            'inputs' : self.inputs,
            'type' : self.type
        })
    def __str__(self):
        return str({
            'access' : self.access,
            'name' : self.name,
            'equation' : self.equation,
            'parent' : self.parent,
            'inputs' : self.inputs,
            'type' : self.type
        })

    def getAccess(self):
        return self.access
    def getName(self):
        return self.name
    def getEquation(self):
        return self.equation
    def getParent(self):
        return self.parent
    def getInputs(self):
        return self.inputs
    def getType(self):
        return self.type