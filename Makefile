# Build PgUtils.
CC = g++
CFLAGS = -Wall -O2 -I"./inc/"
LIBPQ = -lpq

all: deploy

deploy: testpq
	cp scripts/test.sh . && chmod +x ./test.sh

testpq: pgclient.o
	$(CC) testpq.cpp pgclient.o $(CFLAGS) $(LIBPQ) -o testpq

pgclient.o:
	$(CC) -c inc/pgclient.cpp $(CFLAGS) -o pgclient.o

clean:
	rm -f *.o *.a *.sh testpq
