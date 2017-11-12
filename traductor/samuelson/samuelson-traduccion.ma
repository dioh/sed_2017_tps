[top]
components : previousConsumptionIntegrator@QSS1 previousOutputIntegrator@QSS1 ftPreviousConsumptionIntegrator@FtotPreviousConsumptionIntegrator ftPreviousOutputIntegrator@FtotPreviousOutputIntegrator fpPreviousConsumptionChgPreviousConsumption@FplusPreviousConsumptionChgPreviousConsumption fpPreviousOutputChgPreviousOutput@FplusPreviousOutputChgPreviousOutput timestep@Cte marginalPropensitytoConsumealpha@Cte oneunitTimestep@Cte investmentproportionalityrelationbeta@Cte twounitTimestep@Cte steptime@Cte spendingstep@Cte basespending@Cte  output@Auxoutput  investment@Auxinvestment  consumption@Auxconsumption  governmentSpending@AuxgovernmentSpending 

% Puertos: Input de parametros. Output de variables de interes
in : in_timestep in_marginalPropensitytoConsumealpha in_oneunitTimestep in_investmentproportionalityrelationbeta in_twounitTimestep in_steptime in_spendingstep in_basespending 
out : out_previousConsumptionIntegrator out_previousOutputIntegrator 

% Links inputs a constantes (conexiones con el top model)
link : in_timestep inValue@timestep
link : in_marginalPropensitytoConsumealpha inValue@marginalPropensitytoConsumealpha
link : in_oneunitTimestep inValue@oneunitTimestep
link : in_investmentproportionalityrelationbeta inValue@investmentproportionalityrelationbeta
link : in_twounitTimestep inValue@twounitTimestep
link : in_steptime inValue@steptime
link : in_spendingstep inValue@spendingstep
link : in_basespending inValue@basespending

% Links constantes a f's que las usan
link : out@timestep in_timestep@fpPreviousConsumptionChgPreviousConsumption
link : out@twounitTimestep in_twounitTimestep@fpPreviousOutputChgPreviousOutput

% Link constantes a Aux's que las usan
link : out@investmentproportionalityrelationbeta in_investmentproportionalityrelationbeta@investment
link : out@marginalPropensitytoConsumealpha in_marginalPropensitytoConsumealpha@consumption
link : out@basespending in_basespending@governmentSpending
link : out@spendingstep in_spendingstep@governmentSpending
link : out@steptime in_steptime@governmentSpending
link : out@oneunitTimestep in_oneunitTimestep@governmentSpending

% Link Aux's a Aux's que las usan
link : out@governmentSpending in_governmentSpending@output
link : out@consumption in_consumption@investment

% Link Aux's a funciones que las usan 
link : out@consumption in_consumption@fpPreviousConsumptionChgPreviousConsumption
link : out@output in_output@fpPreviousOutputChgPreviousOutput

% Links internos de los acoplados minimales (Ftot => Integrador)
link : out@ftPreviousConsumptionIntegrator in@previousConsumptionIntegrator
link : out@ftPreviousOutputIntegrator in@previousOutputIntegrator

% Links internos de los acoplados minimales (Fms => Fts)

% Links internos de los acoplados minimales (Fps => Fts)
link : out@fpPreviousConsumptionChgPreviousConsumption inPlus_ChgPreviousConsumption@ftPreviousConsumptionIntegrator
link : out@fpPreviousOutputChgPreviousOutput inPlus_ChgPreviousOutput@ftPreviousOutputIntegrator

% Links importantes del modelo

% Liks output variables de interes
link : out@previousConsumptionIntegrator out_previousConsumptionIntegrator
link : out@previousOutputIntegrator out_previousOutputIntegrator

% Integradores
[previousConsumptionIntegrator]
x0 : 0
dQRel : 1e-2
dQMin : 1e-4

[previousOutputIntegrator]
x0 : 0
dQRel : 1e-2
dQMin : 1e-4

