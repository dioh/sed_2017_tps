
from py_expression_eval import Parser

class Equation(object):
    def __init__(self, text, debug):
        self.text = text
        self.debug = debug
        self.variables = self.setVariables()
        
    def __repr__(self):
        return str({
            'text' : self.text
        })
    
    def __str__(self):
        return str({
            'text' : self.text
        })
    
    def getText(self):
        return self.text

    def setVariables(self):
        parser = Parser()
        expression = parser.parse(self.text)
        return expression.variables()

    def getVariables(self):
        return self.variables