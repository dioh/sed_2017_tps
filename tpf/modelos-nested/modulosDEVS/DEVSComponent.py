

class DEVSComponent(object):
    def __init__(self):
        self.xxx = 'Component'

    def parameters(self):
        return {}


class DEVSAtomicComponent(DEVSComponent):
    def __init__(self):
        self.yyy = 'AtomicComponent'
