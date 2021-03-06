
[top]
%Coupled model
components: DEVS_BASIC_COUPLED_stock1 firstPulse0@firstPulsetop interval0@intervaltop volume0@volumetop
% In ports
in: in_port_firstPulse in_port_interval in_port_volume start
% Out ports
out: out_port_stock1

% Input connections
link: in_port_firstPulse in_port_firstPulse@firstPulse0
link: in_port_interval in_port_interval@interval0
link: in_port_volume in_port_volume@volume0
link: start start@DEVS_BASIC_COUPLED_stock1
% Output connections
link: out_port_stock1@DEVS_BASIC_COUPLED_stock1 out_port_stock1
% Internal connections
link: out_port_volume@volume0 in_port_volume@DEVS_BASIC_COUPLED_stock1
% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')

[DEVS_BASIC_COUPLED_stock1]
%Coupled model
components: flow1_stock11@flow1_stock1DEVS_BASIC_COUPLED_stock1 Totstock11@Totstock1DEVS_BASIC_COUPLED_stock1 stock11@stock1DEVS_BASIC_COUPLED_stock1 PULSE_V_volume_FP_firstPulse_I_interval1@Pulse
% In ports
in: in_port_volume start
% Out ports
out: out_port_stock1
% Input connections
link: start start@PULSE_V_volume_FP_firstPulse_I_interval1
%link: in_port_volume in_port_volume@PULSE_V_volume_FP_firstPulse_I_interval1
link: out@PULSE_V_volume_FP_firstPulse_I_interval1 in_port_PULSE_V_volume_FP_firstPulse_I_interval@flow1_stock11
% Output connections
link: out_port_stock1@stock11 out_port_stock1
% Internal connections
link: out_port_flow1_stock1@flow1_stock11 in_minus_port_flow1_stock1@Totstock11
%link: out_port_PULSE_V_volume_FP_firstPulse_I_interval@PULSE_V_volume_FP_firstPulse_I_interval1 in_port_PULSE_V_volume_FP_firstPulse_I_interval@flow1_stock11
link: out_port_stock1@stock11 in_port_stock1@flow1_stock11
%link: out_port_Totstock1@Totstock11 in_port_Totstock1@stock11
%link: out@PULSE_V_volume_FP_firstPulse_I_interval1 in_port_subtract@stock11
link: out@PULSE_V_volume_FP_firstPulse_I_interval1 in_port_increment@stock11

[stock11]
% Atomic model DEVSIntegrator
x0: 1000
dQMin: 0.001
dQRel: 0.001
non_negative: 0
