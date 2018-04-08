from modulosXMILE.Equation import Equation


class Aux(object):
    def __init__(self, aux_element, source_xmlns, parent, debug):
        self.debug = debug
        self.parent = parent
        self.source_xmlns = source_xmlns
        self.aux_element = aux_element
        self.name = self.set_name()
        self.equation = self.set_equation()
        self.access = self.set_access()

    def __repr__(self):
        return str({
            'parent': self.parent,
            'name': self.name,
            'equation': self.equation,
            'access': self.access
        })

    def __str__(self):
        return str({
            'parent': self.parent,
            'name': self.name,
            'equation': self.equation,
            'access': self.access
        })

    def get_parent(self):
        return self.parent

    def set_name(self):
        name = self.aux_element.get('name')
        if name is None:
            raise Exception('Error: todos los auxs deben tener nombre')
        return name

    def get_name(self):
        return self.name

    def set_access(self):
        access = self.aux_element.get('access')
        if access is None:
            return None
        if self.debug:
            print('El aux ' + self.parent + '.' + self.name + ' es de acceso tipo ' + access)
        return access

    def get_access(self):
        return self.access

    def set_equation(self):
        try:
            equation = self.aux_element.find(self.source_xmlns + 'eqn').text
            if equation == '':
                raise Exception('Error: hay una ecuacion definida sin ningun simbolo (invalida) en ' + self.name)
        except:
            print('aux_element: {0}'.format(aux_element))
            print('equation: {0}'.format(equation))
        return Equation(equation, self.debug)

    def get_equation(self):
        return self.equation

    def get_equation_variables(self):
        return self.equation.get_variables()