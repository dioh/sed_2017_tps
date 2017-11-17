
todos=`ls cc33`

for valFile in $todos; do
	forlog=${valFile::-4}
	
	replace='cc33/'$valFile
	sed "s:valfile.val:${replace}:" Influmodel_3x3.ma > Influmodel_now_3x3.ma

	eventFile='evfile33.ev'
	src/bin/cd++ -mInflumodel_now_3x3.ma -e$eventFile -t00:04:00:00	-llog

	newlog='result_'$forlog
	# cp log01 'result_logs/'$newlog'.log'
	mv log* result_logs/
done
