
from modulosDEVS.DEVSAtomic.DEVSPulse import *
import re

class SpecialFunctionFinder(object):
    def __init__(self):
        self.function_names = [
            'PULSE', 'RAMP', 'STEP'
        ]
        self.regexs = {
            'PULSE' : [
                (r"PULSE\([ ]*[\w]+[ ]*\)", r"PULSE\([ ]*([\w]+)[ ]*\)"),
                (r"PULSE\([ ]*[\w]+[ ]*,[ ]*[\w]+[ ]*\)", r"PULSE\([ ]*([\w]+)[ ]*,[ ]*([\w]+)[ ]*\)"),
                (r"PULSE\([ ]*[\w]+[ ]*,[ ]*[\w]+[ ]*,[ ]*[\w]+[ ]*\)", r"PULSE\(([\w]+),([\w]+),([\w]+)\)")],
            'RAMP' : [
               (r"RAMP\([ ]*[\w]+[ ]*\)", r"RAMP\([ ]*([\w]+)[ ]*\)"),
               (r"RAMP\([ ]*[\w]+[ ]*,[ ]*[\w]+[ ]*\)", r"RAMP\([ ]*([\w]+)[ ]*,[ ]*([\w]+)[ ]*\)")],
            'STEP' : [
                (r"STEP\([ ]*[\w]+[ ]*\)", r"STEP\([ ]*([\w]+)[ ]*\)"),
                (r"STEP\([ ]*[\w]+[ ]*,[ ]*[\w]+[ ]*\)", r"STEP\([ ]*([\w]+)[ ]*,[ ]*([\w]+)[ ]*\)")]
        }
        assert(set(self.regexs.keys()) == set(self.function_names))

    def getSpecialFunctionsNames(self):
        return self.function_names

    def getSpecialFunctionsWithParameters(self, equation):
        ans = []
        for func_name in self.function_names:
            regexs_pulse = self.regexs[func_name]
            for regex in regexs_pulse:
                search_results = re.findall(re.compile(regex[0]), equation)
                ans = ans + search_results
        return ans

    def parseFunctionWithParameters(self, func_with_parameters):
        # Chequeo que la funcion este entre las que puedo parsear
        func_name = None
        ok = False
        for name in self.function_names:
            if name in func_with_parameters:
                ok = True
                func_name = name
        assert(ok)
        assert(func_name is not None)
        return self.generateFunction(func_name, func_with_parameters)
        
    # TODO : esta funcion pasarla a un 'SpecialFunctionGenerator', que puede generar DEVSPulse, DEVSRamp, etc.
    def generateFunction(self, func_name, equation):
        # PULSE(volume, [<first pulse>, <interval>])
        if func_name == 'PULSE':
            devs_pulse = None
            regexs_pulse = self.regexs['PULSE']
            for regex in regexs_pulse:
                first_pulse = 0
                interval    = 1
                equation = equation.replace(' ', '')
                search_res = re.search(regex[1], equation)
                if search_res is not None:
                    parameters = list(search_res.groups())  
                    if len(parameters) == 0:
                        raise Exception('Error : a funcion especial le faltan parametros (pulse)')
                    volume = parameters[0]
                    if len(parameters) > 1:
                        interval = parameters[1]
                    if len(parameters) > 2:
                        interval = parameters[2]
                        devs_pulse = DEVSPulse(volume, first_pulse, interval)
            assert(devs_pulse is not None)
            return devs_pulse
        else:
            raise Exception('Error : la funcion ' + func_name + ' no puede ser generada')