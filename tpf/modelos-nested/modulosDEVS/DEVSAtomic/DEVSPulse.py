
from modulosDEVS.DEVSComponent import *
import re

class DEVSPulse(DEVSAtomicComponent):
	def __init__(self, volume, first_pulse, interval):
		# TODO : llamar constructor del parent : in Python 2 use super(DEVSPulse, self).__init__()
		self.volume      = volume
		self.first_pulse = first_pulse
		self.interval    = interval
		self.name        = self.setName()

	def __repr__(self):
		return str({
			'name'   : self.name,
			'volume' : self.volume,
			'first_pulse' : self.first_pulse,
			'interval' : self.interval
		})
	def __str__(self):
		return str({
			'name'   : self.name,
			'volume' : self.volume,
			'first_pulse' : self.first_pulse,
			'interval' : self.interval
		})

	# Setters
	def setName(self):
		# Nota : Reemplazamos el '.' de los floats por un '_'
		vol_name = 'V_' + str(self.volume).replace('.', '_')
		first_pulse_name = 'FP_' + str(self.first_pulse).replace('.', '_')
		interval_name = 'I_' + str(self.interval).replace('.','_')
		return 'PULSE_' + vol_name + '_' + first_pulse_name + '_' + interval_name

	# devuelve todo lo que sea numerico (int's, float's)
	def getParameters(self):
		return 1
	# devuelve todo lo que sea alfanumerico
	def getVariables(self):
		return 1
	def getName(self):
		return self.name