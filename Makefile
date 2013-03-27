# App info
APPNAME = example

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
$(APPNAME): library example.c
	$(CC) $(CFLAGS) $(SOURCES) $(LIBS) -o $(APPNAME)

# Make object
library: libmackerel.c
	$(CC) $(FLAGS) -c libmackerel.c

# Clean for dist
clean:
	rm -rf $(APPNAME) *.o

