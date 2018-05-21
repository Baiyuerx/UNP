#! /usr/bash

if [ -f 20000.lines ]
then
	rm -f 20000.lines
fi

touch 2000.lines

for i in $(seq 20000)
do
	date -R >> 20000.lines
done

exit 0

