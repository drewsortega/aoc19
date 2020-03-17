#!/bin/bash

let N_AMPS=5
let N_LOOPS=5**${N_AMPS}-1
let AMPS_LOOP=${N_AMPS}-1
PROG='program.int'

echo 0-$N_LOOPS N_LOOPS

let max=0
for (( i=0; i<=$N_LOOPS; i++ ))
do
    it="$i"
    let inp=0
    for (( j=0; j<=$AMPS_LOOP; j++ ))
    do
	let "sig = ${it} % 5"
	let it=${it}/5
    echo $sig $it $inp
	inp=$(printf "${sig}\n${inp}\n" | ./intcode ${PROG})
    done
    if (( $inp > ${max} )); then
	let max=$inp
    fi
    echo ${inp}, ${max}
done
echo ${max}
