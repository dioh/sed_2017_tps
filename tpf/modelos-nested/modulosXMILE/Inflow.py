class Inflow(object):
    def __init__(self, inflow_element, source_xmlns, debug):
        self.inflow_element = inflow_element
        self.source_xmlns = source_xmlns
        self.name = self.setName()
        self.debug = debug
        
    def __repr__(self):
        return str({
            'name' : self.name
        })
    
    def __str__(self):
        return str({
            'name' : self.name
        })
        
    def setName(self):
        return self.inflow_element.text

    def getName(self):
        return self.name