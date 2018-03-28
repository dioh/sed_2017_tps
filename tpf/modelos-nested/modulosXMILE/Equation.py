
from py_expression_eval import Parser
from modulosDEVS.DEVSAtomic.DEVSPulse import *
from modulosDEVS.DEVSAtomic.DEVSRamp import *
from modulosDEVS.DEVSAtomic.DEVSStep import *
from modulosAuxiliares.SpecialFunctionFinder import *

class Equation(object):
    def __init__(self, equation, debug=False):
        self.debug = debug
        self.equation = None
        self.variables         = []
        self.special_functions = []
        # Reseteo el equationo para que en lugar de PULSE(a,b,c) tengo PULSE_a_b_c como variable
        self.setVariablesAndequationAndFunctions(equation)

    def __repr__(self):
        return str({
            'equation' : self.equation
        })
    
    def __str__(self):
        return str({
            'equation' : self.equation
        })


    def preprocess(self, equation):
        # TODO : mejorar este chequeo
        if equation == '{Enter equation for use when not hooked up to other models}':
            return False
        return True

    # Setters
    def setVariablesAndequationAndFunctions(self, equation):
        if self.preprocess(equation):
            parser = Parser()
            finder = SpecialFunctionFinder()

            special_functions_names            = finder.getSpecialFunctionsNames()
            special_functions_with_parameters  = finder.getSpecialFunctionsWithParameters(equation)
            
            # special_functions => lista de objectos funciones que estan en la ecuacion
            special_functions = []
            for func_with_params in special_functions_with_parameters:
                # Genero el objeto correspondiente a esta funcion
                obj_func = finder.parseFunctionWithParameters(func_with_params)
                special_functions.append(obj_func)
                # Defino nombre que va a tener la variable correspondiente al output de esta funcion ; Redefino el equationo de 'equation'
                equation = equation.replace(func_with_params, obj_func.getName())
                
            # variables => lista de variables que utiliza la ecuacion
            # Nota : es importante que esto corra sobre 'equation' ya modificada
            expression = parser.parse(equation)
            variables  = expression.variables()

            # seteo variables y special_functions
            self.variables         = variables
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
    # TODO
    def getParameters(self):
        return []