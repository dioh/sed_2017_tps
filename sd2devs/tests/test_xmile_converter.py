"""
  Pruebas del modulo
"""
import unittest
import sys

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
        doc = read_xml('./tests/teacup.xmile')
        self.assertEqual('{http://docs.oasis-open.org/xmile/ns/XMILE/v1.0}xmile', doc.getroot().tag)
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
