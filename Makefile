###################################
# Makefile for FILE IO Application 
###################################

CFLAGS= -Wall -Wextra  -c -I./inc -g

SRC  := ./src
OBJS := $(patsubst ./src/%.c, ./res/%.o, $(shell find $(SRC) -name "*.c"))

PROG := ./bin/util

all: $(PROG)

./res/%.o:	$(SRC)/%.c
	mkdir -p ./res
	$(CC) $(CFLAGS) -o $@ $^

$(PROG): $(OBJS)
	mkdir -p ./bin
	$(CC) -o $@ $^

clean: 
	@echo $(OBJS)
	rm -rf ./bin
	rm -rf ./res
