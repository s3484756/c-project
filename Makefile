CC=g++
CXXFLAGS=-Wall -pedantic -std=c++14

all:mazer

mazer:mazer.o binaryIO.o generator.o maze.o  
	$(CC) mazer.o binaryIO.o generator.o maze.o -o mazer

mazer.o:mazer.cpp
	$(CC) $(CXXFLAGS) -c mazer.cpp
binaryIO.o:binaryIO.cpp
	$(CC) $(CXXFLAGS) -c binaryIO.cpp
generator.o:generator.cpp
	$(CC) $(CXXFLAGS) -c generator.cpp
maze.o:maze.cpp
	$(CC) $(CXXFLAGS) -c maze.cpp

.PHONY:clean
clean:
	rm -f binaryIO.o mazer.o mazer
