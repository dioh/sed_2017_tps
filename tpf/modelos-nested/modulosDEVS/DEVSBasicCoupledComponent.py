
from modulosDEVS.DEVSComponent import *

class DEVSBasicCoupledComponent(DEVSComponent):
    ################################################################################
    def __init__(self, xmile_model, root_models, name=None,
                 atomic_components=None, coupled_components=None, 
                 external_input_connections=None, external_output_connections=None, 
                 internal_connections=None,
                 input_ports=None, output_ports=None):
        self.xmile_model = xmile_model
        self.root_models = root_models
        self.type = 'DEVSBasicCoupledComponent'
        if name is not None:
            self.name = name
        else:
            self.name = 'DEVS_BASIC_COUPLED_' + self.xmile_model.getName()
        
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
    def getType(self):
        return self.type
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
    def getDEVSInputPorts(self):
        return self.input_ports
    def getDEVSOutputPorts(self):
        return self.output_ports