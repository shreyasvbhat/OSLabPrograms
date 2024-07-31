#!/bin/bash
echo "Enter the number: "
read n
temp=$n
rev=0
while(($temp > 0))
 do
        r=$((temp%10))
        rev=$((rev*10+r))
        temp=$((temp/10))
 done
if [ $rev -eq $n ];
 then echo "It is a Palindrome..."
else echo "It is not a Palindrome..."
fi