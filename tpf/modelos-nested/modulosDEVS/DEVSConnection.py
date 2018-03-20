
class DEVSConnection(object):
    def __init__(self, x):
        self.x = x
class DEVSInternalConnection(DEVSConnection):
    def __init__(self, x):
        self.x = x
class DEVSExternalConnection(DEVSConnection):
    def __init__(self, x):
        self.x = x