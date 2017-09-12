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
performance: performance.o
	$(CC) $(CFLAGS) -o $@ $^
run-performance-test:performance
	./performanceTest.sh
dining: dining.o
	$(CC) $(CFLAGS) -o $@ $^
run-dining: dining
	./dining
clean:
	rm -f non-determinism shared-variable performance dining *.o

.PHONY: all clean
