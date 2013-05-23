.PHONY : run

run :
	rm -f unhappy
	./check
	test \! -f unhappy && ./run
