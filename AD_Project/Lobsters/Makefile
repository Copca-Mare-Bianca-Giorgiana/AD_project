CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: lobster_knapsack

lobster_knapsack: main.o lobster.o
	$(CC) $(CFLAGS) -o lobster_knapsack main.o lobster.o

main.o: main.c lobster.h
	$(CC) $(CFLAGS) -c main.c

lobster.o: lobster.c lobster.h
	$(CC) $(CFLAGS) -c lobster.c

clean:
	rm -f lobster_knapsack *.o
