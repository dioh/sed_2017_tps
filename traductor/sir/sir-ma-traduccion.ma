[top]
components : infectiousIntegrator@QSS1 susceptibleIntegrator@QSS1 recoveredIntegrator@QSS1 ftSusceptible@Ftot ftInfectious@Ftot ftRecovered@Ftot fpInfectious@FplusInfectious fpRecovered@FplusRecovered fmSusceptible@FminusSusceptible fmInfectious@FminusInfectious duration@Cte totalPopulation@Cte contactInfectivity@Cte 

% Puertos: Input de parametros. Output de variables de interes
in : inDuration inTotalPopulation inContactInfectivity 

out : outSusceptible outInfectious outRecovered 

% Links inputs a constantes (conexiones con el top model)
link : inDuration inValue@duration
link : inTotalPopulation inValue@totalPopulation
link : inContactInfectivity inValue@contactInfectivity

% Links constantes a f's que las usan
link : out@duration inDuration@fmInfectious
link : out@duration inDuration@fpRecovered
link : out@totalPopulation inTotalPopulation@fmSusceptible
link : out@totalPopulation inTotalPopulation@fpInfectious
link : out@contactInfectivity inContactInfectivity@fmSusceptible
link : out@contactInfectivity inContactInfectivity@fpInfectious

% Links acoplado minimal integrador Susceptible
link : out@fmSusceptible inMinus@ftSusceptible
link : out@ftSusceptible in@susceptibleIntegrator
% Links acoplado minimal integrador Infectious
link : out@fpInfectious inPlus@ftInfectious
link : out@fmInfectious inMinus@ftInfectious
link : out@ftInfectious in@infectiousIntegrator
% Links acoplado minimal integrador Recovered
link : out@fpRecovered inPlus@ftRecovered
link : out@ftRecovered in@recoveredIntegrator

% Links modelo
link : out@susceptibleIntegrator inSusceptibleIntegrator@fmSusceptible
link : out@susceptibleIntegrator inSusceptibleIntegrator@fpInfectious
link : out@infectiousIntegrator inInfectiousIntegrator@fmSusceptible
link : out@infectiousIntegrator inInfectiousIntegrator@fpInfectious
link : out@infectiousIntegrator inInfectiousIntegrator@fmInfectious
link : out@infectiousIntegrator inInfectiousIntegrator@fpRecovered

% Liks output variables de interes
link : out@susceptibleIntegrator outSusceptible 
link : out@infectiousIntegrator outInfectious 
link : out@recoveredIntegrator outRecovered 

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

