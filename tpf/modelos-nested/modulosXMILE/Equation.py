
from py_expression_eval import Parser
from modulosDEVS.DEVSAtomic.DEVSPulse import *
from modulosDEVS.DEVSAtomic.DEVSRamp import *
from modulosDEVS.DEVSAtomic.DEVSStep import *
from modulosAuxiliares.SpecialFunctionFinder import *


class Equation(object):
    def __init__(self, equation, debug):
        self.debug = debug
        self.equation = None
        self.variables = []
        self.special_functions = []
        # Reseteo el equationo para que en lugar de PULSE(a,b,c) 
        # tengo PULSE_a_b_c como variable
        self.setVariablesAndequationAndFunctions(equation)

    def __repr__(self):
        return str({
            'equation': self.equation
        })
    
    def __str__(self):
        return str({
            'equation': self.equation
        })

    # Setters
    def setVariablesAndequationAndFunctions(self, equation):
        parser = Parser()
        finder = SpecialFunctionFinder()

        special_functions_names = finder.getSpecialFunctionsNames()
        special_functions_with_parameters = finder.getSpecialFunctionsWithParameters(equation)
        expression = parser.parse(equation)
        variables_parser = expression.variables()

        # variables => lista de variables que utiliza la ecuacion
        variables = []
        for var_parser in variables_parser:
            if var_parser in special_functions_names:
                variables.append(var_parser)
        
        # special_functions => lista de objectos funciones 
        # que estan en la ecuacion
        special_functions = []
        for func_with_params in special_functions_with_parameters:
            # Genero el objeto correspondiente a esta funcion
            obj_func = finder.parseFunctionWithParameters(func_with_params)
            special_functions.append(obj_func)
            # Defino nombre que va a tener la variable correspondiente 
            # al output de esta funcion ; Redefino el equationo de 'equation'
            equation = equation.replace(func_with_params, obj_func.getName())

        # seteo variables y special_functions
        self.variables = variables
        self.special_functions = special_functions
        self.equation = equation
        return 

    # Getters
    def getEquation(self):
        return self.equation

    def getVariables(self):
        return self.variables
    
    def getSpecialFunctions(self):
        return self.special_functions