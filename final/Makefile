CC = g++
CFLAGS = -Wall -std=c++14

main: main.o linkedlist.o node.o
	$(CC) $(CFLAGS) main.o linkedlist.o node.o -o main

test: testprog.o linkedlist.o node.o
	$(CC) $(CFLAGS) testprog.o linkedlist.o node.o -o test

main.o: main.cpp linkedlist.o node.o
	$(CC) $(CFLAGS) -c main.cpp

testprog.o: testprog.cpp linkedlist.o node.o
	$(CC) $(CFLAGS) -c testprog.cpp

linkedlist.o: linkedlist.cpp linkedlist.hpp
	$(CC) $(CFLAGS) -c linkedlist.cpp

node.o: node.cpp node.hpp
	$(CC) $(CFLAGS) -c node.cpp

clean: 
	rm *.o