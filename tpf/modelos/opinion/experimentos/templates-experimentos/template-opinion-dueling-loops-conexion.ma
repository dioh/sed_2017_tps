#include(macros.inc)

[top]
components : {% for atomico in atomicos -%}{{atomico}} {% endfor -%} conector@Conector opinion dueling-loops

in : inShockCriteria
out : RationalSupporters Degenerates Neutralists

link : inShockCriteria inShockCriteria@conector

% ======= Output Connections ======= %
link : RationalSupporters@dueling-loops RationalSupporters
link : Degenerates@dueling-loops Degenerates
link : Neutralists@dueling-loops Neutralists

% =============================== Conexiones entre modelos acoplados ========================= %
link : RationalSupporters@dueling-loops inRationalSupporters@conector
link : Degenerates@dueling-loops inDegenerates@conector
link : Neutralists@dueling-loops inNeutralists@conector

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
% ======================================           Modelo Dueling Loops             ======================================
% ====================================== % ====================================== % ====================================== %
[dueling-loops]
components : RationalSupportersTot@RationalSupportersTot RationalSupporters@QSS1 DegeneratesTot@DegeneratesTot Degenerates@QSS1 NeutralistsTot@NeutralistsTot Neutralists@QSS1 outDegeneratesRightPlus@outDegeneratesRightPlus outDegeneratesRightMinus@outDegeneratesRightMinus neutralistsToDegeneratesPlus@neutralistsToDegeneratesPlus neutralistsToDegeneratesMinus@neutralistsToDegeneratesMinus rationalsToNeutralistsPlus@rationalsToNeutralistsPlus rationalsToNeutralistsMinus@rationalsToNeutralistsMinus neutralistsToRationalsPlus@neutralistsToRationalsPlus neutralistsToRationalsMinus@neutralistsToRationalsMinus outDegeneratesLeftPlus@outDegeneratesLeftPlus outDegeneratesLeftMinus@outDegeneratesLeftMinus 

% I/O Ports
in : in0 in1 in2 in3 in4
out : RationalSupporters Degenerates Neutralists 

% Internal I/O Connections
link : out@RationalSupportersTot in@RationalSupporters
link : out@DegeneratesTot in@Degenerates
link : out@NeutralistsTot in@Neutralists
link : out@outDegeneratesRightMinus outDegeneratesRightMinus@DegeneratesTot
link : out@neutralistsToDegeneratesPlus neutralistsToDegeneratesPlus@DegeneratesTot
link : out@neutralistsToDegeneratesMinus neutralistsToDegeneratesMinus@NeutralistsTot
link : out@rationalsToNeutralistsMinus rationalsToNeutralistsMinus@RationalSupportersTot
link : out@rationalsToNeutralistsPlus rationalsToNeutralistsPlus@NeutralistsTot
link : out@neutralistsToRationalsPlus neutralistsToRationalsPlus@RationalSupportersTot
link : out@neutralistsToRationalsMinus neutralistsToRationalsMinus@NeutralistsTot
link : out@outDegeneratesLeftMinus outDegeneratesLeftMinus@DegeneratesTot
link : out@RationalSupporters RationalSupporters@rationalsToNeutralistsPlus
link : out@RationalSupporters RationalSupporters@rationalsToNeutralistsMinus
link : out@Degenerates Degenerates@outDegeneratesRightPlus
link : out@Degenerates Degenerates@outDegeneratesRightMinus
link : out@Degenerates Degenerates@outDegeneratesLeftPlus
link : out@Degenerates Degenerates@outDegeneratesLeftMinus
link : out@Neutralists Neutralists@neutralistsToDegeneratesPlus
link : out@Neutralists Neutralists@neutralistsToDegeneratesMinus
link : out@Neutralists Neutralists@neutralistsToRationalsPlus
link : out@Neutralists Neutralists@neutralistsToRationalsMinus

% Links internos (variables de interes => output ports)
link : out@RationalSupporters RationalSupporters
link : out@Degenerates Degenerates
link : out@Neutralists Neutralists

% Integradores
[RationalSupporters]
x0 : 1
dQRel : 0.0001
dQMin : 0.0001

[Degenerates]
x0 : 1
dQRel : 0.0001
dQMin : 0.0001

[Neutralists]
x0 : 98
dQRel : 0.0001
dQMin : 0.0001

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
