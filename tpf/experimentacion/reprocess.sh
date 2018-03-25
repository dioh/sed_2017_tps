#!/bin/bash

# Ejemplo de uso
# ./run.sh ./models/Influmodel.ma ./tp2_val_files ./event_files/exp_55555 00:10:00:00 tu.mail@dominio.com > ./ejecucion 2>&1

FILES_DIR="./logs/Model_B_shock_results"
LOGS=`ls $FILES_DIR/result*`

for LOGFILE in $LOGS; do
        # CSV_LOG=$MODEL_FILE_"result_"$VAL_FILE_NAME"_"$EVENTS_FILE".csv"
        GROUPED_CSV=${LOGFILE//result_/grouped_}

        # El script python pone la extension .csv en el archivo resultado
        echo "Creando csv con cantidad de celdas de cada grupos para cada t."
        echo "Input: $LOGFILE -> Output: $GROUPED_CSV"
        ./tools/csv_logfile_to_groups_count.py $LOGFILE $GROUPED_CSV
done

