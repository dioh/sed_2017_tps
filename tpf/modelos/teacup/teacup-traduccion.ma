[top]
components : TemperatureTot@TemperatureTot Temperature@QSS1 RoomTemperature@Cte CharacteristicTime@Cte HeatLossToRoomPlus@HeatLossToRoomPlus HeatLossToRoomMinus@HeatLossToRoomMinus 

% External Input Ports
in : RoomTemperature CharacteristicTime 
% External Output Ports
out : Temperature 

% Links internos (input ports => atomicos tipo 'Cte')
link : RoomTemperature inValue@RoomTemperature
link : CharacteristicTime inValue@CharacteristicTime

% Internal I/O Connections
link : out@TemperatureTot in@Temperature
link : out@HeatLossToRoomMinus HeatLossToRoomMinus@TemperatureTot
link : out@Temperature Temperature@HeatLossToRoomMinus
link : out@RoomTemperature RoomTemperature@HeatLossToRoomPlus
link : out@RoomTemperature RoomTemperature@HeatLossToRoomMinus
link : out@CharacteristicTime CharacteristicTime@HeatLossToRoomPlus
link : out@CharacteristicTime CharacteristicTime@HeatLossToRoomMinus

% Links internos (variables de interes => output ports)
link : out@Temperature Temperature

% Integradores
[Temperature]
x0 : 180
dQRel : 0.0001
dQMin : 0.0001