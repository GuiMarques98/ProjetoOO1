CC := g++

CFLAG := -Wall

LNFLAG := -lncurses

SRCFILES := $(wildcard src/*.cpp)

all: $(SRCFILES:src/%.cpp=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o $(LNFLAG) -o bin/saida 

obj/%.o : src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	bin/saida
