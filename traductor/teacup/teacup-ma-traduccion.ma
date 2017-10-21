[top]
components : teacupTemperatureIntegrator@QSS1 ftTeacupTemperature@Ftot fmTeacupTemperature@FminusTeacupTemperature roomTemperature@Cte characteristicTime@Cte 

% Puertos: Input de parametros. Output de variables de interes
in : inRoomTemperature inCharacteristicTime 

out : outTeacupTemperature 

% Links inputs a constantes (conexiones con el top model)
link : inRoomTemperature inValue@roomTemperature
link : inCharacteristicTime inValue@characteristicTime

% Links constantes a f's que las usan
link : out@characteristicTime inCharacteristicTime@fmTeacupTemperature
link : out@roomTemperature inRoomTemperature@fmTeacupTemperature

% Links acoplado minimal integrador Teacup Temperature
link : out@fmTeacupTemperature inMinus@ftTeacupTemperature
link : out@ftTeacupTemperature in@teacupTemperatureIntegrator

% Links modelo
link : out@teacupTemperatureIntegrator inTeacupTemperatureIntegrator@fmTeacupTemperature

% Liks output variables de interes
link : out@teacupTemperatureIntegrator outTeacupTemperature 

% Integradores
[teacupTemperatureIntegrator]
x0 : 180
dQRel : 1e-2
dQMin : 1e-4

