#include(macros.inc)

[cell]
% Parameters
dim: (3,3,3)
initialvalue: 0
type: cell
delay: 4.3
defaultDelayTime: 5.0
localtransition: zzz-rule
initialCellsValue: valfile.val
border: unwrapped

% Neighbors
neighbors: (0,-1,0) (0,0,-1) (0,0,1) (0,0,0) (0,1,0)
% In ports
in: in1 in2 in3
% Out ports
out: out1 out2 out3
% Input connections
% Output connections
% Internal connections
link: in1 in@cell(0,0,0)
link: in2 in@cell(0,1,2)
link: in3 in@cell(2,2,2)
link: out@cell(0,0,0) out1
link: out@cell(0,1,2) out2
link: out@cell(2,2,2) out3
% Ports in transition
PortInTransition: in@cell(0,0,0) xxx-rule
% Transitions
[zzz-rule]
rule: { (0,0,0) + 10 * (0,0,1) } 10 { t }
[xxx-rule]
rule: { portValue(thisPort) } 0.1 { t }