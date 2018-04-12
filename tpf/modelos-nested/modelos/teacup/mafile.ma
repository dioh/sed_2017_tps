
[top]
%Coupled model
components:  DEVS_BASIC_COUPLED_TemperatureValue CharacteristicTime@CharacteristicTimetop RoomTemperature@RoomTemperaturetop

% In ports
in: in_port_CharacteristicTime in_port_RoomTemperature


% Out ports
out: out_port_TemperatureValue

% Input connections
link: in_port_CharacteristicTime in_port_CharacteristicTime@CharacteristicTime
link: in_port_RoomTemperature in_port_RoomTemperature@RoomTemperature

% Output connections
link: out_port_TemperatureValue@DEVS_BASIC_COUPLED_TemperatureValue out_port_TemperatureValue

% Internal connections
link: out_port_CharacteristicTime@CharacteristicTime in_port_CharacteristicTime@DEVS_BASIC_COUPLED_TemperatureValue
link: out_port_RoomTemperature@RoomTemperature in_port_RoomTemperature@DEVS_BASIC_COUPLED_TemperatureValue

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')

[DEVS_BASIC_COUPLED_TemperatureValue]
%Coupled model
components: HeatLossToRoom_TemperatureValue@HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue TotTemperatureValue@TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue TemperatureValue@TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue

% In ports
in: in_port_CharacteristicTime in_port_RoomTemperature


% Out ports
out: out_port_TemperatureValue

% Input connections
link: in_port_CharacteristicTime in_port_CharacteristicTime@HeatLossToRoom_TemperatureValue
link: in_port_RoomTemperature in_port_RoomTemperature@HeatLossToRoom_TemperatureValue

% Output connections
link: out_port_TemperatureValue@TemperatureValue out_port_TemperatureValue

% Internal connections
link: out_port_TemperatureValue@TemperatureValue in_port_TemperatureValue@HeatLossToRoom_TemperatureValue
link: out_port_TotTemperatureValue@TotTemperatureValue in_port_TotTemperatureValue@TemperatureValue
link: out_port_HeatLossToRoom_TemperatureValue@HeatLossToRoom_TemperatureValue in_minus_port_HeatLossToRoom_TemperatureValue@TotTemperatureValue

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[TemperatureValue]
% Atomic model DEVSIntegrator
x0: 180
dQMin: 0.001
dQRel: 0.001





