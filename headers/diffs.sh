#!/bin/bash
vers=($(ls *.h | sed s/a/.a./g | sed s/b/.b./g | sed s/f/.f./g | sed s/p/.p./g | sort -t. -k1,1n -k2,2n -k3,3n -k4,4d -k5,5n | sed s/.a./a/g | sed s/.b./b/g | sed s/.f./f/g | sed s/.p./p/g))
rm -f diffs.diff
for ((i=0; i<${#vers[@]}-1; i++)); do
    echo ${vers[i]} .. ${vers[i+1]}
    diff -purwB --label=${vers[i]} --label=${vers[i+1]} ${vers[i]} ${vers[i+1]} >> diffs.diff
done
