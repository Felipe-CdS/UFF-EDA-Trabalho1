#!/bin/bash

## Vars
T="2"
ADD_FILE1="a n teste1.txt"
ADD_FILE2="a n teste2.txt"
PRINT="l"

## Script
make relibs
clear
cat <(echo $T) <(echo $ADD_FILE1) <(echo $ADD_FILE2) <(echo $PRINT) - | ./a.out
