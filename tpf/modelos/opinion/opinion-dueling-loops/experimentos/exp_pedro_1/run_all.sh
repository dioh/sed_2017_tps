#!/bin/bash
cwd=$PWD
cd ../../src && make && cd $cwd
chmod -R 777 .
for dir in */; do
	cd $dir
	./run.sh
	cd ..
done