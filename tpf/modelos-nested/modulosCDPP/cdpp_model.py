class CdppModel(object):

    def __init__(self, **kwargs):
        allowed_keys = ['name', 'in_ports', 'out_ports']
        self.name = ''
        self.in_ports = set()
        self.out_ports = set()
        # and update the given keys by their given values
        self.__dict__.update((key, value) for key, value
                             in kwargs.items() if key in allowed_keys)

    @classmethod
    def from_devsml_xml(cls, devsml_xml):
        root = devsml_xml.getroot()
        d = dict()
        d['name'] = root.attrib['name']
        d['in_ports'] = cls.extract_in_ports(root, d['name'])
        d['out_ports'] = cls.extract_out_ports(root, d['name'])
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
