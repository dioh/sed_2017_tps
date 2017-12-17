[top]
components : capitalIntegrator@QSS1 laborProductivityIntegrator@QSS1 wageRateIntegrator@QSS1 debtIntegrator@QSS1 populationIntegrator@QSS1 ftDebtIntegrator@FtotDebtIntegrator ftWageRateIntegrator@FtotWageRateIntegrator ftCapitalIntegrator@FtotCapitalIntegrator ftPopulationIntegrator@FtotPopulationIntegrator ftLaborProductivityIntegrator@FtotLaborProductivityIntegrator fpPopulationchgPopulation@FplusPopulationchgPopulation fpCapitalchgCapital@FplusCapitalchgCapital fpWageRatechgWageRate@FplusWageRatechgWageRate fpLaborProductivitychgLaborProductivity@FplusLaborProductivitychgLaborProductivity fpDebtchgDebt@FplusDebtchgDebt deltaKReal@Cte betaa@Cte rateInterestOnLoans@Cte piZ@Cte alphaa@Cte employmentRateZero@Cte employmentRateStable@Cte piS@Cte velocityOfMoney@Cte  wageFunction@AuxwageFunction  investmentGross@AuxinvestmentGross  interestPayments@AuxinterestPayments  profitNet@AuxprofitNet  investmentFunctionReal@AuxinvestmentFunctionReal  investmentNetReal@AuxinvestmentNetReal  piR@AuxpiR  profitGrossReal@AuxprofitGrossReal  output@Auxoutput  wages@Auxwages  labor@Auxlabor  omega@Auxomega  debtRate@AuxdebtRate  employmentRate@AuxemploymentRate 

% Puertos: Input de parametros. Output de variables de interes
in : in_deltaKReal in_betaa in_rateInterestOnLoans in_piZ in_alphaa in_employmentRateZero in_employmentRateStable in_piS in_velocityOfMoney 
out : out_capitalIntegrator out_laborProductivityIntegrator out_wageRateIntegrator out_debtIntegrator out_populationIntegrator out_output out_labor out_debtrate out_employmentrate

% Links inputs a constantes (conexiones con el top model)
link : in_deltaKReal inValue@deltaKReal
link : in_betaa inValue@betaa
link : in_rateInterestOnLoans inValue@rateInterestOnLoans
link : in_piZ inValue@piZ
link : in_alphaa inValue@alphaa
link : in_employmentRateZero inValue@employmentRateZero
link : in_employmentRateStable inValue@employmentRateStable
link : in_piS inValue@piS
link : in_velocityOfMoney inValue@velocityOfMoney

% Links constantes a f's que las usan
link : out@betaa in_betaa@fpPopulationchgPopulation
link : out@alphaa in_alphaa@fpLaborProductivitychgLaborProductivity

% Link constantes a Aux's que las usan
link : out@employmentRateZero in_employmentRateZero@wageFunction
link : out@employmentRateStable in_employmentRateStable@wageFunction
link : out@rateInterestOnLoans in_rateInterestOnLoans@interestPayments
link : out@piZ in_piZ@investmentFunctionReal
link : out@piS in_piS@investmentFunctionReal
link : out@deltaKReal in_deltaKReal@investmentNetReal
link : out@velocityOfMoney in_velocityOfMoney@output

% Link Aux's a Aux's que las usan
link : out@employmentRate in_employmentRate@wageFunction
link : out@investmentFunctionReal in_investmentFunctionReal@investmentGross
link : out@output in_output@investmentGross
link : out@profitGrossReal in_profitGrossReal@profitNet
link : out@interestPayments in_interestPayments@profitNet
link : out@piR in_piR@investmentFunctionReal
link : out@investmentGross in_investmentGross@investmentNetReal
link : out@profitNet in_profitNet@piR
link : out@output in_output@profitGrossReal
link : out@wages in_wages@profitGrossReal
link : out@labor in_labor@wages
link : out@output in_output@labor
link : out@wages in_wages@omega
link : out@output in_output@omega
link : out@output in_output@debtRate
link : out@labor in_labor@employmentRate

link : out@labor out_labor
link : out@output out_output
link : out@debtRate out_debtrate
link : out@employmentRate out_employmentrate

% Link Aux's a funciones que las usan 
link : out@investmentNetReal in_investmentNetReal@fpCapitalchgCapital
link : out@wageFunction in_wageFunction@fpWageRatechgWageRate
link : out@investmentGross in_investmentGross@fpDebtchgDebt

% Links internos de los acoplados minimales (Ftot => Integrador)
link : out@ftCapitalIntegrator in@capitalIntegrator
link : out@ftLaborProductivityIntegrator in@laborProductivityIntegrator
link : out@ftWageRateIntegrator in@wageRateIntegrator
link : out@ftDebtIntegrator in@debtIntegrator
link : out@ftPopulationIntegrator in@populationIntegrator

% Links internos de los acoplados minimales (Fms => Fts)

% Links internos de los acoplados minimales (Fps => Fts)
link : out@fpPopulationchgPopulation inPlus_chgPopulation@ftPopulationIntegrator
link : out@fpCapitalchgCapital inPlus_chgCapital@ftCapitalIntegrator
link : out@fpWageRatechgWageRate inPlus_chgWageRate@ftWageRateIntegrator
link : out@fpLaborProductivitychgLaborProductivity inPlus_chgLaborProductivity@ftLaborProductivityIntegrator
link : out@fpDebtchgDebt inPlus_chgDebt@ftDebtIntegrator

% Links importantes del modelo
link : out@capitalIntegrator in_capitalIntegrator@investmentNetReal
link : out@capitalIntegrator in_capitalIntegrator@piR
link : out@capitalIntegrator in_capitalIntegrator@output
link : out@laborProductivityIntegrator in_laborProductivityIntegrator@fpLaborProductivitychgLaborProductivity
link : out@laborProductivityIntegrator in_laborProductivityIntegrator@labor
link : out@wageRateIntegrator in_wageRateIntegrator@fpWageRatechgWageRate
link : out@wageRateIntegrator in_wageRateIntegrator@wages
link : out@debtIntegrator in_debtIntegrator@interestPayments
link : out@debtIntegrator in_debtIntegrator@debtRate
link : out@populationIntegrator in_populationIntegrator@fpPopulationchgPopulation
link : out@populationIntegrator in_populationIntegrator@employmentRate

% Liks output variables de interes
link : out@capitalIntegrator out_capitalIntegrator
link : out@laborProductivityIntegrator out_laborProductivityIntegrator
link : out@wageRateIntegrator out_wageRateIntegrator
link : out@debtIntegrator out_debtIntegrator
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

[debtIntegrator]
x0 : 0
dQRel : 1e-4
dQMin : 1e-4

[populationIntegrator]
x0 : 150
dQRel : 1e-4
dQMin : 1e-4

