#include(macros.inc)

[opinion]
type : cell
dim : (3, 3, 3)
delay : 
defaultDelayTime : 5.0
border : unwrapped
neighbors : (0, 0, -1)
neighbors : (0, 0, 1)
neighbors : (0, -1, 0)
neighbors : (0, 1, 0)
initialvalue : 0
localtransition : zzz-rule

[zzz-rule]
rule : {'action': '(0,0,0) + 10', 'delay': '100', 'condition': 't'}
% Input ports
in:input_port_nameinput_port_nameinput_port_name% Output ports (por ahora sin programar)
out:output_port_nameoutput_port_nameoutput_port_name% PortInTransition