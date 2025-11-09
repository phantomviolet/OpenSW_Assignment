#! /bin/bash

factorial() {

    list=$(seq $1 1)
    result=1
    for i in $list
    do
        result=$((i * $result))
    done
    echo "Factorial of $1 is $result"
}

read -p "Enter a number: " NUM
factorial $NUM