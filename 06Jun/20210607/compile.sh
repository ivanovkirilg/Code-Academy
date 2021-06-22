#!/bin/bash

CC=gcc

if [ ! -e bin ]
then
    mkdir bin
fi

for SRC_FILE in `ls src | grep .c`
do
    $CC src/$SRC_FILE -o bin/${SRC_FILE%.c} -lm
done