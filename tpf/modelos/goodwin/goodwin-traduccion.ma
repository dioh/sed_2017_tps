[top]
components : Debt@QSS1 WageRate@QSS1 LaborProductivity@QSS1 Capital@QSS1 Population@QSS1 ft_WageRate@ft_WageRate ft_Debt@ft_Debt ft_Capital@ft_Capital ft_LaborProductivity@ft_LaborProductivity ft_Population@ft_Population fp_Capital_chgCapital@fp_Capital_chgCapital fp_WageRate_chgWageRate@fp_WageRate_chgWageRate fp_Population_chgPopulation@fp_Population_chgPopulation fp_Debt_chgDebt@fp_Debt_chgDebt fp_LaborProductivity_chgLaborProductivity@fp_LaborProductivity_chgLaborProductivity deltaKReal@Cte Betaa@Cte rateInterestOnLoans@Cte piZ@Cte Alphaa@Cte employmentRateZero@Cte employmentRateStable@Cte piS@Cte velocityOfMoney@Cte wageFunction@wageFunction InvestmentGross@InvestmentGross InterestPayments@InterestPayments ProfitNet@ProfitNet InvestmentFunctionReal@InvestmentFunctionReal employmentRate@employmentRate piR@piR ProfitGrossReal@ProfitGrossReal Output@Output Wages@Wages Labor@Labor Omega@Omega debtRate@debtRate InvestmentNetReal@InvestmentNetReal 

% Puertos: Input de parametros. Output de variables de interes
in : in_piS in_Betaa in_rateInterestOnLoans in_piZ in_Alphaa in_employmentRateZero in_employmentRateStable in_deltaKReal in_velocityOfMoney 
out : out_LaborProductivity out_WageRate out_Debt out_Population out_Capital 

% Links inputs a constantes (conexiones con el top model)
link : in_piS inValue@piS 
link : in_Betaa inValue@Betaa 
link : in_rateInterestOnLoans inValue@rateInterestOnLoans 
link : in_piZ inValue@piZ 
link : in_Alphaa inValue@Alphaa 
link : in_employmentRateZero inValue@employmentRateZero 
link : in_employmentRateStable inValue@employmentRateStable 
link : in_deltaKReal inValue@deltaKReal 
link : in_velocityOfMoney inValue@velocityOfMoney 


% Link entre Stocks, Cte's, Aux's y f's
link : out@Betaa in_Betaa@fp_Population_chgPopulation 
link : out@Alphaa in_Alphaa@fp_LaborProductivity_chgLaborProductivity 
link : out@piS in_piS@InvestmentFunctionReal 
link : out@rateInterestOnLoans in_rateInterestOnLoans@InterestPayments 
link : out@piZ in_piZ@InvestmentFunctionReal 
link : out@employmentRateZero in_employmentRateZero@wageFunction 
link : out@employmentRateStable in_employmentRateStable@wageFunction 
link : out@deltaKReal in_deltaKReal@InvestmentNetReal 
link : out@velocityOfMoney in_velocityOfMoney@Output 
link : out@InvestmentGross in_InvestmentGross@InvestmentNetReal 
link : out@InterestPayments in_InterestPayments@ProfitNet 
link : out@ProfitNet in_ProfitNet@piR 
link : out@InvestmentFunctionReal in_InvestmentFunctionReal@InvestmentGross 
link : out@Labor in_Labor@Wages 
link : out@Labor in_Labor@employmentRate 
link : out@ProfitGrossReal in_ProfitGrossReal@ProfitNet 
link : out@Output in_Output@InvestmentGross 
link : out@Output in_Output@debtRate 
link : out@Output in_Output@Omega 
link : out@Output in_Output@Labor 
link : out@Output in_Output@ProfitGrossReal 
link : out@Wages in_Wages@Omega 
link : out@Wages in_Wages@ProfitGrossReal 
link : out@piR in_piR@InvestmentFunctionReal 
link : out@employmentRate in_employmentRate@wageFunction 
link : out@wageFunction in_wageFunction@fp_WageRate_chgWageRate 
link : out@InvestmentGross in_InvestmentGross@fp_Debt_chgDebt 
link : out@InvestmentNetReal in_InvestmentNetReal@fp_Capital_chgCapital 
link : out@LaborProductivity in_LaborProductivity@Labor 
link : out@WageRate in_WageRate@Wages 
link : out@Debt in_Debt@InterestPayments 
link : out@Debt in_Debt@debtRate 
link : out@Population in_Population@employmentRate 
link : out@Capital in_Capital@Output 
link : out@Capital in_Capital@InvestmentNetReal 
link : out@Capital in_Capital@piR 
link : out@fp_LaborProductivity_chgLaborProductivity inPlus_chgLaborProductivity@ft_LaborProductivity 
link : out@ft_LaborProductivity in@LaborProductivity 
link : out@fp_WageRate_chgWageRate inPlus_chgWageRate@ft_WageRate 
link : out@ft_WageRate in@WageRate 
link : out@fp_Debt_chgDebt inPlus_chgDebt@ft_Debt 



% Liks output variables de interes
link : out@Debt out_Debt
link : out@WageRate out_WageRate
link : out@LaborProductivity out_LaborProductivity
link : out@Capital out_Capital
link : out@Population out_Population


% Integradores
[Debt]
x0 : x0
dQRel : 1e-4
dQMin : ee-4

[WageRate]
x0 : x0
dQRel : 1e-4
dQMin : ee-4

[LaborProductivity]
x0 : x0
dQRel : 1e-4
dQMin : ee-4

[Capital]
x0 : x0
dQRel : 1e-4
dQMin : ee-4

[Population]
x0 : x0
dQRel : 1e-4
dQMin : ee-4

