#include(macros.inc)

[top]
components : shocker0@Shocker shocker1@Shocker shocker2@Shocker shocker3@Shocker shocker4@Shocker conector@Conector opinion dueling-loops

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
link : out0@shocker0 in25@opinion
link : out0@shocker1 in32@opinion
link : out0@shocker2 in41@opinion
link : out0@shocker3 in61@opinion
link : out0@shocker4 in03@opinion
link : out10@shocker0 in75@opinion
link : out10@shocker1 in83@opinion
link : out10@shocker2 in87@opinion
link : out10@shocker3 in12@opinion
link : out10@shocker4 in96@opinion
link : out11@shocker0 in50@opinion
link : out11@shocker1 in64@opinion
link : out11@shocker2 in53@opinion
link : out11@shocker3 in07@opinion
link : out11@shocker4 in81@opinion
link : out12@shocker0 in63@opinion
link : out12@shocker1 in31@opinion
link : out12@shocker2 in26@opinion
link : out12@shocker3 in91@opinion
link : out12@shocker4 in74@opinion
link : out13@shocker0 in88@opinion
link : out13@shocker1 in43@opinion
link : out13@shocker2 in69@opinion
link : out13@shocker3 in42@opinion
link : out13@shocker4 in57@opinion
link : out14@shocker0 in01@opinion
link : out14@shocker1 in06@opinion
link : out14@shocker2 in76@opinion
link : out14@shocker3 in34@opinion
link : out14@shocker4 in70@opinion
link : out15@shocker0 in94@opinion
link : out15@shocker1 in33@opinion
link : out15@shocker2 in27@opinion
link : out15@shocker3 in90@opinion
link : out15@shocker4 in08@opinion
link : out16@shocker0 in65@opinion
link : out16@shocker1 in49@opinion
link : out16@shocker2 in86@opinion
link : out16@shocker3 in77@opinion
link : out16@shocker4 in89@opinion
link : out17@shocker0 in13@opinion
link : out17@shocker1 in45@opinion
link : out17@shocker2 in52@opinion
link : out17@shocker3 in82@opinion
link : out17@shocker4 in67@opinion
link : out18@shocker0 in29@opinion
link : out18@shocker1 in16@opinion
link : out18@shocker2 in66@opinion
link : out18@shocker3 in11@opinion
link : out18@shocker4 in72@opinion
link : out19@shocker0 in51@opinion
link : out19@shocker1 in84@opinion
link : out19@shocker2 in09@opinion
link : out19@shocker3 in99@opinion
link : out19@shocker4 in10@opinion
link : out1@shocker0 in78@opinion
link : out1@shocker1 in98@opinion
link : out1@shocker2 in62@opinion
link : out1@shocker3 in02@opinion
link : out1@shocker4 in28@opinion
link : out2@shocker0 in46@opinion
link : out2@shocker1 in20@opinion
link : out2@shocker2 in92@opinion
link : out2@shocker3 in44@opinion
link : out2@shocker4 in14@opinion
link : out3@shocker0 in79@opinion
link : out3@shocker1 in15@opinion
link : out3@shocker2 in58@opinion
link : out3@shocker3 in37@opinion
link : out3@shocker4 in56@opinion
link : out4@shocker0 in04@opinion
link : out4@shocker1 in18@opinion
link : out4@shocker2 in48@opinion
link : out4@shocker3 in05@opinion
link : out4@shocker4 in21@opinion
link : out5@shocker0 in39@opinion
link : out5@shocker1 in19@opinion
link : out5@shocker2 in71@opinion
link : out5@shocker3 in36@opinion
link : out5@shocker4 in55@opinion
link : out6@shocker0 in23@opinion
link : out6@shocker1 in93@opinion
link : out6@shocker2 in47@opinion
link : out6@shocker3 in73@opinion
link : out6@shocker4 in22@opinion
link : out7@shocker0 in97@opinion
link : out7@shocker1 in40@opinion
link : out7@shocker2 in38@opinion
link : out7@shocker3 in85@opinion
link : out7@shocker4 in35@opinion
link : out8@shocker0 in24@opinion
link : out8@shocker1 in00@opinion
link : out8@shocker2 in54@opinion
link : out8@shocker3 in80@opinion
link : out8@shocker4 in59@opinion
link : out9@shocker0 in17@opinion
link : out9@shocker1 in30@opinion
link : out9@shocker2 in95@opinion
link : out9@shocker3 in60@opinion
link : out9@shocker4 in68@opinion


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
dQRel : 0.001
dQMin : 0.001

[Degenerates]
x0 : 1
dQRel : 0.001
dQMin : 0.001

[Neutralists]
x0 : 98
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
PortInTransition : in@opinion(2,5,0) shockExterno
PortInTransition : in@opinion(3,2,0) shockExterno
PortInTransition : in@opinion(4,1,0) shockExterno
PortInTransition : in@opinion(6,1,0) shockExterno
PortInTransition : in@opinion(0,3,0) shockExterno
PortInTransition : in@opinion(7,8,0) shockExterno
PortInTransition : in@opinion(9,8,0) shockExterno
PortInTransition : in@opinion(6,2,0) shockExterno
PortInTransition : in@opinion(0,2,0) shockExterno
PortInTransition : in@opinion(2,8,0) shockExterno
PortInTransition : in@opinion(4,6,0) shockExterno
PortInTransition : in@opinion(2,0,0) shockExterno
PortInTransition : in@opinion(9,2,0) shockExterno
PortInTransition : in@opinion(4,4,0) shockExterno
PortInTransition : in@opinion(1,4,0) shockExterno
PortInTransition : in@opinion(7,9,0) shockExterno
PortInTransition : in@opinion(1,5,0) shockExterno
PortInTransition : in@opinion(5,8,0) shockExterno
PortInTransition : in@opinion(3,7,0) shockExterno
PortInTransition : in@opinion(5,6,0) shockExterno
PortInTransition : in@opinion(0,4,0) shockExterno
PortInTransition : in@opinion(1,8,0) shockExterno
PortInTransition : in@opinion(4,8,0) shockExterno
PortInTransition : in@opinion(0,5,0) shockExterno
PortInTransition : in@opinion(2,1,0) shockExterno
PortInTransition : in@opinion(3,9,0) shockExterno
PortInTransition : in@opinion(1,9,0) shockExterno
PortInTransition : in@opinion(7,1,0) shockExterno
PortInTransition : in@opinion(3,6,0) shockExterno
PortInTransition : in@opinion(5,5,0) shockExterno
PortInTransition : in@opinion(2,3,0) shockExterno
PortInTransition : in@opinion(9,3,0) shockExterno
PortInTransition : in@opinion(4,7,0) shockExterno
PortInTransition : in@opinion(7,3,0) shockExterno
PortInTransition : in@opinion(2,2,0) shockExterno
PortInTransition : in@opinion(9,7,0) shockExterno
PortInTransition : in@opinion(4,0,0) shockExterno
PortInTransition : in@opinion(3,8,0) shockExterno
PortInTransition : in@opinion(8,5,0) shockExterno
PortInTransition : in@opinion(3,5,0) shockExterno
PortInTransition : in@opinion(2,4,0) shockExterno
PortInTransition : in@opinion(0,0,0) shockExterno
PortInTransition : in@opinion(5,4,0) shockExterno
PortInTransition : in@opinion(8,0,0) shockExterno
PortInTransition : in@opinion(5,9,0) shockExterno
PortInTransition : in@opinion(1,7,0) shockExterno
PortInTransition : in@opinion(3,0,0) shockExterno
PortInTransition : in@opinion(9,5,0) shockExterno
PortInTransition : in@opinion(6,0,0) shockExterno
PortInTransition : in@opinion(6,8,0) shockExterno
PortInTransition : in@opinion(7,5,0) shockExterno
PortInTransition : in@opinion(8,3,0) shockExterno
PortInTransition : in@opinion(8,7,0) shockExterno
PortInTransition : in@opinion(1,2,0) shockExterno
PortInTransition : in@opinion(9,6,0) shockExterno
PortInTransition : in@opinion(5,0,0) shockExterno
PortInTransition : in@opinion(6,4,0) shockExterno
PortInTransition : in@opinion(5,3,0) shockExterno
PortInTransition : in@opinion(0,7,0) shockExterno
PortInTransition : in@opinion(8,1,0) shockExterno
PortInTransition : in@opinion(6,3,0) shockExterno
PortInTransition : in@opinion(3,1,0) shockExterno
PortInTransition : in@opinion(2,6,0) shockExterno
PortInTransition : in@opinion(9,1,0) shockExterno
PortInTransition : in@opinion(7,4,0) shockExterno
PortInTransition : in@opinion(8,8,0) shockExterno
PortInTransition : in@opinion(4,3,0) shockExterno
PortInTransition : in@opinion(6,9,0) shockExterno
PortInTransition : in@opinion(4,2,0) shockExterno
PortInTransition : in@opinion(5,7,0) shockExterno
PortInTransition : in@opinion(0,1,0) shockExterno
PortInTransition : in@opinion(0,6,0) shockExterno
PortInTransition : in@opinion(7,6,0) shockExterno
PortInTransition : in@opinion(3,4,0) shockExterno
PortInTransition : in@opinion(7,0,0) shockExterno
PortInTransition : in@opinion(9,4,0) shockExterno
PortInTransition : in@opinion(3,3,0) shockExterno
PortInTransition : in@opinion(2,7,0) shockExterno
PortInTransition : in@opinion(9,0,0) shockExterno
PortInTransition : in@opinion(0,8,0) shockExterno
PortInTransition : in@opinion(6,5,0) shockExterno
PortInTransition : in@opinion(4,9,0) shockExterno
PortInTransition : in@opinion(8,6,0) shockExterno
PortInTransition : in@opinion(7,7,0) shockExterno
PortInTransition : in@opinion(8,9,0) shockExterno
PortInTransition : in@opinion(1,3,0) shockExterno
PortInTransition : in@opinion(4,5,0) shockExterno
PortInTransition : in@opinion(5,2,0) shockExterno
PortInTransition : in@opinion(8,2,0) shockExterno
PortInTransition : in@opinion(6,7,0) shockExterno
PortInTransition : in@opinion(2,9,0) shockExterno
PortInTransition : in@opinion(1,6,0) shockExterno
PortInTransition : in@opinion(6,6,0) shockExterno
PortInTransition : in@opinion(1,1,0) shockExterno
PortInTransition : in@opinion(7,2,0) shockExterno
PortInTransition : in@opinion(5,1,0) shockExterno
PortInTransition : in@opinion(8,4,0) shockExterno
PortInTransition : in@opinion(0,9,0) shockExterno
PortInTransition : in@opinion(9,9,0) shockExterno
PortInTransition : in@opinion(1,0,0) shockExterno


%----------------------------------------------------------------------------
% --------------- REGLAS DE REACCION ANTE SHOCKS EXTERNOS -------------------
%----------------------------------------------------------------------------
[shockExterno]
rule : {  uniform(-3, -2) } 0 { portValue(in) = 5 }
rule : {  uniform(-1, 1)  } 0 { portValue(in) = 6 }
rule : {  uniform(2, 3) } 0 { portValue(in) = 7 }
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