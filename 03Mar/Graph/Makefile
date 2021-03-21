CC = gcc
CTARGET = pathfinder
DTARGET = debug
CFLAGS = -Wall -Werror -pedantic -o # Flags for regular compilation
DFLAGS = -g -Wall -DDEBUG -o # Flags for debugging
SOURCE = ./src/functions.c ./src/test.c
HEADER = ./src/header.h

compile: $(SOURCE) $(HEADER)
	$(CC) $(SOURCE) $(CFLAGS) $(CTARGET)

debug: $(SOURCE) $(HEADER)
	$(CC) $(SOURCE) $(DFLAGS) $(DTARGET)
	-gdb $(DTARGET)
	#del debug.exe 	# Windows
	#rm -f $(DTARGET) 	# Linux

clean:
	#-del *.exe 		# Windows
	rm -f $(DTARGET) 	# Linux
	rm -f $(CTARGET) 	# Linux