
CC=g++
CFLAGS=-std=c++11
OUTPUTNAME=StoreSimulator

all: Queue Customer Clock Driver
	$(CC) $(CFLAGS) *.o -o $(OUTPUTNAME)

Queue: Queue.cpp
	$(CC) $(CFLAGS) -c Queue.cpp

Customer: Customer.cpp
	$(CC) $(CFLAGS) -c Customer.cpp

Driver: Driver.cpp
	$(CC) $(CFLAGS) -c Driver.cpp

Clock: Clock.cpp
	$(CC) $(CFLAGS) -c Clock.cpp

clean:
	rm *.o
	rm $(OUTPUTNAME)