#!/bin/sh

cat syscallent.h | grep "=" | sed "s/\[/ /g" | sed "s/\]/ /g" | awk '{print "{ " $1 ", " $7 ", " $4 "}"}' | sed "s/\"}/\"/g" | sed "s/,}/ },/g" | sed "s/,,/,/g"

# cat /usr/include/asm/unistd_64.h | cut -d ' ' -f 2,3 | grep __NR_ | sed "s/ /\", /g" | sed "s/__NR_/{ \"/g" | sed ':a;N;$!ba;s/\n/ },\n/g'
