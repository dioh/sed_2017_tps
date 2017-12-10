[top]
components : capitalIntegrator@QSS1 laborProductivityIntegrator@QSS1 wageRateIntegrator@QSS1 populationIntegrator@QSS1 ftPopulationIntegrator@FtotPopulationIntegrator ftwageRateIntegrator@FtotwageRateIntegrator ftCapitalIntegrator@FtotCapitalIntegrator ftLaborProductivityIntegrator@FtotLaborProductivityIntegrator fpPopulationchgPopulation@FplusPopulationchgPopulation fpwageRatechgWageRate@FpluswageRatechgWageRate fpLaborProductivitychgLaborProductivity@FplusLaborProductivitychgLaborProductivity fpCapitalchgCapital@FplusCapitalchgCapital  wageFunction@AuxwageFunction  investmentGross@AuxinvestmentGross  profit@Auxprofit  wageBill@AuxwageBill  labor@Auxlabor  output@Auxoutput  omega@Auxomega  investmentNetReal@AuxinvestmentNetReal  employmentRate@AuxemploymentRate 

% Puertos: Input de parametros. Output de variables de interes
in : 
out : out_capitalIntegrator out_laborProductivityIntegrator out_wageRateIntegrator out_populationIntegrator out_labor out_employmentrate out_output out_wagebill

% Links inputs a constantes (conexiones con el top model)

% Links constantes a f's que las usan

% Link constantes a Aux's que las usan

% Link Aux's a Aux's que las usan
link : out@employmentRate in_employmentRate@wageFunction
link : out@profit in_profit@investmentGross
link : out@output in_output@profit
link : out@wageBill in_wageBill@profit
link : out@labor in_labor@wageBill
link : out@output in_output@labor
link : out@wageBill in_wageBill@omega
link : out@output in_output@omega
link : out@investmentGross in_investmentGross@investmentNetReal
link : out@labor in_labor@employmentRate
link : out@labor out_labor
link : out@output out_output
link : out@employmentRate out_employmentrate
link : out@wageBill out_wagebill

% Link Aux's a funciones que las usan 
link : out@wageFunction in_wageFunction@fpwageRatechgWageRate
link : out@investmentNetReal in_investmentNetReal@fpCapitalchgCapital

% Links internos de los acoplados minimales (Ftot => Integrador)
link : out@ftCapitalIntegrator in@capitalIntegrator
link : out@ftLaborProductivityIntegrator in@laborProductivityIntegrator
link : out@ftWageRateIntegrator in@wageRateIntegrator
link : out@ftPopulationIntegrator in@populationIntegrator

% Links internos de los acoplados minimales (Fms => Fts)

% Links internos de los acoplados minimales (Fps => Fts)
link : out@fpPopulationchgPopulation inPlus_chgPopulation@ftPopulationIntegrator
link : out@fpwageRatechgWageRate inPlus_chgWageRate@ftwageRateIntegrator
link : out@fpLaborProductivitychgLaborProductivity inPlus_chgLaborProductivity@ftLaborProductivityIntegrator
link : out@fpCapitalchgCapital inPlus_chgCapital@ftCapitalIntegrator

% Links importantes del modelo
link : out@capitalIntegrator in_capitalIntegrator@output
link : out@capitalIntegrator in_capitalIntegrator@investmentNetReal
link : out@laborProductivityIntegrator in_laborProductivityIntegrator@fpLaborProductivitychgLaborProductivity
link : out@laborProductivityIntegrator in_laborProductivityIntegrator@labor
link : out@wageRateIntegrator in_wageRateIntegrator@fpwageRatechgWageRate
link : out@wageRateIntegrator in_wageRateIntegrator@wageBill
link : out@populationIntegrator in_populationIntegrator@fpPopulationchgPopulation
link : out@populationIntegrator in_populationIntegrator@employmentRate

% Liks output variables de interes
link : out@capitalIntegrator out_capitalIntegrator
link : out@laborProductivityIntegrator out_laborProductivityIntegrator
link : out@wageRateIntegrator out_wageRateIntegrator
link : out@populationIntegrator out_populationIntegrator

% Integradores
[capitalIntegrator]
x0 : 300
dQRel : 1e-4
dQMin : 1e-4

[laborProductivityIntegrator]
x0 : 1
dQRel : 1e-4
dQMin : 1e-4

[wageRateIntegrator]
x0 : 0.8
dQRel : 1e-4
dQMin : 1e-4

[populationIntegrator]
x0 : 150
dQRel : 1e-4
dQMin : 1e-4

