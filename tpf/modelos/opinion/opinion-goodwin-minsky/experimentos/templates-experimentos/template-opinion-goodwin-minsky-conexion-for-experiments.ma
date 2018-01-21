#include(macros.inc)

[top]
components : shocker0@Shocker shocker1@Shocker shocker2@Shocker shocker3@Shocker shocker4@Shocker conector@Conector opinion goodwin-minsky

in : inShockCriteria Betaa rateInterestOnLoans Alphaa employmentRateStable deltaKReal velocityOfMoney piZ employmentRateZero piS
out : LaborProductivity WageRate Debt Population Capital

% ======= Input Connections ======= %
link : inShockCriteria inShockCriteria@conector

link : Betaa Betaa@goodwin-minsky
link : rateInterestOnLoans rateInterestOnLoans@goodwin-minsky
link : Alphaa Alphaa@goodwin-minsky
link : employmentRateStable employmentRateStable@goodwin-minsky
link : deltaKReal deltaKReal@goodwin-minsky
link : velocityOfMoney velocityOfMoney@goodwin-minsky
link : piZ piZ@goodwin-minsky
link : employmentRateZero employmentRateZero@goodwin-minsky
link : piS piS@goodwin-minsky

% ======= Output Connections ======= %
link : LaborProductivity@goodwin-minsky LaborProductivity
link : WageRate@goodwin-minsky WageRate
link : Debt@goodwin-minsky Debt
link : Population@goodwin-minsky Population
link : Capital@goodwin-minsky Capital

% =============================== Conexiones entre modelos acoplados ========================= %
link : LaborProductivity@goodwin-minsky inLaborProductivity@conector
link : WageRate@goodwin-minsky inWageRate@conector
link : Debt@goodwin-minsky inDebt@conector
link : Population@goodwin-minsky inPopulation@conector
link : Capital@goodwin-minsky inCapital@conector

% ======== Links : conector => shockers ========= %
link : out0@conector in@shocker0
link : out1@conector in@shocker1
link : out2@conector in@shocker2
link : out3@conector in@shocker3
link : out4@conector in@shocker4

% ======== Links : shockers => opinion ========= %
link : out0@shocker0 in81@opinion
link : out0@shocker1 in67@opinion
link : out0@shocker2 in51@opinion
link : out0@shocker3 in75@opinion
link : out0@shocker4 in13@opinion
link : out10@shocker0 in42@opinion
link : out10@shocker1 in17@opinion
link : out10@shocker2 in07@opinion
link : out10@shocker3 in30@opinion
link : out10@shocker4 in88@opinion
link : out11@shocker0 in94@opinion
link : out11@shocker1 in11@opinion
link : out11@shocker2 in59@opinion
link : out11@shocker3 in72@opinion
link : out11@shocker4 in63@opinion
link : out12@shocker0 in01@opinion
link : out12@shocker1 in21@opinion
link : out12@shocker2 in79@opinion
link : out12@shocker3 in43@opinion
link : out12@shocker4 in24@opinion
link : out13@shocker0 in16@opinion
link : out13@shocker1 in31@opinion
link : out13@shocker2 in27@opinion
link : out13@shocker3 in54@opinion
link : out13@shocker4 in19@opinion
link : out14@shocker0 in62@opinion
link : out14@shocker1 in69@opinion
link : out14@shocker2 in23@opinion
link : out14@shocker3 in47@opinion
link : out14@shocker4 in84@opinion
link : out15@shocker0 in18@opinion
link : out15@shocker1 in98@opinion
link : out15@shocker2 in04@opinion
link : out15@shocker3 in05@opinion
link : out15@shocker4 in08@opinion
link : out16@shocker0 in37@opinion
link : out16@shocker1 in87@opinion
link : out16@shocker2 in90@opinion
link : out16@shocker3 in57@opinion
link : out16@shocker4 in22@opinion
link : out17@shocker0 in55@opinion
link : out17@shocker1 in64@opinion
link : out17@shocker2 in85@opinion
link : out17@shocker3 in58@opinion
link : out17@shocker4 in77@opinion
link : out18@shocker0 in66@opinion
link : out18@shocker1 in38@opinion
link : out18@shocker2 in92@opinion
link : out18@shocker3 in65@opinion
link : out18@shocker4 in86@opinion
link : out19@shocker0 in35@opinion
link : out19@shocker1 in53@opinion
link : out19@shocker2 in49@opinion
link : out19@shocker3 in46@opinion
link : out19@shocker4 in26@opinion
link : out1@shocker0 in48@opinion
link : out1@shocker1 in56@opinion
link : out1@shocker2 in40@opinion
link : out1@shocker3 in14@opinion
link : out1@shocker4 in03@opinion
link : out2@shocker0 in70@opinion
link : out2@shocker1 in82@opinion
link : out2@shocker2 in93@opinion
link : out2@shocker3 in10@opinion
link : out2@shocker4 in20@opinion
link : out3@shocker0 in76@opinion
link : out3@shocker1 in97@opinion
link : out3@shocker2 in33@opinion
link : out3@shocker3 in02@opinion
link : out3@shocker4 in96@opinion
link : out4@shocker0 in99@opinion
link : out4@shocker1 in91@opinion
link : out4@shocker2 in32@opinion
link : out4@shocker3 in74@opinion
link : out4@shocker4 in60@opinion
link : out5@shocker0 in95@opinion
link : out5@shocker1 in44@opinion
link : out5@shocker2 in28@opinion
link : out5@shocker3 in45@opinion
link : out5@shocker4 in00@opinion
link : out6@shocker0 in25@opinion
link : out6@shocker1 in89@opinion
link : out6@shocker2 in52@opinion
link : out6@shocker3 in29@opinion
link : out6@shocker4 in50@opinion
link : out7@shocker0 in34@opinion
link : out7@shocker1 in80@opinion
link : out7@shocker2 in12@opinion
link : out7@shocker3 in41@opinion
link : out7@shocker4 in39@opinion
link : out8@shocker0 in78@opinion
link : out8@shocker1 in15@opinion
link : out8@shocker2 in61@opinion
link : out8@shocker3 in71@opinion
link : out8@shocker4 in73@opinion
link : out9@shocker0 in06@opinion
link : out9@shocker1 in36@opinion
link : out9@shocker2 in83@opinion
link : out9@shocker3 in68@opinion
link : out9@shocker4 in09@opinion


% ====================================== % ====================================== % ====================================== %
% ======================================           Modelo Goodwin Minsky            ======================================
% ====================================== % ====================================== % ====================================== %
[goodwin-minsky]
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
link : out@LaborProductivity LaborProductivity@chgLaborProductivityMinus
link : out@LaborProductivity LaborProductivity@Labor
link : out@WageRate WageRate@chgWageRatePlus
link : out@WageRate WageRate@chgWageRateMinus
link : out@WageRate WageRate@Wages
link : out@Debt Debt@InterestPayments
link : out@Debt Debt@debtRate
link : out@Population Population@chgPopulationPlus
link : out@Population Population@chgPopulationMinus
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
dQRel : 0.001
dQMin : 0.001
[WageRate]
x0 : 0.8
dQRel : 0.001
dQMin : 0.001
[Debt]
x0 : 0
dQRel : 0.001
dQMin : 0.001
[Population]
x0 : 150
dQRel : 0.001
dQMin : 0.001
[Capital]
x0 : 300
dQRel : 0.001
dQMin : 0.001

% ====================================== % ====================================== % ====================================== %
% ======================================         Modelo Cell-Devs de OPINION        ======================================
% ====================================== % ====================================== % ====================================== %
[opinion]
type : cell
dim : (10,10,2)
delay : inertial
defaultDelayTime : {{delayValue}}
border : unwrapped 		
neighbors : opinion(-1,0,0)
neighbors : opinion(0,-1,0)  opinion(0,0,0)  opinion(0,1,0)
neighbors : opinion(1,0,0)
neighbors : opinion(0,0,1)
initialvalue : -70
initialCellsValue : valfile.val

%---------------------------------------------------
% Inputs + Links internos para shock exogeno
%---------------------------------------------------
in : in00 in01 in02 in03 in04 in05 in06 in07 in08 in09 in10 in11 in12 in13 in14 in15 in16 in17 in18 in19 in20 in21 in22 in23 in24 in25 in26 in27 in28 in29 in30 in31 in32 in33 in34 in35 in36 in37 in38 in39 in40 in41 in42 in43 in44 in45 in46 in47 in48 in49 in50 in51 in52 in53 in54 in55 in56 in57 in58 in59 in60 in61 in62 in63 in64 in65 in66 in67 in68 in69 in70 in71 in72 in73 in74 in75 in76 in77 in78 in79 in80 in81 in82 in83 in84 in85 in86 in87 in88 in89 in90 in91 in92 in93 in94 in95 in96 in97 in98 in99 
link : in00 in@opinion(0,0,0)
link : in01 in@opinion(0,1,0)
link : in02 in@opinion(0,2,0)
link : in03 in@opinion(0,3,0)
link : in04 in@opinion(0,4,0)
link : in05 in@opinion(0,5,0)
link : in06 in@opinion(0,6,0)
link : in07 in@opinion(0,7,0)
link : in08 in@opinion(0,8,0)
link : in09 in@opinion(0,9,0)
link : in10 in@opinion(1,0,0)
link : in11 in@opinion(1,1,0)
link : in12 in@opinion(1,2,0)
link : in13 in@opinion(1,3,0)
link : in14 in@opinion(1,4,0)
link : in15 in@opinion(1,5,0)
link : in16 in@opinion(1,6,0)
link : in17 in@opinion(1,7,0)
link : in18 in@opinion(1,8,0)
link : in19 in@opinion(1,9,0)
link : in20 in@opinion(2,0,0)
link : in21 in@opinion(2,1,0)
link : in22 in@opinion(2,2,0)
link : in23 in@opinion(2,3,0)
link : in24 in@opinion(2,4,0)
link : in25 in@opinion(2,5,0)
link : in26 in@opinion(2,6,0)
link : in27 in@opinion(2,7,0)
link : in28 in@opinion(2,8,0)
link : in29 in@opinion(2,9,0)
link : in30 in@opinion(3,0,0)
link : in31 in@opinion(3,1,0)
link : in32 in@opinion(3,2,0)
link : in33 in@opinion(3,3,0)
link : in34 in@opinion(3,4,0)
link : in35 in@opinion(3,5,0)
link : in36 in@opinion(3,6,0)
link : in37 in@opinion(3,7,0)
link : in38 in@opinion(3,8,0)
link : in39 in@opinion(3,9,0)
link : in40 in@opinion(4,0,0)
link : in41 in@opinion(4,1,0)
link : in42 in@opinion(4,2,0)
link : in43 in@opinion(4,3,0)
link : in44 in@opinion(4,4,0)
link : in45 in@opinion(4,5,0)
link : in46 in@opinion(4,6,0)
link : in47 in@opinion(4,7,0)
link : in48 in@opinion(4,8,0)
link : in49 in@opinion(4,9,0)
link : in50 in@opinion(5,0,0)
link : in51 in@opinion(5,1,0)
link : in52 in@opinion(5,2,0)
link : in53 in@opinion(5,3,0)
link : in54 in@opinion(5,4,0)
link : in55 in@opinion(5,5,0)
link : in56 in@opinion(5,6,0)
link : in57 in@opinion(5,7,0)
link : in58 in@opinion(5,8,0)
link : in59 in@opinion(5,9,0)
link : in60 in@opinion(6,0,0)
link : in61 in@opinion(6,1,0)
link : in62 in@opinion(6,2,0)
link : in63 in@opinion(6,3,0)
link : in64 in@opinion(6,4,0)
link : in65 in@opinion(6,5,0)
link : in66 in@opinion(6,6,0)
link : in67 in@opinion(6,7,0)
link : in68 in@opinion(6,8,0)
link : in69 in@opinion(6,9,0)
link : in70 in@opinion(7,0,0)
link : in71 in@opinion(7,1,0)
link : in72 in@opinion(7,2,0)
link : in73 in@opinion(7,3,0)
link : in74 in@opinion(7,4,0)
link : in75 in@opinion(7,5,0)
link : in76 in@opinion(7,6,0)
link : in77 in@opinion(7,7,0)
link : in78 in@opinion(7,8,0)
link : in79 in@opinion(7,9,0)
link : in80 in@opinion(8,0,0)
link : in81 in@opinion(8,1,0)
link : in82 in@opinion(8,2,0)
link : in83 in@opinion(8,3,0)
link : in84 in@opinion(8,4,0)
link : in85 in@opinion(8,5,0)
link : in86 in@opinion(8,6,0)
link : in87 in@opinion(8,7,0)
link : in88 in@opinion(8,8,0)
link : in89 in@opinion(8,9,0)
link : in90 in@opinion(9,0,0)
link : in91 in@opinion(9,1,0)
link : in92 in@opinion(9,2,0)
link : in93 in@opinion(9,3,0)
link : in94 in@opinion(9,4,0)
link : in95 in@opinion(9,5,0)
link : in96 in@opinion(9,6,0)
link : in97 in@opinion(9,7,0)
link : in98 in@opinion(9,8,0)
link : in99 in@opinion(9,9,0)


%----------------------------------------------------------------------------
localtransition : opinion-rule
%----------------------------------------------------------------------------

%----------------------------------------------------------------------------
% --- SETEO PUERTOS DEL CELL-DEVS QUE REACCIONAN ANTE SHOCKS EXTERNOS -------
%----------------------------------------------------------------------------
PortInTransition : in@opinion(8,1,0) shockExterno
PortInTransition : in@opinion(6,7,0) shockExterno
PortInTransition : in@opinion(5,1,0) shockExterno
PortInTransition : in@opinion(7,5,0) shockExterno
PortInTransition : in@opinion(1,3,0) shockExterno
PortInTransition : in@opinion(4,8,0) shockExterno
PortInTransition : in@opinion(5,6,0) shockExterno
PortInTransition : in@opinion(4,0,0) shockExterno
PortInTransition : in@opinion(1,4,0) shockExterno
PortInTransition : in@opinion(0,3,0) shockExterno
PortInTransition : in@opinion(7,0,0) shockExterno
PortInTransition : in@opinion(8,2,0) shockExterno
PortInTransition : in@opinion(9,3,0) shockExterno
PortInTransition : in@opinion(1,0,0) shockExterno
PortInTransition : in@opinion(2,0,0) shockExterno
PortInTransition : in@opinion(7,6,0) shockExterno
PortInTransition : in@opinion(9,7,0) shockExterno
PortInTransition : in@opinion(3,3,0) shockExterno
PortInTransition : in@opinion(0,2,0) shockExterno
PortInTransition : in@opinion(9,6,0) shockExterno
PortInTransition : in@opinion(9,9,0) shockExterno
PortInTransition : in@opinion(9,1,0) shockExterno
PortInTransition : in@opinion(3,2,0) shockExterno
PortInTransition : in@opinion(7,4,0) shockExterno
PortInTransition : in@opinion(6,0,0) shockExterno
PortInTransition : in@opinion(9,5,0) shockExterno
PortInTransition : in@opinion(4,4,0) shockExterno
PortInTransition : in@opinion(2,8,0) shockExterno
PortInTransition : in@opinion(4,5,0) shockExterno
PortInTransition : in@opinion(0,0,0) shockExterno
PortInTransition : in@opinion(2,5,0) shockExterno
PortInTransition : in@opinion(8,9,0) shockExterno
PortInTransition : in@opinion(5,2,0) shockExterno
PortInTransition : in@opinion(2,9,0) shockExterno
PortInTransition : in@opinion(5,0,0) shockExterno
PortInTransition : in@opinion(3,4,0) shockExterno
PortInTransition : in@opinion(8,0,0) shockExterno
PortInTransition : in@opinion(1,2,0) shockExterno
PortInTransition : in@opinion(4,1,0) shockExterno
PortInTransition : in@opinion(3,9,0) shockExterno
PortInTransition : in@opinion(7,8,0) shockExterno
PortInTransition : in@opinion(1,5,0) shockExterno
PortInTransition : in@opinion(6,1,0) shockExterno
PortInTransition : in@opinion(7,1,0) shockExterno
PortInTransition : in@opinion(7,3,0) shockExterno
PortInTransition : in@opinion(0,6,0) shockExterno
PortInTransition : in@opinion(3,6,0) shockExterno
PortInTransition : in@opinion(8,3,0) shockExterno
PortInTransition : in@opinion(6,8,0) shockExterno
PortInTransition : in@opinion(0,9,0) shockExterno
PortInTransition : in@opinion(4,2,0) shockExterno
PortInTransition : in@opinion(1,7,0) shockExterno
PortInTransition : in@opinion(0,7,0) shockExterno
PortInTransition : in@opinion(3,0,0) shockExterno
PortInTransition : in@opinion(8,8,0) shockExterno
PortInTransition : in@opinion(9,4,0) shockExterno
PortInTransition : in@opinion(1,1,0) shockExterno
PortInTransition : in@opinion(5,9,0) shockExterno
PortInTransition : in@opinion(7,2,0) shockExterno
PortInTransition : in@opinion(6,3,0) shockExterno
PortInTransition : in@opinion(0,1,0) shockExterno
PortInTransition : in@opinion(2,1,0) shockExterno
PortInTransition : in@opinion(7,9,0) shockExterno
PortInTransition : in@opinion(4,3,0) shockExterno
PortInTransition : in@opinion(2,4,0) shockExterno
PortInTransition : in@opinion(1,6,0) shockExterno
PortInTransition : in@opinion(3,1,0) shockExterno
PortInTransition : in@opinion(2,7,0) shockExterno
PortInTransition : in@opinion(5,4,0) shockExterno
PortInTransition : in@opinion(1,9,0) shockExterno
PortInTransition : in@opinion(6,2,0) shockExterno
PortInTransition : in@opinion(6,9,0) shockExterno
PortInTransition : in@opinion(2,3,0) shockExterno
PortInTransition : in@opinion(4,7,0) shockExterno
PortInTransition : in@opinion(8,4,0) shockExterno
PortInTransition : in@opinion(1,8,0) shockExterno
PortInTransition : in@opinion(9,8,0) shockExterno
PortInTransition : in@opinion(0,4,0) shockExterno
PortInTransition : in@opinion(0,5,0) shockExterno
PortInTransition : in@opinion(0,8,0) shockExterno
PortInTransition : in@opinion(3,7,0) shockExterno
PortInTransition : in@opinion(8,7,0) shockExterno
PortInTransition : in@opinion(9,0,0) shockExterno
PortInTransition : in@opinion(5,7,0) shockExterno
PortInTransition : in@opinion(2,2,0) shockExterno
PortInTransition : in@opinion(5,5,0) shockExterno
PortInTransition : in@opinion(6,4,0) shockExterno
PortInTransition : in@opinion(8,5,0) shockExterno
PortInTransition : in@opinion(5,8,0) shockExterno
PortInTransition : in@opinion(7,7,0) shockExterno
PortInTransition : in@opinion(6,6,0) shockExterno
PortInTransition : in@opinion(3,8,0) shockExterno
PortInTransition : in@opinion(9,2,0) shockExterno
PortInTransition : in@opinion(6,5,0) shockExterno
PortInTransition : in@opinion(8,6,0) shockExterno
PortInTransition : in@opinion(3,5,0) shockExterno
PortInTransition : in@opinion(5,3,0) shockExterno
PortInTransition : in@opinion(4,9,0) shockExterno
PortInTransition : in@opinion(4,6,0) shockExterno
PortInTransition : in@opinion(2,6,0) shockExterno


%----------------------------------------------------------------------------
% --------------- REGLAS DE REACCION ANTE SHOCKS EXTERNOS -------------------
%----------------------------------------------------------------------------
[shockExterno]
rule : -3 0 { portValue(in) = 5 }
rule : 0 0 { portValue(in) = 6 }
rule : 3 0 { portValue(in) = 7 }
rule : 3 0 { portValue(in) = 8 }
rule : { (0,0,0) } 0 { t }
%----------------------------------------------------------------------------
% ------------- REGLAS LOCALES PARA EL CELL - DEVS --------------------------
%----------------------------------------------------------------------------
[opinion-rule]
rule :  { uniform(-2,2) } 0 { (0,0,0)=-70 and (0,0,1)!=? }
%Condicion inicial para la capa de opiniones (layer 1).
rule :  { randInt(3)+1 } 0 { (0,0,0)=-70 and (0,0,1)=?   }
%Condicion inicial para la capa de conectividad (layer 2).
 
%----------------------------------------------------------------------------
rule :  { randInt(3)+1 } {{delayValue}} { (0,0,1)=?  }	
%Clock del modelo: actualizacion de la capa de conectividad.
%----------------------------------------------------------------------------

%Reglas para no pasarme del intervalo [-3;3] por sumar o restar #macro(delta): 
%Mire a quien mire, vote a quien vote, si el resultado de mi estado de conviccion actual +/- delta es mayor a
%3 (o -3), fijo el valor a 3 (o -3).
rule :  { -3 } {{delayValue}} { (0,0,1)=1  and (0,0,0) < -1 and (((0,0,0) - #macro(delta))<-3 )and ( (0,1,0) < (0,0,0) or  (0,1,0) > 1 )}
rule :  { 3 } {{delayValue}} { (0,0,1)=1  and (0,0,0) < -1 and (0,1,0) <= 1 and (((0,0,0) + #macro(delta))>3) }
rule :  { 3 } {{delayValue}} { (0,0,1)=1  and (0,0,0) > 1 and (((0,0,0) + #macro(delta))>3) and ((0,1,0) > (0,0,0)  or  (0,1,0) <= -1 )  }
rule :  { -3 } {{delayValue}} { (0,0,1)=1  and (0,0,0) > 1 and (((0,0,0) - #macro(delta))<-3) and (0,1,0) < (0,0,0)  }
rule :  { -3 } {{delayValue}} { (0,0,1)=3  and (0,0,0) < -1 and (((0,0,0) - #macro(delta))<-3) and ( (0,-1,0) < (0,0,0) or  (0,-1,0) > 1 )}
rule :  { 3 } {{delayValue}} { (0,0,1)=3  and (0,0,0) < -1 and (((0,0,0) + #macro(delta))>3) and (0,-1,0) <= 1 }
rule :  { 3 } {{delayValue}} { (0,0,1)=3  and (0,0,0) > 1 and (((0,0,0) + #macro(delta))>3) and ((0,-1,0) > (0,0,0)  or  (0,-1,0) <= -1 )  }
rule :  { -3 } {{delayValue}} { (0,0,1)=3  and (0,0,0) > 1 and (((0,0,0) - #macro(delta))<-3) and (0,-1,0) < (0,0,0)  }
rule :  { -3 } {{delayValue}} { (0,0,1)=2  and (0,0,0) < -1 and (((0,0,0) - #macro(delta))<-3) and ( (-1,0,0) < (0,0,0) or  (-1,0,0) > 1 )}
rule :  { 3 } {{delayValue}} { (0,0,1)=2  and (0,0,0) < -1 and (((0,0,0) + #macro(delta))>3) and (-1,0,0) <= 1 }
rule :  { 3 } {{delayValue}} { (0,0,1)=2  and (0,0,0) > 1 and (((0,0,0) + #macro(delta))>3) and ((-1,0,0) > (0,0,0)  or  (-1,0,0) <= -1 )  }
rule :  { -3 } {{delayValue}} { (0,0,1)=2  and (0,0,0) > 1 and (((0,0,0) - #macro(delta))<-3) and (-1,0,0) < (0,0,0)  }
rule :  { -3 } {{delayValue}} { (0,0,1)=4  and (0,0,0) < -1 and (((0,0,0) - #macro(delta))<-3) and ( (1,0,0) < (0,0,0) or  (1,0,0) > 1 )}
rule :  { 3 } {{delayValue}} { (0,0,1)=4  and (0,0,0) < -1 and (((0,0,0) + #macro(delta))>3) and (1,0,0) <= 1 }
rule :  { 3 } {{delayValue}} { (0,0,1)=4  and (0,0,0) > 1 and (((0,0,0) + #macro(delta))>3) and ((1,0,0) > (0,0,0)  or  (1,0,0) <= -1 )  }
rule :  { -3 } {{delayValue}} { (0,0,1)=4  and (0,0,0) > 1 and (((0,0,0) - #macro(delta))<-3) and (1,0,0) < (0,0,0)  }


%----- Reglas para ver a la derecha (capa de conectividad = 1) -----------------------------
rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=1  and ((0,1,0)=? or (0,1,0)=(0,0,0))}
%Me quedo igual si tengo una pared o mi vecino tiene igual conviccion que yo.

%----------------------------------------------------------------------------
rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=1 and (0,0,0)<=-#macro(long) and (0,1,0)>=#macro(long) }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=1 and (0,0,0)>=#macro(long) and (0,1,0)<=-#macro(long) }
%Yo: Influyente - El: Influyente del otro bando - Resultado: Me repelo un delta.

rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=1 and abs((0,0,0))>=abs(#macro(long)) and abs((0,1,0))>1 }
%Yo: Influyente - El: Influyente - Resultado: Me quedo igual. (regla posterior a la de InfA-InfB)

rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=1 and (0,0,0)>1 and abs((0,1,0))<=1 }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=1 and (0,0,0)<-1 and abs((0,1,0))<=1 }
%Yo: Influyente/Partidiario - El: Indefinido - Resultado: Me acerco un delta.

rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=1 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (0,1,0)<=-#macro(long) }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=1 and (0,0,0)>1 and (0,0,0)<#macro(long) and (0,1,0)>=#macro(long) }
%Yo: Partidiario - El: Influyente - Resultado: Me acerco un delta.

rule :  { (0,0,0) + #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=1 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (0,1,0)>=#macro(long) }
rule :  { (0,0,0) - #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=1 and (0,0,0)>1 and (0,0,0)<#macro(long) and (0,1,0)<=-#macro(long) }
%Yo: Partidiario - El Inflyente del otro bando - Resultado: Me acerco un q*delta.

rule :  { (0,0,0) + #macro(k)*#macro(delta) } {{delayValue}} { (0,0,1)=1 and abs((0,0,0))<=1 and (0,1,0)>1 and (0,1,0)<#macro(long)}
rule :  { (0,0,0) - #macro(k)*#macro(delta) } {{delayValue}} { (0,0,1)=1 and abs((0,0,0))<=1 and (0,1,0)<-1 and (0,1,0)>-#macro(long)}
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un k*delta.

rule :  { (0,0,0) + #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=1 and abs((0,0,0))<=1 and (0,1,0)>=#macro(long) }
rule :  { (0,0,0) - #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=1 and abs((0,0,0))<=1 and (0,1,0)<-#macro(long) }
%Yo: Indefinido - El: Influyente - Resultado: Me acerco un q*delta.

rule :  { (0,0,0)*0 } {{delayValue}} { (0,0,1)=1 and abs((0,0,0))<=#macro(delta) and abs((0,1,0))<=1 }
rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=1 and abs((0,0,0))<=1 and abs((0,1,0))<=1 and (0,0,0)>0 }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=1 and abs((0,0,0))<=1 and abs((0,1,0))<=1 and (0,0,0)<0 }
%Yo: Indefinido - El: Indefinido - Resultado: Me acerco un delta, sin cruzarme. Si estoy en cero, me quedo ahi.

rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=1 and (0,0,0)>1 and (0,1,0)>1 and (0,0,0)<(0,1,0) }
rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=1 and (0,0,0)>1 and (0,1,0)>1 and (0,0,0)>(0,1,0) }
rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=1 and (0,0,0)<-1 and (0,1,0)<-1 and (0,0,0)>(0,1,0) }
rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=1 and (0,0,0)<-1 and (0,1,0)<-1 and (0,0,0)<(0,1,0) }
%Yo: Partidiario - El: Partidiario - Resultado: Si tengo mayor conviccion, me quedo igual, si no, me acerco un delta.

rule :  { if( randInt(1) < 1,(0,0,0) + #macro(delta),(0,0,0) - #macro(delta) )  } {{delayValue}} { (0,0,1)=1 and (0,0,0)*(0,1,0)<=-1   }
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Tengo un 50% de acercarme y un 50% de alejarme un delta. (regla al final)
%----------------------------------------------------------------------------
%----------------------------------------------------------------------------
%----------------------------------------------------------------------------
%----------------------------------------------------------------------------
%----- Reglas para ver a abajo (capa de conectividad = 2) -----------------------------
rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=2  and ((1,0,0)=? or (1,0,0)=(0,0,0))}
%Me quedo igual si tengo una pared o mi vecino tiene igual conviccion que yo.

%----------------------------------------------------------------------------
rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=2 and (0,0,0)<=-#macro(long) and (1,0,0)>=#macro(long) }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=2 and (0,0,0)>=#macro(long) and (1,0,0)<=-#macro(long) }
%Yo: Influyente - El: Influyente del otro bando - Resultado: Me repelo un delta.

rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=2 and abs((0,0,0))>=abs(#macro(long)) and abs((1,0,0))>1 }
%Yo: Influyente - El: Influyente - Resultado: Me quedo igual. (regla posterior a la de InfA-InfB)

rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=2 and (0,0,0)>1 and abs((1,0,0))<=1 }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=2 and (0,0,0)<-1 and abs((1,0,0))<=1  }
%Yo: Influyente/Partidiario - El: Indefinido - Resultado: Me acerco un delta.

rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=2 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (1,0,0)<=-#macro(long) }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=2 and (0,0,0)>1 and (0,0,0)<#macro(long) and (1,0,0)>=#macro(long) }
%Yo: Partidiario - El: Influyente - Resultado: Me acerco un delta.

rule :  { (0,0,0) + #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=2 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (1,0,0)>=#macro(long) }
rule :  { (0,0,0) - #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=2 and (0,0,0)>1 and (0,0,0)<#macro(long) and (1,0,0)<=-#macro(long) }
%Yo: Partidiario - El Inflyente del otro bando - Resultado: Me acerco un q*delta.

rule :  { (0,0,0) + #macro(k)*#macro(delta) } {{delayValue}} { (0,0,1)=2 and abs((0,0,0))<=1 and (1,0,0)>1 and (1,0,0)<#macro(long)}
rule :  { (0,0,0) - #macro(k)*#macro(delta) } {{delayValue}} { (0,0,1)=2 and abs((0,0,0))<=1 and (1,0,0)<-1 and (1,0,0)>-#macro(long)}
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un k*delta.

rule :  { (0,0,0) + #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=2 and abs((0,0,0))<=1 and (1,0,0)>=#macro(long) }
rule :  { (0,0,0) - #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=2 and abs((0,0,0))<=1 and (1,0,0)<-#macro(long) }
%Yo: Indefinido - El: Influyente - Resultado: Me acerco un q*delta.

rule :  { (0,0,0)*0 } {{delayValue}} { (0,0,1)=2 and abs((0,0,0))<=#macro(delta) and abs((1,0,0))<=1 }
rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=2 and abs((0,0,0))<=1 and abs((1,0,0))<=1 and (0,0,0)>0 }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=2 and abs((0,0,0))<=1 and abs((1,0,0))<=1 and (0,0,0)<0 }
%%Yo: Indefinido - El: Indefinido - Resultado: Me acerco un delta.

rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=2 and (0,0,0)>1 and (1,0,0)>1 and (0,0,0)<(1,0,0) }
rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=2 and (0,0,0)>1 and (1,0,0)>1 and (0,0,0)>(1,0,0) }
rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=2 and (0,0,0)<-1 and (1,0,0)<-1 and (0,0,0)>(1,0,0) }
rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=2 and (0,0,0)<-1 and (1,0,0)<-1 and (0,0,0)<(1,0,0) }
%Yo: Partidiario - El: Partidiario - Resultado: Si tengo mayor conviccion, me quedo igual, si no, me acerco un delta.

rule :  { if( randInt(1) < 1,(0,0,0) + #macro(delta),(0,0,0) - #macro(delta) )  } {{delayValue}} { (0,0,1)=2 and (0,0,0)*(1,0,0)<=-1   }
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Tengo un 50% de acercarme y un 50% de alejarme un delta. (regla al final)
%----------------------------------------------------------------------------
%----------------------------------------------------------------------------
%----------------------------------------------------------------------------
%----------------------------------------------------------------------------
%----- Reglas para ver a la izquierda (capa de conectividad = 3) -----------------------------
rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=3  and ((0,-1,0)=? or (0,-1,0)=(0,0,0))}
%Me quedo igual si tengo una pared o mi vecino tiene igual conviccion que yo.

%----------------------------------------------
rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=3 and (0,0,0)<=-#macro(long) and (0,-1,0)>=#macro(long) }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=3 and (0,0,0)>=#macro(long) and (0,-1,0)<=-#macro(long) }
%Yo: Influyente - El: Influyente del otro bando - Resultado: Me repelo un delta.

rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=3 and abs((0,0,0))>=abs(#macro(long)) and abs((0,-1,0))>1 }
%Yo: Influyente - El: Influyente - Resultado: Me quedo igual. (regla posterior a la de InfA-InfB)

rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=3 and (0,0,0)>1 and abs((0,-1,0))<=1 }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=3 and (0,0,0)<-1 and abs((0,-1,0))<=1 }
%Yo: Influyente/Partidiario - El: Indefinido - Resultado: Me acerco un delta.

rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=3 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (0,-1,0)<=-#macro(long) }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=3 and (0,0,0)>1 and (0,0,0)<#macro(long) and (0,-1,0)>=#macro(long) }
%Yo: Partidiario - El: Influyente - Resultado: Me acerco un delta.

rule :  { (0,0,0) + #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=3 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (0,-1,0)>=#macro(long) }
rule :  { (0,0,0) - #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=3 and (0,0,0)>1 and (0,0,0)<#macro(long) and (0,-1,0)<=-#macro(long) }
%Yo: Partidiario - El Inflyente del otro bando - Resultado: Me acerco un q*delta.

rule :  { (0,0,0) + #macro(k)*#macro(delta) } {{delayValue}} { (0,0,1)=3 and abs((0,0,0))<=1 and (0,-1,0)>1 and (0,-1,0)<#macro(long) }
rule :  { (0,0,0) - #macro(k)*#macro(delta) } {{delayValue}} { (0,0,1)=3 and abs((0,0,0))<=1 and (0,-1,0)<-1 and (0,-1,0)>-#macro(long)}
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un k*delta.

rule :  { (0,0,0) + #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=3 and abs((0,0,0))<=1 and (0,-1,0)>=#macro(long) }
rule :  { (0,0,0) - #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=3 and abs((0,0,0))<=1 and (0,-1,0)<-#macro(long) }
%Yo: Indefinido - El: Influyente - Resultado: Me acerco un q*delta.

rule :  { (0,0,0)*0 } {{delayValue}} { (0,0,1)=3 and abs((0,0,0))<=#macro(delta) and abs((0,-1,0))<=1 }
rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=3 and abs((0,0,0))<=1 and abs((0,-1,0))<=1 and (0,0,0)>0 }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=3 and abs((0,0,0))<=1 and abs((0,-1,0))<=1 and (0,0,0)<0 }
%Yo: Indefinido - El: Indefinido - Resultado: Me acerco un delta.

rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=3 and (0,0,0)>1 and (0,-1,0)>1 and (0,0,0)<(0,-1,0) }
rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=3 and (0,0,0)>1 and (0,-1,0)>1 and (0,0,0)>(0,-1,0) }
rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=3 and (0,0,0)<-1 and (0,-1,0)<-1 and (0,0,0)>(0,-1,0) }
rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=3 and (0,0,0)<-1 and (0,-1,0)<-1 and (0,0,0)<(0,-1,0) }
%Yo: Partidiario - El: Partidiario - Resultado: Si tengo mayor conviccion, me quedo igual, si no, me acerco un delta.

rule :  { if( randInt(1) < 1,(0,0,0) + #macro(delta),(0,0,0) - #macro(delta) )  } {{delayValue}} { (0,0,1)=3 and (0,0,0)*(0,-1,0)<=-1   }
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Tengo un 50% de acercarme y un 50% de alejarme un delta. (regla al final)
%----------------------------------------------------------------------------
%----------------------------------------------------------------------------
%----------------------------------------------------------------------------
%----- Reglas para ver a arriba (capa de conectividad = 4) -----------------------------
rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=4  and ((-1,0,0)=? or (-1,0,0)=(0,0,0))}
%Me quedo igual si tengo una pared o mi vecino tiene igual conviccion que yo.

%----------------------------------------------
rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=4 and (0,0,0)<=-#macro(long) and (-1,0,0)>=#macro(long) }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=4 and (0,0,0)>=#macro(long) and (-1,0,0)<=-#macro(long) }
%Yo: Influyente - El: Influyente del otro bando - Resultado: Me repelo un delta.

rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=4 and abs((0,0,0))>=abs(#macro(long)) and abs((-1,0,0))>1 }
%Yo: Influyente - El: Influyente - Resultado: Me quedo igual. (regla posterior a la de InfA-InfB)

rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=4 and (0,0,0)>1 and abs((-1,0,0))<=1 }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=4 and (0,0,0)<-1 and abs((-1,0,0))<=1 }
%Yo: Influyente/Partidiario - El: Indefinido - Resultado: Me acerco un delta.

rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=4 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (-1,0,0)<=-#macro(long) }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=4 and (0,0,0)>1 and (0,0,0)<#macro(long) and (-1,0,0)>=#macro(long) }
%Yo: Partidiario - El: Influyente - Resultado: Me acerco un delta.

rule :  { (0,0,0) + #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=4 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (-1,0,0)>=#macro(long) }
rule :  { (0,0,0) - #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=4 and (0,0,0)>1 and (0,0,0)<#macro(long) and (-1,0,0)<=-#macro(long) }
%Yo: Partidiario - El Inflyente del otro bando - Resultado: Me acerco un q*delta.

rule :  { (0,0,0) + #macro(k)*#macro(delta) } {{delayValue}} { (0,0,1)=4 and abs((0,0,0))<=1 and (-1,0,0)>1 and (-1,0,0)<#macro(long)}
rule :  { (0,0,0) - #macro(k)*#macro(delta) } {{delayValue}} { (0,0,1)=4 and abs((0,0,0))<=1 and (-1,0,0)<-1 and (-1,0,0)>-#macro(long) }
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un k*delta.

rule :  { (0,0,0) + #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=4 and abs((0,0,0))<=1 and (-1,0,0)>=#macro(long) }
rule :  { (0,0,0) - #macro(q)*#macro(delta) } {{delayValue}} { (0,0,1)=4 and abs((0,0,0))<=1 and (-1,0,0)<-#macro(long) }
%Yo: Indefinido - El: Influyente - Resultado: Me acerco un q*delta.

rule :  { (0,0,0)*0 } {{delayValue}} { (0,0,1)=4 and abs((0,0,0))<=#macro(delta) and abs((-1,0,0))<=1 }
rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=4 and abs((0,0,0))<=1 and abs((-1,0,0))<=1 and (0,0,0)>0 }
rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=4 and abs((0,0,0))<=1 and abs((-1,0,0))<=1 and (0,0,0)<0 }
%%Yo: Indefinido - El: Indefinido - Resultado: Me acerco un delta.

rule :  { (0,0,0) + #macro(delta) } {{delayValue}} { (0,0,1)=4 and (0,0,0)>1 and (-1,0,0)>1 and (0,0,0)<(-1,0,0) }
rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=4 and (0,0,0)>1 and (-1,0,0)>1 and (0,0,0)>(-1,0,0) }
rule :  { (0,0,0) - #macro(delta) } {{delayValue}} { (0,0,1)=4 and (0,0,0)<-1 and (-1,0,0)<-1 and (0,0,0)>(-1,0,0) }
rule :  { (0,0,0) } {{delayValue}} { (0,0,1)=4 and (0,0,0)<-1 and (-1,0,0)<-1 and (0,0,0)<(-1,0,0) }
%Yo: Partidiario - El: Partidiario - Resultado: Si tengo mayor conviccion, me quedo igual, si no, me acerco un delta.

rule :  { if( randInt(1) < 1,(0,0,0) + #macro(delta),(0,0,0) - #macro(delta) )  } {{delayValue}} { (0,0,1)=4 and (0,0,0)*(-1,0,0)<=-1   }
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Tengo un 50% de acercarme y un 50% de alejarme un delta. (regla al final)
%----------------------------------------------------------------------------
%----------------------------------------------------------------------------
%----------------------------------------------------------------------------
%----------------------------------------------------------------------------
rule : { (0,0,0) } {{delayValue}} { t }