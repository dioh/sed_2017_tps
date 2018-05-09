
Restricciones
	* en las funciones especiales, no se pueden utilizar dentro de la funcion simbolos +,-,*,/,etc. En
	lugar de eso, hay que crear una Aux que haga esa cuenta, y meterle como input esa variable a la funcion

Update:
	* agrego el atributo 'parent' a todos los atomicos (es necesario porque puede que tengamos el mismo atomico 
	- es decir, con el mismo nombre - en diferentes modulos, y de alguna forma hay que diferenciarlos)
	* empiezo a estructurar un archivo traductor.py para traducir tanto a devsml como a archivos .h y .cpp
	* el output de traductor.py por ahora va a lotka-volterra-nested/top.xml y los .h y .cpp van a ir a lotka-volterra-nested/atomics/*
	* agrego DEVSGenerator.py con el proposito de hacer lo que puse mas arriba
	* Nota : algo importante, es que las Cte's van a poder tener inputs! (!= a como estaba antes). Esto es basicamente por el tema de las
	funciones especiales que pueden haber en la 'equation' de la Cte

Pendientes:
	* reestructurar el codigo un toque... usar clases / subclases
	* terminar generador de CellDevs
	* DEVSPulse: 
		* cambiar 'start' por first_pulse


Comentarios:
	* DEVSPulse:
		. que pasa si en equation biene un PULSE(,,) + 'algo'? (guardar ultimo valor de PULSE) => comportamiento indefinido (ver que pasa en STELLA ... es medio raro)