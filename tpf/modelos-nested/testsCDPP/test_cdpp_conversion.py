"""
  Pruebas del modulo
"""
import unittest
import xml.etree.ElementTree as ET
import os
from modulosCDPP import *


class TestXmileConverterTeacup(unittest.TestCase):
    '''
    Pruebas del conversor de DEVSML a CDPP
    '''

    def setUp(self):
        self.devs_ml_model = ET.parse('./testsCDPP/model.xml')

    def test_model_name(self):
        model = CdppModel.from_devsml_xml(self.devs_ml_model)
        self.assertEqual('DEVS_COUPLED_top', model.name)

    def test_model_in_ports(self):
        expected_ports = set(['paramA', 'paramB', 'paramC',
                              'cteVariable', 'paramD'])
        model = CdppModel.from_devsml_xml(self.devs_ml_model)
        self.assertSetEqual(expected_ports, model.in_ports)

    def test_model_out_ports(self):
        expected_ports = set(['auxVariable', 'paramE', 'hunter',
                              'Predator', 'Prey', 'PreySubModelStock',
                              'PreySubSubModelStock'])

        model = CdppModel.from_devsml_xml(self.devs_ml_model)
        self.assertSetEqual(expected_ports, model.out_ports)

    def test_model_internal_connections(self):
        expected_conns = set([CdppConnection(CdppPort("paramC", "paramC"),
                                             CdppPort("paramC", "paramC"))])
        model = CdppModel.from_devsml_xml(self.devs_ml_model)
        self.assertSetEqual(expected_conns, model.internal_connections)


if __name__ == '__main__':
    unittest.main()
