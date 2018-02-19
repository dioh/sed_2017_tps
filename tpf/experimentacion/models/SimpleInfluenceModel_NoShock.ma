#include(models/macros.inc)

% NOTA: este modelo no tiene las reglas de los influyentes. 
%       Ni de 50% de atraccion entre distinto partido (intenta mas parecido al paper original)
%       Tampoco acerca de manera diferenciada a los indecisos hacia un bando

#include(macros.inc)

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

%----------------------------------------------------------------------------
% --------------- REGLAS DE REACCION ANTE SHOCKS EXTERNOS -------------------
%----------------------------------------------------------------------------
rule : {  uniform(-3, -2) } 0 { (0,0,0) = 5 }
rule : {  uniform(-1, 1)  } 0 { (0,0,0) = 6 }
rule : {  uniform(2, 3) } 0 { (0,0,0) = 7 }
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
rule :  { (0,0,0) } 100 { (0,0,1)=1  and ((0,1,0)=? or (0,1,0)=(0,0,0))}
%Me quedo igual si tengo una pared o mi vecino tiene igual conviccion que yo.

%----------------------------------------------------------------------------
%Yo: Influyente - El: Influyente del otro bando - Resultado: Me repelo un delta.
% rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=1 and (0,0,0)<=-#macro(long) and (0,1,0)>=#macro(long) }
% rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=1 and (0,0,0)>=#macro(long) and (0,1,0)<=-#macro(long) }

%----------------------------------------------------------------------------
%Yo: Influyente - El: Influyente - Resultado: Me quedo igual. (regla posterior a la de InfA-InfB)
% rule :  { (0,0,0) } 100 { (0,0,1)=1 and abs((0,0,0))>=abs(#macro(long)) and abs((0,1,0))>1 }

%----------------------------------------------------------------------------
%Yo: Influyente/Partidiario - El: Indefinido - Resultado: Me acerco un delta.
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=1 and (0,0,0)>1 and abs((0,1,0))<=1 }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=1 and (0,0,0)<-1 and abs((0,1,0))<=1 }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Influyente - Resultado: Me acerco un delta.
% rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=1 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (0,1,0)<=-#macro(long) }
% rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=1 and (0,0,0)>1 and (0,0,0)<#macro(long) and (0,1,0)>=#macro(long) }

%----------------------------------------------------------------------------
%Yo: Partidiario - El Influyente del otro bando - Resultado: Me acerco un q*delta.
% rule :  { (0,0,0) + #macro(q)*#macro(delta) } 100 { (0,0,1)=1 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (0,1,0)>=#macro(long) }
% rule :  { (0,0,0) - #macro(q)*#macro(delta) } 100 { (0,0,1)=1 and (0,0,0)>1 and (0,0,0)<#macro(long) and (0,1,0)<=-#macro(long) }

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un k*delta.
% rule :  { (0,0,0) + #macro(k)*#macro(delta) } 100 { (0,0,1)=1 and abs((0,0,0))<=1 and (0,1,0)>1 and (0,1,0)<#macro(long)}
% rule :  { (0,0,0) - #macro(k)*#macro(delta) } 100 { (0,0,1)=1 and abs((0,0,0))<=1 and (0,1,0)<-1 and (0,1,0)>-#macro(long)}

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un delta.
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=1 and abs((0,0,0))<=1 and (0,1,0)>1 and (0,1,0)<#macro(long)}
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=1 and abs((0,0,0))<=1 and (0,1,0)<-1 and (0,1,0)>-#macro(long)}

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Influyente - Resultado: Me acerco un q*delta.
% rule :  { (0,0,0) + #macro(q)*#macro(delta) } 100 { (0,0,1)=1 and abs((0,0,0))<=1 and (0,1,0)>=#macro(long) }
% rule :  { (0,0,0) - #macro(q)*#macro(delta) } 100 { (0,0,1)=1 and abs((0,0,0))<=1 and (0,1,0)<-#macro(long) }

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
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Tengo un 50% de acercarme y un 50% de alejarme un delta. (regla al final)
%rule :  { if( randInt(1) < 1,(0,0,0) + #macro(delta),(0,0,0) - #macro(delta) )  } 100 { (0,0,1)=1 and (0,0,0)*(0,1,0)<=-1   }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Me repele. (regla al final)
rule :  { (0,0,0) - #macro(delta)  } 100 { (0,0,1)=1 and (0,0,0)<-1 and (0,0,0)*(0,1,0)<=-1   }
rule :  { (0,0,0) + #macro(delta)  } 100 { (0,0,1)=1 and (0,0,0)>1 and (0,0,0)*(0,1,0)<=-1   }

%------Fin Reglas para ver a la derecha (capa de conectividad == 1)-----------

%----- Reglas para ver a abajo (capa de conectividad == 2) -------------------
%Me quedo igual si tengo una pared o mi vecino tiene igual conviccion que yo.
rule :  { (0,0,0) } 100 { (0,0,1)=2  and ((1,0,0)=? or (1,0,0)=(0,0,0))}

%----------------------------------------------------------------------------
%Yo: Influyente - El: Influyente del otro bando - Resultado: Me repelo un delta.
%rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)<=-#macro(long) and (1,0,0)>=#macro(long) }
%rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)>=#macro(long) and (1,0,0)<=-#macro(long) }

%----------------------------------------------------------------------------
%Yo: Influyente - El: Influyente - Resultado: Me quedo igual. (regla posterior a la de InfA-InfB)
%rule :  { (0,0,0) } 100 { (0,0,1)=2 and abs((0,0,0))>=abs(#macro(long)) and abs((1,0,0))>1 }

%----------------------------------------------------------------------------
%Yo: Influyente/Partidiario - El: Indefinido - Resultado: Me acerco un delta.
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)>1 and abs((1,0,0))<=1 }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)<-1 and abs((1,0,0))<=1  }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Influyente - Resultado: Me acerco un delta.
%rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (1,0,0)<=-#macro(long) }
%rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)>1 and (0,0,0)<#macro(long) and (1,0,0)>=#macro(long) }

%----------------------------------------------------------------------------
%Yo: Partidiario - El Influyente del otro bando - Resultado: Me acerco un q*delta.
%rule :  { (0,0,0) + #macro(q)*#macro(delta) } 100 { (0,0,1)=2 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (1,0,0)>=#macro(long) }
%rule :  { (0,0,0) - #macro(q)*#macro(delta) } 100 { (0,0,1)=2 and (0,0,0)>1 and (0,0,0)<#macro(long) and (1,0,0)<=-#macro(long) }

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un k*delta.
%rule :  { (0,0,0) + #macro(k)*#macro(delta) } 100 { (0,0,1)=2 and abs((0,0,0))<=1 and (1,0,0)>1 and (1,0,0)<#macro(long)}
%rule :  { (0,0,0) - #macro(k)*#macro(delta) } 100 { (0,0,1)=2 and abs((0,0,0))<=1 and (1,0,0)<-1 and (1,0,0)>-#macro(long)}

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un delta.
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=2 and abs((0,0,0))<=1 and (1,0,0)>1 and (1,0,0)<#macro(long)}
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=2 and abs((0,0,0))<=1 and (1,0,0)<-1 and (1,0,0)>-#macro(long)}


%----------------------------------------------------------------------------
%Yo: Indefinido - El: Influyente - Resultado: Me acerco un q*delta.
%rule :  { (0,0,0) + #macro(q)*#macro(delta) } 100 { (0,0,1)=2 and abs((0,0,0))<=1 and (1,0,0)>=#macro(long) }
%rule :  { (0,0,0) - #macro(q)*#macro(delta) } 100 { (0,0,1)=2 and abs((0,0,0))<=1 and (1,0,0)<-#macro(long) }

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
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Tengo un 50% de acercarme y un 50% de alejarme un delta. (regla al final)
% rule :  { if( randInt(1) < 1,(0,0,0) + #macro(delta),(0,0,0) - #macro(delta) )  } 100 { (0,0,1)=2 and (0,0,0)*(1,0,0)<=-1   }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Me repele delta. (regla al final)
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)<-1 and (0,0,0)*(1,0,0)<=-1   }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=2 and (0,0,0)>1 and (0,0,0)*(1,0,0)<=-1   }


%----- Fin reglas para ver a abajo (capa de conectividad == 2) --------------

%----- Reglas para ver a la izquierda (capa de conectividad = 3) ------------
%Me quedo igual si tengo una pared o mi vecino tiene igual conviccion que yo.
rule :  { (0,0,0) } 100 { (0,0,1)=3  and ((0,-1,0)=? or (0,-1,0)=(0,0,0))}

%----------------------------------------------------------------------------
%Yo: Influyente - El: Influyente del otro bando - Resultado: Me repelo un delta.
%rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=3 and (0,0,0)<=-#macro(long) and (0,-1,0)>=#macro(long) }
%rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=3 and (0,0,0)>=#macro(long) and (0,-1,0)<=-#macro(long) }

%----------------------------------------------------------------------------
%Yo: Influyente - El: Influyente - Resultado: Me quedo igual. (regla posterior a la de InfA-InfB)
%rule :  { (0,0,0) } 100 { (0,0,1)=3 and abs((0,0,0))>=abs(#macro(long)) and abs((0,-1,0))>1 }

%----------------------------------------------------------------------------
%Yo: Influyente/Partidiario - El: Indefinido - Resultado: Me acerco un delta.
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=3 and (0,0,0)>1 and abs((0,-1,0))<=1 }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=3 and (0,0,0)<-1 and abs((0,-1,0))<=1 }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Influyente - Resultado: Me acerco un delta.
%rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=3 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (0,-1,0)<=-#macro(long) }
%rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=3 and (0,0,0)>1 and (0,0,0)<#macro(long) and (0,-1,0)>=#macro(long) }

%----------------------------------------------------------------------------
%Yo: Partidiario - El Influyente del otro bando - Resultado: Me acerco un q*delta.
%rule :  { (0,0,0) + #macro(q)*#macro(delta) } 100 { (0,0,1)=3 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (0,-1,0)>=#macro(long) }
%rule :  { (0,0,0) - #macro(q)*#macro(delta) } 100 { (0,0,1)=3 and (0,0,0)>1 and (0,0,0)<#macro(long) and (0,-1,0)<=-#macro(long) }

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un k*delta.
%rule :  { (0,0,0) + #macro(k)*#macro(delta) } 100 { (0,0,1)=3 and abs((0,0,0))<=1 and (0,-1,0)>1 and (0,-1,0)<#macro(long) }
%rule :  { (0,0,0) - #macro(k)*#macro(delta) } 100 { (0,0,1)=3 and abs((0,0,0))<=1 and (0,-1,0)<-1 and (0,-1,0)>-#macro(long)}

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un delta.
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=3 and abs((0,0,0))<=1 and (0,-1,0)>1 and (0,-1,0)<#macro(long) }
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=3 and abs((0,0,0))<=1 and (0,-1,0)<-1 and (0,-1,0)>-#macro(long)}


%----------------------------------------------------------------------------
%Yo: Indefinido - El: Influyente - Resultado: Me acerco un q*delta.
%rule :  { (0,0,0) + #macro(q)*#macro(delta) } 100 { (0,0,1)=3 and abs((0,0,0))<=1 and (0,-1,0)>=#macro(long) }
%rule :  { (0,0,0) - #macro(q)*#macro(delta) } 100 { (0,0,1)=3 and abs((0,0,0))<=1 and (0,-1,0)<-#macro(long) }

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

%-----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Tengo un 50% de acercarme y un 50% de alejarme un delta. (regla al final)
% rule :  { if( randInt(1) < 1,(0,0,0) + #macro(delta),(0,0,0) - #macro(delta) )  } 100 { (0,0,1)=3 and (0,0,0)*(0,-1,0)<=-1   }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Me repele delta. (regla al final)
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=3 and (0,0,0)<-1 and (0,0,0)*(0,-1,0)<=-1   }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=3 and (0,0,0)>1 and (0,0,0)*(0,-1,0)<=-1   }


%----- Fin reglas para ver a la izquierda (capa de conectividad == 3) -------

%----- Reglas para ver a arriba (capa de conectividad == 4) -----------------
%Me quedo igual si tengo una pared o mi vecino tiene igual conviccion que yo.
rule :  { (0,0,0) } 100 { (0,0,1)=4  and ((-1,0,0)=? or (-1,0,0)=(0,0,0))}

%----------------------------------------------------------------------------
%Yo: Influyente - El: Influyente del otro bando - Resultado: Me repelo un delta.
%rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=4 and (0,0,0)<=-#macro(long) and (-1,0,0)>=#macro(long) }
%rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=4 and (0,0,0)>=#macro(long) and (-1,0,0)<=-#macro(long) }

%----------------------------------------------------------------------------
%Yo: Influyente - El: Influyente - Resultado: Me quedo igual. (regla posterior a la de InfA-InfB)
%rule :  { (0,0,0) } 100 { (0,0,1)=4 and abs((0,0,0))>=abs(#macro(long)) and abs((-1,0,0))>1 }

%----------------------------------------------------------------------------
%Yo: Influyente/Partidiario - El: Indefinido - Resultado: Me acerco un delta.
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=4 and (0,0,0)>1 and abs((-1,0,0))<=1 }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=4 and (0,0,0)<-1 and abs((-1,0,0))<=1 }

%----------------------------------------------------------------------------
%Yo: Partidiario - El: Influyente - Resultado: Me acerco un delta.
%rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=4 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (-1,0,0)<=-#macro(long) }
%rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=4 and (0,0,0)>1 and (0,0,0)<#macro(long) and (-1,0,0)>=#macro(long) }

%----------------------------------------------------------------------------
%Yo: Partidiario - El Influyente del otro bando - Resultado: Me acerco un q*delta.
%rule :  { (0,0,0) + #macro(q)*#macro(delta) } 100 { (0,0,1)=4 and (0,0,0)<-1 and (0,0,0)>-#macro(long) and (-1,0,0)>=#macro(long) }
%rule :  { (0,0,0) - #macro(q)*#macro(delta) } 100 { (0,0,1)=4 and (0,0,0)>1 and (0,0,0)<#macro(long) and (-1,0,0)<=-#macro(long) }

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un k*delta.
%rule :  { (0,0,0) + #macro(k)*#macro(delta) } 100 { (0,0,1)=4 and abs((0,0,0))<=1 and (-1,0,0)>1 and (-1,0,0)<#macro(long)}
%rule :  { (0,0,0) - #macro(k)*#macro(delta) } 100 { (0,0,1)=4 and abs((0,0,0))<=1 and (-1,0,0)<-1 and (-1,0,0)>-#macro(long) }

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Partidiario - Resultado: Me acerco un delta.
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=4 and abs((0,0,0))<=1 and (-1,0,0)>1 and (-1,0,0)<#macro(long)}
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=4 and abs((0,0,0))<=1 and (-1,0,0)<-1 and (-1,0,0)>-#macro(long) }

%----------------------------------------------------------------------------
%Yo: Indefinido - El: Influyente - Resultado: Me acerco un q*delta.
%rule :  { (0,0,0) + #macro(q)*#macro(delta) } 100 { (0,0,1)=4 and abs((0,0,0))<=1 and (-1,0,0)>=#macro(long) }
%rule :  { (0,0,0) - #macro(q)*#macro(delta) } 100 { (0,0,1)=4 and abs((0,0,0))<=1 and (-1,0,0)<-#macro(long) }

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
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Tengo un 50% de acercarme y un 50% de alejarme un delta. (regla al final)
%rule :  { if( randInt(1) < 1,(0,0,0) + #macro(delta),(0,0,0) - #macro(delta) )  } 100 { (0,0,1)=4 and (0,0,0)*(-1,0,0)<=-1   }


%----------------------------------------------------------------------------
%Yo: Partidiario - El: Partidiario del bando contrario - Resultado: Me repele delta. (regla al final)
rule :  { (0,0,0) - #macro(delta) } 100 { (0,0,1)=4 and (0,0,0)<-1 and (0,0,0)*(-1,0,0)<=-1   }
rule :  { (0,0,0) + #macro(delta) } 100 { (0,0,1)=4 and (0,0,0)>1 and (0,0,0)*(-1,0,0)<=-1   }

%---- Fin rglas para ver a arriba (capa de conectividad == 4) ---------------

%----------------------- Regla por defecto (default) ------------------------
rule : { (0,0,0) } 100 { t }
