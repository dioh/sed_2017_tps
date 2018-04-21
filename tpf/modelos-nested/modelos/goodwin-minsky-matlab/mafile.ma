
[top]
%Coupled model
components: Interest0@Interesttop InvestmentFunctionReal0@InvestmentFunctionRealtop InvestmentGross0@InvestmentGrosstop InvestmentNetReal0@InvestmentNetRealtop Labor0@Labortop Output0@Outputtop ProfitGrossReal0@ProfitGrossRealtop ProfitNet0@ProfitNettop Wages0@Wagestop employmentRateValue0@employmentRateValuetop omega0@omegatop piR0@piRtop wageFunction0@wageFunctiontop  DEVS_BASIC_COUPLED_Capital  DEVS_BASIC_COUPLED_Debt  DEVS_BASIC_COUPLED_LaborProductivity  DEVS_BASIC_COUPLED_Population  DEVS_BASIC_COUPLED_wageRate Alphaa0@Alphaatop Betaa0@Betaatop deltaKReal0@deltaKRealtop employmentRateStable0@employmentRateStabletop employmentRateZero0@employmentRateZerotop piS0@piStop piZ0@piZtop rateInterestOnLoans0@rateInterestOnLoanstop velocityOfMoney0@velocityOfMoneytop

% In ports
in: in_port_Alphaa in_port_Betaa in_port_deltaKReal in_port_employmentRateStable in_port_employmentRateZero in_port_piS in_port_piZ in_port_rateInterestOnLoans in_port_velocityOfMoney


% Out ports
out: out_port_Capital out_port_Debt out_port_Interest out_port_InvestmentFunctionReal out_port_InvestmentGross out_port_InvestmentNetReal out_port_Labor out_port_LaborProductivity out_port_Output out_port_Population out_port_ProfitGrossReal out_port_ProfitNet out_port_Wages out_port_employmentRateValue out_port_omega out_port_piR out_port_wageFunction out_port_wageRate

% Input connections
link: in_port_Alphaa in_port_Alphaa@Alphaa0
link: in_port_Betaa in_port_Betaa@Betaa0
link: in_port_deltaKReal in_port_deltaKReal@deltaKReal0
link: in_port_employmentRateStable in_port_employmentRateStable@employmentRateStable0
link: in_port_employmentRateZero in_port_employmentRateZero@employmentRateZero0
link: in_port_piS in_port_piS@piS0
link: in_port_piZ in_port_piZ@piZ0
link: in_port_rateInterestOnLoans in_port_rateInterestOnLoans@rateInterestOnLoans0
link: in_port_velocityOfMoney in_port_velocityOfMoney@velocityOfMoney0

% Output connections
link: out_port_Capital@DEVS_BASIC_COUPLED_Capital out_port_Capital
link: out_port_Debt@DEVS_BASIC_COUPLED_Debt out_port_Debt
link: out_port_Interest@Interest0 out_port_Interest
link: out_port_InvestmentFunctionReal@InvestmentFunctionReal0 out_port_InvestmentFunctionReal
link: out_port_InvestmentGross@InvestmentGross0 out_port_InvestmentGross
link: out_port_InvestmentNetReal@InvestmentNetReal0 out_port_InvestmentNetReal
link: out_port_Labor@Labor0 out_port_Labor
link: out_port_LaborProductivity@DEVS_BASIC_COUPLED_LaborProductivity out_port_LaborProductivity
link: out_port_Output@Output0 out_port_Output
link: out_port_Population@DEVS_BASIC_COUPLED_Population out_port_Population
link: out_port_ProfitGrossReal@ProfitGrossReal0 out_port_ProfitGrossReal
link: out_port_ProfitNet@ProfitNet0 out_port_ProfitNet
link: out_port_Wages@Wages0 out_port_Wages
link: out_port_employmentRateValue@employmentRateValue0 out_port_employmentRateValue
link: out_port_omega@omega0 out_port_omega
link: out_port_piR@piR0 out_port_piR
link: out_port_wageFunction@wageFunction0 out_port_wageFunction
link: out_port_wageRate@DEVS_BASIC_COUPLED_wageRate out_port_wageRate

% Internal connections
link: out_port_InvestmentNetReal@InvestmentNetReal0 in_port_InvestmentNetReal@DEVS_BASIC_COUPLED_Capital
link: out_port_InvestmentGross@InvestmentGross0 in_port_InvestmentGross@DEVS_BASIC_COUPLED_Debt
link: out_port_Alphaa@Alphaa0 in_port_Alphaa@DEVS_BASIC_COUPLED_LaborProductivity
link: out_port_Betaa@Betaa0 in_port_Betaa@DEVS_BASIC_COUPLED_Population
link: out_port_wageFunction@wageFunction0 in_port_wageFunction@DEVS_BASIC_COUPLED_wageRate
link: out_port_Debt@DEVS_BASIC_COUPLED_Debt in_port_Debt@Interest0
link: out_port_rateInterestOnLoans@rateInterestOnLoans0 in_port_rateInterestOnLoans@Interest0
link: out_port_piR@piR0 in_port_piR@InvestmentFunctionReal0
link: out_port_piS@piS0 in_port_piS@InvestmentFunctionReal0
link: out_port_piZ@piZ0 in_port_piZ@InvestmentFunctionReal0
link: out_port_InvestmentFunctionReal@InvestmentFunctionReal0 in_port_InvestmentFunctionReal@InvestmentGross0
link: out_port_Output@Output0 in_port_Output@InvestmentGross0
link: out_port_Capital@DEVS_BASIC_COUPLED_Capital in_port_Capital@InvestmentNetReal0
link: out_port_InvestmentGross@InvestmentGross0 in_port_InvestmentGross@InvestmentNetReal0
link: out_port_deltaKReal@deltaKReal0 in_port_deltaKReal@InvestmentNetReal0
link: out_port_LaborProductivity@DEVS_BASIC_COUPLED_LaborProductivity in_port_LaborProductivity@Labor0
link: out_port_Output@Output0 in_port_Output@Labor0
link: out_port_Capital@DEVS_BASIC_COUPLED_Capital in_port_Capital@Output0
link: out_port_velocityOfMoney@velocityOfMoney0 in_port_velocityOfMoney@Output0
link: out_port_Output@Output0 in_port_Output@ProfitGrossReal0
link: out_port_Wages@Wages0 in_port_Wages@ProfitGrossReal0
link: out_port_Interest@Interest0 in_port_Interest@ProfitNet0
link: out_port_ProfitGrossReal@ProfitGrossReal0 in_port_ProfitGrossReal@ProfitNet0
link: out_port_Labor@Labor0 in_port_Labor@Wages0
link: out_port_wageRate@DEVS_BASIC_COUPLED_wageRate in_port_wageRate@Wages0
link: out_port_Labor@Labor0 in_port_Labor@employmentRateValue0
link: out_port_Population@DEVS_BASIC_COUPLED_Population in_port_Population@employmentRateValue0
link: out_port_Output@Output0 in_port_Output@omega0
link: out_port_Wages@Wages0 in_port_Wages@omega0
link: out_port_Capital@DEVS_BASIC_COUPLED_Capital in_port_Capital@piR0
link: out_port_ProfitNet@ProfitNet0 in_port_ProfitNet@piR0
link: out_port_employmentRateStable@employmentRateStable0 in_port_employmentRateStable@wageFunction0
link: out_port_employmentRateValue@employmentRateValue0 in_port_employmentRateValue@wageFunction0
link: out_port_employmentRateZero@employmentRateZero0 in_port_employmentRateZero@wageFunction0

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')



























[DEVS_BASIC_COUPLED_Capital]
%Coupled model
components: chgCapital_Capital1@chgCapital_CapitalDEVS_BASIC_COUPLED_Capital TotCapital1@TotCapitalDEVS_BASIC_COUPLED_Capital Capital1@CapitalDEVS_BASIC_COUPLED_Capital

% In ports
in: in_port_InvestmentNetReal


% Out ports
out: out_port_Capital

% Input connections
link: in_port_InvestmentNetReal in_port_InvestmentNetReal@chgCapital_Capital1

% Output connections
link: out_port_Capital@Capital1 out_port_Capital

% Internal connections
link: out_port_TotCapital@TotCapital1 in_port_TotCapital@Capital1
link: out_port_chgCapital_Capital@chgCapital_Capital1 in_plus_port_chgCapital_Capital@TotCapital1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[Capital1]
% Atomic model DEVSIntegrator
x0: 300
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_Debt]
%Coupled model
components: chgDebt_Debt1@chgDebt_DebtDEVS_BASIC_COUPLED_Debt TotDebt1@TotDebtDEVS_BASIC_COUPLED_Debt Debt1@DebtDEVS_BASIC_COUPLED_Debt

% In ports
in: in_port_InvestmentGross


% Out ports
out: out_port_Debt

% Input connections
link: in_port_InvestmentGross in_port_InvestmentGross@chgDebt_Debt1

% Output connections
link: out_port_Debt@Debt1 out_port_Debt

% Internal connections
link: out_port_TotDebt@TotDebt1 in_port_TotDebt@Debt1
link: out_port_chgDebt_Debt@chgDebt_Debt1 in_plus_port_chgDebt_Debt@TotDebt1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[Debt1]
% Atomic model DEVSIntegrator
x0: 0
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_LaborProductivity]
%Coupled model
components: chgLaborProductivity_LaborProductivity1@chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity TotLaborProductivity1@TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity LaborProductivity1@LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity

% In ports
in: in_port_Alphaa


% Out ports
out: out_port_LaborProductivity

% Input connections
link: in_port_Alphaa in_port_Alphaa@chgLaborProductivity_LaborProductivity1

% Output connections
link: out_port_LaborProductivity@LaborProductivity1 out_port_LaborProductivity

% Internal connections
link: out_port_TotLaborProductivity@TotLaborProductivity1 in_port_TotLaborProductivity@LaborProductivity1
link: out_port_chgLaborProductivity_LaborProductivity@chgLaborProductivity_LaborProductivity1 in_plus_port_chgLaborProductivity_LaborProductivity@TotLaborProductivity1
link: out_port_LaborProductivity@LaborProductivity1 in_port_LaborProductivity@chgLaborProductivity_LaborProductivity1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[LaborProductivity1]
% Atomic model DEVSIntegrator
x0: 1
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_Population]
%Coupled model
components: chgPopulation_Population1@chgPopulation_PopulationDEVS_BASIC_COUPLED_Population TotPopulation1@TotPopulationDEVS_BASIC_COUPLED_Population Population1@PopulationDEVS_BASIC_COUPLED_Population

% In ports
in: in_port_Betaa


% Out ports
out: out_port_Population

% Input connections
link: in_port_Betaa in_port_Betaa@chgPopulation_Population1

% Output connections
link: out_port_Population@Population1 out_port_Population

% Internal connections
link: out_port_TotPopulation@TotPopulation1 in_port_TotPopulation@Population1
link: out_port_chgPopulation_Population@chgPopulation_Population1 in_plus_port_chgPopulation_Population@TotPopulation1
link: out_port_Population@Population1 in_port_Population@chgPopulation_Population1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[Population1]
% Atomic model DEVSIntegrator
x0: 150
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_wageRate]
%Coupled model
components: chgwageRate_wageRate1@chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate TotwageRate1@TotwageRateDEVS_BASIC_COUPLED_wageRate wageRate1@wageRateDEVS_BASIC_COUPLED_wageRate

% In ports
in: in_port_wageFunction


% Out ports
out: out_port_wageRate

% Input connections
link: in_port_wageFunction in_port_wageFunction@chgwageRate_wageRate1

% Output connections
link: out_port_wageRate@wageRate1 out_port_wageRate

% Internal connections
link: out_port_chgwageRate_wageRate@chgwageRate_wageRate1 in_plus_port_chgwageRate_wageRate@TotwageRate1
link: out_port_wageRate@wageRate1 in_port_wageRate@chgwageRate_wageRate1
link: out_port_TotwageRate@TotwageRate1 in_port_TotwageRate@wageRate1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[wageRate1]
% Atomic model DEVSIntegrator
x0: 0.8
dQMin: 0.001
dQRel: 0.001




















