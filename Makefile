CC=g++
CXXFLAGS=-Wall -pedantic -Wextra -std=c++14

all:mazer

mazer: svgWriter.o binaryIO.o generator.o maze.o cell.o edge.o userValidation.o mazer.o AldousBroderGen.o Solver.o DFS_Solver.o BFSSolver.o
	$(CC) binaryIO.o userValidation.o generator.o maze.o cell.o edge.o mazer.o AldousBroderGen.o -o mazer

mazer.o:mazer.cpp
	$(CC) $(CXXFLAGS) -c mazer.cpp
userValidation.o:userValidation.cpp
	$(CC) $(CXXFLAGS) -c userValidation.cpp	
binaryIO.o:binaryIO.cpp
	$(CC) $(CXXFLAGS) -c binaryIO.cpp
generator.o:generator.cpp
	$(CC) $(CXXFLAGS) -c generator.cpp
AldousBroderGen.o:AldousBroderGen.cpp
	$(CC) $(CXXFLAGS) -c AldousBroderGen.cpp
maze.o:maze.cpp
	$(CC) $(CXXFLAGS) -c maze.cpp
cell.o:cell.cpp
	$(CC) $(CXXFLAGS) -c cell.cpp
edge.o:edge.cpp
	$(CC) $(CXXFLAGS) -c edge.cpp
Solver.o:Solver.cpp
	$(CC) $(CXXFLAGS) -c Solver.cpp
DFS_Solver.o:DFS_Solver.cpp
	$(CC) $(CXXFLAGS) -c DFS_Solver.cpp
BFSSolver.o:BFSSolver.cpp
	$(CC) $(CXXFLAGS) -c BFSSolver.cpp	
svgWriter.o:svgWriter.cpp
	$(CC) $(CXXFLAGS) -c svgWriter.cpp



.PHONY:clean
clean:
	rm -f *.o mazer
