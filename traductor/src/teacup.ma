[top]
components : int_temp_teacup@QSS1 ft@Ftot fm@FminusTeacup roomTemperature@Cte characteristicTime@Cte

% Puertos. Input: parametros. Output: variables de interes del modelo
in : inRoomTemperature inCharacteristicTime
out : tempTeacup

% Links parametros a constantes
link : inRoomTemperature inVal@roomTemperature
link : inCharacteristicTime inVal@characteristicTime

% Links constantes a modelo
link : out@roomTemperature inRoomTemperature@fm
link : out@characteristicTime inCharacteristicTime@fm

% Links modelo acoplado minimal integrador temp_teacup
link : out@fm inMinus@ft
link : out@ft in@int_temp_teacup

% Links modelo
link : out@int_temp_teacup inTeacupTemperature@fm 

% Links output variables de interes
link : out@int_temp_teacup tempTeacup

[int_temp_teacup]
x0 : 80
dQRel : 1e-2
dQMin : 1e-4