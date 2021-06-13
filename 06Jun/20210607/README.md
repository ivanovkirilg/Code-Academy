# Bash Testing Script
_by Kiril Ivanov and Nikolay Georgiev_

## Running instructions:
1. Set your C compiler path in `compile.sh` (default is 'gcc')
2. Run `test.sh` (manually running `compile.sh` should not be necessary)
<br>

## What it does:
1. All .c files in `/src/` are compiled to corresponding binaries in `/bin/`. <br>
2. Each binary is run with input from `/tests/`. <br>
3. The output and exit status are compared against expected values from `/tests/`. <br>
4. Any failed tests generate logs of the discrepancies. <br>

**Test files must** contain valid bash code defining the arrays `INPUT`, `OUTPUT` and `EXIT`.
<br> <br>

## Tested C Programs
### Task 11:

Разбийте число като сума от степени на двойката. <br>
Break up a number into powers of two.
- _Implemented in_ `powers.c` <br>

### Task 17:

Направете генератор на случайни числа последния алгоритъм (xorshift):
Make a random number generator using the following algorithm (xorshift):
1. `A ^= A << 13;`
2. `A ^= A >> 17;`
3. `A ^= A << 5;` <br>
- _Implemented in_ `rng.c` <br>

