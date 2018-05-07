
from modulosDEVS.DEVSInternalConnection import DEVSInternalConnection
from modulosDEVS.DEVSExternalInputConnection import DEVSExternalInputConnection
from modulosDEVS.DEVSExternalOutputConnection import DEVSExternalOutputConnection
from modulosDEVS.DEVSPort import DEVSPort
from modulosDEVS.DEVSComponent import DEVSComponent
from modulosDEVS.DEVSAtomic.DEVSFpm import DEVSFpm
from modulosDEVS.DEVSAtomic.DEVSFtot import DEVSFtot
from modulosDEVS.DEVSAtomic.DEVSIntegrator import DEVSIntegrator

DEVS_BASIC_COUPLED_NAME_PREFIX = "DEVS_BASIC_COUPLED_"

class DEVSBasicCoupledComponent(DEVSComponent):
    ################################################################################
    def __init__(self, xmile_model, root_models, name=None, atomic_components=None, coupled_components=None,
                 external_input_connections=None, external_output_connections=None, internal_connections=None,
                 input_ports=None, output_ports=None, parent_name=None):
        self.xmile_model = xmile_model
        self.root_models = root_models
        self.type = 'DEVSBasicCoupledComponent'
        if name is not None:
            self.name = name
        else:
            self.name = 'DEVS_BASIC_COUPLED_' + self.xmile_model.get_name()

        # Atomic components
        if atomic_components is not None:
            self.atomic_components = atomic_components
        # Coupled components
        if coupled_components is not None:
            self.coupled_components = coupled_components
        # Output Ports
        if output_ports is not None:
            self.output_ports = output_ports
        # Input Ports
        if input_ports is not None:
            self.input_ports = input_ports
        # External input connections
        if external_input_connections is not None:
            self.external_input_connections = external_input_connections
        # External output connections
        if external_output_connections is not None:
            self.external_output_connections = external_output_connections
        # Internal connections
        if internal_connections is not None:
            self.internal_connections = internal_connections
        # Parent name
        if parent_name is not None:
            self.parent = parent_name

    ################################################################################
    # Representation functions
    def __repr__(self):
        return str({'name': self.name, 'type': self.type, 'atomic_components': self.atomic_components,
                    'coupled_components': self.coupled_components,
                    'external_input_connections': self.external_input_connections,
                    'external_output_connections': self.external_output_connections,
                    'internal_connections': self.internal_connections, 'input_ports': self.input_ports,
                    'output_ports': self.output_ports})

    def __str__(self):
        return str({'name': self.name, 'type': self.type, 'atomic_components': self.atomic_components,
                    'coupled_components': self.coupled_components,
                    'external_input_connections': self.external_input_connections,
                    'external_output_connections': self.external_output_connections,
                    'internal_connections': self.internal_connections, 'input_ports': self.input_ports,
                    'output_ports': self.output_ports})

    ################################################################################
    # Setters
    def set_parent(self, parent_name):
        self.parent = parent_name

    def set_name(self, name):
        self.name = name

    def set_atomic_components(self, atomic_components):
        self.atomic_components = atomic_components

    def set_coupled_components(self, coupled_components):
        self.coupled_components = coupled_components

    def set_output_ports(self, output_ports):
        self.output_ports = output_ports

    def set_input_ports(self, input_ports):
        self.input_ports = input_ports

    def set_external_input_connections(self, external_input_connections):
        self.external_input_connections = external_input_connections

    def set_external_output_connections(self, external_output_connections):
        self.external_output_connections = external_output_connections

    def set_internal_connections(self, internal_connections):
        self.internal_connections = internal_connections

    # Getters
    def get_parent(self):
        return self.parent

    def get_type(self):
        return self.type

    def get_name(self):
        return self.name

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

    # Set full instance
    def initialize(self, xmile_flows, parent_coupled, stock):
        name = DEVS_BASIC_COUPLED_NAME_PREFIX + stock.get_name()
        ###########
        # Acoplados : ninguno
        coupled_components = []
        ###########
        # Atomicos : Ftot + Integrador + Fpm's (recordar que los Cte's y Aux's los sacamos afuera)
        # (Ftot + Integrador)
        integrator = DEVSIntegrator(stock, name)
        ftot = DEVSFtot(stock, name)
        atomic_components = [integrator, ftot]

        #  (Fpm's)
        devs_fpms = list(map(lambda x: DEVSFpm(x, [stock], name), xmile_flows))
        devs_fps = list(filter(lambda x: x is not None, list(map(lambda x: x.get_fplus(), devs_fpms))))
        devs_fms = list(filter(lambda x: x is not None, list(map(lambda x: x.get_fminus(), devs_fpms))))
        atomic_components = atomic_components + devs_fps + devs_fms

        ####
        # Special Atomics (correspondientes a Fp's y Fm's)
        special_atomics = []
        for fp in devs_fps:
            special_atomics_fps = fp.get_equation().get_special_functions(name)
            special_atomics = special_atomics + special_atomics_fps
            atomic_components = atomic_components + special_atomics_fps
        for fm in devs_fms:
            special_atomics_fms = fm.get_equation().get_special_functions(name)
            special_atomics = special_atomics + special_atomics_fms
            atomic_components = atomic_components + special_atomics_fms

        ###########
        # Inputs :
        #   . necesito 1 input para cada variable que usan los flows
        #   . necesito los inputs requeridos por cada SpecialFunction de cada Fp/Fm
        # Nota : es necesario quitar de esta lista a los que corresponden a 'stock'
        # Nota : filtro los inputs correspondientes a funciones especiales (estas quedan ADENTRO del BASIC_)
        input_ports = []
        # Agrego inputs correspondientes a la ecuacion 'pelada' del Fp/Fm
        for devs_fp in devs_fps:
            input_ports_fp = devs_fp.get_input_ports()
            for input_port_fp in input_ports_fp:
                if input_port_fp.get_name() != stock.get_name() and input_port_fp.get_name() not in list(
                        map(lambda x: x.get_name(), devs_fp.get_equation().get_special_functions(name))):
                    input_ports.append(DEVSPort(input_port_fp.get_name(), parent_coupled, 'in'))
        for devs_fm in devs_fms:
            input_ports_fm = devs_fm.get_input_ports()
            for input_port_fm in input_ports_fm:
                if input_port_fm.get_name() != stock.get_name() and input_port_fm.get_name() not in list(
                        map(lambda x: x.get_name(), devs_fm.get_equation().get_special_functions(name))):
                    input_ports.append(DEVSPort(input_port_fm.get_name(), parent_coupled, 'in'))
        # Agrego los inputs correspondientes a funciones especiales (ej. DEVSPulse)
        for special_atomic in special_atomics:
            for variable_name in special_atomic.get_all_inputs():
                input_ports.append(DEVSPort(variable_name, parent_coupled, 'in'))
        # Si un fp y fm reciben el mismo input, solo voy a querer que llegue por un unico puerto
        input_ports = list(set(input_ports))

        ###########
        # Outputs : solamente el valor del stock
        output_ports = [DEVSPort(stock.get_name(), parent_coupled, 'out')]

        ###########
        # External input connections : conexiones que vienen de 'input_ports', y llegan a algun componente
        # (Fp's y Fm's)
        external_input_connections = []
        for atomic_component in atomic_components:
            # TODO : esta lista deberia considerar a todas las funciones especiales. Hay que estandarizar esta lista / chequear directamente la clase del atomico
            if atomic_component.get_type() in ['DEVSFplus', 'DEVSFminus', 'DEVSPulse']:
                for input_port_atomic in atomic_component.get_input_ports():
                    for input_port_basic_coupled in input_ports:
                        if input_port_atomic.get_name() == input_port_basic_coupled.get_name():
                            external_input_connections.append(
                                DEVSExternalInputConnection(input_port_basic_coupled, input_port_atomic,
                                                            input_port_atomic.get_component()))
        external_input_connections = list(set(external_input_connections))

        ###########
        # External output connections : conexiones que salen de algun componente hacia algun puerto de
        # 'output_ports' (Integradores)
        external_output_connections = []
        for atomic_component in atomic_components:
            if atomic_component.get_type() == 'DEVSIntegrator':
                for output_port in atomic_component.get_output_ports():
                    external_output_connections.append(DEVSExternalOutputConnection(atomic_component, output_port,
                                                                                    DEVSPort(output_port.get_name(),
                                                                                             parent_coupled,
                                                                                             'out')))

        ###########
        # Internal connections
        internal_connections = []
        # ftot => Integrator
        internal_connections.append(DEVSInternalConnection(DEVSPort(ftot.get_name(), ftot, 'out'), ftot,
                                                           DEVSPort('Tot' + stock.get_name(), integrator, 'in'),
                                                           integrator))
        # fp => ftot
        for fp in devs_fps:
            for output_port in fp.get_output_ports():
                updated_port = ftot.add_plus_port(output_port.get_name())
                internal_connections.append(DEVSInternalConnection(output_port, fp, updated_port, ftot))
        # fm => ftot
        for fm in devs_fms:
            for output_port in fm.get_output_ports():
                updated_port = ftot.add_minus_port(output_port.get_name())
                internal_connections.append(DEVSInternalConnection(output_port, fm, updated_port, ftot))
        # Integrator <=> Fp's/Fm's | SpecialFunctions <=> Fp's/Fm's (las SpecialFunction's las dejo adentro del BASIC)
        # - Fp's
        for fp in devs_fps:
            input_ports_fp = fp.get_input_ports()
            for input_port in input_ports_fp:
                # Integrator => Fp's
                if integrator.get_name() == input_port.get_name():
                    output_port = integrator.get_output_ports()[0]
                    internal_connections.append(
                        DEVSInternalConnection(output_port, integrator, input_port, input_port.get_component()))
                # SpecialFunctions => Fp's
                for special_func_obj in fp.get_equation().get_special_functions(name):
                    if special_func_obj.get_type() == 'DEVSPulse':
                        internal_connections.append(
                            DEVSInternalConnection(DEVSPort(special_func_obj.get_name(), special_func_obj, 'out'),
                                                   special_func_obj, DEVSPort('increment', integrator, 'in'),
                                                   integrator))
        # - Fm's
        for fm in devs_fms:
            input_ports_fm = fm.get_input_ports()
            for input_port in input_ports_fm:
                # Integrator => Fm's
                if integrator.get_name() == input_port.get_name():
                    output_port = integrator.get_output_ports()[0]
                    internal_connections.append(
                        DEVSInternalConnection(output_port, integrator, input_port, input_port.get_component()))
                # SpecialFunctions => Fm's
                for special_func_obj in fm.get_equation().get_special_functions(name):
                    if special_func_obj.get_type() == 'DEVSPulse':
                        internal_connections.append(
                            DEVSInternalConnection(DEVSPort(special_func_obj.get_name(), special_func_obj, 'out'),
                                                   special_func_obj, DEVSPort('subtract', integrator, 'in'),
                                                   integrator))
        internal_connections = list(set(internal_connections))

        # Append component
        self.set_parent(parent_coupled.name)
        self.set_name(name)
        self.set_atomic_components(atomic_components)
        self.set_coupled_components(coupled_components)
        self.set_output_ports(output_ports)
        self.set_input_ports(input_ports)
        self.set_external_input_connections(external_input_connections)
        self.set_external_output_connections(external_output_connections)
        self.set_internal_connections(internal_connections)
