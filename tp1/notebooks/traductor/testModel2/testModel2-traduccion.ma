[top]
components : investmentIntegrator@QSS1 capitalIntegrator@QSS1 ftInvestmentIntegrator@FtotInvestmentIntegrator ftCapitalIntegrator@FtotCapitalIntegrator fpInvestmentinflow@FplusInvestmentinflow fpCapitalbiflow@FplusCapitalbiflow constant@Cte 

% Puertos: Input de parametros. Output de variables de interes
in : in_constant 
out : out_investmentIntegrator out_capitalIntegrator 

% Links inputs a constantes (conexiones con el top model)
link : in_constant inValue@constant

% Links constantes a f's que las usan
link : out@constant in_constant@fpInvestmentinflow

% Link constantes a Aux's que las usan

% Link Aux's a Aux's que las usan

% Link Aux's a funciones que las usan 

% Links internos de los acoplados minimales (Ftot => Integrador)
link : out@ftInvestmentIntegrator in@investmentIntegrator
link : out@ftCapitalIntegrator in@capitalIntegrator

% Links internos de los acoplados minimales (Fms => Fts)

% Links internos de los acoplados minimales (Fps => Fts)
link : out@fpInvestmentinflow inPlus_inflow@ftInvestmentIntegrator
link : out@fpCapitalbiflow inPlus_biflow@ftCapitalIntegrator

% Links importantes del modelo
link : out@investmentIntegrator in_investmentIntegrator@fpCapitalbiflow
link : out@capitalIntegrator in_capitalIntegrator@fpCapitalbiflow

% Liks output variables de interes
link : out@investmentIntegrator out_investmentIntegrator
link : out@capitalIntegrator out_capitalIntegrator

% Integradores
[investmentIntegrator]
x0 : 10
dQRel : 1e-2
dQMin : 1e-4

[capitalIntegrator]
x0 : 100
dQRel : 1e-2
dQMin : 1e-4

