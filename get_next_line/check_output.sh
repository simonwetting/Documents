#!/bin/bash
for i in $*
do
   echo "\033[0;31mdiff for file \"$i\":\033[0;37m"
   ./a.out $i > output.txt; diff $i output.txt
done