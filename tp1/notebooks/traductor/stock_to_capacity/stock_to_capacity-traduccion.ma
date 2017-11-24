[top]
components : stock1Integrator@QSS1 ftStock1Integrator@FtotStock1Integrator fpStock1Flow1@FplusStock1Flow1 maximumCapacityofStock@Cte  growthCoefficient@AuxgrowthCoefficient  effectofRatioofStocktoCapacityonGrowthCoefficient@AuxeffectofRatioofStocktoCapacityonGrowthCoefficient  ratioofStocktoCapacity@AuxratioofStocktoCapacity 

% Puertos: Input de parametros. Output de variables de interes
in : in_maximumCapacityofStock 
out : out_stock1Integrator 

% Links inputs a constantes (conexiones con el top model)
link : in_maximumCapacityofStock inValue@maximumCapacityofStock

% Links constantes a f's que las usan

% Link constantes a Aux's que las usan
link : out@maximumCapacityofStock in_maximumCapacityofStock@ratioofStocktoCapacity

% Link Aux's a Aux's que las usan
link : out@effectofRatioofStocktoCapacityonGrowthCoefficient in_effectofRatioofStocktoCapacityonGrowthCoefficient@growthCoefficient
link : out@ratioofStocktoCapacity in_ratioofStocktoCapacity@effectofRatioofStocktoCapacityonGrowthCoefficient

% Link Aux's a funciones que las usan 
link : out@growthCoefficient in_growthCoefficient@fpStock1Flow1

% Links internos de los acoplados minimales (Ftot => Integrador)
link : out@ftStock1Integrator in@stock1Integrator

% Links internos de los acoplados minimales (Fms => Fts)

% Links internos de los acoplados minimales (Fps => Fts)
link : out@fpStock1Flow1 inPlus_Flow1@ftStock1Integrator

% Links importantes del modelo
link : out@stock1Integrator in_stock1Integrator@fpStock1Flow1
link : out@stock1Integrator in_stock1Integrator@ratioofStocktoCapacity

% Liks output variables de interes
link : out@stock1Integrator out_stock1Integrator

% Integradores
[stock1Integrator]
x0 : 100
dQRel : 1e-2
dQMin : 1e-4

