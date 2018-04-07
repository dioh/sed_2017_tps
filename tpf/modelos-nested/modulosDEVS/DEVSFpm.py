
from modulosDEVS.DEVSAtomicComponent import DEVSAtomicComponent
from modulosDEVS.DEVSPort import DEVSPort

PLUS_INDEX = 0
MINUS_INDEX = 1
###############################################################


class DEVSFpm(DEVSAtomicComponent):
    def __init__(self, xmile_flow, xmile_stocks, parent_name):
        self.xmile_flow = xmile_flow
        self.xmile_stocks = xmile_stocks
        self.parent = parent_name
        self.equation = self.xmile_flow.get_equation()
        self.corresponding_stock_names_plus_minus = self.set_corresponding_stocks()
        self.fp = self.set_fplus()
        self.fm = self.set_fminus()
        self.name = xmile_flow.get_name()

    def __repr__(self):
        return str({
            'name': self.name,
            'equation': self.equation
        })

    def __str__(self):
        return str({
            'name': self.name,
            'equation': self.equation
        })

    def get_fplus(self):
        return self.fp

    def get_fminus(self):
        return self.fm

    def set_corresponding_stocks(self):
        flow_name = self.xmile_flow.get_name()
        corresponding_stock_name_plus = None
        corresponding_stock_name_minus = None

        # ver si flow_name esta entre los inflows/outflows 
        # de algun stock - puede ser inflow/outflow de 0 o 1 stock solamente -
        for stock in self.xmile_stocks:
            if flow_name in list(map(lambda x: x.get_name(),
                                     stock.get_inflows())):
                corresponding_stock_name_plus = stock.get_name()
            if flow_name in list(map(lambda x: x.get_name(),
                                     stock.get_outflows())):
                corresponding_stock_name_minus = stock.get_name()

        return corresponding_stock_name_plus, corresponding_stock_name_minus

    def set_fplus(self):
        corresponding_stock_name_plus = self.corresponding_stock_names_plus_minus[PLUS_INDEX]
        if corresponding_stock_name_plus is None:
            return None
        return DEVSFplus(self.xmile_flow, corresponding_stock_name_plus, self.parent)

    def set_fminus(self):
        corresponding_stock_name_minus = self.corresponding_stock_names_plus_minus[MINUS_INDEX]
        if corresponding_stock_name_minus is None:
            return None
        return DEVSFminus(self.xmile_flow, corresponding_stock_name_minus, self.parent)

    def parameters(self):
        return {'equation': self.equation.get_equation()}
###############################################################


class DEVSFminus(DEVSFpm):
    def __init__(self, xmile_flow, stock_name, parent_name):
        self.xmile_flow = xmile_flow
        self.stock_name = stock_name
        self.parent = parent_name
        self.name = self.set_name()
        self.equation = self.xmile_flow.get_equation()
        self.input_ports = self.set_input_ports()
        self.output_ports = [DEVSPort(self.name, self, 'out')]
        self.type = 'DEVSFminus'

    def __repr__(self):
        return str({
            'name': self.name,
            'equation': self.equation,
            'input_ports': self.input_ports,
            'output_ports': self.output_ports,
            'type': self.type
        })

    def __str__(self):
        return str({
            'name': self.name,
            'equation': self.equation,
            'input_ports': self.input_ports,
            'output_ports': self.output_ports,
            'type': self.type
        })

    def set_input_ports(self):
        input_ports = []
        variables = self.equation.get_variables()
        for var in variables:
            input_ports.append(DEVSPort(var, self, 'in'))
        # Agrego inputs correspondientes a funciones especiales
        for special_func_obj in self.equation.get_special_functions(self.parent):
            input_ports.append(DEVSPort(special_func_obj.get_name(),
                                        self, 'in'))
        return list(set(input_ports))

    def set_name(self):
        return self.xmile_flow.get_name() + '_' + self.stock_name

    def get_name(self):
        return self.name

    def get_parent_name(self):
        return self.parent

    def get_type(self):
        return self.type

    def get_equation(self):
        return self.equation

    def get_input_ports(self):
        return self.input_ports

    def get_output_ports(self):
        return self.output_ports
###############################################################


class DEVSFplus(DEVSFpm):
    def __init__(self, xmile_flow, stock_name, parent_name):
        self.xmile_flow = xmile_flow
        self.stock_name = stock_name
        self.parent = parent_name
        self.name = self.set_name()
        self.equation = self.xmile_flow.get_equation()
        self.input_ports = self.set_input_ports()
        self.output_ports = [DEVSPort(self.name, self, 'out')]
        self.type = 'DEVSFplus'

    def __repr__(self):
        return str({
            'name': self.name,
            'equation': self.equation,
            'input_ports': self.input_ports,
            'output_ports': self.output_ports,
            'type': self.type
        })

    def __str__(self):
        return str({
            'name': self.name,
            'equation': self.equation,
            'input_ports': self.input_ports,
            'output_ports': self.output_ports,
            'type': self.type
        })

    def set_input_ports(self):
        input_ports = []
        variables = self.equation.get_variables()
        for var in variables:
            input_ports.append(DEVSPort(var, self, 'in'))
        # Agrego inputs correspondientes a funciones especiales
        for special_func_obj in self.equation.get_special_functions(self.parent):
            input_ports.append(DEVSPort(special_func_obj.get_name(),
                                        self, 'in'))
        return list(set(input_ports))

    def set_name(self):
        return self.xmile_flow.get_name() + '_' + self.stock_name

    def get_name(self):
        return self.name

    def get_parent_name(self):
        return self.parent

    def get_type(self):
        return self.type

    def get_equation(self):
        return self.equation

    def get_input_ports(self):
        return self.input_ports

    def get_output_ports(self):
        return self.output_ports
