
[top]
%Coupled model
components:  DEVS_BASIC_COUPLED_TemperatureValue CharacteristicTime0@CharacteristicTimetop RoomTemperature0@RoomTemperaturetop

% In ports
in: in_port_CharacteristicTime in_port_RoomTemperature


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

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')

[DEVS_BASIC_COUPLED_TemperatureValue]
%Coupled model
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

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[TemperatureValue1]
% Atomic model DEVSIntegrator
x0: 180
dQMin: 0.001
dQRel: 0.001






