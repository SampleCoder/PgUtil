# Build PgUtils.
CC = g++
CFLAGS = -Wall -O2
LIBPQ = -lpq

all: testpq

testpq: pgclient.o
	$(CC) testpq.cpp pgclient.o $(CFLAGS) $(LIBPQ) -o testpq

pgclient.o:
	$(CC) -c pgclient.cpp $(CFLAGS) -o pgclient.o

clean:
	rm -f *.o *.a testpq
