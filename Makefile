CC=g++
CXXFLAGS=-Wall -pedantic -Wextra -std=c++14

all:mazer

mazer: svgWriter.o binaryIO.o generator.o maze.o cell.o edge.o userValidation.o mazer.o
	$(CC) generator.o maze.o cell.o edge.o mazer.o -o mazer

mazer.o:mazer.cpp
	$(CC) $(CXXFLAGS) -c mazer.cpp
userValidation.o:userValidation.cpp
	$(CC) $(CXXFLAGS) -c userValidation.cpp	
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
svgWriter.o:svgWriter.cpp
	$(CC) $(CXXFLAGS) -c svgWriter.cpp



.PHONY:clean
clean:
	rm -f *.o mazer
