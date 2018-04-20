[top]
components : DebtTot@DebtTot Debt@QSS1 wageRateTot@wageRateTot wageRate@QSS1 LaborProductivityTot@LaborProductivityTot LaborProductivity@QSS1 CapitalTot@CapitalTot Capital@QSS1 PopulationTot@PopulationTot Population@QSS1 wageFunction@wageFunction velocityOfMoney@Cte Betaa@Cte employmentRateValue@employmentRateValue Labor@Labor Alphaa@Cte employmentRateStable@Cte Interest@Interest Output@Output deltaKReal@Cte omega@omega Wages@Wages InvestmentGross@InvestmentGross ProfitNet@ProfitNet rateInterestOnLoans@Cte piZ@Cte employmentRateZero@Cte ProfitGrossReal@ProfitGrossReal piR@piR piS@Cte InvestmentFunctionReal@InvestmentFunctionReal InvestmentNetReal@InvestmentNetReal chgPopulationPlus@chgPopulationPlus chgPopulationMinus@chgPopulationMinus chgLaborProductivityPlus@chgLaborProductivityPlus chgLaborProductivityMinus@chgLaborProductivityMinus chgDebtPlus@chgDebtPlus chgDebtMinus@chgDebtMinus chgwageRatePlus@chgwageRatePlus chgwageRateMinus@chgwageRateMinus chgCapitalPlus@chgCapitalPlus chgCapitalMinus@chgCapitalMinus 

% External Input Ports
in : velocityOfMoney Betaa Alphaa employmentRateStable deltaKReal rateInterestOnLoans piZ employmentRateZero piS 
% External Output Ports
out : Debt wageRate LaborProductivity Capital Population 

% Links internos (input ports => atomicos tipo 'Cte')
link : velocityOfMoney inValue@velocityOfMoney
link : Betaa inValue@Betaa
link : Alphaa inValue@Alphaa
link : employmentRateStable inValue@employmentRateStable
link : deltaKReal inValue@deltaKReal
link : rateInterestOnLoans inValue@rateInterestOnLoans
link : piZ inValue@piZ
link : employmentRateZero inValue@employmentRateZero
link : piS inValue@piS

% Internal I/O Connections
link : out@DebtTot in@Debt
link : out@wageRateTot in@wageRate
link : out@LaborProductivityTot in@LaborProductivity
link : out@CapitalTot in@Capital
link : out@PopulationTot in@Population
link : out@chgPopulationPlus chgPopulationPlus@PopulationTot
link : out@chgLaborProductivityPlus chgLaborProductivityPlus@LaborProductivityTot
link : out@chgDebtPlus chgDebtPlus@DebtTot
link : out@chgwageRatePlus chgwageRatePlus@wageRateTot
link : out@chgCapitalPlus chgCapitalPlus@CapitalTot
link : out@Debt Debt@Interest
link : out@wageRate wageRate@chgwageRatePlus
link : out@wageRate wageRate@chgwageRateMinus
link : out@wageRate wageRate@Wages
link : out@LaborProductivity LaborProductivity@chgLaborProductivityPlus
link : out@LaborProductivity LaborProductivity@chgLaborProductivityMinus
link : out@LaborProductivity LaborProductivity@Labor
link : out@Capital Capital@Output
link : out@Capital Capital@piR
link : out@Capital Capital@InvestmentNetReal
link : out@Population Population@chgPopulationPlus
link : out@Population Population@chgPopulationMinus
link : out@Population Population@employmentRateValue
link : out@wageFunction wageFunction@chgwageRatePlus
link : out@wageFunction wageFunction@chgwageRateMinus
link : out@velocityOfMoney velocityOfMoney@Output
link : out@Betaa Betaa@chgPopulationPlus
link : out@Betaa Betaa@chgPopulationMinus
link : out@employmentRateValue employmentRateValue@wageFunction
link : out@Labor Labor@employmentRateValue
link : out@Labor Labor@Wages
link : out@Alphaa Alphaa@chgLaborProductivityPlus
link : out@Alphaa Alphaa@chgLaborProductivityMinus
link : out@employmentRateStable employmentRateStable@wageFunction
link : out@Interest Interest@ProfitNet
link : out@Output Output@Labor
link : out@Output Output@omega
link : out@Output Output@InvestmentGross
link : out@Output Output@ProfitGrossReal
link : out@deltaKReal deltaKReal@InvestmentNetReal
link : out@Wages Wages@omega
link : out@Wages Wages@ProfitGrossReal
link : out@InvestmentGross InvestmentGross@chgDebtPlus
link : out@InvestmentGross InvestmentGross@chgDebtMinus
link : out@InvestmentGross InvestmentGross@InvestmentNetReal
link : out@ProfitNet ProfitNet@piR
link : out@rateInterestOnLoans rateInterestOnLoans@Interest
link : out@piZ piZ@InvestmentFunctionReal
link : out@employmentRateZero employmentRateZero@wageFunction
link : out@ProfitGrossReal ProfitGrossReal@ProfitNet
link : out@piR piR@InvestmentFunctionReal
link : out@piS piS@InvestmentFunctionReal
link : out@InvestmentFunctionReal InvestmentFunctionReal@InvestmentGross
link : out@InvestmentNetReal InvestmentNetReal@chgCapitalPlus
link : out@InvestmentNetReal InvestmentNetReal@chgCapitalMinus

% Links internos (variables de interes => output ports)
link : out@Debt Debt
link : out@wageRate wageRate
link : out@LaborProductivity LaborProductivity
link : out@Capital Capital
link : out@Population Population

% Integradores
[Debt]
x0 : 0
dQRel : 0.0001
dQMin : 0.0001
[wageRate]
x0 : 0.8
dQRel : 0.0001
dQMin : 0.0001
[LaborProductivity]
x0 : 1
dQRel : 0.0001
dQMin : 0.0001
[Capital]
x0 : 300
dQRel : 0.0001
dQMin : 0.0001
[Population]
x0 : 150
dQRel : 0.0001
dQMin : 0.0001