CC = g++
CFLAGS = -Wall -O2
LIBPQ = -lpq

all: testpq

testpq:
	$(CC) testpq.cpp $(CFLAGS) $(LIBPQ) -o testpq

clean:
	rm -f *.o *.a testpq
