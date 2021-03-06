import sys
import os

cwd = os.getcwd()
if cwd not in sys.path:
    sys.path.append( cwd )
from jinja2 import Environment, FileSystemLoader
import xml.etree.ElementTree as etree
import vkbeautify as vkb
from modulosXMILE.Model import *
from DEVSCoupled.DEVSCoupledComponent import DEVSCoupledComponent
from modulosCDPP.cdpp_model import CdppModel
from modulosCDPP.cdpp_model_to_ma_file import CdppModelToMaConverter
from modulosCDPP.preprocessing import preprocessing_devsml_for_ma
import logging


###################################################################################################################
# Configuraciones

###################################################################################################################
def generateHCPP(devsml_top_filename, devsml_cpp_h_directory, cpp_h_templates_filenames, devsml_events_filename,
                 devsml_ma_filename):
    # atomicos = ['DEVSConstant', 'DEVSAux', 'DEVSFplus', 'DEVSFminus', 'DEVSPulse']
    with open( devsml_top_filename, 'r') as xml_file:
        parser = etree.XMLParser( encoding="utf-8" )
        xml_tree = etree.parse( xml_file, parser=parser )
    root = xml_tree.getroot()

    # TODO : parametrizar esto
    PATH = './'
    PATH_TEMPLATES = 'templates'
    TEMPLATE_ENVIRONMENT = Environment( autoescape=False,
        loader=FileSystemLoader( os.path.join( PATH, PATH_TEMPLATES )), trim_blocks=False )

    def render_template(template_filename, context):
        return TEMPLATE_ENVIRONMENT.get_template( template_filename ).render( context )

    # For Reg File
    atomics_names = []

    # DEVSConstant + Events File
    ctes_names_values = []
    template_cte = cpp_h_templates_filenames['DEVSConstant']
    atomic_ctes = filter( lambda x: x.get('model') in ['DEVSConstant'], root.findall('.//atomicRef'))
    for ac in atomic_ctes:
        cte_name = ac.get('name')
        cte_full_name = cte_name + ac.get('parent')
        cte_value = filter( lambda x: x.get('name') == 'value', ac.find('parameters').findall('parameter'))[
            0].text
        atomics_names.append( cte_full_name )

        # TODO : ver esto. Son los casos en los que la Cte esta adentro de nn acoplado, y recibe input proveniente de un Aux de mas arriba
        # Events File
        def is_numeric(text):
            try:
                float( text )
                return True
            except ValueError:
                return False

        if is_numeric( cte_value ):
            ctes_names_values.append( {'cte_name': cte_name, 'cte_value': cte_value} )
        # DEVSConstant
        for extension in ['.h', '.cpp']:
            with open( devsml_cpp_h_directory + cte_full_name + extension, 'w+') as f:
                template_now = template_cte + extension
                f.write( render_template( template_now,
                                          {'cte_name_lower': cte_full_name, 'cte_name_upper': cte_full_name.upper(),
                                           'cte_name' : cte_name,
                                           'input_ports': list( map( lambda x: x.get('name'),
                                                                    ac.find('inputs').findall('input')) ),
                                           'output_ports': list( map( lambda x: x.get('name'),
                                                                     ac.find('outputs').findall(
                                                                         'output')) )} ))
    # events
    with open( devsml_events_filename, 'w+') as f:
        template_now = cpp_h_templates_filenames['events']
        f.write( render_template( template_now, {
            # Para no repetir los inputs de Ctes que vienen de afuera y van hacia adentro de los acoplados
            'ctes_names_values': [dict( tupleized ) for tupleized in
                                  set( tuple( item.items()) for item in ctes_names_values )]} ))

    # DEVSAux
    # DEVSFplus
    # DEVSFminus
    template_aux = cpp_h_templates_filenames['DEVSAux']
    atomic_auxs = filter( lambda x: x.get('model') in ['DEVSAux', 'DEVSFplus', 'DEVSFminus'],
                          root.findall('.//atomicRef'))
    for aa in atomic_auxs:
        aux_name = aa.get('name') + aa.get('parent')
        for extension in ['.h', '.cpp']:
            with open( devsml_cpp_h_directory + aux_name + extension, 'w+') as f:
                template_now = template_aux + extension
                f.write(render_template(template_now, {
                    'aux_name': aa.get('name'),
                    'aux_name_lower': aux_name, 'aux_name_upper': aux_name.upper(),
                    'input_ports': list(map(lambda x: x.get('name'), aa.find('inputs').findall('input'))),
                    'output_ports': list(map(lambda x: x.get('name'), aa.find('outputs').findall('output'))),
                    'equation': aa.find('parameters').find('parameter').text
                }))
        # por ahora el unico parametero posible es 'equation' aca } ))
        atomics_names.append(aux_name)

    # TODO : pasar volume e interval, de la manera correcta
    # DEVSFPulse
    template_pulse = cpp_h_templates_filenames['DEVSPulse']
    atomic_pulses = filter(lambda x : x.get('model') == 'DEVSPulse', root.findall('.//atomicRef'))
    for p in atomic_pulses:
        pulse_name = p.get('name') + p.get('parent')
        for extension in ['.h', '.cpp']:
            with open(devsml_cpp_h_directory + pulse_name + extension, 'w+') as f:
                template_now = template_pulse + extension
                f.write(render_template(template_now, {
                    'pulse_name': p.get('name'),
                    'pulse_name_lower': pulse_name, 'pulse_name_upper': pulse_name.upper(),
                    'output_ports': list(map(lambda x : x.get('name'), p.find('outputs').findall('output'))),
                    'equation': filter(lambda x : x.get('name') == 'equation', p.find('parameters').findall('parameter'))[0].text,
                    'volume_param': filter(lambda x : x.get('name') == 'volume_param', p.find('parameters').findall('parameter'))[0].text,
                    'interval_param': filter(lambda x : x.get('name') == 'interval_param', p.find('parameters').findall('parameter'))[0].text,
                    'volume_input': filter(lambda x : x.get('name') == 'volume_input', p.find('parameters').findall('parameter'))[0].text,
                    'interval_input': filter(lambda x : x.get('name') == 'interval_input', p.find('parameters').findall('parameter'))[0].text
                }))
        atomics_names.append(pulse_name)

    # DEVSFtot
    template_tot = cpp_h_templates_filenames['DEVSFtot']
    atomic_tots = filter( lambda x: x.get('model') in ['DEVSFtot'], root.findall('.//atomicRef'))
    for at in atomic_tots:
        tot_name = at.get('name') + at.get('parent')
        for extension in ['.h', '.cpp']:
            with open(devsml_cpp_h_directory + tot_name + extension, 'w+') as f:
                template_now = template_tot + extension
                f.write(render_template(template_now,
                  {'tot_name' : at.get('name'),
                   'tot_name_lower': tot_name, 'tot_name_upper': tot_name.upper(),
                   'plus_input_ports': list( map( lambda y: y.get('name'), filter(
                          lambda x: x.get('type') == 'in_plus',
                          at.find('inputs').findall('input')))),
                    'minus_input_ports': list( map( lambda y: y.get('name'), filter(
                          lambda x: x.get('type') == 'in_minus',
                          at.find('inputs').findall('input')) )), 'output_ports': list(
                      map( lambda x: x.get('name'),
                           at.find('outputs').findall('output')))}))
        atomics_names.append(tot_name)

    template_integrator = cpp_h_templates_filenames['DEVSIntegrator']
    atomic_integrators = filter(lambda x : x.get('model') in ['DEVSIntegrator'], root.findall('.//atomicRef'))
    for ai in atomic_integrators:
        integrator_name = ai.get('name') + ai.get('parent')
        for extension in ['.h', '.cpp']:
            with open(devsml_cpp_h_directory + integrator_name + extension, 'w+') as f:
                template_now = template_integrator + extension
                f.write(render_template(template_now, {
                    'name_full': integrator_name,
                    'name_full_upper': integrator_name.upper(),
                    'name': ai.get('name')
                }))
        atomics_names.append(integrator_name)

    # Reg File
    template_reg = cpp_h_templates_filenames['reg']
    with open(devsml_cpp_h_directory + 'reg.cpp', 'w+') as f:
        template_now = template_reg
        f.write(render_template(template_now, {'atomics_names': atomics_names}));

    # MA File
    # Preprocessing of DEVSML File
    devs_ml_model = preprocessing_devsml_for_ma(etree.parse(devsml_top_filename))
    # Generation of .ma file
    cdpp_model = CdppModel.from_devsml_xml(devs_ml_model)
    mafile = CdppModelToMaConverter.parse_model(cdpp_model)
    with open(devsml_ma_filename, 'w') as f:
        f.write(str(mafile))

    # fin
    return 0


###################################################################################################################
def generateDEVSML(dir_xmile, devsml_template_filename, devsml_top_filename):
    source_xmlns = "{http://docs.oasis-open.org/xmile/ns/XMILE/v1.0}"
    source_xmlns_isee = "{http://iseesystems.com/XMILE}"
    DEBUG = False

    # TODO : parametrizar esto
    PATH = './'
    PATH_TEMPLATES = 'templates'

    ## Auxiliary functions
    logging.info('PARSING : ' + dir_xmile )
    parser = etree.XMLParser( encoding="utf-8" )
    with open( dir_xmile, 'r') as xml_file:
        xml_tree = etree.parse(xml_file, parser=parser)
    root = xml_tree.getroot()
    models = root.findall(source_xmlns + 'model')
    models_parsed = list(map(lambda x: Model(x, DEBUG), models))
    TEMPLATE_ENVIRONMENT = Environment(autoescape=False,
        loader=FileSystemLoader(os.path.join(PATH, PATH_TEMPLATES)), trim_blocks=False)

    def render_template(template_filename, context):
        return TEMPLATE_ENVIRONMENT.get_template(template_filename).render(context)

    # Code
    for model in models_parsed:
        logging.info('GENERATE MODEL : ' + model.get_name())
    ##
    top_model = models_parsed[0]
    dm = DEVSCoupledComponent( top_model, models_parsed )

    filenames = []

    def traverse(dm):
        name = dm.get_name()
        dst_filename = name

        # Accumulate all names for deleting later
        filenames.append( name )

        ccs = dm.get_coupled_components()
        ccs_names = []

        # Recursion
        for cc in ccs:
            traverse(cc)
            ccs_names.append(cc.get_name())

        # Generate xml
        context = {
            'type': dm.get_type(),
            'coupled_name': name,     
            'coupled_filenames': ccs_names, 
            'atomics': dm.get_atomic_components(),
            'input_ports': dm.get_input_ports(), 'output_ports': dm.get_output_ports(),
            'internal_connections': dm.get_internal_connections(),
            'external_input_connections': dm.get_external_input_connections(),
            'external_output_connections': dm.get_external_output_connections()}
        coupled_xml = render_template(devsml_template_filename, context)

        # Cargo los 'include' del modelo
        from xml.etree import ElementTree as et
        tree = et.fromstring( coupled_xml )
        includes = tree.findall('.//include')

        for include in includes:
            include_filename = include.get('filename')
            include_tree = et.parse( include_filename )

            for element in tree.iter():
                if element.tag == 'include' and element.get('filename') == include_filename:
                    tree.find('components').append(include_tree.getroot())

        tree2 = et.tostring(tree)
        with open(dst_filename, 'wb') as f:
            f.write(tree2)

    traverse( dm )

    # Pretty print
    with open('DEVS_COUPLED_top', 'r') as xml_file_new:
        parser = etree.XMLParser(encoding="utf-8")
        xml_tree_new = etree.parse(xml_file_new, parser=parser)
    root = xml_tree_new.getroot()

    # Erase includes
    for elem in root.iter():
        for child in list(elem):
            if child.tag == 'include':
                elem.remove(child)
    x = etree.tostring(root)
    vkb.xml(x, devsml_top_filename)

    # Erase unneeded files
    for filename in filenames:
        os.remove(filename)
