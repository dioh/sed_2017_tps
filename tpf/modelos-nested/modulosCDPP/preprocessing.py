
import xml.etree.ElementTree as etree
import vkbeautify as vkb

def preprocessing_devsml_for_ma(root):

	# TODO : no anda
	def traverse(r, level):
		atomics = r.findall('./components/atomicRef')
		atomics_names = [a.get('name') for a in atomics]
		coupleds = r.findall('./components/coupledRef')
		
		#print atomics_names

		internal_connections = r.find('./internal_connections')
		ext_input_conn  = r.find('./external_input_connections')
		ext_output_conn = r.find('./external_output_connections')
		
		for ic in internal_connections:
			if ic.get('component_from') in atomics_names:
				ic.set('component_from', ic.get('component_from') + str(level))
				#print ic.get('component_from')
			if ic.get('component_to') in atomics_names:
				ic.set('component_to', ic.get('component_to') + str(level))
				#print ic.get('component_to')
		
		for eic in ext_input_conn:
			if eic.get('component_to') in atomics_names:
				eic.set('component_to', eic.get('component_to') + str(level))
				#print eic.get('component_to')
		
		for eoc in ext_output_conn:
			if eoc.get('component_from') in atomics_names:
				eoc.set('component_from', eoc.get('component_from') + str(level))
				#print eoc.get('component_from')
		
		for a in atomics:
			a.set('name_level', a.get('name') + str(level))
			#print a.get('name_level')



		for c in coupleds:
			traverse(c, level + 1)

	# Run
	traverse(root, 0)
	
	return root