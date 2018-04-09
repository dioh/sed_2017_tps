
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
