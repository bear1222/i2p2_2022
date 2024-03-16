#!/bin/bash

for i in {0..12}
do 
    echo "./testcase/$i.in ok."
    ./ans < "./testcase/$i.in" > "./testcase/$i.out"
done
