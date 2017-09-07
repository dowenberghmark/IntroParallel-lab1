CC=g++
CFLAGS=-std=c++11 -Wall -pthread

all: non-determinism


non-determinism: non-determinism.o
	$(CC) $(CFLAGS) -o $@ $^ 
run-non-determinism: non-determinism
	./non-determinism
clean:
	rm -f non-determinism *.o

.PHONY: all clean
