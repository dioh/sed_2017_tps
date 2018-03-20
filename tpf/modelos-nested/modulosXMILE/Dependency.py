class Dependency(object):
    def __init__(self, var_element, source_xmlns, parent, debug):
        self.parent = parent
        self.source_xmlns = source_xmlns
        self.var_element = var_element
        self.name = self.setName()
        self.inputs = self.setInputs()
        self.debug = debug
        
    def __repr__(self):
        return str({
            'parent' : self.parent,
            'name' : self.name,
            'inputs' : self.inputs
        })
    
    def __str__(self):
        return str({
            'parent' : self.parent,
            'name' : self.name,
            'inputs' : self.inputs
        })
    
    def setName(self):
        name = self.var_element.get('name')
        if name is None:
            raise Exception('Error: todas las dependencies deben tener nombre')
        return name
    def getName(self):
        return self.name

    def setInputs(self):
        inputs = self.var_element.findall(self.source_xmlns + 'in')
        inputs = list(map(lambda x : x.text, inputs))
        return inputs
    def getInputs(self):
        return self.inputs