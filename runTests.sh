#!/bin/bash

for I in {1..10}
do
echo "
Test number $I:"
cat ./tests/*test$I[VI]**.txt | ./build/main 
done