#!/bin/bash

BIN_PATH="bin"
TEST_PATH="tests"

rm -f $TEST_PATH/*.FAIL.txt

./compile.sh

for BIN in `ls $BIN_PATH`
do
    if [ ! -e $TEST_PATH/$BIN.sh ]
    then
        echo $BIN "- NO test file"
        continue
    fi

    . $TEST_PATH/$BIN.sh
    
    FAILED=0

    for i in ${!INPUT[@]}
    do
        RESULT=`$BIN_PATH/$BIN ${INPUT[$i]}`
        EXITED=$?
        
        if [[ "$RESULT" != "${OUTPUT[$i]}" ]]
        then
            echo $BIN - test $(($i+1)) FAIL
            echo TEST $(($i+1)): $RESULT >>$TEST_PATH/$BIN.FAIL.txt
            echo EXPECT: ${OUTPUT[$i]} >>$TEST_PATH/$BIN.FAIL.txt
            FAILED=1
        fi

        if [[ $EXITED != ${EXIT[$i]} ]]
        then
            echo $BIN - test $(($i+1)) EXIT status mismatch
            echo EXIT TEST $(($i+1)): $EXITED >>$TEST_PATH/$BIN.FAIL.txt
            echo EXIT EXPECT: ${EXIT[$i]} >>$TEST_PATH/$BIN.FAIL.txt
            FAILED=1
        fi
    done

    if [[ $FAILED == 0 ]]
    then
        echo $BIN - PASS
    fi

done
