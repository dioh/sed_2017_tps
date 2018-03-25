[top]
components : 

% Puertos: Input de parametros. Output de variables de interes
in : paramA paramB paramC cteVariable
out : out_preyIntegrator out_predatorIntegrator 

% Links inputs a constantes (conexiones con el top model)

% Links constantes a f's que las usan

% Link constantes a Aux's que las usan

% Link Aux's a Aux's que las usan

% Link Aux's a funciones que las usan 

% Links internos de los acoplados minimales (Ftot => Integrador)
link : out@ftPreyIntegrator in@preyIntegrator
link : out@ftPredatorIntegrator in@predatorIntegrator

% Links internos de los acoplados minimales (Fms => Fts)
link : out@fmPreyMinusPrey inMinus_MinusPrey@ftPreyIntegrator
link : out@fmPredatorMinusPredator inMinus_MinusPredator@ftPredatorIntegrator

% Links internos de los acoplados minimales (Fps => Fts)
link : out@fpPreyPlusPrey inPlus_PlusPrey@ftPreyIntegrator
link : out@fpPredatorPlusPredator inPlus_PlusPredator@ftPredatorIntegrator

% Links importantes del modelo
link : out@preyIntegrator in_preyIntegrator@fmPreyMinusPrey
link : out@preyIntegrator in_preyIntegrator@fpPreyPlusPrey
link : out@preyIntegrator in_preyIntegrator@fpPredatorPlusPredator
link : out@predatorIntegrator in_predatorIntegrator@fmPreyMinusPrey
link : out@predatorIntegrator in_predatorIntegrator@fmPredatorMinusPredator
link : out@predatorIntegrator in_predatorIntegrator@fpPredatorPlusPredator

% Liks output variables de interes
link : out@preyIntegrator out_preyIntegrator
link : out@predatorIntegrator out_predatorIntegrator

% Integradores
[preyIntegrator]
x0 : 100
dQRel : 1e-4
dQMin : 1e-4

[predatorIntegrator]
x0 : 5
dQRel : 1e-4
dQMin : 1e-4

