[top]
components : prevOutptIntegrator@QSS1 prevConsIntegrator@QSS1 ftPrevOutptIntegrator@FtotPrevOutptIntegrator ftPrevConsIntegrator@FtotPrevConsIntegrator fpPrevOutptChgPrevOutpt@FplusPrevOutptChgPrevOutpt fpPrevConsChgPrevCons@FplusPrevConsChgPrevCons marginalPropensitytoConsumealpha@Cte investmentproportionalityrelationbeta@Cte steptime@Cte spendingstep@Cte basespending@Cte timestep@Cte oneunitTimestep@Cte twounitTimestep@Cte  consumption@Auxconsumption  output@Auxoutput  investment@Auxinvestment  governmentSpending@AuxgovernmentSpending 

% Puertos: Input de parametros. Output de variables de interes
in : in_marginalPropensitytoConsumealpha in_investmentproportionalityrelationbeta in_steptime in_spendingstep in_basespending in_timestep in_oneunitTimestep in_twounitTimestep 
out : out_prevOutptIntegrator out_prevConsIntegrator 

% Links inputs a constantes (conexiones con el top model)
link : in_marginalPropensitytoConsumealpha inValue@marginalPropensitytoConsumealpha
link : in_investmentproportionalityrelationbeta inValue@investmentproportionalityrelationbeta
link : in_steptime inValue@steptime
link : in_spendingstep inValue@spendingstep
link : in_basespending inValue@basespending
link : in_timestep inValue@timestep
link : in_oneunitTimestep inValue@oneunitTimestep
link : in_twounitTimestep inValue@twounitTimestep

% Links constantes a f's que las usan

% Link constantes a Aux's que las usan

% Link Aux's a Aux's que las usan

% Link Aux's a funciones que las usan 

% Links internos de los acoplados minimales (Ftot => Integrador)
link : out@ftPrevOutptIntegrator in@prevOutptIntegrator
link : out@ftPrevConsIntegrator in@prevConsIntegrator

% Links internos de los acoplados minimales (Fms => Fts)

% Links internos de los acoplados minimales (Fps => Fts)
link : out@fpPrevOutptChgPrevOutpt inPlus_ChgPrevOutpt@ftPrevOutptIntegrator
link : out@fpPrevConsChgPrevCons inPlus_ChgPrevCons@ftPrevConsIntegrator

% Links importantes del modelo

% Liks output variables de interes
link : out@prevOutptIntegrator out_prevOutptIntegrator
link : out@prevConsIntegrator out_prevConsIntegrator

% Integradores
[prevOutptIntegrator]
x0 : 0
dQRel : 1e-2
dQMin : 1e-4

[prevConsIntegrator]
x0 : 0
dQRel : 1e-2
dQMin : 1e-4

