CC = gcc
CTARGET = pathfinder.exe
DTARGET = debug.exe
CFLAGS = -Wall -Werror -pedantic -o # Flags for regular compilation
DFLAGS = -g -Wall -DDEBUG -o # Flags for debugging
SOURCE = test.c functions.c

compile: $(SOURCE)
	$(CC) $(SOURCE) $(CFLAGS) $(CTARGET)

clean:
	del *.exe

debug: $(SOURCE)
	$(CC) $(SOURCE) $(DFLAGS) $(DTARGET)
	gdb $(DTARGET)
	del debug.exe