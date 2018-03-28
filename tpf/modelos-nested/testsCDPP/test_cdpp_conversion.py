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
        expected_conns = set()
        expected_conns.add(CdppConnection(CdppPort("paramC", "paramC"),
                                          CdppPort("paramC", "paramC")))

        expected_conns.add(CdppConnection(CdppPort("paramA", "paramA"),
                                          CdppPort("paramA", "paramA")))
        expected_conns.add(CdppConnection(CdppPort("paramD", "paramD"),
                                          CdppPort("paramD", "paramD")))
        expected_conns.add(CdppConnection(CdppPort("paramB", "paramB"),
                                          CdppPort("paramB", "paramB")))
        expected_conns.add(
            CdppConnection(CdppPort("paramD", "paramD"),
                           CdppPort("paramD",
                                    "DEVS_COUPLED_PredatorModel")))
        expected_conns.add(
            CdppConnection(CdppPort("paramC", "paramC"),
                           CdppPort("paramC",
                                    "DEVS_COUPLED_PredatorModel")))
        expected_conns.add(CdppConnection(CdppPort("paramA", "paramA"),
                                          CdppPort("paramA",
                                                   "DEVS_COUPLED_PreyModel")))
        expected_conns.add(CdppConnection(CdppPort("paramB", "paramB"),
                                          CdppPort("paramB",
                                                   "DEVS_COUPLED_PreyModel")))
        model = CdppModel.from_devsml_xml(self.devs_ml_model)
        self.assertSetEqual(expected_conns, model.internal_connections)

    def test_model_external_input_connections(self):
        expected_conns = set()
        expected_conns.add(CdppConnection(CdppPort("paramA",
                                                   "DEVS_COUPLED_top"),
                                          CdppPort("paramA", "paramA")))
        expected_conns.add(CdppConnection(CdppPort("paramB",
                                                   "DEVS_COUPLED_top"),
                                          CdppPort("paramB", "paramB")))
        expected_conns.add(CdppConnection(CdppPort("paramC",
                                                   "DEVS_COUPLED_top"),
                                          CdppPort("paramC", "paramC")))
        expected_conns.add(CdppConnection(CdppPort("paramD",
                                                   "DEVS_COUPLED_top"),
                                          CdppPort("paramD", "paramD")))
        expected_conns.add(CdppConnection(
                            CdppPort("cteVariable",
                                     "DEVS_COUPLED_top"),
                            CdppPort("cteVariable",
                                     "DEVS_COUPLED_PredatorModel")))

        model = CdppModel.from_devsml_xml(self.devs_ml_model)
        self.assertSetEqual(expected_conns, model.external_input_connections)

    def test_model_external_output_connections(self):
        expected_conns = set()
        expected_conns.add(CdppConnection(CdppPort("paramE", "paramE"),
                                          CdppPort("paramE",
                                                   "DEVS_COUPLED_top")))
        expected_conns.add(
            CdppConnection(CdppPort("Predator",
                                    "DEVS_COUPLED_PredatorModel"),
                           CdppPort("Predator",
                                    "DEVS_COUPLED_top")))

        expected_conns.add(CdppConnection(
                            CdppPort("auxVariable",
                                     "DEVS_COUPLED_PredatorModel"),
                            CdppPort("auxVariable", "DEVS_COUPLED_top")))

        expected_conns.add(CdppConnection(CdppPort("Prey",
                                                   "DEVS_COUPLED_PreyModel"),
                                          CdppPort("Prey",
                                                   "DEVS_COUPLED_top")))

        expected_conns.add(CdppConnection(CdppPort("PreySubSubModelStock",
                                                   "DEVS_COUPLED_PreyModel"),
                                          CdppPort("PreySubSubModelStock",
                                                   "DEVS_COUPLED_top")))

        expected_conns.add(CdppConnection(CdppPort("PreySubModelStock",
                                                   "DEVS_COUPLED_PreyModel"),
                                          CdppPort("PreySubModelStock",
                                                   "DEVS_COUPLED_top")))

        expected_conns.add(
            CdppConnection(CdppPort("hunter",
                                    "DEVS_BASIC_COUPLED_hunter"),
                           CdppPort("hunter",
                                    "DEVS_COUPLED_top")))

        model = CdppModel.from_devsml_xml(self.devs_ml_model)
        self.assertSetEqual(expected_conns, model.external_output_connections)

    def test_model_components(self):
        expected_components = set()

        params = {'name': 'paramC',
                  'model': 'DEVSConstant',
                  'in_ports': set(['paramC']),
                  'out_ports': set(['paramC']),
                  'params': {'equation': "0.3"}}

        expected_components.add(CdppModel(**params))
        params = {'name': 'paramD',
                  'model': 'DEVSConstant',
                  'in_ports': set(['paramD']),
                  'out_ports': set(['paramD']),
                  'params': {'equation': "0.3"}}

        expected_components.add(CdppModel(**params))

        params = {'name': 'paramB',
                  'model': 'DEVSConstant',
                  'in_ports': set(['paramB']),
                  'out_ports': set(['paramB']),
                  'params': {'equation': "0.3"}}

        expected_components.add(CdppModel(**params))

        params = {'name': 'paramA',
                  'model': 'DEVSConstant',
                  'in_ports': set(['paramA']),
                  'out_ports': set(['paramA']),
                  'params': {'equation': "0.3"}}

        expected_components.add(CdppModel(**params))

        params = {'name': 'paramE',
                  'model': 'DEVSAux',
                  'in_ports': set(),
                  'out_ports': set(['paramE']),
                  'params': {'equation': "0.3"}}

        expected_components.add(CdppModel(**params))

        model = CdppModel.from_devsml_xml(self.devs_ml_model)
        self.assertSetEqual(expected_components, model.components)


if __name__ == '__main__':
    unittest.main()
