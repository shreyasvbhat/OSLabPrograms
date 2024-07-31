#!/bin/bash
read -p "Enter the first number: " num1
read -p "Enter the second number: " num2
read -p "Enter the operation (+,-,/,*): " operator
case $operator in
 +) result=$(($num1+$num2));;
 -) result=$(($num1-$num2));;
 \*) result=$(($num1*$num2));;
 /) if [ $num2 -eq 0 ];
    then echo "Error: Division by zero!"
        exit 1
    fi
    result=$(($num1/$num2));;
 *) echo "Invalid operator "; exit 1;;
esac
echo "Result = $result"