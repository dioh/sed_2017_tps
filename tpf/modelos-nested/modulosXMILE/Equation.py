
from py_expression_eval import Parser
import re

class Equation(object):
    def __init__(self, text, debug):
        self.text = text
        self.debug = debug
        self.variables = self.setVariables()
        self.special_functions = self.setSpecialFunctions()

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

    def setSpecialFunctions(self):
        special_functions = []
        regex_list = [
            re.compile(r"[\w]+=\d+[\.\d+]*")
        ]
        search_results = list(map(lambda x : re.search(x, regex), regex_list))
        return special_functions


    # Getters
    def getVariables(self):
        return self.variables

    # TODO : hacer parser de 'unaEquation' para detectar funciones especiales (ej.: PULSE, RAMP, STEP, DELAY, GRAPHICAL_INPUT)
    def getSpecialFunctions(self):
        return self.special_functions