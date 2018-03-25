
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
        # Output Ports
        if output_ports is not None:
            self.output_ports = output_ports
        else :
            self.output_ports = self.setOutputPorts()
        # Input Ports
        if input_ports is not None:
            self.input_ports  = input_ports
        else:
            self.input_ports = self.setInputPorts()
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

        ############## !!!!!!!! ACA !!!!!!!!! ############
        # TODO : agregar los atomicos correspondientes a funciones especiales (ie.: PULSE, RAMP, etc.)
        #        hay que mirar el atributo 'equation' de los Cte's y Aux's
        #        * despues tambien hay que agregar las 'internal connections' correspondientes
        #        * si la funcion toma como input otras variables del modelo, tambien habria que setear EXTERNAL_{INPUT/OUTPUT}_CONNECTIONS
        ##################################################

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

    def setInputPorts(self):
        input_ports = []

        # La union de los inputs de los Const's que tengo adentro
        for atomic_component in self.getDEVSAtomicComponents():
            # no sabemos si el input de estos atomicos va a venir de afuera o de algun otra acoplado interno
            if atomic_component.getType() == 'DEVSConstant':
                for input_port in atomic_component.getDEVSInputPorts():
                    input_ports.append(DEVSPort(input_port.getName(), self, 'in', True))

        # La union de los inputs de los coupled models adentro mio, que son especificamente para Cte's
        for coupled_component in self.getDEVSCoupledComponents():
            for input_port in coupled_component.getDEVSInputPorts():
                if input_port.get_is_for_constant():
                    input_ports.append(DEVSPort(input_port.getName(), self, 'in'))

        # La union de los inputs provenientes de CoupledModels de los chabones adentro mio que no se corresponden a output's Stocks / Auxs de este DCM
        if self.getName() != 'DEVS_COUPLED_top':
            my_internal_output_names = []
            for atomic_component in self.getDEVSAtomicComponents():
                if atomic_component.getType() == 'DEVSAux':
                    atomic_outputs = atomic_component.getDEVSOutputPorts()
                    my_internal_output_names = my_internal_output_names + list(map(lambda x : x.getName(), atomic_outputs))
            
            for basic_coupled in self.getDEVSCoupledComponents():
                basic_coupled_outputs = basic_coupled.getDEVSOutputPorts()
                for output_port in basic_coupled_outputs:
                    my_internal_output_names.append(output_port.getName())

            for coupled_component in self.getDEVSCoupledComponents():
                for input_port in coupled_component.getDEVSInputPorts():
                    if input_port.getName() not in my_internal_output_names:
                        input_ports.append(DEVSPort(input_port.getName(), self, 'in'))
        
        input_ports = list(set(input_ports))
        return input_ports
    
    # External input connections
    def setExternalInputConnections(self):
        return self.setExternalInputToAtomicConnections() + self.setExternalInputToCoupledConnections()

    def setExternalInputToAtomicConnections(self):
        inputs_atomic_connections = []
        input_ports = self.getDEVSInputPorts();
        for input_port in input_ports:
            port_from = input_port
            for atomic_component in self.getDEVSAtomicComponents():
                # si el atomico tiene el puerto de input para esto...
                for atomic_input_port in atomic_component.getDEVSInputPorts():
                    if atomic_input_port.getName() == input_port.getName():
                        port_to      = atomic_input_port
                        component_to = atomic_component 
                        inputs_atomic_connections.append(
                            DEVSExternalInputConnection(port_from, port_to, component_to)
                        )
        return inputs_atomic_connections

    def setExternalInputToCoupledConnections(self):
        input_coupled_connections = []

        cte_aux_names = list(map(lambda x : x.getName(), self.getDEVSAtomicComponents()))
        # TODO : filtrar las conexiones que van a puertos correspondientes a Cte's / Aux's internas mias
        input_ports = self.getDEVSInputPorts()
        for input_port in input_ports:
            port_from = input_port
            for coupled_component in self.getDEVSCoupledComponents():
                # si el acoplado tiene el puerto de input para esto...
                for coupled_input_port in coupled_component.getDEVSInputPorts():
                    if coupled_input_port.getName() == input_port.getName() and coupled_input_port.getName() not in cte_aux_names:
                        port_to      = coupled_input_port
                        component_to = coupled_component
                        input_coupled_connections.append(
                            DEVSExternalInputConnection(port_from, port_to, component_to)
                        ) 
        return input_coupled_connections

    # External output connections
    def setExternalOutputConnections(self):
        return self.setAtomicToOutputConnections() + self.setCoupledToOutputConnections()

    def setAtomicToOutputConnections(self):
        atomic_output_connections = []
        for atomic_component in self.getDEVSAtomicComponents():
            if atomic_component.getType() == 'DEVSAux':
                for output_port in atomic_component.getDEVSOutputPorts():
                    atomic_output_connections.append(
                        DEVSExternalOutputConnection(atomic_component, output_port, DEVSPort(output_port.getName(), self, 'out'))
                    )
        return atomic_output_connections

    def setCoupledToOutputConnections(self):
        coupled_output_connections = []
        for coupled_component in self.getDEVSCoupledComponents():
            for output_port in coupled_component.getDEVSOutputPorts():
                coupled_output_connections.append(
                    DEVSExternalOutputConnection(coupled_component, output_port, DEVSPort(output_port.getName(), self, 'out'))
                )
        return coupled_output_connections
    
    # Internal connections
    def setInternalConnections(self):
        return self.setAtomicToAtomicConnections() + self.setAtomicToCoupledConnections() + \
                self.setCoupledToAtomicConnections() + self.setCoupledToCoupledConnections()
    
    def setAtomicToAtomicConnections(self):
        atomic_to_atomic_connections = []
        for atomic_component_from in self.getDEVSAtomicComponents():
            for output_port in atomic_component_from.getDEVSOutputPorts():
                for atomic_component_to in self.getDEVSAtomicComponents():
                    for input_port in atomic_component_to.getDEVSInputPorts():
                        if output_port.getName() == input_port.getName():
                            atomic_to_atomic_connections.append(
                                DEVSInternalConnection(output_port, atomic_component_from, input_port, atomic_component_to)
                            ) 

        return list(set(atomic_to_atomic_connections))
    
    def setAtomicToCoupledConnections(self):
        atomic_to_coupled_connections = []
        for atomic_component_from in self.getDEVSAtomicComponents():
            for output_port in atomic_component_from.getDEVSOutputPorts():
                for coupled_component_to in self.getDEVSCoupledComponents():
                    for input_port in coupled_component_to.getDEVSInputPorts():
                        if output_port.getName() == input_port.getName():
                            atomic_to_coupled_connections.append(
                                DEVSInternalConnection(output_port, atomic_component_from, input_port, coupled_component_to)
                            )
        return list(set(atomic_to_coupled_connections))

    def setCoupledToCoupledConnections(self):
        coupled_to_coupled_connections = []
        for coupled_component_from in self.getDEVSCoupledComponents():
            for output_port in coupled_component_from.getDEVSOutputPorts():
                for coupled_component_to in self.getDEVSCoupledComponents():
                    for input_port in coupled_component_to.getDEVSInputPorts():
                        if output_port.getName() == input_port.getName():
                            coupled_to_coupled_connections.append(
                                DEVSInternalConnection(output_port, coupled_component_from, input_port, coupled_component_to)
                            )
        return list(set(coupled_to_coupled_connections))

    def setCoupledToAtomicConnections(self):
        coupled_to_atomic_connections = []
        for coupled_component_from in self.getDEVSCoupledComponents():
            for output_port in coupled_component_from.getDEVSOutputPorts():
                for atomic_component_to in self.getDEVSAtomicComponents():
                    for input_port in atomic_component_to.getDEVSInputPorts():
                        if output_port.getName() == input_port.getName():
                            coupled_to_atomic_connections.append(
                                DEVSInternalConnection(output_port, coupled_component_from, input_port, atomic_component_to)
                            ) 

        return list(set(coupled_to_atomic_connections))

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

                ############## !!!!!!!! ACA !!!!!!!!! ############
                # TODO : agregar los atomicos correspondientes a funciones especiales (ie.: PULSE, RAMP, etc.)
                #        hay que mirar el atributo 'equation' de Fplus's, Fminus's
                #        * despues tambien hay que agregar las 'internal connections correspondientes'
                #        * si la funcion toma como input otras variables del modelo, tambien habria que setear EXTERNAL_{INPUT/OUTPUT}_CONNECTIONS
                ##################################################
                
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
                for atomic_component in atomic_components:
                    if atomic_component.getType() in ['DEVSFplus', 'DEVSFminus']:
                        for input_port in atomic_component.getDEVSInputPorts():
                            external_input_connections.append(
                                DEVSExternalInputConnection(DEVSPort(atomic_component.getName(), self, 'in'), input_port, atomic_component)
                            )
                external_input_connections = list(set(external_input_connections))

                ###########
                # External output connections : conexiones que salen de algun componente hacia algun puerto de 'output_ports' (Integradores)
                external_output_connections = []
                for atomic_component in atomic_components:
                    if atomic_component.getType() == 'DEVSIntegrator':
                        for output_port in atomic_component.getDEVSOutputPorts():
                            external_output_connections.append(
                                DEVSExternalOutputConnection(atomic_component, output_port, DEVSPort(output_port.getName(), self, 'out'))
                            )
                
                ###########
                # Internal connections
                internal_connections = []
                # Ftot => Integrator
                internal_connections.append(DEVSInternalConnection(
                        DEVSPort(DEVSFtot(stock).getName(), DEVSFtot(stock), 'out'), DEVSFtot(stock),
                        DEVSPort(stock.getName(), DEVSIntegrator(stock), 'in'), DEVSIntegrator(stock)
                    ))
                # fp => ftot
                for fp in devs_fps:
                    for output_port in fp.getDEVSOutputPorts():
                        internal_connections.append(DEVSInternalConnection(
                            output_port, fp, DEVSPort('plus', DEVSFtot(stock), 'in'), DEVSFtot(stock)
                        ))
                # fm => ftot
                for fm in devs_fms:
                    for output_port in fm.getDEVSOutputPorts():
                        internal_connections.append(DEVSInternalConnection(
                            output_port, fm, DEVSPort('minus', DEVSFtot(stock), 'in'), DEVSFtot(stock)
                        ))
                internal_connections = list(set(internal_connections))

                coupleds.append(
                    DEVSBasicCoupledComponent(None, root_models, name,
                        atomic_components, coupled_components, 
                        external_input_connections, external_output_connections, 
                        internal_connections,
                        input_ports, output_ports
                    )
                )

        return coupleds