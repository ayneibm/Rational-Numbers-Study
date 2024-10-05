# Makefile de exemplo (Manual do GNU Make)

CFLAGS = -Wall -Wextra -g -std=c99 # flags de compilacao
CC = gcc

# gera o executável
all: tp2

tp2: tp2.o racional.o
	$(CC) -o tp2 tp2.o racional.o

# compila racional.c
racional.o: racional.c racional.h
	$(CC) -c $(CFLAGS) racional.c

# compila tp2.c
tp2.o: tp2.c racional.h
	$(CC) -c $(CFLAGS) tp2.c

all_tests: test1 test2 test3

test1: all
	./tp2 < entrada1.txt

test2: all
	./tp2 < entrada2.txt

test3: all
	./tp2 < entrada3.txt

clean:
	rm -f *.o *~ tp2
