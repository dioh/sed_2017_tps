"""
Convertir un archivo devsml en un ma
"""

from .xml_utils import read_xml


def get_component_model_name(name, devsml_model):
    """
    Obtiene el nombre del modelo de acuerdo a su nombre y modelo en devsml
    """
    if devsml_model == 'Function':
        return name.replace(' ', '') + devsml_model
    elif devsml_model == 'Flows Adder':
        return name.replace(' ', '')
    else:
        return devsml_model


def get_component_name(raw_name):
    """
    Obtiene el nombre del componente en el ma a partir del nombre en devsml
    """
    return raw_name.lower().replace(' ', '-')


def element_components(top_element):
    """
    Obtiene el string de componentes del elemento pasado como parametros
    """

    components_element = top_element.find('.//components')
    components = []

    for component in components_element:
        name = get_component_name(component.attrib['name'])
        model = get_component_model_name(component.attrib['name'],
                                         component.attrib['model'])
        components.append(name + '@' + model)

    return ['components : ' + ' '.join(components)]


def element_inputs(top_element):
    """
    Devuelve la lista de string de in del ma
    """
    inputs_element = top_element.find('.//inputs')

    inputs = []

    for input_elem in inputs_element:
        inputs.append(get_top_port_name(input_elem.attrib['name']))

    return ['in : ' + ' '.join(inputs)]


def get_top_port_name(raw_name):
    """
    Devuelve el nombre del puerto para el ma
    """
    return 'in' + raw_name.replace(' ', '-')


def element_outputs(top_element):
    """
    Devuelve la lista de string de in del ma
    """
    outputs_element = top_element.find('.//outputs')

    outputs = []

    for output_elem in outputs_element:
        name = output_elem.attrib['name'].replace(' ', '-')
        outputs.append(name)

    return ['out : ' + ' '.join(outputs)]


def get_component_port_name(raw_name):
    return raw_name.replace(' ', '-').lower()


def get_component_port(component_raw_name,
                       component_raw_port,
                       top_element_name,
                       direction):
    component_name = get_component_name(component_raw_name)
    port_name = get_component_port_name(component_raw_port)
    if top_element_name == component_name:
        if direction == 'from':
            return get_top_port_name(component_raw_port)
        elif direction == 'to':
            return get_top_port_name(component_raw_port)
        else:
            return 'BAD_PORT_DEFINTION'
    else:
        if direction == 'from' or direction == 'to':
            return (get_component_port_name(component_raw_port) +
                    '@' +
                    get_component_name(component_raw_name))
        else:
            return 'BAD_PORT_DEFINTION'


def element_links(top_element):
    """
    Devuelve la lista de string de in del ma
    """
    top_element_name = get_component_name(top_element.attrib['name'])
    internal_connections_element = top_element.find('.//internal_connections')

    links = []

    for internal_connection_elem in internal_connections_element:
        link_str = 'link : '
        connection_attribs = internal_connection_elem.attrib
        link_str = ('link : ' +
                    get_component_port(connection_attribs['component_from'],
                                       connection_attribs['from_port'],
                                       top_element_name,
                                       'from') +
                    ' ' +
                    get_component_port(connection_attribs['component_to'],
                                       connection_attribs['to_port'],
                                       top_element_name,
                                       'to'))
        links.append(link_str)

    return (links)


def get_component_parameters(component):
    parameters = []
    for parameter in component.findall('.//parameter'):
        parameters.append(parameter.attrib['name'] +
                          ' : ' +
                          parameter.attrib['value'])

    return parameters


def components_config(top_element):
    components_element = top_element.find('.//components')
    components = []

    for component in components_element:
        name = get_component_name(component.attrib['name'])
        parameters = get_component_parameters(component)

        components.append('['+name+']')
        components = components + parameters
        components.append('')

    return components


def devsml_to_ma(doc):
    """
    Genera un dag del devsml
    """

    top_element = doc.find('.//coupled[@name=\'top\']')
    if top_element is None:
        return ''
    else:
        ma_str = ['[top]']
        ma_str = ma_str + element_components(top_element)
        ma_str = ma_str + element_inputs(top_element)
        ma_str = ma_str + element_outputs(top_element)
        ma_str = ma_str + element_links(top_element)
        ma_str = ma_str + components_config(top_element)
        return ma_str


def ma_from_devsml_file(filename):
    """
    Crea un doc devsml a partir de un doc xmile
    """
    doc = read_xml(filename)
    return devsml_to_ma(doc)
