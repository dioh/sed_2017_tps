[top]
components : teacupTemperatureIntegrator@QSS1 ftTeacupTemperature@Ftot heatLossToRoom@Fminus roomTemperature@Cte characteristicTime@Cte

% Puertos. Input: parametros. Output: variables de interes del modelo
in : inRoomTemperature inCharacteristicTime
out : tempTeacup

% Links parametros a constantes
link : inRoomTemperature inVal@roomTemperature
link : inCharacteristicTime inVal@characteristicTime

% Links output variables de interes
link : out@teacupTemperatureIntegrator tempTeacup

% Links modelo acoplado minimal integrador temp_teacup
link : out@heatLossToRoom inMinus@ftTeacupTemperature
link : out@ftTeacupTemperature in@teacupTemperatureIntegrator

% Links modelo
link : out@teacupTemperatureIntegrator inTeacupTemperature@heatLossToRoom 

% Links constantes a modelo
link : out@roomTemperature inRoomTemperature@heatLossToRoom
link : out@characteristicTime inCharacteristicTime@heatLossToRoom

[teacupTemperatureIntegrator]
x0 : 80
dQRel : 1e-2
dQMin : 1e-4