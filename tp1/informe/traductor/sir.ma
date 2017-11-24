[top]
components : susceptibleIntegrator@QSS1 infectiousIntegrator@QSS1 recoveredIntegrator@QSS1 ftSusceptibleIntegrator@FtotSusceptibleIntegrator ftInfectiousIntegrator@FtotInfectiousIntegrator ftRecoveredIntegrator@FtotRecoveredIntegrator fmSusceptibleSuccumbing@FminusSusceptibleSuccumbing fmInfectiousRecovering@FminusInfectiousRecovering fpInfectiousSuccumbing@FplusInfectiousSuccumbing fpRecoveredRecovering@FplusRecoveredRecovering totalPopulation@Cte duration@Cte contactInfectivity@Cte 

% Puertos: Input de parametros. Output de variables de interes
in : in_totalPopulation in_duration in_contactInfectivity 
out : out_susceptibleIntegrator out_infectiousIntegrator out_recoveredIntegrator 

% Links inputs a constantes (conexiones con el top model)
link : in_totalPopulation inValue@totalPopulation
link : in_duration inValue@duration
link : in_contactInfectivity inValue@contactInfectivity

% Links constantes a f's que las usan
link : out@totalPopulation in_totalPopulation@fmSusceptibleSuccumbing
link : out@contactInfectivity in_contactInfectivity@fmSusceptibleSuccumbing
link : out@duration in_duration@fmInfectiousRecovering
link : out@totalPopulation in_totalPopulation@fpInfectiousSuccumbing
link : out@contactInfectivity in_contactInfectivity@fpInfectiousSuccumbing
link : out@duration in_duration@fpRecoveredRecovering

% Link constantes a Aux's que las usan

% Link Aux's a Aux's que las usan

% Link Aux's a funciones que las usan 

% Links internos de los acoplados minimales (Ftot => Integrador)
link : out@ftSusceptibleIntegrator in@susceptibleIntegrator
link : out@ftInfectiousIntegrator in@infectiousIntegrator
link : out@ftRecoveredIntegrator in@recoveredIntegrator

% Links internos de los acoplados minimales (Fms => Fts)
link : out@fmSusceptibleSuccumbing inMinus_Succumbing@ftSusceptibleIntegrator
link : out@fmInfectiousRecovering inMinus_Recovering@ftInfectiousIntegrator

% Links internos de los acoplados minimales (Fps => Fts)
link : out@fpInfectiousSuccumbing inPlus_Succumbing@ftInfectiousIntegrator
link : out@fpRecoveredRecovering inPlus_Recovering@ftRecoveredIntegrator

% Links importantes del modelo
link : out@susceptibleIntegrator in_susceptibleIntegrator@fmSusceptibleSuccumbing
link : out@susceptibleIntegrator in_susceptibleIntegrator@fpInfectiousSuccumbing
link : out@infectiousIntegrator in_infectiousIntegrator@fmSusceptibleSuccumbing
link : out@infectiousIntegrator in_infectiousIntegrator@fmInfectiousRecovering
link : out@infectiousIntegrator in_infectiousIntegrator@fpInfectiousSuccumbing
link : out@infectiousIntegrator in_infectiousIntegrator@fpRecoveredRecovering

% Liks output variables de interes
link : out@susceptibleIntegrator out_susceptibleIntegrator
link : out@infectiousIntegrator out_infectiousIntegrator
link : out@recoveredIntegrator out_recoveredIntegrator

% Integradores
[susceptibleIntegrator]
x0 : 1000
dQRel : 1e-2
dQMin : 1e-4

[infectiousIntegrator]
x0 : 5
dQRel : 1e-2
dQMin : 1e-4

[recoveredIntegrator]
x0 : 0
dQRel : 1e-2
dQMin : 1e-4

