CC=g++
CFLAGS=-std=c++11 -Wall -pthread

all: non-determinism


non-determinism: non-determinism.o
	$(CC) $(CFLAGS) -o $@ $^
run-non-determinism: non-determinism
	./non-determinism
shared-variable: shared-variable.o
	$(CC) $(CFLAGS) -o $@ $^
run-shared-variable: shared-variable
	./shared-variable
clean:
	rm -f non-determinism shared-variable *.o

.PHONY: all clean
