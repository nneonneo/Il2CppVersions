#!/bin/bash -ex
for i in *.h; do
    cc -m32 -DIS_32BIT -include stdint.h -include stdlib.h -include $i -c offsettest.cpp -o /dev/null
    cc -m64 -include stdint.h -include stdlib.h -include $i -c offsettest.cpp -o /dev/null
done
