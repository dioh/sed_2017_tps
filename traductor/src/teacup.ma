[top]
components : intTeacupTemperature@QSS1 ft@Ftot fmTeacupTemperature@FminusTeacupTemperature roomTemperature@Cte characteristicTime@Cte

% Puertos. Input: parametros. Output: variables de interes del modelo
in : inRoomTemperature inCharacteristicTime
out : tempTeacup

% Links parametros a constantes
link : inRoomTemperature inVal@roomTemperature
link : inCharacteristicTime inVal@characteristicTime

% Links constantes a modelo
link : out@roomTemperature inRoomTemperature@fmTeacupTemperature
link : out@characteristicTime inCharacteristicTime@fmTeacupTemperature

% Links modelo acoplado minimal integrador temp_teacup
link : out@fmTeacupTemperature inMinus@ft
link : out@ft in@intTeacupTemperature

% Links modelo
link : out@intTeacupTemperature inTeacupTemperature@fm 

% Links output variables de interes
link : out@intTeacupTemperature tempTeacup

[intTeacupTemperature]
x0 : 80
dQRel : 1e-2
dQMin : 1e-4