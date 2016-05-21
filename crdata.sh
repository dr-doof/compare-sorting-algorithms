#!/bin/bash

n=0

`gcc prog.c`
while [ $n -lt 1000000 ]
do
`./a.out $n>>data.txt`
n=`expr $n + 1000`
done
