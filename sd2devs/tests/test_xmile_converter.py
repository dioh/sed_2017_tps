"""
  Pruebas del modulo
"""
import unittest
import sys
import os

sys.path.append('D:\\simu\\sed2017\\tps\\converter\\sd2devs')

class TestXmileConverter(unittest.TestCase):
    '''
    Pruebas del conversor en si
    '''
    def test_read_xml_file(self):
        '''
        Prueba que pueda abrirse un xml tipo xmile
        '''
        from sd2devs import read_xml
        doc = read_xml('./sd2devs/tests/teacup.xmile')
        self.assertEqual('{http://docs.oasis-open.org/xmile/ns/XMILE/v1.0}xmile', doc.getroot().tag)

    def test_model_to_dag(self):
        """
        Transforma un model de xmile en un DAG
        """
        from sd2devs import dag_from_xmile_model
        import xml.etree.ElementTree as ET

        xml_model = '<model><variables><flow name="Heat Loss to Room"><doc>Heat Loss to Room</doc><eqn>("Teacup Temperature"-"Room Temperature")/"Characteristic Time"</eqn></flow><aux name="Room Temperature"><doc>Ambient Room Temperature</doc><eqn>70</eqn></aux><stock name="Teacup Temperature"><doc>The average temperature of the tea and the cup</doc><outflow>"Heat Loss to Room"</outflow><eqn>180</eqn></stock><aux name="Characteristic Time"><eqn>10</eqn></aux></variables></model>'
        model_doc = ET.fromstring(xml_model)
        model_dag = dag_from_xmile_model(model_doc)
        self.assertCountEqual(["Heat Loss to Room","Room Temperature","Teacup Temperature","Characteristic Time"], model_dag.nodes())

    def test_convert_xmile_to_devsml(self):
        """
        Prueba que la conversion de xmile a devsml
        """
        self.fail('Not implemented')
    def test_convert_devsml_to_ma_file(self):
        """
        Prueba la conversion de devsml a archivo .ma de CD++
        """
        self.fail('Not implemented')
