
todos=`ls cc`

for valFile in $todos; do
	forlog=${valFile::-4}
	
	replace='cc/'$valFile
	sed "s:valfile.val:${replace}:" Influmodel.ma > Influmodel_now.ma

	eventFile='evfile.ev'
	src/bin/cd++ -mInflumodel_now.ma -e$eventFile -t00:04:00:00	-llog

	newlog='result_'$forlog
	cp log01 'result_logs/'$newlog
	rm log*
done