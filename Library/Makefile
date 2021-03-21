CC = gcc
CFLAGS = -Wall -Werror -shared -fPIC

VER_LIB = 0
VER_LIST = 0

SRC_LIB = src/kilib.c
HDR_LIB = kilib.h
TAR_LIB = shared/libkilib.so.$(VER_LIB)
LNK_LIB = libkilib.so

SRC_LIST = src/kilist.c
HDR_LIST = kilist.h
TAR_LIST = shared/libkilist.so.$(VER_LIST)
LNK_LIST = libkilist.so

all: $(TAR_LIB) $(TAR_LIST)

$(TAR_LIB): $(SRC_LIB) $(HDR_LIB)
	$(CC) $(CFLAGS) $(SRC_LIB) -o $(TAR_LIB)
	ln -sf $(TAR_LIB) $(LNK_LIB)

$(TAR_LIST): $(SRC_LIST) $(HDR_LIST)
	$(CC) $(CFLAGS) $(SRC_LIST) -o $(TAR_LIST)
	ln -sf $(TAR_LIST) $(LNK_LIST)

cleanold:
	rm -f shared/$(LNK_LIB).[^$(VER_LIB)]

purge:
	rm -f shared/*
	rm -f $(LNK_LIB)
	rm -f $(LNK_LIST)