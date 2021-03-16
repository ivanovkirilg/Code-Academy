COMP = gcc
FLAGS = -Wall -Werror -shared -fPIC
SOURCES = kilib.c kilist.c
TARGET = libkilib.so.0

all: $(SOURCES)
	$(COMP) $(FLAGS) $(SOURCES) -o $(TARGET)

clean:
	del $(TARGET)
