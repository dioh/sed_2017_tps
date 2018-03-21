
PLUS_INDEX  = 0
MINUS_INDEX = 1

class DEVSFpm(object):
    def __init__(self, xmile_flow, xmile_stocks):
        self.xmile_flow   = xmile_flow
        self.xmile_stocks = xmile_stocks
        self.equation     = self.xmile_flow.getEquation()
        self.corresponding_stock_names_plus_minus = self.setCorrespondingStocks()
        self.fp = self.setFPlus()
        self.fm = self.setFMinus()

    def __repr__(self):
        return str({
            'name' : self.name,
            'equation' : self.equation,
            'input_ports' : self.input_ports,
            'output_ports' : self.output_ports
        })
    def __str__(self):
        return str({
            'name' : self.name,
            'equation' : self.equation,
            'input_ports' : self.input_ports,
            'output_ports' : self.output_ports
        })

    def getFPlus(self):
        return self.fp
    def getFMinus(self):
        return self.fm

    def setCorrespondingStocks(self):
        flow_name = self.xmile_flow.getName()
        corresponding_stock_name_plus  = None
        corresponding_stock_name_minus = None

        # ver si flow_name esta entre los inflows/outflows de algun stock - puede ser inflow/outflow de 0 o 1 stock solamente -
        for stock in self.xmile_stocks:
            if flow_name in list(map(lambda x : x.getName(), stock.getInflows())):
                corresponding_stock_name_plus = stock.getName()
            if flow_name in list(map(lambda x : x.getName(), stock.getOutflows())):
                corresponding_stock_name_minus = stock.getName()

        return corresponding_stock_name_plus, corresponding_stock_name_minus

    def setFPlus(self):
        corresponding_stock_name_plus = self.corresponding_stock_names_plus_minus[PLUS_INDEX]
        if corresponding_stock_name_plus is None:
            return None
        return DEVSFplus(self.xmile_flow, corresponding_stock_name_plus)

    def setFMinus(self):
        corresponding_stock_name_minus = self.corresponding_stock_names_plus_minus[MINUS_INDEX]
        if corresponding_stock_name_minus is None:
            return None
        return DEVSFminus(self.xmile_flow, corresponding_stock_name_minus)

class DEVSFminus(DEVSFpm):
    def __init__(self, xmile_flow, stock_name):
        self.xmile_flow = xmile_flow
        self.stock_name = stock_name
        self.equation   = self.xmile_flow.getEquation()
        self.input_ports  = self.xmile_flow.getEquationVariables()
        self.output_ports = ['out']
        self.name = self.setName()
        self.type = 'Fminus'

    def __repr__(self):
        return str({
            'name' : self.name,
            'equation' : self.equation,
            'input_ports' : self.input_ports,
            'output_ports' : self.output_ports
        })

    def __str__(self):
        return str({
            'name' : self.name,
            'equation' : self.equation,
            'input_ports' : self.input_ports,
            'output_ports' : self.output_ports
        })

    def setName(self):
        return 'minus_' + self.xmile_flow.getName() + '_' + self.stock_name

    def getName(self):
        return self.name

    def getType(self):
        return self.type

class DEVSFplus(DEVSFpm):
    def __init__(self, xmile_flow, stock_name):
        self.xmile_flow = xmile_flow
        self.stock_name = stock_name
        self.equation   = self.xmile_flow.getEquation()
        self.input_ports  = self.xmile_flow.getEquationVariables()
        self.output_ports = ['out']
        self.name = self.setName()
        self.type = 'Fplus'

    def __repr__(self):
        return str({
            'name' : self.name,
            'equation' : self.equation,
            'input_ports' : self.input_ports,
            'output_ports' : self.output_ports
        })

    def __str__(self):
        return str({
            'name' : self.name,
            'equation' : self.equation,
            'input_ports' : self.input_ports,
            'output_ports' : self.output_ports
        })

    def setName(self):
        return 'plus_' + self.xmile_flow.getName() + '_' + self.stock_name

    def getName(self):
        return self.name

    def getType(self):
        return self.type
    