
from modulosDEVS.DEVSComponent import *
from modulosDEVS.DEVSConstant import *
from modulosDEVS.DEVSAux import *
from modulosDEVS.DEVSConnection import *
from modulosDEVS.DEVSFpm import DEVSFpm
from modulosDEVS.DEVSFtot import *
from modulosDEVS.DEVSIntegrator import *
from modulosDEVS.DEVSPort import *
from modulosDEVS.DEVSBasicCoupledComponent import *

class DEVSCoupledComponent(DEVSComponent):
    ################################################################################
    def __init__(self, xmile_model, root_models, name=None,
                 atomic_components=None, coupled_components=None, 
                 external_input_connections=None, external_output_connections=None, 
                 internal_connections=None,
                 input_ports=None, output_ports=None):
        self.xmile_model = xmile_model
        self.root_models = root_models
        self.type = 'DEVSCoupledComponent'
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
        # Input Ports
        if input_ports is not None:
            self.input_ports  = input_ports
        else:
            self.input_ports = self.setInputPorts()
        # Output Ports
        if output_ports is not None:
            self.output_ports = output_ports
        else :
            self.output_ports = self.setOutputPorts()
    ################################################################################
    # Representation functions
    def __repr__(self):
        return str({
            'name' : self.name,
            'type' : self.type,
            'atomic_components' : self.atomic_components,
            'coupled_components' : self.coupled_components,
            'external_input_connections' : self.external_input_connections,
            'external_output_connections' : self.external_output_connections,
            'internal_connections' : self.internal_connections,
            'input_ports' : self.input_ports,
            'output_ports' : self.output_ports
        })
    def __str__(self):
        return str({
            'name' : self.name,
            'type' : self.type,
            'atomic_components' : self.atomic_components,
            'coupled_components' : self.coupled_components,
            'external_input_connections' : self.external_input_connections,
            'external_output_connections' : self.external_output_connections,
            'internal_connections' : self.internal_connections,
            'input_ports' : self.input_ports,
            'output_ports' : self.output_ports
        })
    ################################################################################ 
    # Getters
    def getName(self):
        return self.name
    def getType(self):
        return self.type
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
    def getDEVSInputPorts(self):
        return self.input_ports
    def getDEVSOutputPorts(self):
        return self.output_ports
    ################################################################################
    # Setters    
    def setDEVSAtomicComponents(self):
        xmile_model = self.xmile_model

        # 1 atomico por cada Cte
        # 1 atomico por cada Aux
        # Eventualmente, 1 atomico por cada funcion rara (PULSE, etc.)
        atomic_components = []

        # Ctes
        xmile_ctes, xmile_auxs = self.setXMILEConstantsAndAuxiliaryComponents()
        devs_ctes = list(map(lambda x : DEVSConstant(x, xmile_model), xmile_ctes))
        atomic_components = atomic_components + devs_ctes

        # Auxs
        devs_auxs = []
        deps = xmile_model.getDependencies()
        for xmile_aux in xmile_auxs:
            aux_dependencies = []
            for dep in deps:
                if xmile_aux.getName() == dep.getName():
                    aux_dependencies = aux_dependencies + dep.getInputs()
            devs_auxs.append(DEVSAux(xmile_aux, xmile_model, aux_dependencies))
        atomic_components = atomic_components + devs_auxs
        return atomic_components
    
    def setDEVSCoupledComponents(self):
        # 1 acoplado por cada modulo
        xmile_modules = self.xmile_model.getModules()
        xmile_modules_models = []
        for model in self.root_models:
            for module in xmile_modules:
                if model.getName() == module.getName():
                    xmile_modules_models.append(model)
        devs_modules  = list(map(lambda x : DEVSCoupledComponent(x, self.root_models), xmile_modules_models))
        
        # 1 acoplado por cada Stock (+ Flows asociados)
        devs_generics = self.setBasicStockFlowCoupleds(self.root_models)
        return devs_modules + devs_generics
    
    # TODO : CUANDO ES EL TOP MODEL, NO QUIERO COMO INPUT LOS OUTPUT DE LOS ACOPLADOS INTERNOS NI DE LOS AUX / CONST !!!!!!!!!!!!!!!!!!!!!!!!!!!! ACA !!!!!!
    def setInputPorts(self):
        input_ports = []

        # { La union de los inputs de los Const's que tengo adentro }
        for atomic_component in self.getDEVSAtomicComponents():
            # no sabemos si el input de estos atomicos va a venir de afuera o de algun otra acoplado interno
            if atomic_component.getType() == 'DEVSConstant':
                for input_port in atomic_component.getDEVSInputPorts():
                    input_ports.append(DEVSPort(input_port.getName(), self, 'in'))

        # { La union de los inputs provenientes de CoupledModels de los chabones adentro mio que no se corresponden a output's Stocks / Const / Auxs de este DCM }
        my_internal_output_names = []
        for atomic_component in self.getDEVSAtomicComponents():
            atomic_outputs = atomic_component.getDEVSOutputPorts()
            my_internal_output_names = my_internal_output_names + list(map(lambda x : x.getName(), atomic_outputs))
        for basic_coupled in filter(lambda x : x.getType() == 'DEVSBasicCoupledComponent', self.getDEVSCoupledComponents()):
            basic_coupled_outputs = basic_coupled.getDEVSOutputPorts()
            for output_port in basic_coupled_outputs:
                my_internal_output_names.append(output_port.getName())

        for coupled_component in self.getDEVSCoupledComponents():
            for input_port in coupled_component.getDEVSInputPorts():
                if input_port.getName() not in my_internal_output_names:
                    input_ports.append(DEVSPort(input_port.getName(), self, 'in'))
        input_ports = list(set(input_ports))
        return input_ports
    
    def setOutputPorts(self):
        output_ports = []
 
        # 1 output por cada Aux
        for atomic_component in self.getDEVSAtomicComponents():
            if atomic_component.getType() == 'DEVSAux':
                for output_port in atomic_component.getDEVSOutputPorts():
                    output_ports.append(DEVSPort(output_port.getName(), self, 'out'))

        #  1 output por cada output de cada acoplado
        for coupled_component in self.getDEVSCoupledComponents():
            for output_port in coupled_component.getDEVSOutputPorts():
                output_ports.append(DEVSPort(output_port.getName(), self, 'out'))

        return list(set(output_ports))
    
    def setInputsToAtomicConnections(self):
        return []
    
    def setInputsToCoupledConnections(self):
        return []
    
    def setAtomicToOutputConnections(self):
        return []
    
    def setCoupledToOutputConnections(self):
        return []
    
    def setAtomicToAtomicConnections(self):
        return []
    
    def setCoupledToCoupledConnections(self):
        return []
    
    def setCoupledToAtomicConnections(self):
        return []
    
    def setAtomicToCoupledConnections(self):
        return []
    
    def setExternalInputConnections(self):
        return []
    
    def setExternalOutputConnections(self):
        return []
    
    def setInternalConnections(self):
        return []

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
    
    # TODO : generar un acoplado por cada Stock! Y cada uno va a tener el nombre del stock
    # Por ahora, que ande asi con los Puertos de Input y Output y despues de eso mejorar esta parte
    def setBasicStockFlowCoupleds(self, root_models):
        xmile_generic_model = self.xmile_model

        # TODO : que esto lo haga un helper
        xmile_stocks = xmile_generic_model.getStocks()
        xmile_flows  = xmile_generic_model.getFlows()
        coupleds = []

        for stock in xmile_stocks:
            # Los stocks que no entran en el if, obtengo/entrego su valor mediante los puertos de input/output
            if stock.getAccess() is None or stock.getAccess() != 'input':
                name = "DEVS_BASIC_COUPLED_" + stock.getName()

                ###########
                # Acoplados : ninguno
                coupled_components = []
                
                ###########
                # Atomicos : Ftot + Integrador + Fpm's (recordar que los Cte's y Aux's los sacamos afuera)
                # (Ftot + Integrador)
                atomic_components = [DEVSIntegrator(stock), DEVSFtot(stock)]
                
                #  (Fpm's)
                devs_fpms = list(map(lambda x : DEVSFpm(x, [stock]), xmile_flows))
                devs_fps  = filter(lambda x : x is not None, list(map(lambda x : x.getFPlus(), devs_fpms)))
                devs_fms  = filter(lambda x : x is not None, list(map(lambda x : x.getFMinus(), devs_fpms)))
                atomic_components = atomic_components + devs_fps + devs_fms
                
                ###########
                # Inputs : necesito 1 input para cada variable que usan los flows
                # Nota : es necesario quitar de esta lista a lo que corresponden a 'stock'
                input_ports = []
                for devs_fp in devs_fps:
                    input_ports_fp = devs_fp.getDEVSInputPorts()
                    for input_port_fp in input_ports_fp:
                        if input_port_fp.getName() != stock.getName():
                            input_ports.append(DEVSPort(input_port_fp.getName(), self, 'in'))
                for devs_fm in devs_fms:
                    input_ports_fm = devs_fm.getDEVSInputPorts()
                    for input_port_fm in input_ports_fm:
                        if input_port_fm.getName() != stock.getName():
                            input_ports.append(DEVSPort(input_port_fm.getName(), self, 'in'))
                # Si un fp y fm reciben el mismo input, solo voy a querer que llegue por un unico puerto
                input_ports = list(set(input_ports))

                ###########
                # Outputs : 1 output por el stock ; nada mas ;
                output_ports = [DEVSPort(stock.getName(), self, 'out')]

                ###########
                # External input connections : conexiones que vienen de 'input_ports', y llegan a algun componente (Fp's y Fm's)
                external_input_connections = []

                ###########
                # External output connections : conexiones que salen de algun componente hacia algun puerto de 'output_ports' (Integradores)
                external_output_connections = []
                
                ###########
                # Internal connections
                internal_connections = []

                coupleds.append(
                    DEVSBasicCoupledComponent(None, root_models, name,
                        atomic_components, coupled_components, 
                        external_input_connections, external_output_connections, 
                        internal_connections,
                        input_ports, output_ports
                    )
                )

        return coupleds