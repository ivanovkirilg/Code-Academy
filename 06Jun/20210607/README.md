# Bash Testing Script
### For bitwise operators Task 11
_by Kiril Ivanov and Nikolay Georgiev_

## Running instructions:
1. Set your C compiler path in `compile.sh` (default is 'gcc')
2. Run `test.sh` (manually running `compile.sh` should not be necessary)
<br>

## What it does:
1. All .c files in `/src/` are compiled to corresponding binaries in `/bin/`. <br>
2. Each binary is run using commands (including input) from `/tests/`. <br>
3. The output is compared against expected values also stored in `/tests/`. <br>
4. Any failed tests leave behind the received output for manual analisys. <br>

#### Test files must follow the pattern:
`test.BINARY_NAME.in.txt` has one command on each line 
which runs BINARY from /bin/ with args. <br>
`test.BINARY_NAME.out.txt` has expected output for each command. <br>
<br>

### Task 11:

Разбийте число като сума от степени на двойката. <br>
Break up a number into powers of two.
- _Implemented in_ `powers.c` <br>
