class CdppModel(object):

    def __init__(self, **kwargs):
        allowed_keys = ['name', 'in_ports', 'out_ports',
                        'internal_connections',
                        'external_input_connections',
                        'external_output_connections']
        self.name = ''
        self.in_ports = set()
        self.out_ports = set()
        self.internal_connections = set()
        self.external_input_connections = set()
        self.external_output_connections = set()
        # and update the given keys by their given values
        self.__dict__.update((key, value) for key, value
                             in kwargs.items() if key in allowed_keys)

    @classmethod
    def from_devsml_xml(cls, devsml_xml):
        root = devsml_xml.getroot()
        model_name = root.attrib['name']
        d = {'name': root.attrib['name'],
             'in_ports': cls.extract_in_ports(root, model_name),
             'out_ports': cls.extract_out_ports(root, model_name),
             'internal_connections': cls.extract_internal_connections(root),
             'external_input_connections':
             cls.extract_external_input_connections(root, model_name),
             'external_output_connections':
             cls.extract_external_output_connections(root, model_name)}

        return cls(**d)

    @classmethod
    def extract_in_ports(cls, devsml_xml_root, component_name):
        rv = set()
        for in_port in devsml_xml_root.findall('./inputs/input'):
            if (in_port.attrib['component'] == component_name and
               in_port.attrib['type'].lower() == 'in'):
                rv.add(in_port.attrib['name'])

        return rv

    @classmethod
    def extract_out_ports(cls, devsml_xml_root, component_name):
        rv = set()
        for out_port in devsml_xml_root.findall('./outputs/output'):
            if (out_port.attrib['component'] == component_name and
               out_port.attrib['type'].lower() == 'out'):
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
        internal_connections_path = './external_output_connections/connection'
        internal_connections = devsml_xml_root.findall(
            internal_connections_path)
        for internal_connection in internal_connections:
            attribs = internal_connection.attrib
            connection = CdppConnection(CdppPort(attribs['port_from'],
                                                 attribs['component_from']),
                                        CdppPort(attribs['port_to'],
                                                 model_name))
            rv.add(connection)
        
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

    def __hash__(self):
        return (hash(self.port_from) ^ hash(self.port_to))

