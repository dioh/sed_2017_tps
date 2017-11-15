* Instrucciones de ejecucion:

** El software fue testeado en Python 2.7.13
** Instalar dependencias en requirements.txt con 'pip install -r requirements.txt'
** Al correr los tests para cada modelo, se leen los archivos xmile en /tests, y a partir de esto se generan los archivos DEVSML, .h, .cpp, .ma y .ev
** Para correr los tests de traduccion para cada unos de los modelos, ejectuar:
*** python traducir_teacup.py
*** python traducir_sir.py
*** python traducir_samuelson.py
*** Ir a las carpetas correspondientes a cada uno de los modelos. Ir a src. Compilar con 'make'.
*** Una vez que compilo todo, correr de la siguiente forma (ejemplo para teacup):
**** src/bin/cd++ -mteacup.ma -eteacup.ev
**** src/bin/cd++ -msir.ma -esir.ev

** En templates/ se pueden encontrar los templates utilizados para generar los archivos .cpp, .h, .ma y .ev 
** El codigo de los traductores esta en:
*** sd2devsml.py, para pasar de XMILE a DEVSML
*** devsml2ma.py, para pasar de DEVSML a un programe CD++ ejecutable 
