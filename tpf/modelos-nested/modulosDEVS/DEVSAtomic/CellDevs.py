
from modulosDEVS.DEVSAtomic.DEVSAtomicComponent import DEVSAtomicComponent


class Cell(DEVSAtomicComponent):
    def __init__(self, name):
        self.name = name
        self.type = 'cell'
        self.dim = None
        self.delay = None
        self.default_delay_time = None
        self.border_type = None
        self.neighbors = None
        self.initial_value = None
        self.initial_cells_value = None
        self.local_transition = None
        self.rules = None
        self.macros = None
        self.input_ports = None
        self.output_ports = None
        self.internal_input_connections = None
        self.internal_output_connections = None
        self.internal_connections = None

    # Setters
    def set_dim(self, dim):
        self.dim = dim

    def set_delay(self, delay):
        self.delay = delay

    def set_default_delay_time(self, delay):
        self.default_delay_time = delay

    def set_border_type(self, border_type):
        self.border_type = border_type

    def set_initial_value(self, initial_value):
        self.initial_value = initial_value

    def set_local_transition(self, local_transition_name):
        self.local_transition = local_transition_name

    def set_neighbors(self, neighbors):
        assert(self.dim is not None)
        for neighbor in neighbors:
            assert(len(neighbor) == len(self.dim))
        self.neighbors = neighbors

    def set_rules(self, rules):
        self.rules = rules

    def set_input_ports(self, input_ports):
        self.input_ports = input_ports

    def set_output_ports(self, output_ports):
        self.output_ports = output_ports

    def set_internal_input_connections(self, internal_input_connections):
        assert(self.input_ports is not None)
        assert(self.dim is not None)
        for iic in internal_input_connections:
            assert(iic['port_from'] in self.input_ports)
            assert('port_from' in iic.keys() and 'component_to' in iic.keys())
            dims = list(map(lambda x : int(x), iic['component_to'].split('_')[1:]))
            assert(len(dims) == len(self.dim))
            for i,x in enumerate(dims):
                assert(0 <= x and x < self.dim[i])
        self.internal_input_connections = internal_input_connections

    def set_internal_output_connections(self, internal_output_connections):
        assert(self.output_ports is not None)
        assert(self.dim is not None)
        for ioc in internal_output_connections:
            assert(ioc['port_to'] in self.output_ports)
            assert('component_from' in ioc.keys() and 'port_to' in ioc.keys())
            dims = list(map(lambda x : int(x), ioc['component_from'].split('_')[1:]))
            assert(len(dims) == len(self.dim))
            for i,x in enumerate(dims):
                assert(0 <= x and x < self.dim[i])
        self.internal_output_connections = internal_output_connections

    # Getters
    def get_name(self):
        return self.name

    def get_type(self):
        return self.type

    def get_dim(self):
        return self.dim

    def get_delay(self):
        return self.delay

    def get_default_delay_time(self):
        return self.default_delay_time

    def get_border_type(self):
        return self.border_type

    def get_neighbors(self):
        return self.neighbors

    def get_initial_value(self):
        return self.initial_value

    def get_local_transition(self):
        return self.local_transition

    def get_rules(self):
        return self.rules

    def get_input_ports(self):
        return self.input_ports

    def get_output_ports(self):
        return self.output_ports

    def get_internal_input_connections(self):
        return self.internal_input_connections

    def get_internal_output_connections(self):
        return self.internal_output_connections

    def get_internal_connections(self):
        return self.internal_input_connections + self.internal_output_connections
