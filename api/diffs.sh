vers=($(ls *.h | sort -t. -k1,1n -k2,2n -k3,3n))
rm -f diffs.diff
for ((i=0; i<${#vers[@]}-1; i++)); do
    echo ${vers[i]} .. ${vers[i+1]}
    diff -wBu0 --label=${vers[i]} --label=${vers[i+1]} ${vers[i]} ${vers[i+1]} >> diffs.diff
done
