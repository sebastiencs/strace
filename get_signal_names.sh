#!/bin/sh

cd `dirname $0`

cp templates/signames.h includes/
echo '  "'Undefined'",' >> includes/signames.h

for signal in `kill -l | tr ' ' '
'`; do
    echo '  "'SIG$signal'",' >> includes/signames.h
done

echo '};' >> includes/signames.h
echo -e "\n#endif /* !SIGNAMES_H_ */" >> includes/signames.h
