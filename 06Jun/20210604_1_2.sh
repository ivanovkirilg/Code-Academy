#!/bin/bash

ALL_FILENAMES=$@

if [ $# == 0 ]
then
	echo "Enter one or multiple filenames"
	read ALL_FILENAMES
fi

for FILENAME in $ALL_FILENAMES
do
	touch ~/$FILENAME
done
