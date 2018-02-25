#include(models/macros.inc)

% Modelo de ejemplo con las reglas del Modelo bando
% para probar reglas de shock.

[top]
components : opinion shocker0@Shocker shocker1@Shocker shocker2@Shocker 
%---------------------------------------------------
% Inputs + Links externos para shock exogeno
%---------------------------------------------------
in : in0 in1 in2 
link : in0 in@shocker0 
link : in1 in@shocker1 
link : in2 in@shocker2 

link : out0@shocker0 in22@opinion
link : out0@shocker1 in11@opinion
link : out0@shocker2 in12@opinion
link : out1@shocker0 in02@opinion
link : out1@shocker1 in01@opinion
link : out1@shocker2 in21@opinion
link : out2@shocker0 in20@opinion
link : out2@shocker1 in10@opinion
link : out2@shocker2 in00@opinion

%---------------------------------------------------

[opinion]
type : cell
dim : (3,3,2)
delay : transport
defaultDelayTime : 100	
border : unwrapped 		
neighbors : opinion(-1,0,0)
neighbors : opinion(0,-1,0)  opinion(0,0,0)  opinion(0,1,0)
neighbors : opinion(1,0,0)
neighbors : opinion(0,0,1)
initialvalue : -70
initialCellsValue : valfile.val

%---------------------------------------------------
Inputs + Links internos para shock exogeno
%---------------------------------------------------
in : in00 in01 in02 in10 in11 in12 in20 in21 in22 
link : in00 in@opinion(0,0,0)
link : in01 in@opinion(0,1,0)
link : in02 in@opinion(0,2,0)
link : in10 in@opinion(1,0,0)
link : in11 in@opinion(1,1,0)
link : in12 in@opinion(1,2,0)
link : in20 in@opinion(2,0,0)
link : in21 in@opinion(2,1,0)
link : in22 in@opinion(2,2,0)

%---------------------------------------------------

localtransition : opinion-rule
% Se debe definir para todas las celdas el PortInTransition
PortInTransition: in@opinion(0,0,0)	shock-rule
PortInTransition: in@opinion(0,1,0) shock-rule
PortInTransition: in@opinion(0,2,0) shock-rule
PortInTransition: in@opinion(1,0,0) shock-rule
PortInTransition: in@opinion(1,1,0) shock-rule
PortInTransition: in@opinion(1,2,0) shock-rule
PortInTransition: in@opinion(2,0,0) shock-rule
PortInTransition: in@opinion(2,1,0) shock-rule
PortInTransition: in@opinion(2,2,0) shock-rule

%----------------------------------------------------------------------------
%----------------------------------------------------------------------------

%----------------------------------------------------------------------------
% --------------- REGLAS DE REACCION ANTE SHOCKS EXTERNOS -------------------
% 5 es un shock hacia A [-3,-1) en qshock * delta
% 6 es un shock hacia I (-1,1) en qshock * delta
% 7 es un shock hacia B (1,3] en qshock * delta
%----------------------------------------------------------------------------
[shock-rule]
rule : {  (0,0,0) - #macro(shockq) * #macro(delta) } 0 { portValue(thisPort) = 5 }
rule : {  (0,0,0) } 0 { portValue(thisPort) = 6 and (0,0,0) = 0}
rule : {  (0,0,0) + #macro(shockq) * #macro(delta)  } 0 { portValue(thisPort) = 6 and (0,0,0) < 0}
rule : {  (0,0,0) - #macro(shockq) * #macro(delta)  } 0 { portValue(thisPort) = 6 and (0,0,0) > 0}
rule : {  (0,0,0) + #macro(shockq) * #macro(delta) } 0 { portValue(thisPort) = 7 }
% Regla por defecto
rule : { (0,0,0) } 100 { t }
%----------------------------------------------------------------------------


[opinion-rule]
rule :  { uniform(-2,2) } 0 { (0,0,0)=-70 and (0,0,1)!=? }
%Condicion inicial para la capa de opiniones (layer 1).
rule :  { randInt(3)+1 } 0 { (0,0,0)=-70 and (0,0,1)=?   }
%Condicion inicial para la capa de conectividad (layer 2).
 
%----------------------------------------------------------------------------
rule :  { randInt(3)+1 } 100 { (0,0,1)=?  }	
%Clock del modelo: actualizacion de la capa de conectividad.
%----------------------------------------------------------------------------

%Reglas para no pasarme del intervalo [-3;3] por sumar o restar #macro(delta): 
%Mire a quien mire, vote a quien vote, si el resultado de mi estado de conviccion actual +/- delta es mayor a
%3 (o -3), fijo el valor a 3 (o -3).
rule :  { -3 } 100 { (0,0,1)=1  and (0,0,0) < -1 and (((0,0,0) - #macro(delta))<-3 )and ( (0,1,0) < (0,0,0) or  (0,1,0) > 1 )}
rule :  { 3 } 100 { (0,0,1)=1  and (0,0,0) < -1 and (0,1,0) <= 1 and (((0,0,0) + #macro(delta))>3) }
rule :  { 3 } 100 { (0,0,1)=1  and (0,0,0) > 1 and (((0,0,0) + #macro(delta))>3) and ((0,1,0) > (0,0,0)  or  (0,1,0) <= -1 )  }
rule :  { -3 } 100 { (0,0,1)=1  and (0,0,0) > 1 and (((0,0,0) - #macro(delta))<-3) and (0,1,0) < (0,0,0)  }
rule :  { -3 } 100 { (0,0,1)=3  and (0,0,0) < -1 and (((0,0,0) - #macro(delta))<-3) and ( (0,-1,0) < (0,0,0) or  (0,-1,0) > 1 )}
rule :  { 3 } 100 { (0,0,1)=3  and (0,0,0) < -1 and (((0,0,0) + #macro(delta))>3) and (0,-1,0) <= 1 }
rule :  { 3 } 100 { (0,0,1)=3  and (0,0,0) > 1 and (((0,0,0) + #macro(delta))>3) and ((0,-1,0) > (0,0,0)  or  (0,-1,0) <= -1 )  }
rule :  { -3 } 100 { (0,0,1)=3  and (0,0,0) > 1 and (((0,0,0) - #macro(delta))<-3) and (0,-1,0) < (0,0,0)  }
rule :  { -3 } 100 { (0,0,1)=2  and (0,0,0) < -1 and (((0,0,0) - #macro(delta))<-3) and ( (-1,0,0) < (0,0,0) or  (-1,0,0) > 1 )}
rule :  { 3 } 100 { (0,0,1)=2  and (0,0,0) < -1 and (((0,0,0) + #macro(delta))>3) and (-1,0,0) <= 1 }
rule :  { 3 } 100 { (0,0,1)=2  and (0,0,0) > 1 and (((0,0,0) + #macro(delta))>3) and ((-1,0,0) > (0,0,0)  or  (-1,0,0) <= -1 )  }
rule :  { -3 } 100 { (0,0,1)=2  and (0,0,0) > 1 and (((0,0,0) - #macro(delta))<-3) and (-1,0,0) < (0,0,0)  }
rule :  { -3 } 100 { (0,0,1)=4  and (0,0,0) < -1 and (((0,0,0) - #macro(delta))<-3) and ( (1,0,0) < (0,0,0) or  (1,0,0) > 1 )}
rule :  { 3 } 100 { (0,0,1)=4  and (0,0,0) < -1 and (((0,0,0) + #macro(delta))>3) and (1,0,0) <= 1 }
rule :  { 3 } 100 { (0,0,1)=4  and (0,0,0) > 1 and (((0,0,0) + #macro(delta))>3) and ((1,0,0) > (0,0,0)  or  (1,0,0) <= -1 )  }
rule :  { -3 } 100 { (0,0,1)=4  and (0,0,0) > 1 and (((0,0,0) - #macro(delta))<-3) and (1,0,0) < (0,0,0)  }


%----- Reglas para ver a la derecha (capa de conectividad == 1) -------------
%Me quedo igual si tengo una pared o mi vecino tiene igual conviccion que yo.
rule :  { (0,0,0) } 100 { (0,0,1)=1  and ((0,1,0)=? or (0,1,0)=(0,0,0))}

%----------------------------------------------------------------------------
%Yo: Influyente/Partidiario - El: Indefinido - Resultado: Me acerco un delta.
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=1 and (0,0,0)>1 and abs((0,1,0))<=1 }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=1 and (0,0,0)<-1 and abs((0,1,0))<=1 }

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un delta.
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=1 and abs((0,0,0))<=1 and (0,1,0)>1 }
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=1 and abs((0,0,0))<=1 and (0,1,0)<-1 }

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Indefinido - Resultado: Me acerco un delta, sin cruzarme. Si estoy en cero, me quedo ahi.
rule :  { (0,0,0)*0 } 100 { (0,0,1)=1 and abs((0,0,0))<=#macro(delta) and abs((0,1,0))<=1 }
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=1 and abs((0,0,0))<=1 and abs((0,1,0))<=1 and (0,0,0)>0 }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=1 and abs((0,0,0))<=1 and abs((0,1,0))<=1 and (0,0,0)<0 }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario - Resultado: Si tengo mayor conviccion, me quedo igual, si no, me acerco un delta.
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=1 and (0,0,0)>1 and (0,1,0)>1 and (0,0,0)<(0,1,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=1 and (0,0,0)>1 and (0,1,0)>1 and (0,0,0)>(0,1,0) }
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=1 and (0,0,0)<-1 and (0,1,0)<-1 and (0,0,0)>(0,1,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=1 and (0,0,0)<-1 and (0,1,0)<-1 and (0,0,0)<(0,1,0) }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Me repele. (regla al final)
rule :  { (0,0,0) - #macro(delta)  } 100 { (0,0,1)=1 and (0,0,0)<-1 and (0,0,0)*(0,1,0)<=-1   }
rule :  { (0,0,0) + #macro(delta)  } 100 { (0,0,1)=1 and (0,0,0)>1 and (0,0,0)*(0,1,0)<=-1   }

%------Fin Reglas para ver a la derecha (capa de conectividad == 1)-----------

%----- Reglas para ver a abajo (capa de conectividad == 2) -------------------
%Me quedo igual si tengo una pared o mi vecino tiene igual conviccion que yo.
rule :  { (0,0,0) } 100 { (0,0,1)=2  and ((1,0,0)=? or (1,0,0)=(0,0,0))}

%----------------------------------------------------------------------------
%Yo: Influyente/Partidiario - El: Indefinido - Resultado: Me acerco un delta.
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)>1 and abs((1,0,0))<=1 }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)<-1 and abs((1,0,0))<=1 }

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un delta.
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=2 and abs((0,0,0))<=1 and (1,0,0)>1 }
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=2 and abs((0,0,0))<=1 and (1,0,0)<-1 }

%----------------------------------------------------------------------------
%%Yo: Indefinido - El: Indefinido - Resultado: Me acerco un delta.
rule :  { (0,0,0)*0 } 100 { (0,0,1)=2 and abs((0,0,0))<=#macro(delta) and abs((1,0,0))<=1 }
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=2 and abs((0,0,0))<=1 and abs((1,0,0))<=1 and (0,0,0)>0 }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=2 and abs((0,0,0))<=1 and abs((1,0,0))<=1 and (0,0,0)<0 }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario - Resultado: Si tengo mayor conviccion, me quedo igual, si no, me acerco un delta.
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)>1 and (1,0,0)>1 and (0,0,0)<(1,0,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=2 and (0,0,0)>1 and (1,0,0)>1 and (0,0,0)>(1,0,0) }
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)<-1 and (1,0,0)<-1 and (0,0,0)>(1,0,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=2 and (0,0,0)<-1 and (1,0,0)<-1 and (0,0,0)<(1,0,0) }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Me repele delta. (regla al final)
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)<-1 and (0,0,0)*(1,0,0)<=-1   }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)>1 and (0,0,0)*(1,0,0)<=-1   }


%----- Fin reglas para ver a abajo (capa de conectividad == 2) --------------

%----- Reglas para ver a la izquierda (capa de conectividad = 3) ------------
%Me quedo igual si tengo una pared o mi vecino tiene igual conviccion que yo.
rule :  { (0,0,0) } 100 { (0,0,1)=3  and ((0,-1,0)=? or (0,-1,0)=(0,0,0))}

%----------------------------------------------------------------------------
%Yo: Influyente/Partidiario - El: Indefinido - Resultado: Me acerco un delta.
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=3 and (0,0,0)>1 and abs((0,-1,0))<=1 }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=3 and (0,0,0)<-1 and abs((0,-1,0))<=1 }

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un delta.
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=3 and abs((0,0,0))<=1 and (0,-1,0)>1 }
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=3 and abs((0,0,0))<=1 and (0,-1,0)<-1 }

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Indefinido - Resultado: Me acerco un delta.
rule :  { (0,0,0)*0 } 100 { (0,0,1)=3 and abs((0,0,0))<=#macro(delta) and abs((0,-1,0))<=1 }
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=3 and abs((0,0,0))<=1 and abs((0,-1,0))<=1 and (0,0,0)>0 }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=3 and abs((0,0,0))<=1 and abs((0,-1,0))<=1 and (0,0,0)<0 }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario - Resultado: Si tengo mayor conviccion, me quedo igual, si no, me acerco un delta.
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=3 and (0,0,0)>1 and (0,-1,0)>1 and (0,0,0)<(0,-1,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=3 and (0,0,0)>1 and (0,-1,0)>1 and (0,0,0)>(0,-1,0) }
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=3 and (0,0,0)<-1 and (0,-1,0)<-1 and (0,0,0)>(0,-1,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=3 and (0,0,0)<-1 and (0,-1,0)<-1 and (0,0,0)<(0,-1,0) }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Me repele delta. (regla al final)
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=3 and (0,0,0)<-1 and (0,0,0)*(0,-1,0)<=-1   }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=3 and (0,0,0)>1 and (0,0,0)*(0,-1,0)<=-1   }


%----- Fin reglas para ver a la izquierda (capa de conectividad == 3) -------

%----- Reglas para ver a arriba (capa de conectividad == 4) -----------------
%Me quedo igual si tengo una pared o mi vecino tiene igual conviccion que yo.
rule :  { (0,0,0) } 100 { (0,0,1)=4  and ((-1,0,0)=? or (-1,0,0)=(0,0,0))}

%----------------------------------------------------------------------------
%Yo: Influyente/Partidiario - El: Indefinido - Resultado: Me acerco un delta.
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=4 and (0,0,0)>1 and abs((-1,0,0))<=1 }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=4 and (0,0,0)<-1 and abs((-1,0,0))<=1 }

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un delta.
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=4 and abs((0,0,0))<=1 and (-1,0,0)>1 }
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=4 and abs((0,0,0))<=1 and (-1,0,0)<-1 }

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Indefinido - Resultado: Me acerco un delta.
rule :  { (0,0,0)*0 } 100 { (0,0,1)=4 and abs((0,0,0))<=#macro(delta) and abs((-1,0,0))<=1 }
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=4 and abs((0,0,0))<=1 and abs((-1,0,0))<=1 and (0,0,0)>0 }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=4 and abs((0,0,0))<=1 and abs((-1,0,0))<=1 and (0,0,0)<0 }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario - Resultado: Si tengo mayor conviccion, me quedo igual, si no, me acerco un delta.
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=4 and (0,0,0)>1 and (-1,0,0)>1 and (0,0,0)<(-1,0,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=4 and (0,0,0)>1 and (-1,0,0)>1 and (0,0,0)>(-1,0,0) }
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=4 and (0,0,0)<-1 and (-1,0,0)<-1 and (0,0,0)>(-1,0,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=4 and (0,0,0)<-1 and (-1,0,0)<-1 and (0,0,0)<(-1,0,0) }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Me repele delta. (regla al final)
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=4 and (0,0,0)<-1 and (0,0,0)*(-1,0,0)<=-1   }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=4 and (0,0,0)>1 and (0,0,0)*(-1,0,0)<=-1   }

%---- Fin rglas para ver a arriba (capa de conectividad == 4) ---------------

%----------------------- Regla por defecto (default) ------------------------
rule : { (0,0,0) } 100 { t }