

class DEVSPort(object):
	def __init__(self, name, component, type_, is_for_constant=False):
		self.type = type_
		self.name = name
		# TODO : asertar que 'component' es de tipo 'DEVSComponent'
		self.component = component
		self.is_for_constant = is_for_constant

	def __repr__(self):
		return str({
			'name' : self.name,
			'type' : self.type,
			'component' : self.component.getName()
		})

	def __str__(self):
		return str({
			'name' : self.name,
			'type' : self.type,
			'component' : self.component.getName()
		})

	def __eq__(self, other):
		# TODO : hacer esto mismo para DEVSCoupledComonent
		return self.name == other.getName() and \
			self.component.getName() == other.getComponent().getName() and \
			self.type == other.getType()
	
	def __hash__(self):
		return (hash(self.name) ^ hash(self.component.getName()) ^ hash(self.type))

	# Setters

	# Getters
	def getType(self):
		return self.type

	def getName(self):
		return self.name

	def getComponent(self):
		return self.component

	def get_is_for_constant(self):
		return self.is_for_constant