INPUT=(
"0"
"1"
"2"
"5"
"13"
"28"
"512"
"2048"
"3001"
"a"
"-128"
""
"28 22 42"
)

OUTPUT=(
""
"2^0 "
"2^1 "
"2^0 2^2 "
"2^0 2^2 2^3 "
"2^2 2^3 2^4 "
"2^9 "
"2^11 "
"2^0 2^3 2^4 2^5 2^7 2^8 2^9 2^11 "
"a is not an integer.
Usage: bin/powers [positive integer]"
"-128 is negative.
Usage: bin/powers [positive integer]"
"Usage: bin/powers [positive integer]"
"Usage: bin/powers [positive integer]"
)

EXIT=(
0
0
0
0
0
0
0
0
0
2
3
1
1
)