[top]
components : infectiousIntegrator@QSS1 susceptibleIntegrator@QSS1 recoveredIntegrator@QSS1 ftSusceptibleIntegrator@FtotSusceptibleIntegrator ftRecoveredIntegrator@FtotRecoveredIntegrator ftInfectiousIntegrator@FtotInfectiousIntegrator fmInfectiousRecovering@FminusInfectiousRecovering fmSusceptibleSuccumbing@FminusSusceptibleSuccumbing fpRecoveredRecovering@FplusRecoveredRecovering fpInfectiousSuccumbing@FplusInfectiousSuccumbing duration@Cte totalPopulation@Cte contactInfectivity@Cte 

% Puertos: Input de parametros. Output de variables de interes
in : in_duration in_totalPopulation in_contactInfectivity 
out : out_infectiousIntegrator out_susceptibleIntegrator out_recoveredIntegrator 

% Links inputs a constantes (conexiones con el top model)
link : in_duration inValue@duration
link : in_totalPopulation inValue@totalPopulation
link : in_contactInfectivity inValue@contactInfectivity

% Links constantes a f's que las usan
link : out@duration in_duration@fmInfectiousRecovering
link : out@totalPopulation in_totalPopulation@fmSusceptibleSuccumbing
link : out@contactInfectivity in_contactInfectivity@fmSusceptibleSuccumbing
link : out@duration in_duration@fpRecoveredRecovering
link : out@totalPopulation in_totalPopulation@fpInfectiousSuccumbing
link : out@contactInfectivity in_contactInfectivity@fpInfectiousSuccumbing

% Links internos de los acoplados minimales (Ftot => Integrador)
link : out@ftInfectiousIntegrator in@infectiousIntegrator
link : out@ftSusceptibleIntegrator in@susceptibleIntegrator
link : out@ftRecoveredIntegrator in@recoveredIntegrator

% Links internos de los acoplados minimales (Fms => Fts)
link : out@fmInfectiousRecovering inMinus_Recovering@ftInfectious
link : out@fmSusceptibleSuccumbing inMinus_Succumbing@ftSusceptible

% Links internos de los acoplados minimales (Fps => Fts)
link : out@fpRecoveredRecovering inPlus_Recovering@ftRecovered
link : out@fpInfectiousSuccumbing inPlus_Succumbing@ftInfectious

% Links importantes del modelo
link : out@infectiousIntegrator in_infectiousIntegrator@fmInfectiousRecovering
link : out@infectiousIntegrator in_infectiousIntegrator@fmSusceptibleSuccumbing
link : out@infectiousIntegrator in_infectiousIntegrator@fpRecoveredRecovering
link : out@infectiousIntegrator in_infectiousIntegrator@fpInfectiousSuccumbing
link : out@susceptibleIntegrator in_susceptibleIntegrator@fmSusceptibleSuccumbing
link : out@susceptibleIntegrator in_susceptibleIntegrator@fpInfectiousSuccumbing

% Liks output variables de interes
link : out@infectiousIntegrator out_infectiousIntegrator
link : out@susceptibleIntegrator out_susceptibleIntegrator
link : out@recoveredIntegrator out_recoveredIntegrator

% Integradores
[infectiousIntegrator]
x0 : 5
dQRel : 1e-2
dQMin : 1e-4

[susceptibleIntegrator]
x0 : 1000
dQRel : 1e-2
dQMin : 1e-4

[recoveredIntegrator]
x0 : 0
dQRel : 1e-2
dQMin : 1e-4

