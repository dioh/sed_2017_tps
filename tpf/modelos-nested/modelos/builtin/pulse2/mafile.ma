#include(macros.inc)
[top]
%Coupled model
components:  DEVS_BASIC_COUPLED_stock1 firstPulseX0@firstPulseXtop intervalX0@intervalXtop volumeX0@volumeXtop
% In ports
in: in_port_firstPulseX in_port_intervalX in_port_start in_port_volumeX
% Out ports
out: out_port_stock1
% Input connections
link: in_port_start in_port_start@DEVS_BASIC_COUPLED_stock1
link: in_port_firstPulseX in_port_firstPulseX@firstPulseX0
link: in_port_intervalX in_port_intervalX@intervalX0
link: in_port_volumeX in_port_volumeX@volumeX0
% Output connections
link: out_port_stock1@DEVS_BASIC_COUPLED_stock1 out_port_stock1
% Internal connections
link: out_port_intervalX@intervalX0 in_port_intervalX@DEVS_BASIC_COUPLED_stock1
link: out_port_volumeX@volumeX0 in_port_volumeX@DEVS_BASIC_COUPLED_stock1[DEVS_BASIC_COUPLED_stock1]
%Coupled model
components: flow1_stock11@flow1_stock1DEVS_BASIC_COUPLED_stock1 flow2_stock11@flow2_stock1DEVS_BASIC_COUPLED_stock1 Totstock11@Totstock1DEVS_BASIC_COUPLED_stock1 stock11@stock1DEVS_BASIC_COUPLED_stock1 PULSE_V_volumeX_I_intervalX_flow11@PULSE_V_volumeX_I_intervalX_flow1DEVS_BASIC_COUPLED_stock1
% In ports
in: in_port_intervalX in_port_start in_port_volumeX
% Out ports
out: out_port_stock1
% Input connections
link: in_port_intervalX in_port_intervalX@PULSE_V_volumeX_I_intervalX_flow11
link: in_port_start in_port_start@PULSE_V_volumeX_I_intervalX_flow11
link: in_port_volumeX in_port_volumeX@PULSE_V_volumeX_I_intervalX_flow11
% Output connections
link: out_port_stock1@stock11 out_port_stock1
% Internal connections
link: out_port_flow1_stock1@flow1_stock11 in_minus_port_flow1_stock1@Totstock11
link: out_port_flow2_stock1@flow2_stock11 in_minus_port_flow2_stock1@Totstock11
link: out_port_stock1@stock11 in_port_stock1@flow2_stock11
link: out_port_Totstock1@Totstock11 in_port_Totstock1@stock11
link: out_port_PULSE_V_volumeX_I_intervalX_flow1@PULSE_V_volumeX_I_intervalX_flow11 in_port_subtract@stock11
[stock11]
% Atomic model DEVSIntegrator
x0: 1000
non_negative: 0
dQMin: 0.001
dQRel: 0.001
