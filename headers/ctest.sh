for i in *.h; do
    gcc -xc -include stdint.h -include stdlib.h -include stdbool.h -o /dev/null -c $i
done