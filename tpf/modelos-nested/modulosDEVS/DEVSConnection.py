
class DEVSConnection(object):
	def __init__(self, x):
		self.x = x

class DEVSInternalConnection(DEVSConnection):
	def __init__(self, port_from, component_from, port_to, component_to):
		self.port_from = port_from
		self.component_from = component_from
		self.port_to = port_to
		self.component_to = component_to

	def __repr__(self):
		return str({
			'port_from' : self.port_from.getName(),
			'component_from' : self.getComponentFrom().getName(),
			'port_to' : self.port_to.getName(),
			'component_to' : self.component_to.getName()
		})

	def __str__(self):
		return str({
			'port_from' : self.port_from.getName(),
			'component_from' : self.getComponentFrom().getName(),
			'port_to' : self.port_to.getName(),
			'component_to' : self.component_to.getName()
		})
	
	def __eq__(self, other):
		return self.port_from == other.getPortFrom() and \
			self.port_to == other.getPortTo() and \
			self.component_to.getName() == other.getComponentTo().getName() and \
			self.component_from.getName() == other.getComponentFrom().getName()
	
	def __hash__(self):
		return (hash(self.port_from) ^ hash(self.port_to) ^ hash(self.component_to) ^ hash(self.component_from))

	def getPortFrom(self):
		return self.port_from
	def getPortTo(self):
		return self.port_to
	def getComponentFrom(self):
		return self.component_from
	def getComponentTo(self):
		return self.component_to

######
class DEVSExternalInputConnection(DEVSConnection):
	def __init__(self, port_from, port_to, component_to):
		self.port_from = port_from
		self.port_to   = port_to
		self.component_to = component_to

	def __repr__(self):
		return str({
			'port_from' : self.port_from.getName(),
			'port_to'   : self.port_to.getName(),
			'component_to' : self.component_to.getName()
		})

	def __eq__(self, other):
		return self.port_from == other.getPortFrom() and \
			self.port_to == other.getPortTo() and \
			self.component.getName() == other.getComponentTo().getName()
	
	def __hash__(self):
		return (hash(self.port_from) ^ hash(self.port_to) ^ hash(self.component_to))

	# Getters
	def getComponentTo(self):
		return self.component_to
	def getPortFrom(self):
		return self.port_from
	def getPortTo(self):
		return self.port_to


######
class DEVSExternalOutputConnection(DEVSConnection):
	def __init__(self, component_from, port_from, port_to):
		self.component_from = component_from
		self.port_from = port_from
		self.port_to   = port_to

	def __repr__(self):
		return str({
			'component_from' : self.component_from.getName(),
			'port_from' : self.port_from.getName(),
			'port_to'   : self.port_to.getName()
		})

	def __eq__(self, other):
		return self.port_from == other.getPortFrom() and \
			self.port_to == other.getPortTo() and \
			self.component.getName() == other.getComponentFrom().getName()

	def __hash__(self):
		return (hash(self.port_from) ^ hash(self.port_to) ^ hash(self.component_from))

	# Getters
	def getComponentFrom(self):
		return self.component_from
	def getPortFrom(self):
		return self.port_from
	def getPortTo(self):
		return self.port_to