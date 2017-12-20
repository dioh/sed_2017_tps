[top]
components : LaborProductivityTot@LaborProductivityTot LaborProductivity@QSS1 WageRateTot@WageRateTot WageRate@QSS1 DebtTot@DebtTot Debt@QSS1 PopulationTot@PopulationTot Population@QSS1 CapitalTot@CapitalTot Capital@QSS1 wageFunction@wageFunction Betaa@Cte employmentRateValue@employmentRateValue rateInterestOnLoans@Cte Labor@Labor Alphaa@Cte employmentRateStable@Cte Output@Output deltaKReal@Cte piR@piR InvestmentGross@InvestmentGross InterestPayments@InterestPayments debtRate@debtRate ProfitNet@ProfitNet velocityOfMoney@Cte piZ@Cte employmentRateZero@Cte ProfitGrossReal@ProfitGrossReal Wages@Wages piS@Cte Omega@Omega InvestmentFunctionReal@InvestmentFunctionReal InvestmentNetReal@InvestmentNetReal chgPopulationPlus@chgPopulationPlus chgPopulationMinus@chgPopulationMinus chgLaborProductivityPlus@chgLaborProductivityPlus chgLaborProductivityMinus@chgLaborProductivityMinus chgDebtPlus@chgDebtPlus chgDebtMinus@chgDebtMinus chgWageRatePlus@chgWageRatePlus chgWageRateMinus@chgWageRateMinus chgCapitalPlus@chgCapitalPlus chgCapitalMinus@chgCapitalMinus 

% External Input Ports
in : Betaa rateInterestOnLoans Alphaa employmentRateStable deltaKReal velocityOfMoney piZ employmentRateZero piS 
% External Output Ports
out : LaborProductivity WageRate Debt Population Capital 

% Links internos (input ports => atomicos tipo 'Cte')
link : Betaa inValue@Betaa
link : rateInterestOnLoans inValue@rateInterestOnLoans
link : Alphaa inValue@Alphaa
link : employmentRateStable inValue@employmentRateStable
link : deltaKReal inValue@deltaKReal
link : velocityOfMoney inValue@velocityOfMoney
link : piZ inValue@piZ
link : employmentRateZero inValue@employmentRateZero
link : piS inValue@piS

% Internal I/O Connections
link : out@LaborProductivityTot in@LaborProductivity
link : out@WageRateTot in@WageRate
link : out@DebtTot in@Debt
link : out@PopulationTot in@Population
link : out@CapitalTot in@Capital
link : out@chgPopulationPlus chgPopulationPlus@PopulationTot
link : out@chgLaborProductivityPlus chgLaborProductivityPlus@LaborProductivityTot
link : out@chgDebtPlus chgDebtPlus@DebtTot
link : out@chgWageRatePlus chgWageRatePlus@WageRateTot
link : out@chgCapitalPlus chgCapitalPlus@CapitalTot
link : out@LaborProductivity LaborProductivity@chgLaborProductivityPlus
link : out@LaborProductivity LaborProductivity@Labor
link : out@WageRate WageRate@chgWageRatePlus
link : out@WageRate WageRate@Wages
link : out@Debt Debt@InterestPayments
link : out@Debt Debt@debtRate
link : out@Population Population@chgPopulationPlus
link : out@Population Population@employmentRateValue
link : out@Capital Capital@Output
link : out@Capital Capital@piR
link : out@Capital Capital@InvestmentNetReal
link : out@wageFunction wageFunction@chgWageRatePlus
link : out@wageFunction wageFunction@chgWageRateMinus
link : out@Betaa Betaa@chgPopulationPlus
link : out@Betaa Betaa@chgPopulationMinus
link : out@employmentRateValue employmentRateValue@wageFunction
link : out@rateInterestOnLoans rateInterestOnLoans@InterestPayments
link : out@Labor Labor@employmentRateValue
link : out@Labor Labor@Wages
link : out@Alphaa Alphaa@chgLaborProductivityPlus
link : out@Alphaa Alphaa@chgLaborProductivityMinus
link : out@employmentRateStable employmentRateStable@wageFunction
link : out@Output Output@Labor
link : out@Output Output@InvestmentGross
link : out@Output Output@debtRate
link : out@Output Output@ProfitGrossReal
link : out@Output Output@Omega
link : out@deltaKReal deltaKReal@InvestmentNetReal
link : out@piR piR@InvestmentFunctionReal
link : out@InvestmentGross InvestmentGross@chgDebtPlus
link : out@InvestmentGross InvestmentGross@chgDebtMinus
link : out@InvestmentGross InvestmentGross@InvestmentNetReal
link : out@InterestPayments InterestPayments@ProfitNet
link : out@ProfitNet ProfitNet@piR
link : out@velocityOfMoney velocityOfMoney@Output
link : out@piZ piZ@InvestmentFunctionReal
link : out@employmentRateZero employmentRateZero@wageFunction
link : out@ProfitGrossReal ProfitGrossReal@ProfitNet
link : out@Wages Wages@ProfitGrossReal
link : out@Wages Wages@Omega
link : out@piS piS@InvestmentFunctionReal
link : out@InvestmentFunctionReal InvestmentFunctionReal@InvestmentGross
link : out@InvestmentNetReal InvestmentNetReal@chgCapitalPlus
link : out@InvestmentNetReal InvestmentNetReal@chgCapitalMinus

% Links internos (variables de interes => output ports)
link : out@LaborProductivity LaborProductivity
link : out@WageRate WageRate
link : out@Debt Debt
link : out@Population Population
link : out@Capital Capital

% Integradores
[LaborProductivity]
x0 : 1
dQRel : 0.0001
dQMin : 0.0001
[WageRate]
x0 : 0.8
dQRel : 0.0001
dQMin : 0.0001
[Debt]
x0 : 0
dQRel : 0.0001
dQMin : 0.0001
[Population]
x0 : 150
dQRel : 0.0001
dQMin : 0.0001
[Capital]
x0 : 300
dQRel : 0.0001
dQMin : 0.0001