mkdir csvs
cp *val csvs
cd csvs
for i in $(ls *.val); do sed -i  "s/(//g;s/)=/,/g" $i; done


