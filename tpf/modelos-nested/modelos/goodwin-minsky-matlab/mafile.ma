
[top]
%Coupled model
components: Interest@Interesttop InvestmentFunctionReal@InvestmentFunctionRealtop InvestmentGross@InvestmentGrosstop InvestmentNetReal@InvestmentNetRealtop Labor@Labortop Output@Outputtop ProfitGrossReal@ProfitGrossRealtop ProfitNet@ProfitNettop Wages@Wagestop employmentRateValue@employmentRateValuetop omega@omegatop piR@piRtop wageFunction@wageFunctiontop  DEVS_BASIC_COUPLED_Capital  DEVS_BASIC_COUPLED_Debt  DEVS_BASIC_COUPLED_LaborProductivity  DEVS_BASIC_COUPLED_Population  DEVS_BASIC_COUPLED_wageRate Alphaa@Alphaatop Betaa@Betaatop deltaKReal@deltaKRealtop employmentRateStable@employmentRateStabletop employmentRateZero@employmentRateZerotop piS@piStop piZ@piZtop rateInterestOnLoans@rateInterestOnLoanstop velocityOfMoney@velocityOfMoneytop

% In ports
in: in_port_Alphaa in_port_Betaa in_port_deltaKReal in_port_employmentRateStable in_port_employmentRateZero in_port_piS in_port_piZ in_port_rateInterestOnLoans in_port_velocityOfMoney


% Out ports
out: out_port_Capital out_port_Debt out_port_Interest out_port_InvestmentFunctionReal out_port_InvestmentGross out_port_InvestmentNetReal out_port_Labor out_port_LaborProductivity out_port_Output out_port_Population out_port_ProfitGrossReal out_port_ProfitNet out_port_Wages out_port_employmentRateValue out_port_omega out_port_piR out_port_wageFunction out_port_wageRate

% Input connections
link: in_port_Alphaa in_port_Alphaa@Alphaa
link: in_port_Betaa in_port_Betaa@Betaa
link: in_port_deltaKReal in_port_deltaKReal@deltaKReal
link: in_port_employmentRateStable in_port_employmentRateStable@employmentRateStable
link: in_port_employmentRateZero in_port_employmentRateZero@employmentRateZero
link: in_port_piS in_port_piS@piS
link: in_port_piZ in_port_piZ@piZ
link: in_port_rateInterestOnLoans in_port_rateInterestOnLoans@rateInterestOnLoans
link: in_port_velocityOfMoney in_port_velocityOfMoney@velocityOfMoney

% Output connections
link: out_port_Capital@DEVS_BASIC_COUPLED_Capital out_port_Capital
link: out_port_Debt@DEVS_BASIC_COUPLED_Debt out_port_Debt
link: out_port_Interest@Interest out_port_Interest
link: out_port_InvestmentFunctionReal@InvestmentFunctionReal out_port_InvestmentFunctionReal
link: out_port_InvestmentGross@InvestmentGross out_port_InvestmentGross
link: out_port_InvestmentNetReal@InvestmentNetReal out_port_InvestmentNetReal
link: out_port_Labor@Labor out_port_Labor
link: out_port_LaborProductivity@DEVS_BASIC_COUPLED_LaborProductivity out_port_LaborProductivity
link: out_port_Output@Output out_port_Output
link: out_port_Population@DEVS_BASIC_COUPLED_Population out_port_Population
link: out_port_ProfitGrossReal@ProfitGrossReal out_port_ProfitGrossReal
link: out_port_ProfitNet@ProfitNet out_port_ProfitNet
link: out_port_Wages@Wages out_port_Wages
link: out_port_employmentRateValue@employmentRateValue out_port_employmentRateValue
link: out_port_omega@omega out_port_omega
link: out_port_piR@piR out_port_piR
link: out_port_wageFunction@wageFunction out_port_wageFunction
link: out_port_wageRate@DEVS_BASIC_COUPLED_wageRate out_port_wageRate

% Internal connections
link: out_port_InvestmentNetReal@InvestmentNetReal in_port_InvestmentNetReal@DEVS_BASIC_COUPLED_Capital
link: out_port_InvestmentGross@InvestmentGross in_port_InvestmentGross@DEVS_BASIC_COUPLED_Debt
link: out_port_Alphaa@Alphaa in_port_Alphaa@DEVS_BASIC_COUPLED_LaborProductivity
link: out_port_Betaa@Betaa in_port_Betaa@DEVS_BASIC_COUPLED_Population
link: out_port_wageFunction@wageFunction in_port_wageFunction@DEVS_BASIC_COUPLED_wageRate
link: out_port_Debt@DEVS_BASIC_COUPLED_Debt in_port_Debt@Interest
link: out_port_rateInterestOnLoans@rateInterestOnLoans in_port_rateInterestOnLoans@Interest
link: out_port_piR@piR in_port_piR@InvestmentFunctionReal
link: out_port_piS@piS in_port_piS@InvestmentFunctionReal
link: out_port_piZ@piZ in_port_piZ@InvestmentFunctionReal
link: out_port_InvestmentFunctionReal@InvestmentFunctionReal in_port_InvestmentFunctionReal@InvestmentGross
link: out_port_Output@Output in_port_Output@InvestmentGross
link: out_port_Capital@DEVS_BASIC_COUPLED_Capital in_port_Capital@InvestmentNetReal
link: out_port_InvestmentGross@InvestmentGross in_port_InvestmentGross@InvestmentNetReal
link: out_port_deltaKReal@deltaKReal in_port_deltaKReal@InvestmentNetReal
link: out_port_LaborProductivity@DEVS_BASIC_COUPLED_LaborProductivity in_port_LaborProductivity@Labor
link: out_port_Output@Output in_port_Output@Labor
link: out_port_Capital@DEVS_BASIC_COUPLED_Capital in_port_Capital@Output
link: out_port_velocityOfMoney@velocityOfMoney in_port_velocityOfMoney@Output
link: out_port_Output@Output in_port_Output@ProfitGrossReal
link: out_port_Wages@Wages in_port_Wages@ProfitGrossReal
link: out_port_Interest@Interest in_port_Interest@ProfitNet
link: out_port_ProfitGrossReal@ProfitGrossReal in_port_ProfitGrossReal@ProfitNet
link: out_port_Labor@Labor in_port_Labor@Wages
link: out_port_wageRate@DEVS_BASIC_COUPLED_wageRate in_port_wageRate@Wages
link: out_port_Labor@Labor in_port_Labor@employmentRateValue
link: out_port_Population@DEVS_BASIC_COUPLED_Population in_port_Population@employmentRateValue
link: out_port_Output@Output in_port_Output@omega
link: out_port_Wages@Wages in_port_Wages@omega
link: out_port_Capital@DEVS_BASIC_COUPLED_Capital in_port_Capital@piR
link: out_port_ProfitNet@ProfitNet in_port_ProfitNet@piR
link: out_port_employmentRateStable@employmentRateStable in_port_employmentRateStable@wageFunction
link: out_port_employmentRateValue@employmentRateValue in_port_employmentRateValue@wageFunction
link: out_port_employmentRateZero@employmentRateZero in_port_employmentRateZero@wageFunction

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')



























[DEVS_BASIC_COUPLED_Capital]
%Coupled model
components: chgCapital_Capital@chgCapital_CapitalDEVS_BASIC_COUPLED_Capital TotCapital@TotCapitalDEVS_BASIC_COUPLED_Capital Capital@CapitalDEVS_BASIC_COUPLED_Capital

% In ports
in: in_port_InvestmentNetReal


% Out ports
out: out_port_Capital

% Input connections
link: in_port_InvestmentNetReal in_port_InvestmentNetReal@chgCapital_Capital

% Output connections
link: out_port_Capital@Capital out_port_Capital

% Internal connections
link: out_port_TotCapital@TotCapital in_port_TotCapital@Capital
link: out_port_chgCapital_Capital@chgCapital_Capital in_plus_port_chgCapital_Capital@TotCapital

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[Capital]
% Atomic model DEVSIntegrator
x0: 300
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_Debt]
%Coupled model
components: chgDebt_Debt@chgDebt_DebtDEVS_BASIC_COUPLED_Debt TotDebt@TotDebtDEVS_BASIC_COUPLED_Debt Debt@DebtDEVS_BASIC_COUPLED_Debt

% In ports
in: in_port_InvestmentGross


% Out ports
out: out_port_Debt

% Input connections
link: in_port_InvestmentGross in_port_InvestmentGross@chgDebt_Debt

% Output connections
link: out_port_Debt@Debt out_port_Debt

% Internal connections
link: out_port_TotDebt@TotDebt in_port_TotDebt@Debt
link: out_port_chgDebt_Debt@chgDebt_Debt in_plus_port_chgDebt_Debt@TotDebt

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[Debt]
% Atomic model DEVSIntegrator
x0: 0
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_LaborProductivity]
%Coupled model
components: chgLaborProductivity_LaborProductivity@chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity TotLaborProductivity@TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity LaborProductivity@LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity

% In ports
in: in_port_Alphaa


% Out ports
out: out_port_LaborProductivity

% Input connections
link: in_port_Alphaa in_port_Alphaa@chgLaborProductivity_LaborProductivity

% Output connections
link: out_port_LaborProductivity@LaborProductivity out_port_LaborProductivity

% Internal connections
link: out_port_TotLaborProductivity@TotLaborProductivity in_port_TotLaborProductivity@LaborProductivity
link: out_port_chgLaborProductivity_LaborProductivity@chgLaborProductivity_LaborProductivity in_plus_port_chgLaborProductivity_LaborProductivity@TotLaborProductivity
link: out_port_LaborProductivity@LaborProductivity in_port_LaborProductivity@chgLaborProductivity_LaborProductivity

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[LaborProductivity]
% Atomic model DEVSIntegrator
x0: 1
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_Population]
%Coupled model
components: chgPopulation_Population@chgPopulation_PopulationDEVS_BASIC_COUPLED_Population TotPopulation@TotPopulationDEVS_BASIC_COUPLED_Population Population@PopulationDEVS_BASIC_COUPLED_Population

% In ports
in: in_port_Betaa


% Out ports
out: out_port_Population

% Input connections
link: in_port_Betaa in_port_Betaa@chgPopulation_Population

% Output connections
link: out_port_Population@Population out_port_Population

% Internal connections
link: out_port_TotPopulation@TotPopulation in_port_TotPopulation@Population
link: out_port_chgPopulation_Population@chgPopulation_Population in_plus_port_chgPopulation_Population@TotPopulation
link: out_port_Population@Population in_port_Population@chgPopulation_Population

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[Population]
% Atomic model DEVSIntegrator
x0: 150
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_wageRate]
%Coupled model
components: chgwageRate_wageRate@chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate TotwageRate@TotwageRateDEVS_BASIC_COUPLED_wageRate wageRate@wageRateDEVS_BASIC_COUPLED_wageRate

% In ports
in: in_port_wageFunction


% Out ports
out: out_port_wageRate

% Input connections
link: in_port_wageFunction in_port_wageFunction@chgwageRate_wageRate

% Output connections
link: out_port_wageRate@wageRate out_port_wageRate

% Internal connections
link: out_port_chgwageRate_wageRate@chgwageRate_wageRate in_plus_port_chgwageRate_wageRate@TotwageRate
link: out_port_wageRate@wageRate in_port_wageRate@chgwageRate_wageRate
link: out_port_TotwageRate@TotwageRate in_port_TotwageRate@wageRate

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[wageRate]
% Atomic model DEVSIntegrator
x0: 0.8
dQMin: 0.001
dQRel: 0.001




















