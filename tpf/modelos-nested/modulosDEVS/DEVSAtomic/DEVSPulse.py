
from modulosDEVS.DEVSPort import *
from modulosDEVS.DEVSComponent import *
import re

class DEVSPulse(DEVSAtomicComponent):
	def __init__(self, volume, first_pulse, interval):
		# TODO : llamar constructor del parent : in Python 2 use super(DEVSPulse, self).__init__()
		self.volume      = volume
		self.first_pulse = first_pulse
		self.interval    = interval
		self.name        = self.setName()
		self.input_ports = self.setInputPorts()
		self.output_ports= self.setOutputPorts()
		self.equation    = self.setEquation()
		self.type        = 'DEVSPulse'


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
	def setEquation(self):
		from modulosXMILE.Equation import Equation
		return Equation(str(self.volume), False)

	def setName(self):
		# Nota : Reemplazamos el '.' de los floats por un '_'
		vol_name         = 'V_' + str(self.volume).replace('.', '_')
		first_pulse_name = 'FP_' + str(self.first_pulse).replace('.', '_')
		interval_name    = 'I_' + str(self.interval).replace('.','_')
		name = 'PULSE_' + vol_name + '_' + first_pulse_name + '_' + interval_name
		return name

	def setInputPorts(self):
		# los correspondientes a las variables que se utilizen como parametro de la funcion
		input_ports = []
		try:
			# no es una variable alfanumerica (es numerica) => no debe entrar ese valor por input
			float(self.volume)
		except ValueError:
			input_ports.append(DEVSPort(self.volume, self, 'in'))
		try:
			float(self.first_pulse)
		except ValueError:
			input_ports.append(DEVSPort(self.first_pulse, self, 'in'))
		try:
			float(self.interval)
		except ValueError:
			input_ports.append(DEVSPort(self.interval, self, 'in'))
		return input_ports

	def setOutputPorts(self):
		# el nombre de esta funcion
		return [DEVSPort(self.name, self, 'out')]

	# Getters
	# devuelve todo lo que sea numerico (int's, float's)
	def getName(self):
		return self.name
	def getType(self):
		return self.type
	def getEquation(self):
		return self.equation
	def getDEVSInputPorts(self):
		return self.input_ports
	def getDEVSOutputPorts(self):
		return self.output_ports
	def getParameters(self):
		return self.equation.getParameters()
	# devuelve todo lo que sea alfanumerico
	def getVariables(self):
		return self.equation.getVariables()