
from modulosDEVS.DEVSConnection import *
from modulosDEVS.DEVSPort import DEVSPort
from modulosDEVS.DEVSComponent import DEVSComponent
from modulosDEVS.DEVSCoupled.DEVSBasicCoupledComponent import DEVSBasicCoupledComponent
from modulosDEVS.DEVSAtomic.DEVSAux import DEVSAux
from modulosDEVS.DEVSAtomic.DEVSConstant import DEVSConstant
from modulosDEVS.DEVSAtomic.DEVSFpm import DEVSFpm
from modulosDEVS.DEVSAtomic.DEVSFtot import DEVSFtot
from modulosDEVS.DEVSAtomic.DEVSIntegrator import DEVSIntegrator


# TODO : buscar una forma de determinar el 'parent' de cada DEVSCoupledComponent. En ppio pareciera no ser necesario para armar los h, cpp y ma
# TODO : que pasa si un PULSE entra en una Cte?
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
        # TODO : setear este parent bien ... donde? (en la funcion que recorre?)
        self.parent = ''
        
        if name is not None:
            self.name = name
        else:
            self.name = 'DEVS_COUPLED_' + self.xmile_model.get_name()
        
        # Atomic components
        if atomic_components is not None:
            self.atomic_components = atomic_components
        else:
            self.atomic_components = self.set_atomic_components()
        # Coupled components
        if coupled_components is not None:
            self.coupled_components = coupled_components
        else:
            self.coupled_components = self.set_coupled_components()
        # Output Ports
        if output_ports is not None:
            self.output_ports = output_ports
        else :
            self.output_ports = self.set_output_ports()
        # Input Ports
        if input_ports is not None:
            self.input_ports  = input_ports
        else:
            self.input_ports = self.set_input_ports()
        # External input connections
        if external_input_connections is not None:
            self.external_input_connections = external_input_connections
        else:
            self.external_input_connections = self.set_external_input_connections()
        # External output connections
        if external_output_connections is not None:
            self.external_output_connections = external_output_connections
        else:
            self.external_output_connections = self.set_external_output_connections()
        # Internal connections
        if internal_connections is not None:
            self.internal_connections = internal_connections
        else:
            self.internal_connections = self.set_internal_connections()

    ################################################################################
    # Representation functions
    def __repr__(self):
        return str({
            'name': self.name,
            'type': self.type,
            'atomic_components': self.atomic_components,
            'coupled_components': self.coupled_components,
            'external_input_connections': self.external_input_connections,
            'external_output_connections': self.external_output_connections,
            'internal_connections': self.internal_connections,
            'input_ports': self.input_ports,
            'output_ports': self.output_ports
        })

    def __str__(self):
        return str({
            'name': self.name,
            'type': self.type,
            'atomic_components': self.atomic_components,
            'coupled_components': self.coupled_components,
            'external_input_connections': self.external_input_connections,
            'external_output_connections': self.external_output_connections,
            'internal_connections': self.internal_connections,
            'input_ports': self.input_ports,
            'output_ports': self.output_ports
        })

    ################################################################################ 
    # Getters
    def get_name(self):
        return self.name

    def get_type(self):
        return self.type

    def get_atomic_components(self):
        return self.atomic_components

    def get_coupled_components(self):
        return self.coupled_components

    def get_external_input_connections(self):
        return self.external_input_connections

    def get_external_output_connections(self):
        return self.external_output_connections

    def get_internal_connections(self):
        return self.internal_connections

    def get_input_ports(self):
        return self.input_ports

    def get_output_ports(self):
        return self.output_ports

    ################################################################################
    # Setters    
    def set_atomic_components(self):
        xmile_model = self.xmile_model

        # 1 atomico por cada Cte
        # 1 atomico por cada Aux
        # Eventualmente, 1 atomico por cada funcion rara (PULSE, etc.)
        atomic_components = []
        devs_auxs = []
        devs_ctes = []
        deps = xmile_model.get_dependencies()

        # Ctes
        # Nota : los Cte's que tienen SpecialFunctions adentro ( van a ser Aux's )
        xmile_ctes, xmile_auxs = self.set_xmile_constants_and_auxiliary_components()
        for xmile_cte in xmile_ctes:
            if len(xmile_cte.get_equation().get_special_functions(self.name)) == 0:
                devs_ctes.append(DEVSConstant(xmile_cte, xmile_model))
            else:
                aux_dependencies = []
                for dep in deps:
                    if xmile_cte.get_name() == dep.get_name():
                        aux_dependencies = aux_dependencies + dep.get_inputs()
                # Genero el Aux (por tener una SpecialFunction)
                devs_auxs.append(DEVSAux(xmile_cte, xmile_model, []))
        # Auxs
        for xmile_aux in xmile_auxs:
            aux_dependencies = []
            for dep in deps:
                if xmile_aux.get_name() == dep.get_name():
                    aux_dependencies = aux_dependencies + dep.get_inputs()
            # Genero los Aux's, teniendo en cuenta las variables de las cuales este atomico depende (y que por ende tiene como input)
            devs_auxs.append(DEVSAux(xmile_aux, xmile_model, aux_dependencies))
        
        atomic_components = atomic_components + devs_ctes + devs_auxs
        # Special Functions
        for atomic_component in atomic_components:
            special_atomic_components = atomic_component.get_equation().get_special_functions(self.name)
            atomic_components         = atomic_components + special_atomic_components

        return list(set(atomic_components))
    
    def set_coupled_components(self):
        # 1 acoplado por cada modulo
        xmile_modules = self.xmile_model.get_modules()
        xmile_modules_models = []
        for model in self.root_models:
            for module in xmile_modules:
                if model.get_name() == module.get_name():
                    xmile_modules_models.append(model)
        devs_modules  = list(map(lambda x : DEVSCoupledComponent(x, self.root_models), xmile_modules_models))
        
        # 1 acoplado por cada Stock (+ Flows asociados)
        devs_generics = self.set_basic_stock_flow_coupleds(self.root_models)
        return devs_modules + devs_generics
    
    def set_output_ports(self):
        output_ports = []
 
        # 1 output por cada Aux
        for atomic_component in self.get_atomic_components():
            if atomic_component.get_type() == 'DEVSAux':
                for output_port in atomic_component.get_output_ports():
                    output_ports.append(DEVSPort(output_port.get_name(), self, 'out'))

        #  1 output por cada output de cada acoplado
        for coupled_component in self.get_coupled_components():
            for output_port in coupled_component.get_output_ports():
                output_ports.append(DEVSPort(output_port.get_name(), self, 'out'))

        return list(set(output_ports))

    def set_input_ports(self):
        input_ports = []

        # !!!!!!!!!!!!!!!!! ACA !!!!!!!!!!!!!!!!!!!!!
        # TODO : agregar input ports que van a Aux's (prestar atencion si el Aux tiene adentro un specialFunction,
        # influye?)

        # La union de los inputs de los Const's que tengo adentro
        for atomic_component in self.get_atomic_components():
            # no sabemos si el input de estos atomicos va a venir de afuera o de algun otra acoplado interno
            if atomic_component.get_type() == 'DEVSConstant':
                for input_port in atomic_component.get_input_ports():
                    # Chequeo que el input no se corresponda a una special function, sino a la Cte propiamente
                    if input_port.get_component().get_name() == 'DEVSConstant':
                        input_ports.append(DEVSPort(input_port.get_name(), self, 'in', True))

        # La union de los inputs de los coupled models adentro mio, que son especificamente para Cte's
        for coupled_component in self.get_coupled_components():
            for input_port in coupled_component.get_input_ports():
                if input_port.get_is_for_constant():
                    input_ports.append(DEVSPort(input_port.get_name(), self, 'in'))

        # La union de los inputs provenientes de CoupledModels de los chabones adentro
        # mio que no se corresponden a output's Stocks / Auxs / SpecialFunctions de este DCM
        my_internal_output_names = []
        for atomic_component in self.get_atomic_components():
            if atomic_component.get_type() in ['DEVSAux', 'DEVSPulse']:
                atomic_outputs = atomic_component.get_output_ports()
                my_internal_output_names = my_internal_output_names + list(map(lambda x : x.get_name(), atomic_outputs))

        for coupled_component in self.get_coupled_components():
            basic_coupled_outputs = coupled_component.get_output_ports()
            for output_port in basic_coupled_outputs:
                my_internal_output_names.append(output_port.get_name())

        for atomic_component in self.get_atomic_components():
            for input_port in atomic_component.get_input_ports():
                if input_port.get_name() not in my_internal_output_names:
                    input_ports.append(DEVSPort(input_port.get_name(), self, 'in'))
        for coupled_component in self.get_coupled_components():
            for input_port in coupled_component.get_input_ports():
                if input_port.get_name() not in my_internal_output_names:
                        input_ports.append(DEVSPort(input_port.get_name(), self, 'in'))
        
        input_ports = list(set(input_ports))
        return input_ports
    
    # External input connections
    def set_external_input_connections(self):
        return self.set_external_input_to_atomic_connections() + self.set_external_input_to_coupled_connections()

    def set_external_input_to_atomic_connections(self):
        flatten = lambda l: [item for sublist in l for item in sublist]
        inputs_atomic_connections = []
        input_ports = self.get_input_ports()
        # TODO : ver otra forma (esta no funciona) de filtrar las conexiones que ya tienen una componente matcheada
        input_names_matching_components = []
        for input_port in input_ports:
            for atomic_component in self.get_atomic_components():
                if input_port.get_name() == atomic_component.get_name():
                    input_names_matching_components.append(input_port.get_name())
        for input_port in input_ports:
            port_from = input_port
            for atomic_component in self.get_atomic_components():
                # si el atomico tiene el puerto de input para esto...
                for atomic_input_port in atomic_component.get_input_ports():
                    if atomic_input_port.get_name() == input_port.get_name():
                        port_to      = atomic_input_port
                        component_to = atomic_component
                        if not (component_to.get_type()== 'DEVSAux' and port_to.get_name() in input_names_matching_components):
                            inputs_atomic_connections.append(
                                DEVSExternalInputConnection(port_from, port_to, component_to)
                            )
        return inputs_atomic_connections

    def set_external_input_to_coupled_connections(self):
        input_coupled_connections = []

        cte_aux_names = list(map(lambda x : x.get_name(), self.get_atomic_components()))
        input_ports = self.get_input_ports()
        for input_port in input_ports:
            port_from = input_port
            for coupled_component in self.get_coupled_components():
                # si el acoplado tiene el puerto de input para esto...
                for coupled_input_port in coupled_component.get_input_ports():
                    if coupled_input_port.get_name() == input_port.get_name() and coupled_input_port.get_name() not in cte_aux_names:
                        port_to      = coupled_input_port
                        component_to = coupled_component
                        input_coupled_connections.append(
                            DEVSExternalInputConnection(port_from, port_to, component_to)
                        ) 
        return input_coupled_connections

    # External output connections
    def set_external_output_connections(self):
        return self.set_atomic_to_output_connections() + self.set_coupled_to_output_connections()

    def set_atomic_to_output_connections(self):
        atomic_output_connections = []
        for atomic_component in self.get_atomic_components():
            if atomic_component.get_type() == 'DEVSAux':
                for output_port in atomic_component.get_output_ports():
                    atomic_output_connections.append(
                        DEVSExternalOutputConnection(atomic_component, output_port, DEVSPort(output_port.get_name(), self, 'out'))
                    )
        return atomic_output_connections

    def set_coupled_to_output_connections(self):
        coupled_output_connections = []
        for coupled_component in self.get_coupled_components():
            for output_port in coupled_component.get_output_ports():
                coupled_output_connections.append(
                    DEVSExternalOutputConnection(coupled_component, output_port, DEVSPort(output_port.get_name(), self, 'out'))
                )
        return coupled_output_connections
    
    # Internal connections
    def set_internal_connections(self):
        return self.set_atomic_to_atomic_connections() + self.set_atomic_to_coupled_connections() + \
               self.set_coupled_to_atomic_connections() + self.set_coupled_to_coupled_connections()
    
    def set_atomic_to_atomic_connections(self):
        atomic_to_atomic_connections = []
        for atomic_component_from in self.get_atomic_components():
            for output_port in atomic_component_from.get_output_ports():
                for atomic_component_to in self.get_atomic_components():
                    # El atomico destino tiene que ser distinto del atomico origen para que haya una conexion de uno al otro
                    if atomic_component_from != atomic_component_to:
                        for input_port in atomic_component_to.get_input_ports():
                            if output_port.get_name() == input_port.get_name():
                                atomic_to_atomic_connections.append(
                                    DEVSInternalConnection(output_port, atomic_component_from, input_port, atomic_component_to)
                                )
        # VERIFICAR : agrega las conexiones correspondientes a : {Cte's, Aux's} => SpecialFunctions
        # VERIFICAR : agrega conexiones correspondientes a : SpecialFunctions => {Cte's, Aux's}

        return list(set(atomic_to_atomic_connections))
    
    def set_atomic_to_coupled_connections(self):
        atomic_to_coupled_connections = []
        for atomic_component_from in self.get_atomic_components():
            for output_port in atomic_component_from.get_output_ports():
                for coupled_component_to in self.get_coupled_components():
                    for input_port in coupled_component_to.get_input_ports():
                        if output_port.get_name() == input_port.get_name():
                            atomic_to_coupled_connections.append(
                                DEVSInternalConnection(output_port, atomic_component_from, input_port, coupled_component_to)
                            )
        return list(set(atomic_to_coupled_connections))

    def set_coupled_to_coupled_connections(self):
        coupled_to_coupled_connections = []
        for coupled_component_from in self.get_coupled_components():
            for output_port in coupled_component_from.get_output_ports():
                for coupled_component_to in self.get_coupled_components():
                    if coupled_component_to != coupled_component_from:
                        for input_port in coupled_component_to.get_input_ports():
                            if output_port.get_name() == input_port.get_name():
                                coupled_to_coupled_connections.append(
                                    DEVSInternalConnection(output_port, coupled_component_from, input_port, coupled_component_to)
                                )
        return list(set(coupled_to_coupled_connections))

    def set_coupled_to_atomic_connections(self):
        coupled_to_atomic_connections = []
        for coupled_component_from in self.get_coupled_components():
            for output_port in coupled_component_from.get_output_ports():
                for atomic_component_to in self.get_atomic_components():
                    for input_port in atomic_component_to.get_input_ports():
                        if output_port.get_name() == input_port.get_name():
                            coupled_to_atomic_connections.append(
                                DEVSInternalConnection(output_port, coupled_component_from, input_port, atomic_component_to)
                            ) 

        return list(set(coupled_to_atomic_connections))

    ################################################################################
    # Funciones auxiliares
    def set_xmile_constants_and_auxiliary_components(self):
        constants, auxiliaries = [], []
        auxs = self.xmile_model.get_auxs()
        dependencies = self.xmile_model.get_dependencies()
        for aux in auxs:
            is_dependent = False
            for dep in dependencies:
                if aux.get_name() == dep.get_name() and len(dep.get_inputs()) > 0:
                    is_dependent = True
            if is_dependent is False:
                constants.append(aux)
            else:
                auxiliaries.append(aux)
        return constants, auxiliaries
    
    def set_basic_stock_flow_coupleds(self, root_models):
        xmile_generic_model = self.xmile_model

        # TODO : que esto lo haga un helper
        xmile_stocks = xmile_generic_model.get_stocks()
        xmile_flows  = xmile_generic_model.get_flows()
        coupleds = []

        # TODO : arreglar problemas de nombres en inputs para Ftot's (minus / plus no alcanzan como nombres de puertos)
        for stock in xmile_stocks:
            # Los stocks que no entran en el if, obtengo/entrego su valor mediante los puertos de input/output
            if stock.get_access() is None or stock.get_access() != 'input':
                
                basic_coupled_now = DEVSBasicCoupledComponent(xmile_generic_model, root_models)
                name = "DEVS_BASIC_COUPLED_" + stock.get_name()
                
                ###########
                # Acoplados : ninguno
                coupled_components = []
                
                ###########
                # Atomicos : Ftot + Integrador + Fpm's (recordar que los Cte's y Aux's los sacamos afuera)
                # (Ftot + Integrador)
                integrator = DEVSIntegrator(stock, name)
                ftot = DEVSFtot(stock,name)
                atomic_components = [integrator, ftot]
                
                #  (Fpm's)
                devs_fpms = list(map(lambda x : DEVSFpm(x, [stock], name), xmile_flows))
                devs_fps  = list(filter(lambda x : x is not None, list(map(lambda x : x.get_fplus(), devs_fpms))))
                devs_fms  = list(filter(lambda x : x is not None, list(map(lambda x : x.get_fminus(), devs_fpms))))
                atomic_components = atomic_components + devs_fps + devs_fms

                ####
                # Special Atomics (correspondientes a Fp's y Fm's)
                for fp in devs_fps:
                    special_atomics = fp.get_equation().get_special_functions(name)
                    atomic_components = atomic_components + special_atomics
                for fm in devs_fms:
                    special_atomics = fm.get_equation().get_special_functions(name)
                    atomic_components = atomic_components + special_atomics
                
                ###########
                # Inputs : necesito 1 input para cada variable que usan los flows
                # Nota : es necesario quitar de esta lista a lo que corresponden a 'stock'
                # Nota : filtro los inputs correspondientes a funciones especiales (estas quedan ADENTRO del BASIC_) (ZZZ)
                input_ports = []
                for devs_fp in devs_fps:
                    input_ports_fp = devs_fp.get_input_ports()
                    for input_port_fp in input_ports_fp:
                        if input_port_fp.get_name() != stock.get_name() and input_port_fp.get_name() not in \
                                list(map(lambda x : x.get_name(), devs_fp.get_equation().get_special_functions(name))):
                            input_ports.append(DEVSPort(input_port_fp.get_name(), self, 'in'))
                for devs_fm in devs_fms:
                    input_ports_fm = devs_fm.get_input_ports()
                    for input_port_fm in input_ports_fm:
                        if input_port_fm.get_name() != stock.get_name() and input_port_fm.get_name() not in \
                                list(map(lambda x : x.get_name(), devs_fm.get_equation().get_special_functions(name))):
                            input_ports.append(DEVSPort(input_port_fm.get_name(), self, 'in'))
                # Agrego los inputs correspondientes a las variables que las SpecialFunctions necesitan
                for devs_fp in devs_fps:
                    special_functions = devs_fp.get_equation().get_special_functions(name)
                    for special_func_obj in special_functions:
                        for variable_name in special_func_obj.get_variables():
                            input_ports.append(DEVSPort(variable_name, self, 'in'))
                for devs_fm in devs_fms:
                    special_functions = devs_fm.get_equation().get_special_functions(name)
                    for special_func_obj in special_functions:
                        for variable_name in special_func_obj.get_variables():
                            input_ports.append(DEVSPort(variable_name, self, 'in'))

                # Si un fp y fm reciben el mismo input, solo voy a querer que llegue por un unico puerto
                input_ports = list(set(input_ports))

                ###########
                # Outputs : 1 output por el stock ; nada mas ;
                output_ports = [DEVSPort(stock.get_name(), self, 'out')]

                ###########
                # External input connections : conexiones que vienen de 'input_ports', y llegan a algun componente
                # (Fp's y Fm's)
                external_input_connections = []
                for atomic_component in atomic_components:
                    # TODO : esta lista deberia considerar a todas las funciones especiales. Hay que estandarizar esta
                    # lista / chequear directamente la clase del atomico
                    if atomic_component.get_type() in ['DEVSFplus', 'DEVSFminus', 'DEVSPulse']:
                        for input_port_atomic in atomic_component.get_input_ports():
                            for input_port_basic_coupled in input_ports:
                                if input_port_atomic.get_name() == input_port_basic_coupled.get_name():
                                    external_input_connections.append(
                                        DEVSExternalInputConnection(input_port_basic_coupled, input_port_atomic,
                                                                    input_port_atomic.get_component())
                                    )
                external_input_connections = list(set(external_input_connections))
                # TODO : agregar las conexiones correspondientes a inputs utilizados por las 'SpecialFunctions'

                ###########
                # External output connections : conexiones que salen de algun componente hacia algun puerto de
                # 'output_ports' (Integradores)
                external_output_connections = []
                for atomic_component in atomic_components:
                    if atomic_component.get_type() == 'DEVSIntegrator':
                        for output_port in atomic_component.get_output_ports():
                            external_output_connections.append(
                                DEVSExternalOutputConnection(atomic_component, output_port,
                                                             DEVSPort(output_port.get_name(), self, 'out'))
                            )
                
                ###########
                # Internal connections
                internal_connections = []
                # Ftot => Integrator
                internal_connections.append(DEVSInternalConnection(
                        DEVSPort(ftot.get_name(), ftot, 'out'), ftot,
                        DEVSPort('Tot' + stock.get_name(), integrator, 'in'), integrator
                    ))
                # fp => ftot
                #print ftot.getDEVSInputPortsNames()
                for fp in devs_fps:
                    for output_port in fp.get_output_ports():
                        updated_port = ftot.add_plus_port(output_port.get_name())
                        internal_connections.append(DEVSInternalConnection(output_port, fp, updated_port, ftot))
                # fm => ftot
                for fm in devs_fms:
                    for output_port in fm.get_output_ports():
                        updated_port = ftot.add_minus_port(output_port.get_name())
                        internal_connections.append(DEVSInternalConnection(output_port, fm, updated_port, ftot))

                # Nota : las SpecialFunction's las dejo adentro del BASIC
                for fp in devs_fps:
                    input_ports_fp = fp.get_input_ports()
                    for input_port in input_ports_fp:
                        # SpecialFunctions => Fp's
                        for special_func_obj in fp.get_equation().get_special_functions(name):
                            if input_port.get_name() == special_func_obj.get_name():
                                internal_connections.append(DEVSInternalConnection(
                                    DEVSPort(special_func_obj.get_name(), special_func_obj, 'out'), special_func_obj, input_port, fp
                                ))
                        # Integrator => Fp's
                        if integrator.get_name() == input_port.get_name():
                            output_port =  integrator.get_output_ports()[0] # tiene solo 1 output port
                            internal_connections.append(DEVSInternalConnection(
                                output_port, integrator, input_port, input_port.get_component()
                            ))

                for fm in devs_fms:
                    input_ports_fm = fm.get_input_ports()
                    for input_port in input_ports_fm:
                        # SpecialFunctions => Fm's
                        for special_func_obj in fm.get_equation().get_special_functions(name):
                            if input_port.get_name() == special_func_obj.get_name():
                                internal_connections.append(DEVSInternalConnection(
                                    DEVSPort(special_func_obj.get_name(), special_func_obj, 'out'), special_func_obj, input_port, fm
                                ))
                        # Integrator => Fm's
                        if integrator.get_name() == input_port.get_name():
                            output_port =  integrator.get_output_ports()[0] # tiene solo 1 output port
                            internal_connections.append(DEVSInternalConnection(
                                output_port, integrator, input_port, input_port.get_component()
                            ))
                internal_connections = list(set(internal_connections))
                
                # Append component
                basic_coupled_now.set_parent(self.name)
                basic_coupled_now.set_name(name)
                basic_coupled_now.set_atomic_components(atomic_components)
                basic_coupled_now.set_coupled_components(coupled_components)
                basic_coupled_now.set_output_ports(output_ports)
                basic_coupled_now.set_input_ports(input_ports)
                basic_coupled_now.set_external_input_connections(external_input_connections)
                basic_coupled_now.set_external_output_connections(external_output_connections)
                basic_coupled_now.set_internal_connections(internal_connections)
                coupleds.append(basic_coupled_now)

        return coupleds