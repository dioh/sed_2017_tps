[top]
components : predatorIntegrator@QSS1 preyIntegrator@QSS1 ftPredatorIntegrator@FtotPredatorIntegrator ftPreyIntegrator@FtotPreyIntegrator fmPredatorMinusPredator@FminusPredatorMinusPredator fmPreyMinusPrey@FminusPreyMinusPrey fpPreyPlusPrey@FplusPreyPlusPrey fpPredatorPlusPredator@FplusPredatorPlusPredator paramD@Cte paramC@Cte paramB@Cte paramA@Cte 

% Puertos: Input de parametros. Output de variables de interes
in : in_paramD in_paramC in_paramB in_paramA 
out : out_predatorIntegrator out_preyIntegrator 

% Links inputs a constantes (conexiones con el top model)
link : in_paramD inValue@paramD
link : in_paramC inValue@paramC
link : in_paramB inValue@paramB
link : in_paramA inValue@paramA

% Links constantes a f's que las usan
link : out@paramC in_paramC@fmPredatorMinusPredator
link : out@paramB in_paramB@fmPreyMinusPrey
link : out@paramA in_paramA@fpPreyPlusPrey
link : out@paramD in_paramD@fpPredatorPlusPredator

% Link constantes a Aux's que las usan

% Link Aux's a Aux's que las usan

% Link Aux's a funciones que las usan 

% Links internos de los acoplados minimales (Ftot => Integrador)
link : out@ftPredatorIntegrator in@predatorIntegrator
link : out@ftPreyIntegrator in@preyIntegrator

% Links internos de los acoplados minimales (Fms => Fts)
link : out@fmPredatorMinusPredator inMinus_MinusPredator@ftPredatorIntegrator
link : out@fmPreyMinusPrey inMinus_MinusPrey@ftPreyIntegrator

% Links internos de los acoplados minimales (Fps => Fts)
link : out@fpPreyPlusPrey inPlus_PlusPrey@ftPreyIntegrator
link : out@fpPredatorPlusPredator inPlus_PlusPredator@ftPredatorIntegrator

% Links importantes del modelo
link : out@predatorIntegrator in_predatorIntegrator@fmPredatorMinusPredator
link : out@predatorIntegrator in_predatorIntegrator@fmPreyMinusPrey
link : out@predatorIntegrator in_predatorIntegrator@fpPredatorPlusPredator
link : out@preyIntegrator in_preyIntegrator@fmPreyMinusPrey
link : out@preyIntegrator in_preyIntegrator@fpPreyPlusPrey
link : out@preyIntegrator in_preyIntegrator@fpPredatorPlusPredator

% Liks output variables de interes
link : out@predatorIntegrator out_predatorIntegrator
link : out@preyIntegrator out_preyIntegrator

% Integradores
[predatorIntegrator]
x0 : 5
dQRel : 1e-2
dQMin : 1e-4

[preyIntegrator]
x0 : 100
dQRel : 1e-2
dQMin : 1e-4

