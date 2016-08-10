CC=g++
CXXFLAGS=-Wall -pedantic -Wextra -std=c++14

all:mazer

mazer:mazer.o binaryIO.o generator.o maze.o cell.o edge.o 
	$(CC) mazer.o binaryIO.o generator.o maze.o cell.o edge.o -o mazer

mazer.o:mazer.cpp
	$(CC) $(CXXFLAGS) -c mazer.cpp
binaryIO.o:binaryIO.cpp
	$(CC) $(CXXFLAGS) -c binaryIO.cpp
generator.o:generator.cpp
	$(CC) $(CXXFLAGS) -c generator.cpp
maze.o:maze.cpp
	$(CC) $(CXXFLAGS) -c maze.cpp
cell.o:cell.cpp
	$(CC) $(CXXFLAGS) -c cell.cpp
edge.o:edge.cpp
	$(CC) $(CXXFLAGS) -c edge.cpp

.PHONY:clean
clean:
	rm -f binaryIO.o mazer.o mazer
