"""
  Pruebas del modulo
"""
import unittest
import sys
import os
import xml.etree.ElementTree as ET

sys.path.append('D:\\simu\\sed2017\\tps\\converter\\sd2devs')

class TestXmileConverter(unittest.TestCase):
    '''
    Pruebas del conversor en si
    '''

    def setUp(self):      
        xml_model = '<model><variables><flow name="Heat Loss to Room"><doc>Heat Loss to Room</doc><eqn>("Teacup Temperature"-"Room Temperature")/"Characteristic Time"</eqn></flow><aux name="Room Temperature"><doc>Ambient Room Temperature</doc><eqn>70</eqn></aux><stock name="Teacup Temperature"><doc>The average temperature of the tea and the cup</doc><outflow>"Heat Loss to Room"</outflow><eqn>180</eqn></stock><aux name="Characteristic Time"><eqn>10</eqn></aux></variables></model>'
        self.model_doc = ET.fromstring(xml_model)

    def test_read_xml_file(self):
        '''
        Prueba que pueda abrirse un xml tipo xmile
        '''
        from sd2devs import read_xml
        doc = read_xml('./tests/teacup.xmile')
        self.assertEqual('xmile', doc.getroot().tag)

    def test_model_to_dag(self):
        """
        Transforma un model de xmile en un DAG
        """
        from sd2devs import dag_from_xmile_model

        model_dag = dag_from_xmile_model(self.model_doc)
        self.assertCountEqual(["Room Temperature", "Teacup Temperature", "Characteristic Time", "Heat Loss to Room"], model_dag.nodes())
        
        self.assertCountEqual([("Teacup Temperature", "Heat Loss to Room"), ("Room Temperature","Heat Loss to Room"), ("Characteristic Time", "Heat Loss to Room"), ("Heat Loss to Room",  "Teacup Temperature")], model_dag.edges())

    def test_transform_xmile_model_dag_to_devsml_model_dag(self):
        from sd2devs import dag_from_xmile_model, xmile_model_dag_to_devsml
        xmile_model_dag = dag_from_xmile_model(self.model_doc)
        devsml_model_dag = xmile_model_dag_to_devsml(xmile_model_dag)
        
        self.assertEqual(5,devsml_model_dag.number_of_nodes())
        self.assertEqual('ConstantFunction', devsml_model_dag.nodes['Room Temperature']['model'])
        self.assertEqual('70', devsml_model_dag.nodes['Room Temperature']['default_value'])
        self.assertEqual('ConstantFunction', devsml_model_dag.nodes['Characteristic Time']['model'])
        self.assertEqual('10', devsml_model_dag.nodes['Characteristic Time']['default_value'])
        self.assertEqual('Function', devsml_model_dag.nodes['Heat Loss to Room']['model'])
        self.assertEqual('("Teacup Temperature"-"Room Temperature")/"Characteristic Time"', devsml_model_dag.nodes['Heat Loss to Room']['function'])
        self.assertEqual('QSS1', devsml_model_dag.nodes['Teacup Temperature Integrator']['model'])
        self.assertEqual('FlowsAdder', devsml_model_dag.nodes['Teacup Temperature Flows Adder']['model'])
        self.assertEqual(['Heat Loss to Room'], devsml_model_dag.nodes['Teacup Temperature Flows Adder']['outflows'])
        self.assertCountEqual([], devsml_model_dag.nodes['Teacup Temperature Flows Adder']['inflows'])

        self.assertCountEqual([("Teacup Temperature Integrator", "Heat Loss to Room"), ("Room Temperature","Heat Loss to Room"), ("Characteristic Time", "Heat Loss to Room"), ("Heat Loss to Room",  "Teacup Temperature Flows Adder"),("Teacup Temperature Flows Adder","Teacup Temperature Integrator")], devsml_model_dag.edges())

    def test_convert_xmile_to_devsml(self):
        """
        Prueba que la conversion de xmile a devsml
        """
        from sd2devs import read_xml, devsml_from_xmile, elements_equal,show_first_elements_diff

        expected_doc = read_xml('./tests/teacup-devsml.xml')
        devsml_doc = devsml_from_xmile('./tests/teacup.xmile')

        #TODO: Revisar como validar el documento esperado vs lo obtenido
        #Este metodo falla con tails con datos vacío.
        self.assertTrue(elements_equal(expected_doc.getroot(), devsml_doc),show_first_elements_diff(expected_doc.getroot(), devsml_doc))    
    
    def test_convert_devsml_to_ma_file(self):
        """
        Prueba la conversion de devsml a archivo .ma de CD++
        """
        self.fail('Not implemented')
