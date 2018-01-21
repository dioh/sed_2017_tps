#include(macros.inc)

[top]
components : {% for atomico in atomicos -%}{{atomico}} {% endfor -%} conector@Conector opinion goodwin-minsky

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
{% for link_externo in links_external -%}
{{link_externo}}
{% endfor %}

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
dim : ({{N}},{{M}},2)
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
in : {% for input in inputs_internal -%}{{input}} {% endfor %}
{% for link_interno in links_internal -%}
{{link_interno}}
{% endfor %}

%----------------------------------------------------------------------------
localtransition : opinion-rule
%----------------------------------------------------------------------------

%----------------------------------------------------------------------------
% --- SETEO PUERTOS DEL CELL-DEVS QUE REACCIONAN ANTE SHOCKS EXTERNOS -------
%----------------------------------------------------------------------------
{% for link_external_transition in links_external_transition -%}
{{link_external_transition}}
{% endfor %}

%----------------------------------------------------------------------------
% --------------- REGLAS DE REACCION ANTE SHOCKS EXTERNOS -------------------
%----------------------------------------------------------------------------
[shockExterno]
{% for rule in rules -%}
rule : {{rule}}
{% endfor -%}

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
