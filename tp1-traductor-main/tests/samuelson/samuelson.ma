[top]
components : previousConsumptionIntegrator@QSS1 previousOutputIntegrator@QSS1 ftPreviousConsumptionIntegrator@FtotPreviousConsumptionIntegrator ftPreviousOutputIntegrator@FtotPreviousOutputIntegrator fpPreviousConsumptionChgPreviousConsumption@FplusPreviousConsumptionChgPreviousConsumption fpPreviousOutputChgPreviousOutput@FplusPreviousOutputChgPreviousOutput basespending@Cte marginalPropensity\ntoConsumealpha@Cte tIMESTEP@Cte investmentproportionality\nrelationbeta@Cte steptime@Cte tIMESTEP2@Cte spendingstep@Cte tIMESTEP1@Cte  output@Auxoutput  investment@Auxinvestment  consumption@Auxconsumption  governmentSpending@AuxgovernmentSpending 

% Puertos: Input de parametros. Output de variables de interes
in : in_basespending in_marginalPropensity\ntoConsumealpha in_tIMESTEP in_investmentproportionality\nrelationbeta in_steptime in_tIMESTEP2 in_spendingstep in_tIMESTEP1 
out : out_previousConsumptionIntegrator out_previousOutputIntegrator 

% Links inputs a constantes (conexiones con el top model)
link : in_basespending inValue@basespending
link : in_marginalPropensity\ntoConsumealpha inValue@marginalPropensity\ntoConsumealpha
link : in_tIMESTEP inValue@tIMESTEP
link : in_investmentproportionality\nrelationbeta inValue@investmentproportionality\nrelationbeta
link : in_steptime inValue@steptime
link : in_tIMESTEP2 inValue@tIMESTEP2
link : in_spendingstep inValue@spendingstep
link : in_tIMESTEP1 inValue@tIMESTEP1

% Links constantes a f's que las usan
link : out@tIMESTEP in_tIMESTEP@fpPreviousConsumptionChgPreviousConsumption
link : out@tIMESTEP2 in_tIMESTEP2@fpPreviousOutputChgPreviousOutput

% Link constantes a Aux's que las usan
link : out@basespending in_basespending@governmentSpending
link : out@spendingstep in_spendingstep@governmentSpending

% Link Aux's a Aux's que las usan
link : out@investment in_investment@output
link : out@consumption in_consumption@output
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
link : out@previousOutputIntegrator in_previousOutputIntegrator@consumption

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

