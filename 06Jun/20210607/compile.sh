#!/bin/bash

CC=gcc

for SRC_FILE in `ls src | grep .c`
do
    $CC src/$SRC_FILE -o bin/${SRC_FILE%.c}
done