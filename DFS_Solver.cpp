#include "DFS_Solver.h"

DFSSolver::DFSSolver(Maze * genMaze, vector<Edge> route) : Solver(genMaze, route){
	solved = false;
	return;
}

bool DFSSolver::solve(){
	visitCell(0,0);
	return solved;
}

void DFSSolver::visitCell(unsigned int xcoord, unsigned int ycoord){
	for(int i = 0; i < maze.getCell(xcoord,ycoord).getNeighbours().size(); ++i){
		if(xcoord == maze.getWidth()-1 && ycoord == maze.getHeight()-1){
			solved = true;
			return;
		}
		if(solved == true){
			route.push_back(maze.getCell.getEdges().at(i));
			return;
		}
		visitCell(maze.getCell.getNeighbours().at(i).getX(), maze.getCell.getNeighbours().at(i).getY());
	}
}


