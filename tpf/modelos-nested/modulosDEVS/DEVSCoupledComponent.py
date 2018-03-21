
from modulosDEVS.DEVSConstant import *
from modulosDEVS.DEVSAux import *
from modulosDEVS.DEVSConnection import *
from modulosDEVS.DEVSFpm import DEVSFpm
from modulosDEVS.DEVSFtot import *
from modulosDEVS.DEVSIntegrator import *

class DEVSCoupledComponent(object):
    ################################################################################
    def __init__(self, xmile_model, root_models, name=None,
                 atomic_components=None, coupled_components=None, 
                 external_input_connections=None, external_output_connections=None, 
                 internal_connections=None,
                 inputs=None, outputs=None):
        self.xmile_model = xmile_model
        self.root_models = root_models
        if name is not None:
            self.name = name
        else:
            self.name = 'DEVS_COUPLED_' + self.xmile_model.getName()
        # Atomic components
        if atomic_components is not None:
            self.atomic_components = atomic_components
        else:
            self.atomic_components = self.setDEVSAtomicComponents()
        # Coupled components
        if coupled_components is not None:
            self.coupled_components = coupled_components
        else:
            self.coupled_components = self.setDEVSCoupledComponents()
        # External input connections
        if external_input_connections is not None:
            self.external_input_connections = external_input_connections
        else:
            self.external_input_connections = self.setExternalInputConnections()
        # External output connections
        if external_output_connections is not None:
            self.external_output_connections = external_output_connections
        else:
            self.external_output_connections = self.setExternalOutputConnections()
        # Internal connections
        if internal_connections is not None:
            self.internal_connections = internal_connections
        else:
            self.internal_connections = self.setInternalConnections()
        # Inputs
        if inputs is not None:
            self.inputs  = inputs
        else:
            self.inputs = self.setInputs()
        # Outputs
        if outputs is not None:
            self.outputs = outputs
        else :
            self.outputs = self.setOutputs()
    ################################################################################
    # Representation functions
    def __repr__(self):
        return str({
            'name' : self.name,
            'atomic_components' : self.atomic_components,
            'coupled_components' : self.coupled_components,
            'external_input_connections' : self.external_input_connections,
            'external_output_connections' : self.external_output_connections,
            'internal_connections' : self.internal_connections,
            'inputs' : self.inputs,
            'outputs' : self.outputs
        })
    def __str__(self):
        return str({
            'name' : self.name,
            'atomic_components' : self.atomic_components,
            'coupled_components' : self.coupled_components,
            'external_input_connections' : self.external_input_connections,
            'external_output_connections' : self.external_output_connections,
            'internal_connections' : self.internal_connections,
            'inputs' : self.inputs,
            'outputs' : self.outputs
        })
    ################################################################################ 
    # Getters
    def getName(self):
        return self.name
    def getDEVSAtomicComponents(self):
        return self.atomic_components
    def getDEVSCoupledComponents(self):
        return self.coupled_components
    def getDEVSExternalInputConnections(self):
        return self.external_input_connections
    def getDEVSExternalOutputConnections(self):
        return self.external_output_connections
    def getDEVSInternalConnections(self):
        return self.internal_connections
    def getDEVSInputs(self):
        return self.inputs
    def getDEVSOutputs(self):
        return self.outputs
    ################################################################################
    # Setters    
    def setDEVSAtomicComponents(self):
        # 1 atomico por cada Cte
        # 1 atomico por cada Aux
        # Eventualmente, 1 atomico por cada funcion rara (PULSE, etc.)
        atomic_components = []

        # Ctes
        xmile_ctes, xmile_auxs = self.setXMILEConstantsAndAuxiliaryComponents()
        devs_ctes = list(map(lambda x : DEVSConstant(x), xmile_ctes))
        atomic_components = atomic_components + devs_ctes

        # Auxs
        devs_auxs = []
        deps = self.xmile_model.getDependencies()
        for xmile_aux in xmile_auxs:
            aux_dependencies = []
            for dep in deps:
                if xmile_aux.getName() == dep.getName():
                    aux_dependencies = aux_dependencies + dep.getInputs()
            devs_auxs.append(DEVSAux(xmile_aux, aux_dependencies))
        atomic_components = atomic_components + devs_auxs
        return atomic_components
    
    def setDEVSCoupledComponents(self):
        # 1 acoplado por cada modulo
        # 1 acoplado por cada Stock (+ Flows asociados)
        # el acoplado va a tener como inputs todos los stocks / auxs / ctes necesarios por los flows / auxs
        # y va a tener como outflows a todos los stocks y auxs
        xmile_modules = self.xmile_model.getModules()
        xmile_modules_models = []
        for model in self.root_models:
            for module in xmile_modules:
                if model.getName() == module.getName():
                    xmile_modules_models.append(model)
        
        xmile_stocks  = self.xmile_model.getStocks()
        devs_modules = list(map(lambda x : DEVSCoupledComponent(x, self.root_models), xmile_modules_models))
        devs_generic = [self.setBasicStockFlowCoupled()]
        return devs_modules + devs_generic
    
    def setInputs(self):
        # 1 input por cada Cte (los Aux que no estan entre las dependencias del modelo)
        # Va a haber 1 conexion entre un input del acoplado y 1 componente del acoplado (corresp al = nombre)
        return 1
    
    def setOutputs(self):
        # 1 output por cada Stock (va a salir de un acoplado que se corresponda al comportamiento del Stock)
        # 1 output por cada Aux
        # Va a haber 1 conexion entre 1 output del acoplado y 1 componente del acoplado (corresp al Stock/Aux)
        return 1
    
    def setInputsToAtomicConnections(self):
        return 1
    
    def setInputsToCoupledConnections(self):
        return 1
    
    def setAtomicToOutputConnections(self):
        return 1
    
    def setCoupledToOutputConnections(self):
        return 1
    
    def setAtomicToAtomicConnections(self):
        return 1
    
    def setCoupledToCoupledConnections(self):
        return 1
    
    def setCoupledToAtomicConnections(self):
        return 1
    
    def setAtomicToCoupledConnections(self):
        return 1
    
    def setExternalInputConnections(self):
        return 1
    
    def setExternalOutputConnections(self):
        return 1
    
    def setInternalConnections(self):
        return 1
    ################################################################################
    # Funciones auxiliares
    def setXMILEConstantsAndAuxiliaryComponents(self):
        constants, auxiliaries = [], []
        auxs = self.xmile_model.getAuxs()
        dependencies = self.xmile_model.getDependencies()
        for aux in auxs:
            is_dependent = False
            for dep in dependencies:
                if aux.getName() == dep.getName() and len(dep.getInputs()) > 0:
                    is_dependent = True
            if is_dependent is False:
                constants.append(aux)
            else:
                auxiliaries.append(aux)
        return constants, auxiliaries
    
    def setBasicStockFlowCoupled(self):
        # TODO : que esto lo haga un helper
        xmile_stocks = self.xmile_model.getStocks()
        xmile_flows  = self.xmile_model.getFlows()
        
        name = "DEVS_BASIC_COUPLED_" + "_".join(list(map(lambda x : x.getName(), xmile_stocks)))
        ###########
        # Acoplados : ninguno
        coupled_components = []
        
        ###########
        # Atomicos : Ctes + Auxs + Ftot + Integrador + Fpm's
        atomic_components = []
        
        # (Ftot + Integrador)
        devs_int = list(map(lambda x : DEVSIntegrator(x), xmile_stocks))
        devs_ftot = list(map(lambda x : DEVSFtot(x), xmile_stocks))
        atomic_components = atomic_components + devs_int + devs_ftot
        
        #  (Fpm's)
        devs_fpms = list(map(lambda x : DEVSFpm(x, xmile_stocks), xmile_flows))
        devs_fps  = filter(lambda x : x is not None, list(map(lambda x : x.getFPlus(), devs_fpms)))
        devs_fms  = filter(lambda x : x is not None, list(map(lambda x : x.getFMinus(), devs_fpms)))
        atomic_components = atomic_components + devs_fps + devs_fms
        
        ###########
        # External input connections
        external_input_connections = []
        
        ###########
        # External output connections
        external_output_connections = []
        
        ###########
        # Internal connections
        internal_connections = []
        
        ###########
        # Inputs
        inputs = []
        
        ###########
        # Outputs
        outputs = []
        
        return DEVSCoupledComponent(self.xmile_model, self.root_models, name,
                 atomic_components, coupled_components, 
                 external_input_connections, external_output_connections, 
                 internal_connections,
                 inputs, outputs)