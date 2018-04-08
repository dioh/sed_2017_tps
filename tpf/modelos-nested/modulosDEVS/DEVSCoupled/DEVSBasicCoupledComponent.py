
from modulosDEVS.DEVSComponent import DEVSComponent

class DEVSBasicCoupledComponent(DEVSComponent):
    ################################################################################
    def __init__(self, xmile_model, root_models, name=None,
                 atomic_components=None, coupled_components=None, 
                 external_input_connections=None, external_output_connections=None, 
                 internal_connections=None,
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
            self.input_ports  = input_ports
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