#!/bin/bash

# Ejemplo de uso
# ./run.sh ./models/Influmodel.ma ./tp2_val_files ./event_files/exp_55555

if [ -z "$1" ]; then
    echo "Debe pasarse un archivo modelo (.ma) a ejecturar como parametro"
    exit 1
fi

if [ -z "$2" ]; then
    echo "Debe pasarse el directorio que contiene los archivos .val como parametro"
    exit 1
fi

if [ -z "$3" ]; then
    echo "Debe pasarse el archivo de eventos a utilizar"
    exit 1
fi

# TODO Agregar parametro para el tiempo. ¿En segundos o formato DEVS?

experimentos=`ls $2`

for valFile in $experimentos; do
	forlog=${valFile::-4}
	
	replace="$2/$valFile"
	sed "s:valfile.val:${replace}:" "$1" > Influmodel_now.ma

	eventFile=$3
	src/bin/cd++ -mInflumodel_now.ma -e$eventFile -t00:04:00:00	-llog
    if [ -f "log01" ]; then
        echo "Archivo de log (log01) encontrado. Procesando.."
        newlog='result_'$forlog
        # El script python pone la extension .csv en el archivo resultado
        ./tools/cell_devs_logfile_to_csv.py log01 "results/$newlog"
        rm log*
    else
        echo "Archivo de log (log01) no encontrado. Continuando loop.."
    fi
done

rm Influmodel_now.ma

count=`ls -1 results/*.csv 2>/dev/null | wc -l`
if [ $count != 0 ]; then
    compress_filename='results/'$2'.tar.gz'
    find ./results -name "*.csv" | xargs tar -czvf $compress_filename
    if [ -f "$compress_filename" ]; then
        echo "$compress_filename generado conteniendo csv. Eliminando archivos ./results/*.csv."
        rm ./results/*.csv
    else
        echo "$compress_filename no encontrado. No se eliminan archivos ./results/*.csv"
    fi    
    echo "Fin."
else
    echo "No se encontraron .csv en ./results para zippear. Fin!"
fi 
