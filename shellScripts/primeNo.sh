#!/bin/bash
echo "Enter low value: "
read low
echo "Enter high value: "
read high
echo -n "Prime Numbers: "
for ((n=low; n<=high; n++))
 do
        isPrime=1
        for((i=2; i<=n/2; i++))
         do
                if [ $((n%i)) -eq 0 ]
                then
                        isPrime=0
                        break
                fi
        done
        if [ $isPrime -eq 1 ]
        then
                echo -n "$n "
        fi
 done