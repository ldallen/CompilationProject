LEX=lex
YACC=bison
CFLAGS=-Wall -std=c++11
CC=g++

all: parser

parser:parser.c scanner.c
	$(CC) $(CFLAGS) -o $@ $^

parser.c:parser.y
	$(YACC) -o $@ --defines=parser.tab.h $^

%.c:%.l
	$(LEX) -o $@ $^
tests:
	for i in `ls ../tests/*.c`; do echo $$i; ./parser $$i; done

clean:
	rm -f parser.c parser.tab.h parser.tab.c scanner.c
