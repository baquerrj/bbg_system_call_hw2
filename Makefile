###################################
# Makefile for FILE IO Application 
###################################

CFLAGS= -Wall -Wextra -c -I./inc

SRC  := ./src
RES  := ./res
OBJS := $(patsubst ./src/%.c, $(RES)/%.o, $(shell find . -name "*.c"))
$(shell export LD_LIBRARY_PATH="../shared:%(LD_LIBRARY_PATH)")
PROG := ./bin/util

all: $(PROG)

$(PROG): $(RES)/libio.so
	mkdir -p ./bin
	$(CC) -o $@ $^ -L$(RES) -lio

$(RES)/libio.so: $(OBJS)
	$(CC) -shared -o $(RES)/libio.so $(OBJS)

$(RES)/%.o:	$(SRC)/%.c
	mkdir -p $(RES)
	$(CC) $(CFLAGS) -fPIC -o $@ $^

clean: 
	@echo $(OBJS)
	rm -rf ./bin
	rm -rf $(RES)
