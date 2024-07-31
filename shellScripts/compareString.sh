#!/bin/bash
echo "Enter the first string "
read str1
echo "Enter the second string "
read str2
if [ $str1 == $str2 ]; then
        echo "$str1 and $str2 are the same"
else if [ $str1 \> $str2 ]
        then echo "$str1 is greater than $str2 "
else
        echo "$str2 is greater than $str1 "
fi
fi