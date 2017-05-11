#!/bin/bash

#Check the time it takes to run the bingen software, to be able to predict the runtime.

for skal in {1..4}
do
    for levels in {40..50}
    do
	A=$((TIMEFORMAT="%U"; time ./bingen --directory vask --Bfield 1 --Efield 1000 --Angle 90 --shells $skal --levels $levels --rmdir --threads 1 --MinShells 0 --MinLevels 40) |& tr -d .| sed s/^0*//)
	echo -e $skal'\t'$levels'\t'$A
	echo -e $skal'\t'$levels'\t'$A >> $1
    done

done