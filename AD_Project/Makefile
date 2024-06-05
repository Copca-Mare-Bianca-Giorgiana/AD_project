build:
	gcc -g -o lobster_calculator src/*.c src/*.h -std=c99 -Wall -Wextra -Wunused
run:
	./lobster_calculator $(target)
debug:
	valgrind ./lobster_calculator $(target)
clean:
	rm lobster_calculator
