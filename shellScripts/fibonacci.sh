#!/bin/bash
n1=0
n2=1
echo "Enter the number of fibonacci numbers in the series: "
read n
echo "First $n fibonacci numbers: "
for (( i=0; i<$n; i++ ))
 do
        echo "$n1 "
        n3=$(($n1+$n2))
        n1=$n2
        n2=$n3
 done