#include "Solver.h"

Solver::Solver(Maze &genMaze, vector<Edge> route){
	maze = &genMaze;
	paths = route;
}

bool Solver::pathExists(Cell current, Cell neighbour){
	unsigned int i;
	for(i = 0; i < paths.size(); ++i){
		if((paths.at(i).getX1() == current.getX() && paths.at(i).getY1() == current.getY()
		&& paths.at(i).getX2() == neighbour.getX() && paths.at(i).getY2() == neighbour.getY())
		|| paths.at(i).getX1() == neighbour.getX() && paths.at(i).getY1() == neighbour.getY()
		&& paths.at(i).getX2() == current.getX() && paths.at(i).getY2() == current.getY())
				return true;
	}
	return false;
}
bool Solver::solve(){
	return true;
}

vector<Edge> Solver::getPaths(){
	return route;
}

Maze * Solver::getMaze(){
	return maze;
}