#!/bin/sh

cd `dirname $0`

cp templates/signames.c src/
echo '  "'Undefined'",' >> src/signames.c

for signal in `kill -l | tr ' ' '
'`; do
    echo '  "'SIG$signal'",' >> src/signames.c
done

echo '};' >> src/signames.c
