
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
        devs_auxs = []
        devs_ctes = []
        deps = xmile_model.getDependencies()

        # Ctes
        # Nota : los Cte's que tienen SpecialFunctions adentro ( van a ser Aux's )
        xmile_ctes, xmile_auxs = self.setXMILEConstantsAndAuxiliaryComponents()
        for xmile_cte in xmile_ctes:
            if len(xmile_cte.getEquation().getSpecialFunctions()) == 0:
                devs_ctes.append(DEVSConstant(xmile_cte, xmile_model))
            else:
                aux_dependencies = []
                for dep in deps:
                    if xmile_cte.getName() == dep.getName():
                        aux_dependencies = aux_dependencies + dep.getInputs()
                # Genero el Aux (por tener una SpecialFunction)
                devs_auxs.append(DEVSAux(xmile_cte, xmile_model, []))
        # Auxs
        for xmile_aux in xmile_auxs:
            aux_dependencies = []
            for dep in deps:
                if xmile_aux.getName() == dep.getName():
                    aux_dependencies = aux_dependencies + dep.getInputs()
            # Genero los Aux's, teniendo en cuenta las variables de las cuales este atomico depende (y que por ende tiene como input)
            devs_auxs.append(DEVSAux(xmile_aux, xmile_model, aux_dependencies))
        
        atomic_components = atomic_components + devs_ctes + devs_auxs
        # Special Functions
        for atomic_component in atomic_components:
            special_atomic_components = atomic_component.getEquation().getSpecialFunctions()
            atomic_components         = atomic_components + special_atomic_components

        return list(set(atomic_components))
    
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

        # !!!!!!!!!!!!!!!!! ACA !!!!!!!!!!!!!!!!!!!!!
        # TODO : agregar input ports que van a Aux's (prestar atencion si el Aux tiene adentro un specialFunction, influye?)

        # La union de los inputs de los Const's que tengo adentro
        for atomic_component in self.getDEVSAtomicComponents():
            # no sabemos si el input de estos atomicos va a venir de afuera o de algun otra acoplado interno
            if atomic_component.getType() == 'DEVSConstant':
                for input_port in atomic_component.getDEVSInputPorts():
                    # Chequeo que el input no se corresponda a una special function, sino a la Cte propiamente
                    if input_port.getComponent().getName() == 'DEVSConstant':
                        input_ports.append(DEVSPort(input_port.getName(), self, 'in', True))

        # La union de los inputs de los coupled models adentro mio, que son especificamente para Cte's
        for coupled_component in self.getDEVSCoupledComponents():
            for input_port in coupled_component.getDEVSInputPorts():
                if input_port.get_is_for_constant():
                    input_ports.append(DEVSPort(input_port.getName(), self, 'in'))

        # La union de los inputs provenientes de CoupledModels de los chabones adentro mio que no se corresponden a output's Stocks / Auxs / SpecialFunctions de este DCM
        my_internal_output_names = []
        for atomic_component in self.getDEVSAtomicComponents():
            if atomic_component.getType() in ['DEVSAux', 'DEVSPulse']:
                atomic_outputs = atomic_component.getDEVSOutputPorts()
                my_internal_output_names = my_internal_output_names + list(map(lambda x : x.getName(), atomic_outputs))

        for coupled_component in self.getDEVSCoupledComponents():
            basic_coupled_outputs = coupled_component.getDEVSOutputPorts()
            for output_port in basic_coupled_outputs:
                my_internal_output_names.append(output_port.getName())

        for atomic_component in self.getDEVSAtomicComponents():
            for input_port in atomic_component.getDEVSInputPorts():
                if input_port.getName() not in my_internal_output_names:
                    input_ports.append(DEVSPort(input_port.getName(), self, 'in'))
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
        flatten = lambda l: [item for sublist in l for item in sublist]
        inputs_atomic_connections = []
        input_ports = self.getDEVSInputPorts()
        # TODO : ver otra forma (esta no funciona) de filtrar las conexiones que ya tienen una componente matcheada
        input_names_matching_components = []
        for input_port in input_ports:
            for atomic_component in self.getDEVSAtomicComponents():
                if input_port.getName() == atomic_component.getName():
                    input_names_matching_components.append(input_port.getName())
        for input_port in input_ports:
            port_from = input_port
            for atomic_component in self.getDEVSAtomicComponents():
                # si el atomico tiene el puerto de input para esto...
                for atomic_input_port in atomic_component.getDEVSInputPorts():
                    if atomic_input_port.getName() == input_port.getName():
                        port_to      = atomic_input_port
                        component_to = atomic_component
                        if not (component_to.getType()=='DEVSAux' and port_to.getName() in input_names_matching_components):
                            inputs_atomic_connections.append(
                                DEVSExternalInputConnection(port_from, port_to, component_to)
                            )
        return inputs_atomic_connections

    def setExternalInputToCoupledConnections(self):
        input_coupled_connections = []

        cte_aux_names = list(map(lambda x : x.getName(), self.getDEVSAtomicComponents()))
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
                    # El atomico destino tiene que ser distinto del atomico origen para que haya una conexion de uno al otro
                    if atomic_component_from != atomic_component_to:
                        for input_port in atomic_component_to.getDEVSInputPorts():
                            if output_port.getName() == input_port.getName():
                                atomic_to_atomic_connections.append(
                                    DEVSInternalConnection(output_port, atomic_component_from, input_port, atomic_component_to)
                                )
        # VERIFICAR : agrega las conexiones correspondientes a : {Cte's, Aux's} => SpecialFunctions
        # VERIFICAR : agrega conexiones correspondientes a : SpecialFunctions => {Cte's, Aux's}

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
                    if coupled_component_to != coupled_component_from:
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
                
                basic_coupled_now = DEVSBasicCoupledComponent(xmile_generic_model, root_models)
                name = "DEVS_BASIC_COUPLED_" + stock.getName()
                
                ###########
                # Acoplados : ninguno
                coupled_components = []
                
                ###########
                # Atomicos : Ftot + Integrador + Fpm's (recordar que los Cte's y Aux's los sacamos afuera)
                # (Ftot + Integrador)
                integrator = DEVSIntegrator(stock)
                atomic_components = [integrator, DEVSFtot(stock)]
                
                #  (Fpm's)
                devs_fpms = list(map(lambda x : DEVSFpm(x, [stock]), xmile_flows))
                devs_fps  = list(filter(lambda x : x is not None, list(map(lambda x : x.getFPlus(), devs_fpms))))
                devs_fms  = list(filter(lambda x : x is not None, list(map(lambda x : x.getFMinus(), devs_fpms))))
                atomic_components = atomic_components + devs_fps + devs_fms

                ####
                # Special Atomics (correspondientes a Fp's y Fm's)
                for fp in devs_fps:
                    special_atomics = fp.getEquation().getSpecialFunctions()
                    atomic_components = atomic_components + special_atomics
                for fm in devs_fms:
                    special_atomics = fm.getEquation().getSpecialFunctions()
                    atomic_components = atomic_components + special_atomics
                
                ###########
                # Inputs : necesito 1 input para cada variable que usan los flows
                # Nota : es necesario quitar de esta lista a lo que corresponden a 'stock'
                # Nota : filtro los inputs correspondientes a funciones especiales (estas quedan ADENTRO del BASIC_) (ZZZ)
                input_ports = []
                for devs_fp in devs_fps:
                    input_ports_fp = devs_fp.getDEVSInputPorts()
                    for input_port_fp in input_ports_fp:
                        if input_port_fp.getName() != stock.getName() and input_port_fp.getName() not in list(map(lambda x : x.getName(), devs_fp.getEquation().getSpecialFunctions())): 
                            input_ports.append(DEVSPort(input_port_fp.getName(), self, 'in'))
                for devs_fm in devs_fms:
                    input_ports_fm = devs_fm.getDEVSInputPorts()
                    for input_port_fm in input_ports_fm:
                        if input_port_fm.getName() != stock.getName() and input_port_fm.getName() not in list(map(lambda x : x.getName(), devs_fm.getEquation().getSpecialFunctions())):
                            input_ports.append(DEVSPort(input_port_fm.getName(), self, 'in'))
                # Agrego los inputs correspondientes a las variables que las SpecialFunctions necesitan
                for devs_fp in devs_fps:
                    special_functions = devs_fp.getEquation().getSpecialFunctions()
                    for special_func_obj in special_functions:
                        for variable_name in special_func_obj.getVariables():
                            input_ports.append(DEVSPort(variable_name, self, 'in'))
                for devs_fm in devs_fms:
                    special_functions = devs_fm.getEquation().getSpecialFunctions()
                    for special_func_obj in special_functions:
                        for variable_name in special_func_obj.getVariables():
                            input_ports.append(DEVSPort(variable_name, self, 'in'))

                # Si un fp y fm reciben el mismo input, solo voy a querer que llegue por un unico puerto
                input_ports = list(set(input_ports))

                ###########
                # Outputs : 1 output por el stock ; nada mas ;
                output_ports = [DEVSPort(stock.getName(), self, 'out')]

                ###########
                # External input connections : conexiones que vienen de 'input_ports', y llegan a algun componente (Fp's y Fm's)
                external_input_connections = []
                for atomic_component in atomic_components:
                    # TODO : esta lista deberia considerar a todas las funciones especiales. Hay que estandarizar esta lista / chequear directamente la clase del atomico
                    if atomic_component.getType() in ['DEVSFplus', 'DEVSFminus', 'DEVSPulse']:
                        for input_port_atomic in atomic_component.getDEVSInputPorts():
                            for input_port_basic_coupled in input_ports:
                                if input_port_atomic.getName() == input_port_basic_coupled.getName():
                                    external_input_connections.append(
                                        DEVSExternalInputConnection(input_port_basic_coupled, input_port_atomic, input_port_atomic.getComponent())
                                    )
                external_input_connections = list(set(external_input_connections))
                # TODO : agregar las conexiones correspondientes a inputs utilizados por las 'SpecialFunctions'

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
                        DEVSPort('Tot'+stock.getName(), integrator, 'in'), integrator
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
                # Nota : las SpecialFunction's las dejo adentro del BASIC
                for fp in devs_fps:
                    input_ports_fp = fp.getDEVSInputPorts()
                    for input_port in input_ports_fp:
                        # SpecialFunctions => Fp's
                        for special_func_obj in fp.getEquation().getSpecialFunctions():
                            if input_port.getName() == special_func_obj.getName():
                                internal_connections.append(DEVSInternalConnection(
                                    DEVSPort(special_func_obj.getName(), special_func_obj, 'out'), special_func_obj, input_port, fp
                                ))
                        # Integrator => Fp's
                        if integrator.getName() == input_port.getName():
                            output_port =  integrator.getDEVSOutputPorts()[0] # tiene solo 1 output port
                            internal_connections.append(DEVSInternalConnection(
                                output_port, integrator, input_port, input_port.getComponent()
                            ))

                for fm in devs_fms:
                    input_ports_fm = fm.getDEVSInputPorts()
                    for input_port in input_ports_fm:
                        # SpecialFunctions => Fm's
                        for special_func_obj in fm.getEquation().getSpecialFunctions():
                            if input_port.getName() == special_func_obj.getName(): 
                                internal_connections.append(DEVSInternalConnection(
                                    DEVSPort(special_func_obj.getName(), special_func_obj, 'out'), special_func_obj, input_port, fm
                                ))
                        # Integrator => Fm's
                        if integrator.getName() == input_port.getName():
                            output_port =  integrator.getDEVSOutputPorts()[0] # tiene solo 1 output port
                            internal_connections.append(DEVSInternalConnection(
                                output_port, integrator, input_port, input_port.getComponent()
                            ))
                internal_connections = list(set(internal_connections))
                
                # Agrego componente
                basic_coupled_now.setDEVSName(name)
                basic_coupled_now.setDEVSAtomicComponents(atomic_components)
                basic_coupled_now.setDEVSCoupledComponents(coupled_components)
                basic_coupled_now.setDEVSOutputPorts(output_ports)
                basic_coupled_now.setDEVSInputPorts(input_ports)
                basic_coupled_now.setDEVSExternalInputConnections(external_input_connections)
                basic_coupled_now.setDEVSExternalOutputConnections(external_output_connections)
                basic_coupled_now.setDEVSInternalConnections(internal_connections)
                coupleds.append(basic_coupled_now)

        return coupleds