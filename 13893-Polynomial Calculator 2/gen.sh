#!/bin/bash

for i in {7..8}
do 
    echo "./testcase/$i.in ok."
    ./ans < "./testcase/$i.in" > "./testcase/$i.out"
done
