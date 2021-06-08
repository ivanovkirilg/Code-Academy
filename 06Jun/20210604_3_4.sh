#!/bin/bash

# Simple calculator. Only supports integer operands.
# Implemented operations are +addition, -subtraction, *multiplication, /division
# Division yields a decimal number
# Input is NOT validated (including division by 0)

# The number of 0s is the decimal precision when dividing:
PRECISION=1000000

if [ $# != 3 ]
then
	echo "Usage: $0 [integer] [+ - * /] [integer]"
	exit 1
fi

if [ $2 != "/" ]
then
	# All NON-DIVISION operations are simple
	
	echo $(($1 $2 $3))

else
	# DIVISION

	# Get integral part
	INT_DIV=$(($1 / $3))
	
	# Find the length (num of digits) of the integral part
	INT_LEN=${#INT_DIV}
	if [ $INT_DIV == 0 ]
	then
		INT_LEN=0
	fi

	# Get integral+decimal part
	DIV=$(($1 * $PRECISION / $3))
	
	# Split the integral and decimal parts
	RES="${DIV:0:$INT_LEN}.${DIV:$INT_LEN}"

	echo $RES
fi

