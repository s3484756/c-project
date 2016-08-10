
#include <vector>
#include "edge.h"
#ifndef CELL
#define CELL
using namespace std;


class Cell{
	bool visited = false;
	unsigned int x;
	unsigned int y;
	vector<Edge> edges;
	vector<Cell> neighbours;
	public:Cell(unsigned int, unsigned int);
		bool getVisited();
		void addEdge(Edge);
		void addNeighbour(Cell);
		unsigned int getX();
		unsigned int getY();
		vector<Edge> getEdges();
		vector<Cell> getNeighbours();
		void setVisited();
		
};

#endif

