#include(macros.inc)

%Coupled model
[top]
components:  cell  DEVS_BASIC_COUPLED_TemperatureValue CharacteristicTime0@CharacteristicTimetop RoomTemperature0@RoomTemperaturetop converter@tuple2real
% In ports
in: in_port_CharacteristicTime in_port_RoomTemperature in1
% Out ports
out: out_port_TemperatureValue
% Input connections
link: in_port_CharacteristicTime in_port_CharacteristicTime@CharacteristicTime0
link: in_port_RoomTemperature in_port_RoomTemperature@RoomTemperature0
% Output connections
link: out_port_TemperatureValue@DEVS_BASIC_COUPLED_TemperatureValue out_port_TemperatureValue
% Internal connections
link: out_port_CharacteristicTime@CharacteristicTime0 in_port_CharacteristicTime@DEVS_BASIC_COUPLED_TemperatureValue
link: out_port_RoomTemperature@RoomTemperature0 in_port_RoomTemperature@DEVS_BASIC_COUPLED_TemperatureValue

link: out_port_TemperatureValue@DEVS_BASIC_COUPLED_TemperatureValue in@converter
link: out@converter in1@cell

[cell]
% Parameters
dim: (3,3,3)
initialvalue: 0
type: cell
delay: 4.3
defaultDelayTime: 5.0
localtransition: zzz-rule
initialCellsValue: valfile.val
border: wrapped

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
rule: { 0.5 * (0,0,0) } 10 { t }
[xxx-rule]
rule: { portValue(thisPort) } 0.1 { t }
%Coupled model
[DEVS_BASIC_COUPLED_TemperatureValue]
components: HeatLossToRoom_TemperatureValue1@HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue TotTemperatureValue1@TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue TemperatureValue1@TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue
% In ports
in: in_port_CharacteristicTime in_port_RoomTemperature
% Out ports
out: out_port_TemperatureValue
% Input connections
link: in_port_CharacteristicTime in_port_CharacteristicTime@HeatLossToRoom_TemperatureValue1
link: in_port_RoomTemperature in_port_RoomTemperature@HeatLossToRoom_TemperatureValue1
% Output connections
link: out_port_TemperatureValue@TemperatureValue1 out_port_TemperatureValue
% Internal connections
link: out_port_TemperatureValue@TemperatureValue1 in_port_TemperatureValue@HeatLossToRoom_TemperatureValue1
link: out_port_TotTemperatureValue@TotTemperatureValue1 in_port_TotTemperatureValue@TemperatureValue1
link: out_port_HeatLossToRoom_TemperatureValue@HeatLossToRoom_TemperatureValue1 in_minus_port_HeatLossToRoom_TemperatureValue@TotTemperatureValue1
[TemperatureValue1]
% Atomic model DEVSIntegrator
x0: 180
non_negative: 0
dQMin: 0.001
dQRel: 0.001
