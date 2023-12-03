CC = gcc
CFLAGS = -Wall -save-temps -O2 -MMD

PROGRAM = median_filter
SRCDIR = ./src/
TESTDIR = ./tests/
BINDIR = ./bin/

SRCS = $(wildcard $(SRCDIR).*c)
OBJECTS = $(SRCDIR)

.PHONY: all

all: $(PROGRAM) test

$(PROGRAM):
