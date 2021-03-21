OS = Linux

ifeq ($(OS), Win)
REM = del
EXECEXT = .exe
MAKE = mingw32-make.exe
else
REM = rm -f
EXECEXT = .out
MAKE = make
endif

CC = gcc
CTARGET = pathfinder$(EXECEXT)
DTARGET = debug$(EXECEXT)
CFLAGS = -Wall -Werror -pedantic -c # Flags for regular compilation
DFLAGS = -g -Wall -DDEBUG # Flags for debugging
SOURCE = ./src/functions.c ./src/main.c
HEADER = ./src/header.h
OBJECT = functions.o main.o

all: $(OBJECT)
	$(CC) $(OBJECT) -o $(CTARGET)

$(OBJECT): $(SOURCE) $(HEADER)
	$(CC) $(CFLAGS) $(SOURCE)

debug: $(SOURCE) $(HEADER)
	$(CC) $(SOURCE) $(DFLAGS) -o $(DTARGET)
	-gdb $(DTARGET)
	$(MAKE) clean

clean:
	$(REM) $(CTARGET) $(DTARGET)

purge:
	$(MAKE) clean
	$(REM) $(OBJECT)