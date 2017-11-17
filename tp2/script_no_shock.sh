
todos=`ls cc`

for valFile in $todos; do
	forlog=${valFile::-4}
	
	replace='cc/'$valFile
	sed "s:valfile.val:${replace}:" Influmodel_no_shock.ma > Influmodel_no_shock_now.ma

	eventFile='evfile.ev'
	src/bin/cd++ -mInflumodel_no_shock_now.ma -t00:04:00:00	-llog

	newlog='result_'$forlog
	cp log01 'result_logs/'$newlog'.log'
	rm log*
done
