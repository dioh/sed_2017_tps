[top]
components : InfectedTot@InfectedTot Infected@QSS1 RecoveredTot@RecoveredTot Recovered@QSS1 SusceptiblesTot@SusceptiblesTot Susceptibles@QSS1 InfectionRate@Cte Duration@Cte TotalPopulation@Cte SuccumbingPlus@SuccumbingPlus SuccumbingMinus@SuccumbingMinus RecoveringPlus@RecoveringPlus RecoveringMinus@RecoveringMinus 

% External Input Ports
in : InfectionRate Duration TotalPopulation 
% External Output Ports
out : Infected Recovered Susceptibles 

% Links internos (input ports => atomicos tipo 'Cte')
link : InfectionRate inValue@InfectionRate
link : Duration inValue@Duration
link : TotalPopulation inValue@TotalPopulation

% Internal I/O Connections
link : out@InfectedTot in@Infected
link : out@RecoveredTot in@Recovered
link : out@SusceptiblesTot in@Susceptibles
link : out@SuccumbingPlus SuccumbingPlus@InfectedTot
link : out@SuccumbingMinus SuccumbingMinus@SusceptiblesTot
link : out@RecoveringMinus RecoveringMinus@InfectedTot
link : out@RecoveringPlus RecoveringPlus@RecoveredTot
link : out@Infected Infected@SuccumbingPlus
link : out@Infected Infected@RecoveringMinus
link : out@Susceptibles Susceptibles@SuccumbingMinus
link : out@InfectionRate InfectionRate@SuccumbingPlus
link : out@InfectionRate InfectionRate@SuccumbingMinus
link : out@Duration Duration@RecoveringPlus
link : out@Duration Duration@RecoveringMinus
link : out@TotalPopulation TotalPopulation@SuccumbingPlus
link : out@TotalPopulation TotalPopulation@SuccumbingMinus

% Links internos (variables de interes => output ports)
link : out@Infected Infected
link : out@Recovered Recovered
link : out@Susceptibles Susceptibles

% Integradores
[Infected]
x0 : 5
dQRel : 0.0001
dQMin : 0.0001
[Recovered]
x0 : 0
dQRel : 0.0001
dQMin : 0.0001
[Susceptibles]
x0 : 995
dQRel : 0.0001
dQMin : 0.0001