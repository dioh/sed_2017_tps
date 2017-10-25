[top]
components : teacupTemperatureIntegrator@QSS1 ftTeacupTemperatureIntegrator@FtotTeacupTemperatureIntegrator fmTeacupTemperatureHeatLosstoRoom@FminusTeacupTemperatureHeatLosstoRoom roomTemperature@Cte characteristicTime@Cte 

% Puertos: Input de parametros. Output de variables de interes
in : in_roomTemperature in_characteristicTime 
out : out_teacupTemperatureIntegrator 

% Links inputs a constantes (conexiones con el top model)
link : in_roomTemperature inValue@roomTemperature
link : in_characteristicTime inValue@characteristicTime

% Links constantes a f's que las usan
link : out@roomTemperature in_roomTemperature@fmTeacupTemperatureHeatLosstoRoom
link : out@characteristicTime in_characteristicTime@fmTeacupTemperatureHeatLosstoRoom

% Links internos de los acoplados minimales (Ftot => Integrador)
link : out@ftTeacupTemperatureIntegrator in@teacupTemperatureIntegrator

% Links internos de los acoplados minimales (Fms => Fts)
link : out@fmTeacupTemperatureHeatLosstoRoom inMinus_HeatLosstoRoom@ftTeacupTemperature

% Links internos de los acoplados minimales (Fps => Fts)

% Links importantes del modelo
link : out@teacupTemperatureIntegrator in_teacupTemperatureIntegrator@fmTeacupTemperatureHeatLosstoRoom

% Liks output variables de interes
link : out@teacupTemperatureIntegrator out_teacupTemperatureIntegrator

% Integradores
[teacupTemperatureIntegrator]
x0 : 180
dQRel : 1e-2
dQMin : 1e-4

