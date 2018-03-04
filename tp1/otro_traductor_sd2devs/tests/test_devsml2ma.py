"""
    Prueba de conversion de devsml a ma
"""
import sys
import unittest

#sys.path.append('D:\\simu\\sed2017\\tps\\converter\\sd2devs')
#sys.path.append('/Users/pedro/Desktop/SED/SDDEVS/sed_2017_tps/sd2devs')
from . import settings
sys.path.append(settings.PATH)

class TestXmileConverter(unittest.TestCase):
    '''
    Pruebas del conversor en si
    '''
    def test_convert_devsml_to_ma(self):
        """
        Prueba que la conversion de xmile a devsml
        """
        pass
