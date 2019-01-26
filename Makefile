###################################
# Makefile for FILE IO Application 
###################################

CFLAGS= -Wall -c -I./inc

SRC  := ./src
OBJS := $(patsubst ./src/%.c, ./res/%.o, $(shell find . -name "*.c"))

PROG := ./bin/util

all: $(PROG)

./src/main.o: ./src/main.c
	$(CC) $(CFLAGS) -o $@ $^

./bin/util: ./src/main.o
	mkdir -p ./bin
	$(CC) -o $@ $^

clean: 
	rm -rf ./bin/*
	rm -f  ./src/*.o
