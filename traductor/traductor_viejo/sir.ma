[top]
components : int_susc@QSS1 int_inf@QSS1 int_recov@QSS1 fts@Ftot fms@FminusSusceptible fti@Ftot fpi@FplusInfected fmi@FminusInfected ftr@Ftot fpr@FplusRecovered duration@Cte contactInfectivity@Cte totalPopulation@Cte

% Puertos: Input de parametros. Output de variables de interes
in : inDuration inContactInfectivity inTotalPopulation
out : susceptible infected recovered

% Links inputs a constantes
link : inDuration inVal@duration
link : inContactInfectivity inVal@contactInfectivity
link : inTotalPopulation inVal@totalPopulation

% Links constantes a f's que las usan	
link : out@duration inDuration@fmi
link : out@contactInfectivity inContactInfectivity@fpi
link : out@totalPopulation inTotalPopulation@fpi
link : out@contactInfectivity inContactInfectivity@fms
link : out@totalPopulation inTotalPopulation@fms
link : out@duration inDuration@fpr

% Links acoplado minimal integrador susceptible
link : out@fms inMinus@fts
link : out@fts in@int_susc

% Links acoplado minimal integrador infected
link : out@fpi inPlus@fti
link : out@fmi inMinus@fti
link : out@fti in@int_inf

% LInks acoplado minimal integrador recovered
link : out@fpr inPlus@ftr
link : out@ftr in@int_recov

% Links modelo
link : out@int_susc inSusceptible@fms
link : out@int_susc inSusceptible@fpi
link : out@int_inf inInfected@fpi
link : out@int_inf inInfected@fmi
link : out@int_inf inInfected@fms
link : out@int_inf inInfected@fpr

% Liks output variables de interes
link : out@int_susc susceptible
link : out@int_inf infected
link : out@int_recov recovered

% Integradores
[int_susc]
x0 : 1000
dQRel : 1e-2
dQMin : 1e-4

[int_inf]
x0 : 5
dQRel : 1e-2
dQMin : 1e-4

[int_recov]
x0 : 0
dQRel : 1e-2
dQMin : 1e-4
