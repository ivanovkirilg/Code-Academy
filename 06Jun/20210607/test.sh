#!/bin/bash

BIN_PATH="bin"

if [[ $1 == -c ]]
then
    rm test.fail.*.txt
    exit 0
fi

./compile.sh

for BIN in `ls $BIN_PATH`
do
    bash tests/test.$BIN.in.txt > test.results.txt
    if cmp -s "tests/test.$BIN.out.txt" "test.results.txt"
    then
        echo $BIN - PASS
    else 
        echo $BIN - FAIL
        cp test.results.txt test.fail.$BIN.txt
    fi
done

rm test.results.txt