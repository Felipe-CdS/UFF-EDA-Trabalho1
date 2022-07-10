#!/bin/bash

## Vars
T="5"
ADD_FILE1="a n teste1.txt"
ADD_FILE2="a n teste2.txt"
ADD_FILE3="a n teste3.txt"
RMV_FILE1="r teste1.txt"
RMV_FILE2="r teste2.txt"
RMV_FILE3="r teste3.txt"
PRINT="l"

## Script
make relibs
clear
cat <(echo $T) <(echo $ADD_FILE1) <(echo $ADD_FILE2) <(echo $ADD_FILE3) <(echo $PRINT) <(echo $PRINT) - | ./a.out
