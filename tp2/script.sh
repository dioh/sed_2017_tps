
todos=`ls cc`

for valFile in $todos; do
	forlog=${valFile::-4}
	newlog='result_'$forlog
	
	replace='cc/'$valFile
	sed "s:valfile.val:${replace}:" Influmodel.ma > Influmodel_now.ma

	eventFile='evfile.ev'
	src/bin/cd++ -mInflumodel_now.ma -e$eventFile -t00:00:01:00	-llog
	cp log01 'result_logs/'$newlog
	rm log*
done