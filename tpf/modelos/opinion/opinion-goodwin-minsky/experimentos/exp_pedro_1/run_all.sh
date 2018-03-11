#!/bin/bash
chmod -R 777 .
for dir in */; do
	cd $dir
	./run.sh
	cd ..
done