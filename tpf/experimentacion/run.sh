#!/bin/bash

# Ejemplo de uso
# ./run.sh ./models/Influmodel.ma ./tp2_val_files ./event_files/exp_55555 00:10:00:00 tu.mail@dominio.com > ./ejecucion 2>&1

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
if [ -z "$4" ]; then
    echo "Debe indicarse cuanto tiempo deben ejecutarse las ejecuciones. En formato HH:MM:SS:MS"
fi

if [ -z "$5" ]; then
    echo "No se enviara correo tras la ejecucion"
else
    echo "Se enviara un correo a $5"
    stty -echo
    printf "email password: "
    read PASSWORD
    stty echo
fi    

# TODO Agregar parametro para el tiempo. ¿En segundos o formato DEVS? DEVS por ahora

MODEL_FILE_PATH="$1"
MODEL_FILE=$(basename $MODEL_FILE_PATH)
VAL_FILES_DIR_PATH="$2"
VAL_FILES_LAST_DIR=${VAL_FILES_DIR_PATH##*/}
EXPERIMENTS=`ls $VAL_FILES_DIR_PATH`
EVENTS_FILE="$3"
SIMULATION_TIME="$4"
EMAIL="$5"

RESULTS_DIR="./results"

for valFile in $EXPERIMENTS; do
	VAL_FILE_NAME=${valFile::-4}
	
	replace="$VAL_FILES_DIR_PATH/$valFile"
	sed "s:valfile.val:${replace}:" "$1" > Influmodel_now.ma

	src/bin/cd++ -mInflumodel_now.ma -e$EVENTS_FILE -t$SIMULATION_TIME -ltmp/log 
    if [ -f "./tmp/log01" ]; then
        echo "Archivo de log (log01) encontrado. Eliminando restantes de ./tmp"
        # Borra todos los archivos de log excepto por log01
        find ./tmp ! -name 'log01' -type f -exec rm -f {} +
        #VAR
        CSV_LOG="result_$VAL_FILE_NAME.csv"
        GROUPED_CSV="grouped_$VAL_FILE_NAME.csv"
        # El script python pone la extension .csv en el archivo resultado
        echo "Pasando out de celdas a csv."
        ./tools/cell_devs_logfile_to_csv.py ./tmp/log01 "$RESULTS_DIR/$CSV_LOG"
        #TODO PROBAR ESTA LINEA
        echo "Creando csv con cantidad de celdas de cada grupos para cada t."
        ./tools/csv_logfile_to_groups_count.py $RESULTS_DIR"/"$CSV_LOG $RESULTS_DIR"/"$GROUPED_CSV
        echo "Comprimiendo archivo $RESULTS_DIR/$CSV_LOG"
        gzip $RESULTS_DIR/$CSV_LOG
        rm ./tmp/log*
    else
        echo "Archivo de log (log01) no encontrado. Continuando loop.."
    fi
done

rm Influmodel_now.ma

count=`ls -1 $RESULTS_DIR/*.csv 2>/dev/null | wc -l`
if [ $count != 0 ]; then
    echo "Creando csv sumarizado."
    SUMMARIZED_FILE=$RESULTS_DIR"/"$VAL_FILES_LAST_DIR"_summarized_grouped.csv"
    ./tools/summarize_experiments.py ./results grouped_*.csv $SUMMARIZED_FILE
    if [[ ! -z $EMAIL ]]; then
        echo "Enviando correo con archivo sumarizado." 
        ./tools/send_email.py "$EMAIL" "$PASSWORD" "Experimento del modelo $MODEL_FILE con valores $VAL_FILES_LAST_DIR finalizado" $SUMMARIZED_FILE
    fi
    echo "Comprimiendo resultados." 
    compress_filename=$MODEL_FILE"_"$VAL_FILES_LAST_DIR".tar.gz"
    find "$RESULTS_DIR" -name "*.csv*" | xargs tar -czvf "$RESULTS_DIR/$compress_filename"
    if [ -f "$RESULTS_DIR/$compress_filename" ]; then
        echo "$compress_filename generado conteniendo archivos generados. Eliminando archivos."
        find "$RESULTS_DIR" ! -name "$compress_filename" -type f -exec rm -f {} +
    else
        echo "$compress_filename no encontrado. No se eliminan archivos de ./results/"
    fi    
    echo "Fin."
else
    echo "No se encontraron .csv en ./results para zippear. Fin!"
fi 
