#!/bin/bash

for I in {1..7}
do
echo "
Test number $I:"
cat ./tests/*test$I.txt | ./build/main 
done