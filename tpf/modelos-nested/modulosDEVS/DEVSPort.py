

class DEVSPort(object):
	def __init__(self, name, component, type_):
		self.type = type_
		self.name = name
		# TODO : asertar que 'component' es de tipo 'DEVSComponent'
		self.component = component

	def __repr__(self):
		return str({
			'name' : self.name,
			'type' : self.type
		})

	def __str__(self):
		return str({
			'name' : self.name,
			'type' : self.type
		})

	def __eq__(self, other):
		# TODO : hacer esto mismo para DEVSCoupledComonent
		return self.name == other.getName() and self.component == other.getComponent() and self.type == other.getType()

	# Getters
	def getType(self):
		return self.type

	def getName(self):
		return self.name

	def getComponent(self):
		return self.component