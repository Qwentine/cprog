#!/bin/bash
#this is the bash script testing the return value of our program

#script runs "a.out" program and tests if the return value was 0

#NOTE 1 different comments style...  "#" means comments in bash

#NOTE 2 !!!!!!!!!!!!!!!  this is not C  !!!!!!!!!!!!!!!!!!!!! ... (its bash)

if ./a.out; then
 echo "***BASH*** program was OK"
else
 echo "***BASH*** program encountered an error"
fi

