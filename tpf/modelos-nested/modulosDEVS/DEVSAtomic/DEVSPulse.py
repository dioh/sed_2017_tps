
from modulosDEVS.DEVSPort import DEVSPort
from modulosDEVS.DEVSAtomic.DEVSAtomicComponent import DEVSAtomicComponent


class DEVSPulse(DEVSAtomicComponent):
    def __init__(self, volume, first_pulse, interval):
        # TODO : llamar constructor del parent : in Python 2 use super(DEVSPulse, self).__init__()
        self.volume = volume
        self.first_pulse = first_pulse
        self.interval = interval
        self.name = self.set_name()
        self.input_ports = self.set_input_ports()
        self.output_ports = self.set_output_ports()
        self.equation = self.set_equation()
        self.type = 'DEVSPulse'
        self.parent = None

    def __repr__(self):
        return str({
            'name': self.name,
            'volume': self.volume,
            'first_pulse': self.first_pulse,
            'interval': self.interval
        })

    def __str__(self):
        return str({
            'name': self.name,
            'volume': self.volume,
            'first_pulse': self.first_pulse,
            'interval': self.interval
        })

    # Setters
    def set_parent(self, parent_name):
        self.parent = parent_name

    def set_equation(self):
        from modulosXMILE.Equation import Equation
        return Equation(str(self.volume), False)

    def set_name(self):
        # Nota : Reemplazamos el '.' de los floats por un '_'
        vol_name = 'V_' + str(self.volume).replace('.', '_')
        first_pulse_name = 'FP_' + str(self.first_pulse).replace('.', '_')
        interval_name = 'I_' + str(self.interval).replace('.', '_')
        name = 'PULSE_' + vol_name + '_' + first_pulse_name + '_' + interval_name
        return name

    def set_input_ports(self):
        # los correspondientes a las variables que se utilizen como parametro de la funcion
        input_ports = []
        try:
            # no es una variable alfanumerica (es numerica) => no debe entrar ese valor por input
            float(self.volume)
        except ValueError:
            input_ports.append(DEVSPort(self.volume, self, 'in'))
        try:
            float(self.first_pulse)
        except ValueError:
            input_ports.append(DEVSPort(self.first_pulse, self, 'in'))
        try:
            float(self.interval)
        except ValueError:
            input_ports.append(DEVSPort(self.interval, self, 'in'))
        return input_ports

    def set_output_ports(self):
        # el nombre de esta funcion
        return [DEVSPort(self.name, self, 'out')]

    # Getters
    # devuelve todo lo que sea numerico (int's, float's)
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

    def get_parameters(self):
        return self.equation.get_parameters()

    # devuelve todo lo que sea alfanumerico
    def get_variables(self):
        return self.equation.get_variables()

    def parameters(self):
        return {'equation': self.equation.get_equation()}