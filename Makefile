# App info
APPNAME = example

# Compiler and options
CC = gcc
CFLAGS += -Wall -O2

# Libraries to link
LIBS = 

# Files
SOURCES = example.c
DOCS = ChangeLog COPYING README

# Targets
# Build
$(APPNAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) $(LIBS) -o $(APPNAME)

# Clean for dist
clean:
	rm -rf $(APPNAME) 

