[top]
components : teacupTemperatureIntegrator@QSS1 ftTeacupTemperature@Ftot fmTeacupTemperatureHeatLosstoRoom@FminusTeacupTemperatureHeatLosstoRoom roomTemperature@Cte characteristicTime@Cte 

% Puertos: Input de parametros. Output de variables de interes
in : inRoomTemperature inCharacteristicTime 

out : outTeacupTemperature 

% Links inputs a constantes (conexiones con el top model)
link : inRoomTemperature inValue@roomTemperature
link : inCharacteristicTime inValue@characteristicTime

% Links constantes a f's que las usan
link : out@characteristicTime inCharacteristicTime@fmTeacupTemperatureHeatLosstoRoom
link : out@roomTemperature inRoomTemperature@fmTeacupTemperatureHeatLosstoRoom

% Links acoplado minimal integrador Teacup Temperature
link : out@fmTeacupTemperature inMinus@ftTeacupTemperature
link : out@ftTeacupTemperature in@teacupTemperatureIntegrator

% Links modelo
link : out@teacupTemperatureIntegrator inTeacupTemperatureIntegrator@fmTeacupTemperatureHeatLosstoRoom

% Liks output variables de interes
link : out@teacupTemperatureIntegrator outTeacupTemperature 

% Integradores
[teacupTemperatureIntegrator]
x0 : 180
dQRel : 1e-2
dQMin : 1e-4

