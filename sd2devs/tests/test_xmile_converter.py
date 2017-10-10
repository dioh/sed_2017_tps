"""
  Pruebas del modulo
"""
import unittest
import sys
import os
import xml.etree.ElementTree as ET

#sys.path.append('D:\\simu\\sed2017\\tps\\converter\\sd2devs')
#sys.path.append('/Users/pedro/Desktop/SED/SDDEVS/sed_2017_tps/sd2devs')
from . import settings
sys.path.append(settings.PATH)

class TestXmileConverterTeacup(unittest.TestCase):
    '''
    Pruebas del conversor en si
    '''

    def setUp(self):
        xml_model = '<model><variables><flow name="Heat Loss to Room">' + \
                     '<doc>Heat Loss to Room</doc>' + \
                     '<eqn>("Teacup Temperature"-"Room Temperature")' + \
                     '/"Characteristic Time"</eqn>' + \
                     '</flow><aux name="Room Temperature">' + \
                     '<doc>Ambient Room Temperature</doc>' + \
                     '<eqn>70</eqn></aux>' + \
                     '<stock name="Teacup Temperature">' + \
                     '<doc>The average temperature of the tea' + \
                     ' and the cup</doc>' + \
                     '<outflow>"Heat Loss to Room"</outflow>'+ \
                     '<eqn>180</eqn></stock>' + \
                     '<aux name="Characteristic Time">'+ \
                     '<eqn>10</eqn></aux>' + \
                     '</variables></model>'
        self.model_doc = ET.fromstring(xml_model)

    def test_read_xml_file(self):
        '''
        Prueba que pueda abrirse un xml tipo xmile
        '''
        from sd2devs import read_xml
        doc = read_xml('./teacup.xmile')
        self.assertEqual('xmile', doc.getroot().tag)

    def test_model_to_dag(self):
        """
        Transforma un model de xmile en un DAG
        """
        from sd2devs import dag_from_xmile_model

        model_dag = dag_from_xmile_model(self.model_doc)
        self.assertCountEqual(["Room Temperature",   # Cte
                               "Teacup Temperature", # Stock
                               "Characteristic Time",# Cte
                               "Heat Loss to Room"], # Flow
                               model_dag.nodes())
        
        self.assertCountEqual([("Teacup Temperature", "Heat Loss to Room"), # Stock => Flow
                               ("Room Temperature", "Heat Loss to Room"),   # Cte usadas en Flows
                               ("Characteristic Time", "Heat Loss to Room"),
                               ("Heat Loss to Room",  "Teacup Temperature")], # Flows => Stocks
                              model_dag.edges())

    def test_transform_xmile_model_dag_to_devsml_model_dag(self):
        from sd2devs import dag_from_xmile_model, xmile_model_dag_to_devsml
        xmile_model_dag = dag_from_xmile_model(self.model_doc)
        devsml_model_dag = xmile_model_dag_to_devsml(xmile_model_dag)
        
        self.assertEqual(5, devsml_model_dag.number_of_nodes())
        room_temperature_node = devsml_model_dag.nodes['Room Temperature']
        self.assertEqual('ConstantFunction', room_temperature_node['model'])
        self.assertEqual('70', room_temperature_node['default_value'])

        characteristic_time_node = \
            devsml_model_dag.nodes['Characteristic Time']
        self.assertEqual('ConstantFunction', characteristic_time_node['model'])
        self.assertEqual('10', characteristic_time_node['default_value'])

        heat_loss_to_room_node = devsml_model_dag.nodes['Heat Loss to Room']
        self.assertEqual('Function', heat_loss_to_room_node['model'])

        expected_func_str = \
            '("Teacup Temperature"-"Room Temperature")/"Characteristic Time"'
        self.assertEqual(expected_func_str, heat_loss_to_room_node['function'])

        teacup_temp_integ_node = \
            devsml_model_dag.nodes['Teacup Temperature Integrator']
        self.assertEqual('QSS1', teacup_temp_integ_node['model'])

        teacup_temp_flows_adder_node = \
            devsml_model_dag.nodes['Teacup Temperature Flows Adder']
        self.assertEqual('FlowsAdder', teacup_temp_flows_adder_node['model'])
        self.assertEqual(['Heat Loss to Room'],
                         teacup_temp_flows_adder_node['outflows'])
        self.assertCountEqual([], teacup_temp_flows_adder_node['inflows'])

        self.assertCountEqual([("Teacup Temperature Integrator",
                                "Heat Loss to Room"),
                               ("Room Temperature", "Heat Loss to Room"),
                               ("Characteristic Time", "Heat Loss to Room"),
                               ("Heat Loss to Room", 
                               "Teacup Temperature Flows Adder"),
                               ("Teacup Temperature Flows Adder",
                               "Teacup Temperature Integrator")],
                              devsml_model_dag.edges())

    def test_convert_xmile_to_devsml(self):
        """
        Prueba que la conversion de xmile a devsml
        """
        from sd2devs import read_xml, devsml_from_xmile
        from sd2devs import elements_equal, show_first_elements_diff

        expected_doc = read_xml('./teacup-devsml.xml')
        devsml_doc = devsml_from_xmile('./teacup.xmile')

        # TODO: Revisar como validar el documento esperado vs lo obtenido
        # Este metodo falla con tails con datos vacío.
        self.assertTrue(elements_equal(expected_doc.getroot(), devsml_doc),
                        show_first_elements_diff(expected_doc.getroot(),
                                                 devsml_doc))

class TestXmileConverterSIR(unittest.TestCase):
    '''
    Pruebas del conversor en si : SIR
    '''

    def setUp(self):
        xml_model = \
        '<model><variables>' + \
            '<stock name="susceptible">' + \
                '<eqn>total_population</eqn>' + \
                '<outflow>succumbing</outflow>' + \
                '<units>people</units>'  + \
            '</stock>' + \
            '<stock name="infectious">'  + \
                '<eqn>5</eqn>'  + \
                '<inflow>succumbing</inflow>'  + \
                '<outflow>recovering</outflow>'  + \
                '<units>people</units>'  + \
            '</stock>'  + \
            '<stock name="recovered">'  + \
                '<eqn>0</eqn>'  + \
                '<inflow>recovering</inflow>'  + \
                '<units>people</units>'  + \
            '</stock>'  + \
            '<flow name="succumbing">'  + \
                '<eqn>susceptible*infectious/total_population*contact_infectivity</eqn>'  + \
                '<units>person/time</units>'  + \
            '</flow>'  + \
            '<flow name="recovering">'  + \
                '<eqn>infectious/duration</eqn>'  + \
                '<units>person/time</units>'  + \
            '</flow>'  + \
            '<aux name="total_population">'  + \
                '<eqn>1000</eqn>'  + \
                '<units>people</units>'  + \
            '</aux>'  + \
            '<aux name="duration">'  + \
                '<eqn>5</eqn>'  + \
                '<units>days</units>'  + \
            '</aux>'  + \
            '<aux name="contact_infectivity">'  + \
                '<eqn>0.3</eqn>'  + \
            '</aux>'  + \
            '</variables>'  + \
        '</model>'
        self.model_doc = ET.fromstring(xml_model)

    def test_read_xml_file(self):
        '''
        Prueba que pueda abrirse un xml tipo xmile
        '''
        from sd2devs import read_xml
        doc = read_xml('./SIR.xmile')
        self.assertEqual('xmile', doc.getroot().tag)

    def test_model_to_dag(self):
        """
        Transforma un model de xmile en un DAG
        """
        from sd2devs import dag_from_xmile_model

        model_dag = dag_from_xmile_model(self.model_doc)
        
        self.assertCountEqual(["susceptible",
                               "infectious",
                               "recovered",  # Stocks
                               "succumbing",
                               "recovering", # Flows
                               "total_population", # Aux's
                               "duration",
                               "contact_infectivity"], model_dag.nodes())
        
        self.assertCountEqual([("total_population", "succumbing"), # Constantes usadas en flows
                               ("contact_infectivity",  "succumbing"),
                               ("duration", "recovering"),
                               ("susceptible", "succumbing"), # Stocks => flows
                               ("infectious", "succumbing"),
                               ("infectious", "recovering"),
                               ("succumbing", "infectious"), # Flows => Stocks
                               ("recovering", "recovered")],
                              model_dag.edges())















