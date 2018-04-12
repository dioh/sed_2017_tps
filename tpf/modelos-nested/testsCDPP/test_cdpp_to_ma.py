"""
  Pruebas del modulo CDPP transformacion de CdppModel a MA File
"""

import unittest
import xml.etree.ElementTree as ET
from modulosCDPP import CdppModelToMaConverter, CdppModel


class TestCdppModelToMaFile(unittest.TestCase):
    '''
    Pruebas del conversor de CdppModel a MA
    '''

    def setUp(self):
        devs_ml_model = ET.parse('./testsCDPP/model.xml')
        self.model = CdppModel.from_devsml_xml(devs_ml_model)

    def test_ma_model_name(self):
        sut = CdppModelToMaConverter.parse_model(self.model)
        self.assertEqual('top', sut.model_name())

    def test_ma_render(self):
        expected_ma = """[top]
components: DEVS_BASIC_COUPLED_hunter@Coupled paramE@DEVSAux specialParamC@DEVSAux paramA@DEVSConstant paramB@DEVSConstant paramD@DEVSConstant paramPulse@DEVSConstant PULSE_V_1_FP_1_I_1@DEVSPulse PULSE_V_2_FP_2_I_2@DEVSPulse

% In ports
in: ctePulse cteVariable paramA paramB paramD paramPulse
% Out ports
out: Predator Prey PreySubModelStock PreySubSubModelStock auxVariable combiner hunter paramE specialParamC

% Input connections
link: cteVariable cteVariable@DEVS_COUPLED_PredatorModel
link: ctePulse ctePulse@DEVS_COUPLED_PreyModel
link: paramA paramA@paramA
link: paramB paramB@paramB
link: paramD paramD@paramD
link: paramPulse paramPulse@paramPulse

% Output connections
link: Predator@DEVS_COUPLED_PredatorModel Predator
link: Prey@DEVS_COUPLED_PreyModel Prey
link: PreySubModelStock@DEVS_COUPLED_PreyModel PreySubModelStock
link: PreySubSubModelStock@DEVS_COUPLED_PreyModel PreySubSubModelStock
link: auxVariable@DEVS_COUPLED_PredatorModel auxVariable
link: combiner@DEVS_COUPLED_PreyModel combiner
link: hunter@DEVS_BASIC_COUPLED_hunter hunter
link: paramE@paramE paramE
link: specialParamC@specialParamC specialParamC

% Internal connections
link: paramPulse@paramPulse paramPulse@DEVS_BASIC_COUPLED_hunter
link: Prey@DEVS_COUPLED_PreyModel Prey@DEVS_COUPLED_PredatorModel
link: hunter@DEVS_BASIC_COUPLED_hunter hunter@DEVS_COUPLED_PredatorModel
link: paramD@paramD paramD@DEVS_COUPLED_PredatorModel
link: specialParamC@specialParamC specialParamC@DEVS_COUPLED_PredatorModel
link: Predator@DEVS_COUPLED_PredatorModel Predator@DEVS_COUPLED_PreyModel
link: paramA@paramA paramA@DEVS_COUPLED_PreyModel
link: paramB@paramB paramB@DEVS_COUPLED_PreyModel
link: PULSE_V_1_FP_1_I_1@PULSE_V_1_FP_1_I_1 PULSE_V_1_FP_1_I_1@paramE
link: paramA@paramA paramA@paramE
link: paramB@paramB paramB@paramE
link: PULSE_V_2_FP_2_I_2@PULSE_V_2_FP_2_I_2 PULSE_V_2_FP_2_I_2@specialParamC"""
        sut = CdppModelToMaConverter.parse_model(self.model)
        print(sut)
        self.maxDiff = None
        self.assertMultiLineEqual(expected_ma, sut.__str__())
