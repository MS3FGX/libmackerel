# App info
APPNAME = libmackerel
VERSION = 1.0

# Compiler and options
CC = gcc
CFLAGS += -Wall -O2

# Libraries to link
LIBS = 

# Files
SOURCES = example.c libmackerel.o
DOCS = ChangeLog COPYING README

# Targets
# Build
all: library example.c
	$(CC) $(CFLAGS) $(SOURCES) $(LIBS) -o example

# Make object
library: libmackerel.c
	$(CC) $(FLAGS) -c libmackerel.c

# Clean for dist
clean:
	rm -rf example *.o *.txt

# Build tarball
release: clean
	tar --exclude='.*' -C ../ -czvf /tmp/$(APPNAME)-$(VERSION).tar.gz $(APPNAME)-$(VERSION)

