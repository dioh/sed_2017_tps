[top]
components : LaborProductivityTot@LaborProductivityTot LaborProductivity@QSS1 wageRateTot@wageRateTot wageRate@QSS1 PopulationTot@PopulationTot Population@QSS1 CapitalTot@CapitalTot Capital@QSS1 wageFunction@wageFunction InvestmentGross@InvestmentGross InvestmentNetReal@InvestmentNetReal Profit@Profit constantEmploymentRate@Cte wageBill@wageBill velocityOfMoney@Cte Output@Output Labor@Labor omega@omega rateOfAppreciation@Cte employmentRate@employmentRate chgLaborProductivityPlus@chgLaborProductivityPlus chgLaborProductivityMinus@chgLaborProductivityMinus chgPopulationPlus@chgPopulationPlus chgPopulationMinus@chgPopulationMinus chgWageRatePlus@chgWageRatePlus chgWageRateMinus@chgWageRateMinus chgCapitalPlus@chgCapitalPlus chgCapitalMinus@chgCapitalMinus 

% External Input Ports
in : constantEmploymentRate velocityOfMoney rateOfAppreciation 
% External Output Ports
out : LaborProductivity wageRate Population Capital 

% Internal I/O Connections
link : out@LaborProductivityTot in@LaborProductivity
link : out@wageRateTot in@wageRate
link : out@PopulationTot in@Population
link : out@CapitalTot in@Capital
link : out@LaborProductivityPlus plus@LaborProductivityTot
link : out@PopulationPlus plus@PopulationTot
link : out@wageRatePlus plus@wageRateTot
link : out@CapitalPlus plus@CapitalTot
link : out@LaborProductivity LaborProductivity@chgLaborProductivityPlus
link : out@LaborProductivity LaborProductivity@Labor
link : out@wageRate wageRate@chgWageRatePlus
link : out@wageRate wageRate@wageBill
link : out@Population Population@chgPopulationPlus
link : out@Population Population@employmentRate
link : out@Capital Capital@InvestmentNetReal
link : out@Capital Capital@Output
link : out@wageFunction wageFunction@chgWageRatePlus
link : out@wageFunction wageFunction@chgWageRateMinus
link : out@InvestmentGross InvestmentGross@InvestmentNetReal
link : out@InvestmentNetReal InvestmentNetReal@chgCapitalPlus
link : out@InvestmentNetReal InvestmentNetReal@chgCapitalMinus
link : out@Profit Profit@InvestmentGross
link : out@constantEmploymentRate constantEmploymentRate@wageFunction
link : out@wageBill wageBill@Profit
link : out@wageBill wageBill@omega
link : out@velocityOfMoney velocityOfMoney@Output
link : out@Output Output@Profit
link : out@Output Output@Labor
link : out@Output Output@omega
link : out@Labor Labor@wageBill
link : out@Labor Labor@employmentRate
link : out@rateOfAppreciation rateOfAppreciation@InvestmentNetReal
link : out@employmentRate employmentRate@wageFunction

% Integradores
[LaborProductivity]
x0 : 1
dQRel : 0.0001
dQMin : 0.0001
[wageRate]
x0 : 0.8
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