class CdppModel(object):

    def __init__(self, **kwargs):
        allowed_keys = ['name', 'model', 'in_ports', 'out_ports',
                        'internal_connections',
                        'external_input_connections',
                        'external_output_connections',
                        'components', 'parameters']
        self.name = ''
        self.model = ''
        self.in_ports = set()
        self.out_ports = set()
        self.internal_connections = set()
        self.external_input_connections = set()
        self.external_output_connections = set()
        self.components = set()
        self.parameters = dict()
        # and update the given keys by their given values
        self.__dict__.update((key, value) for key, value
                             in kwargs.items() if key in allowed_keys)

    def __repr__(self):
        return str({'name': self.name,
                    'model': self.model,
                    'in_ports': self.in_ports.__repr__(),
                    'out_ports': self.out_ports.__repr__(),
                    'internal_connections':
                    self.internal_connections.__repr__(),
                    'external_input_connections':
                    self.external_input_connections.__repr__(),
                    'external_output_connections':
                    self.external_output_connections.__repr__(),
                    'components': self.components.__repr__(),
                    'parameters': self.parameters.__repr__()})

    def __eq__(self, other):
        return (self.name == other.name and
                self.model == other.model and
                self.in_ports == other.in_ports and
                self.out_ports == other. out_ports and
                self.internal_connections == other.internal_connections and
                (self.external_input_connections ==
                 other.external_input_connections) and
                (self.external_output_connections ==
                 other.external_output_connections) and
                self.components == other.components and
                self.parameters == other.parameters)

    def __hash__(self):
        return (hash(self.name) ^ hash(self.model))

    @classmethod
    def from_devsml_xml(cls, devsml_xml):
        root = devsml_xml.getroot()
        return cls.extract_model_from_node(root)

    @classmethod
    def extract_model_from_node(cls, node):
        model_name = node.attrib['name']
        #model_parent = node.attrib['parent']
        d = {'name': model_name,
             #'parent': model_parent,
             'model': node.attrib['model'],
             'params': cls.extract_params(node.attrib),
             'in_ports': cls.extract_in_ports(node, model_name),
             'out_ports': cls.extract_out_ports(node, model_name),
             'components': cls.extract_components(node),
             'internal_connections': cls.extract_internal_connections(node),
             'external_input_connections':
             cls.extract_external_input_connections(node, model_name),
             'external_output_connections':
             cls.extract_external_output_connections(node, model_name),
             'parameters':
             cls.extract_parameters(node)}

        return cls(**d)

    @classmethod
    def extract_in_ports(cls, devsml_xml_root, component_name):
        rv = set()
        for in_port in devsml_xml_root.findall('./inputs/input'):
            if (in_port.attrib['type'].lower() == 'in'):
                rv.add(in_port.attrib['name'])

        return rv

    @classmethod
    def extract_out_ports(cls, devsml_xml_root, component_name):
        rv = set()
        for out_port in devsml_xml_root.findall('./outputs/output'):
            if (out_port.attrib['type'].lower() == 'out'):
                rv.add(out_port.attrib['name'])

        return rv

    @classmethod
    def extract_internal_connections(cls, devsml_xml_root):
        rv = set()
        internal_connections_path = './internal_connections/connection'
        internal_connections = devsml_xml_root.findall(
            internal_connections_path)
        for internal_connection in internal_connections:
            attribs = internal_connection.attrib
            connection = CdppConnection(CdppPort(attribs['port_from'],
                                                 attribs['component_from']),
                                        CdppPort(attribs['port_to'],
                                                 attribs['component_to']))
            rv.add(connection)

        return rv

    @classmethod
    def extract_external_input_connections(cls, devsml_xml_root, model_name):
        rv = set()
        internal_connections_path = './external_input_connections/connection'
        internal_connections = devsml_xml_root.findall(
            internal_connections_path)
        for internal_connection in internal_connections:
            attribs = internal_connection.attrib
            connection = CdppConnection(CdppPort(attribs['port_from'],
                                                 model_name),
                                        CdppPort(attribs['port_to'],
                                                 attribs['component_to']))
            rv.add(connection)

        return rv

    @classmethod
    def extract_external_output_connections(cls, devsml_xml_root, model_name):
        rv = set()
        connections_path = './external_output_connections/connection'
        internal_out_connections = devsml_xml_root.findall(
            connections_path)
        for internal_out_connection in internal_out_connections:
            attribs = internal_out_connection.attrib
            connection = CdppConnection(CdppPort(attribs['port_from'],
                                                 attribs['component_from']),
                                        CdppPort(attribs['port_to'],
                                                 model_name))
            rv.add(connection)

        return rv

    @classmethod
    def extract_components(cls, devsml_xml_root):
        rv = set()
        component_paths = ['./components/atomicRef',
                           './components/coupledRef']

        for component_path in component_paths:
            components = devsml_xml_root.findall(component_path)
            for component in components:
                rv.add(cls.extract_model_from_node(component))

        return rv

    @classmethod
    def extract_params(cls, devsml_xml_attribs):
        rv = dict(devsml_xml_attribs)
        del rv['name']
        del rv['model']
        return rv

    @classmethod
    def extract_parameters(cls, devsml_xml_root):
        rv = dict()
        for param in devsml_xml_root.findall('./parameters/parameter'):
            rv[param.attrib['name']] = param.text

        return rv


class CdppPort(object):
    def __init__(self, port, component):
        self.port = port
        self.component = component

    def __repr__(self):
        return str({
            'port': self.port,
            'component': self.component
            })

    def __eq__(self, other):
        return self.port == other.port and \
               self.component == other.component

    def __lt__(self, other):
        return self.component < other.component or \
               (self.component == other.component and
                self.port < other.port)

    def __hash__(self):
        return (hash(self.port) ^ hash(self.component))


class CdppConnection(object):

    def __init__(self, port_from, port_to):
        self.port_from = port_from
        self.port_to = port_to

    def __repr__(self):
        return str({
            'port_from': self.port_from.__repr__(),
            'port_to': self.port_to.__repr__()
            })

    def __eq__(self, other):
        return self.port_from == other.port_from and \
               self.port_to == other.port_to

    def __lt__(self, other):
        return self.port_to < other.port_to or \
               (self.port_to == other.port_to and
                self.port_from < other.port_from)

    def __hash__(self):
        return (hash(self.port_from) ^ hash(self.port_to))
