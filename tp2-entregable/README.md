* Guía de uso

** src/ contiene los archivos .h, .cpp y Makefile utilizados por CD++ para generar un ejecutable simulador
** templates/ contiene los archivos base .h, .cppy .ma utilizador por generar_conexiones.py para generar los archivos que CD++ requiere para crear el binario ejecutable correspondiente a cada modelo
** cc/ contiene los valores iniciales utilizados en la experimentación
** experimentos_evs/ contiene los archivos .ev, generados a partir de 'crearev.py' que es es un generador de archivos .ev
** script.sh es el script que utilizamos para correr los diferentes experimentos
** Influmodel.ma es el .ma base utilizado en los diferentes experimentos. En cada experimentos usamos el mismo modelo pero con diferentes valores iniciales de los atómicos del cell-devs, renombrando al archivo Influmodel_now.ma para cada una de las diferentes corridas (ver script.sh)
** procesar_logs_para_generar_histogramas y graficar.R se encargan de parsear los logs de cada uno de los experimentos, y generar los graficos de 'Whisker and Boxplot' que se pueden apreciar en el informe