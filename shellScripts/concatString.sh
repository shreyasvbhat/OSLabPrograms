#!/bin/bash
echo "Enter the first string "
read s1
echo "Enter the second string "
read s2
s3=$s1" "$s2
echo "Concatinated String $s3"
echo "Length of $s3 = ${#s3}"