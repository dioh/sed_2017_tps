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
rule : { t } 0 100
% Inputs
% Outputs (por ahora sin programar)

% PortInTransition