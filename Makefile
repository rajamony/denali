.PHONY : run

all : randsleep.c
	gcc -Wall -g -o randsleep randsleep.c

run :
	rm -f unhappy
	./check
	test \! -f unhappy && ./run
