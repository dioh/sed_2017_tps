#include(models/macros.inc)

%NOTA: El modelo sigue las reglas descriptas originalmente en el TPF de Dima. 
%      NO tiene las reglas de los influyentes. 
%      Hay 50% de chances de atraccion entre distinto partidos (no se rechazan siempre)
%      Tampoco acerca de manera diferenciada a los indecisos hacia un bando

[top]
components : opinion 

[opinion]
type : cell
dim : (10,10,2)
delay : intertial
defaultDelayTime : 100	
border : unwrapped 		
neighbors : opinion(-1,0,0)
neighbors : opinion(0,-1,0)  opinion(0,0,0)  opinion(0,1,0)
neighbors : opinion(1,0,0)
neighbors : opinion(0,0,1)
initialvalue : -70
initialCellsValue : valfile.val
localtransition : opinion-rule
%----------------------------------------------------------------------------
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
% rule :  { -3  } 0  { (0,0,0) < -3 }
% rule :  {  3  } 0 { (0,0,0) > 3  }

%----- Reglas para ver a la derecha (capa de conectividad == 1) -------------
%Me quedo igual si tengo una pared o mi vecino tiene igual conviccion que yo.
rule :  { (0,0,0) } 100 { (0,0,1)=1  and ((0,1,0)=? or (0,1,0)=(0,0,0))}

%----------------------------------------------------------------------------
%Yo: Influyente/Partidiario - El: Indefinido - Resultado: Me acerco un delta.
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=1 and (0,0,0)>1 and abs((0,1,0))<=1 }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=1 and (0,0,0)<-1 and abs((0,1,0))<=1 }

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un k*delta.
rule :  { (0,0,0) + #macro(k)*#macro(delta) } 100 { (0,0,1)=1 and abs((0,0,0))<=1 and (0,1,0)>1 }
rule :  { (0,0,0) - #macro(k)*#macro(delta) } 100 { (0,0,1)=1 and abs((0,0,0))<=1 and (0,1,0)<-1 }

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Indefinido - Resultado: Me acerco un delta, sin cruzarme. Si estoy en cero, me quedo ahi.
rule :  { (0,0,0)*0 } 100 { (0,0,1)=1 and abs((0,0,0))<=#macro(delta) and abs((0,1,0))<=1 }
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=1 and abs((0,0,0))<=1 and abs((0,1,0))<=1 and (0,0,0)>0 }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=1 and abs((0,0,0))<=1 and abs((0,1,0))<=1 and (0,0,0)<0 }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario - Resultado: Si tengo mayor conviccion, me quedo igual, si no, me acerco un delta.
rule :  { min((0,0,0) + #macro(delta), 3) } 100 { (0,0,1)=1 and (0,0,0)>1 and (0,1,0)>1 and (0,0,0)<(0,1,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=1 and (0,0,0)>1 and (0,1,0)>1 and (0,0,0)>(0,1,0) }
rule :  { max((0,0,0) - #macro(delta), -3)  } 100 { (0,0,1)=1 and (0,0,0)<-1 and (0,1,0)<-1 and (0,0,0)>(0,1,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=1 and (0,0,0)<-1 and (0,1,0)<-1 and (0,0,0)<(0,1,0) }


%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Tengo un 50% de acercarme y un 50% de alejarme un delta. (regla al final)
rule :  { if( randInt(1) < 1,min((0,0,0) + #macro(delta),3),max((0,0,0) - #macro(delta),-3) )  } 100 { (0,0,1)=1 and (0,0,0)*(0,1,0)<=-1  and (abs((0,0,0)) + #macro(delta) <=3) }

%------Fin Reglas para ver a la derecha (capa de conectividad == 1)-----------

%----- Reglas para ver a abajo (capa de conectividad == 2) -------------------
%Me quedo igual si tengo una pared o mi vecino tiene igual conviccion que yo.
rule :  { (0,0,0) } 100 { (0,0,1)=2  and ((1,0,0)=? or (1,0,0)=(0,0,0))}

%----------------------------------------------------------------------------
%Yo: Influyente/Partidiario - El: Indefinido - Resultado: Me acerco un delta.
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)>1 and abs((1,0,0))<=1 }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)<-1 and abs((1,0,0))<=1  }

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
rule :  { min((0,0,0) + #macro(delta),3) } 100 { (0,0,1)=2 and (0,0,0)>1 and (1,0,0)>1 and (0,0,0)<(1,0,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=2 and (0,0,0)>1 and (1,0,0)>1 and (0,0,0)>(1,0,0) }
rule :  { max((0,0,0) - #macro(delta),-3) } 100 { (0,0,1)=2 and (0,0,0)<-1 and (1,0,0)<-1 and (0,0,0)>(1,0,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=2 and (0,0,0)<-1 and (1,0,0)<-1 and (0,0,0)<(1,0,0) }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Tengo un 50% de acercarme y un 50% de alejarme un delta. (regla al final)
rule :  { if( randInt(1) < 1,min((0,0,0) + #macro(delta),3),max((0,0,0) - #macro(delta),-3) )  } 100 { (0,0,1)=2 and (0,0,0)*(1,0,0)<=-1 }

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
rule :  { min((0,0,0) + #macro(delta),3) } 100 { (0,0,1)=3 and (0,0,0)>1 and (0,-1,0)>1 and (0,0,0)<(0,-1,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=3 and (0,0,0)>1 and (0,-1,0)>1 and (0,0,0)>(0,-1,0) }
rule :  { max((0,0,0) - #macro(delta),-3) } 100 { (0,0,1)=3 and (0,0,0)<-1 and (0,-1,0)<-1 and (0,0,0)>(0,-1,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=3 and (0,0,0)<-1 and (0,-1,0)<-1 and (0,0,0)<(0,-1,0) }

%-----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Tengo un 50% de acercarme y un 50% de alejarme un delta. (regla al final)
rule :  { if( randInt(1) < 1,min((0,0,0) + #macro(delta),3),max((0,0,0) - #macro(delta),-3) )  } 100 { (0,0,1)=3 and (0,0,0)*(0,-1,0)<=-1 }

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
rule :  { min((0,0,0) + #macro(delta),3) } 100 { (0,0,1)=4 and (0,0,0)>1 and (-1,0,0)>1 and (0,0,0)<(-1,0,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=4 and (0,0,0)>1 and (-1,0,0)>1 and (0,0,0)>(-1,0,0) }
rule :  { max((0,0,0) - #macro(delta),-3) } 100 { (0,0,1)=4 and (0,0,0)<-1 and (-1,0,0)<-1 and (0,0,0)>(-1,0,0) }
rule :  { (0,0,0) } 100 { (0,0,1)=4 and (0,0,0)<-1 and (-1,0,0)<-1 and (0,0,0)<(-1,0,0) }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Tengo un 50% de acercarme y un 50% de alejarme un delta. (regla al final)
rule :  { if( randInt(1) < 1,min((0,0,0) + #macro(delta),3),max((0,0,0) - #macro(delta),-3) )  } 100 { (0,0,1)=4 and (0,0,0)*(-1,0,0)<=-1 }

%---- Fin rglas para ver a arriba (capa de conectividad == 4) ---------------

%----------------------- Regla por defecto (default) ------------------------
rule : { (0,0,0) } 100 { t }
