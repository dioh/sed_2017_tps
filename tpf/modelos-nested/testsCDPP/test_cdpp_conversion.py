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
        expected_ports = set(['paramA', 'paramB', 'cteVariable',
                              'ctePulse', 'paramD', 'paramPulse'])
        model = CdppModel.from_devsml_xml(self.devs_ml_model)
        self.assertSetEqual(expected_ports, model.in_ports)

    def test_model_out_ports(self):
        expected_ports = set(['PreySubModelStock', 'Prey', 'auxVariable',
                              'paramE', 'combiner', 'Predator',
                              'specialParamC', 'hunter',
                              'PreySubSubModelStock'])

        model = CdppModel.from_devsml_xml(self.devs_ml_model)
        self.assertSetEqual(expected_ports, model.out_ports)

    def test_model_internal_connections(self):
        expected_conns = set()
        expected_conns.add(CdppConnection(CdppPort("paramB", "paramB"),
                                          CdppPort("paramB", "paramE")))

        expected_conns.add(CdppConnection(CdppPort("PULSE_V_2_FP_2_I_2",
                                                   "PULSE_V_2_FP_2_I_2"),
                                          CdppPort("PULSE_V_2_FP_2_I_2",
                                                   "specialParamC")))

        expected_conns.add(CdppConnection(CdppPort("PULSE_V_1_FP_1_I_1",
                                                   "PULSE_V_1_FP_1_I_1"),
                                          CdppPort("PULSE_V_1_FP_1_I_1",
                                                   "paramE")))

        expected_conns.add(CdppConnection(CdppPort("paramA", "paramA"),
                                          CdppPort("paramA", "paramE")))

        expected_conns.add(CdppConnection(CdppPort("paramB", "paramB"),
                                          CdppPort("paramB",
                                          "DEVS_COUPLED_PreyModel")))
        expected_conns.add(
            CdppConnection(CdppPort("specialParamC", "specialParamC"),
                           CdppPort("specialParamC",
                                    "DEVS_COUPLED_PredatorModel")))

        expected_conns.add(
            CdppConnection(CdppPort("paramD", "paramD"),
                           CdppPort("paramD",
                                    "DEVS_COUPLED_PredatorModel")))

        expected_conns.add(CdppConnection(CdppPort("paramA", "paramA"),
                                          CdppPort("paramA",
                                                   "DEVS_COUPLED_PreyModel")))
        expected_conns.add(CdppConnection(CdppPort("paramB", "paramB"),
                                          CdppPort("paramB",
                                                   "DEVS_COUPLED_PreyModel")))

        expected_conns.add(CdppConnection(
            CdppPort("paramPulse", "paramPulse"),
            CdppPort("paramPulse",
                     "DEVS_BASIC_COUPLED_hunter")))

        expected_conns.add(CdppConnection(
            CdppPort("Predator",
                     "DEVS_COUPLED_PredatorModel"),
            CdppPort("Predator",
                     "DEVS_COUPLED_PreyModel")))

        expected_conns.add(CdppConnection(
            CdppPort("hunter",
                     "DEVS_BASIC_COUPLED_hunter"),
            CdppPort("hunter",
                     "DEVS_COUPLED_PredatorModel")))

        expected_conns.add(CdppConnection(
            CdppPort("Prey",
                     "DEVS_COUPLED_PreyModel"),
            CdppPort("Prey",
                     "DEVS_COUPLED_PredatorModel")))

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
        expected_conns.add(CdppConnection(CdppPort("paramD",
                                                   "DEVS_COUPLED_top"),
                                          CdppPort("paramD", "paramD")))
        expected_conns.add(CdppConnection(CdppPort("paramPulse",
                                                   "DEVS_COUPLED_top"),
                                          CdppPort("paramPulse",
                                                   "paramPulse")))
        expected_conns.add(CdppConnection(
                            CdppPort("cteVariable",
                                     "DEVS_COUPLED_top"),
                            CdppPort("cteVariable",
                                     "DEVS_COUPLED_PredatorModel")))
        expected_conns.add(CdppConnection(
                            CdppPort("ctePulse",
                                     "DEVS_COUPLED_top"),
                            CdppPort("ctePulse",
                                     "DEVS_COUPLED_PreyModel")))

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
        expected_conns.add(
            CdppConnection(CdppPort("specialParamC",
                                    "specialParamC"),
                           CdppPort("specialParamC",
                                    "DEVS_COUPLED_top")))
        expected_conns.add(
            CdppConnection(CdppPort("combiner",
                                    "DEVS_COUPLED_PreyModel"),
                           CdppPort("combiner",
                                    "DEVS_COUPLED_top")))

        model = CdppModel.from_devsml_xml(self.devs_ml_model)
        self.assertSetEqual(expected_conns, model.external_output_connections)

    def test_model_components(self):
        expected_components = set()

        params = {'name': 'paramPulse',
                  'model': 'DEVSConstant',
                  'in_ports': set(['paramPulse']),
                  'out_ports': set(['paramPulse']),
                  'parameters': {'value': '0'}}

        expected_components.add(CdppModel(**params))
        params = {'name': 'paramD',
                  'model': 'DEVSConstant',
                  'in_ports': set(['paramD']),
                  'out_ports': set(['paramD']),
                  'parameters': {'value': "0.01"}}

        expected_components.add(CdppModel(**params))

        params = {'name': 'paramB',
                  'model': 'DEVSConstant',
                  'in_ports': set(['paramB']),
                  'out_ports': set(['paramB']),
                  'parameters': {'value': "0.02"}}

        expected_components.add(CdppModel(**params))

        params = {'name': 'paramA',
                  'model': 'DEVSConstant',
                  'in_ports': set(['paramA']),
                  'out_ports': set(['paramA']),
                  'parameters': {'value': "0.1"}}

        expected_components.add(CdppModel(**params))

        params = {'name': 'paramE',
                  'model': 'DEVSAux',
                  'in_ports': set(['paramA', 'PULSE_V_1_FP_1_I_1', 'paramB']),
                  'out_ports': set(['paramE']),
                  'parameters': {'equation':
                                 'paramA + paramB + 0 * PULSE_V_1_FP_1_I_1'}}

        expected_components.add(CdppModel(**params))

        params = {'name': 'specialParamC',
                  'model': 'DEVSAux',
                  'in_ports': set(['PULSE_V_2_FP_2_I_2']),
                  'out_ports': set(['specialParamC']),
                  'parameters': {'equation':
                                 '0.3 - 0 * PULSE_V_2_FP_2_I_2'}}

        expected_components.add(CdppModel(**params))

        params = {'name': 'PULSE_V_1_FP_1_I_1',
                  'model': 'DEVSPulse',
                  'in_ports': set(),
                  'out_ports': set(['PULSE_V_1_FP_1_I_1']),
                  'parameters': {}}

        expected_components.add(CdppModel(**params))

        params = {'name': 'PULSE_V_2_FP_2_I_2',
                  'model': 'DEVSPulse',
                  'in_ports': set(),
                  'out_ports': set(['PULSE_V_2_FP_2_I_2']),
                  'parameters': {}}
        expected_components.add(CdppModel(**params))

        hunter_params = {'name': 'hunter',
                         'model': 'DEVSIntegrator',
                         'in_ports': set(['Tothunter']),
                         'out_ports': set(['hunter']),
                         'parameters': {'x0': '5', 'dQRel': '0.001',
                                        'dQMin': '0.001'}}

        params = {'name': 'DEVS_BASIC_COUPLED_hunter',
                  'model': 'Coupled',
                  'in_ports': set(['paramPulse']),
                  'out_ports': set(['hunter']),
                  'components': set([CdppModel(**hunter_params)])}
        expected_components.add(CdppModel(**params))


        model = CdppModel.from_devsml_xml(self.devs_ml_model)

        self.assertSetEqual(expected_components, model.components)


if __name__ == '__main__':
    unittest.main()
