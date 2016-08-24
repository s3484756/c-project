#include "cell.h"

Cell::Cell (unsigned int xcoord, unsigned int ycoord){
	x = xcoord;
	y = ycoord;
}

bool Cell::getVisited(){
	return visited;
}

void Cell::addEdge(Edge newEdge){
	edges.push_back(newEdge);
}

void Cell::addNeighbour(Cell * newNeighbour){
	neighbours.push_back(newNeighbour);
}

unsigned int Cell::getX(){
	return x;
}

unsigned int Cell::getY(){
	return y;
}

vector<Edge> Cell::getEdges(){
	return edges;
}

vector<Cell *> Cell::getNeighbours(){
	return neighbours;
}

void Cell::setVisited(){
	visited = true;
}