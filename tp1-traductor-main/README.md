# Instrucciones de ejecución

## Instalación

** El software fue testeado en Python 2.7.13

1. Instalar dependencias en requirements.txt con 'pip install -r requirements.txt'
1. Descargar y configurar CD++ desde el [siguiente link](https://www.dc.uba.ar/materias/sievdi/2017/cuat2/simulador-standalone-avanzado-2017)


## Ejecución

1. Invocar sd2devsml.py archivo_xmile_origen archivo_devsml_destino 


**Nota**: para la correcta compilación de los modelos verifique que la variable
CDPP_PATH se encuentra en el ambiente de la linea de comando y que tiene la ubicación de CD++.


## Tests

En el directorio de test se encuentran los recursos para traducir tres modelos de ejemplo.
Para ejecutar las traducciones utilice los siguientes comandos:

* Teacup: python traducir_teacup.py
* Sir: python traducir_sir.py
* Samuelson: python traducir_samuelson.py
* Stock to capacity: python traducir_stock_to_capacity.py

** Al correr los tests para cada modelo, se leen los archivos xmile en /tests, y a partir de esto se generan los archivos DEVSML, .h, .cpp, .ma y .ev. Antes de correr cada simulación, se puede modificar el archivo .ev para setear el valor de los parámetros del modelo
** Para correr los tests de traduccion para cada unos de los modelos, ejectuar:

Los resultados de las traducciones se encuentran en las carpetas correspondientes de cada uno de los modelos.

Para compilar los modelos a cd++  Ir a src. Compilar con 'make'.

Una vez finalizada la compilación, ejecutar los modelos de la siguiente manera:

* src/bin/cd++ -mteacup.ma -eteacup.ev
* src/bin/cd++ -msir.ma -esir.ev
* src/bin/cd++ -msamuelson.ma -esamuelson.ev
* src/bin/cd++ -mstock_to_capacity.ma -estock_to_capacity.ev


## Directorios de archivos:

* En templates/ se pueden encontrar los templates utilizados para generar los archivos .cpp, .h, .ma y .ev correspondientes a cada binario 'cd++' ejecutable.

* El codigo de los traductores esta en:
* sd2devsml.py, para pasar de XMILE a DEVSML
* devsml2ma.py, para pasar de DEVSML a un programa CD++ ejecutable 
* traducir...py, son archivos wrapper para traducir modelos de prueba
* tests tiene los archivos de entrada y de salida de la generacion de los modelos sir, teacup, samuelson y stock_to_capacity
