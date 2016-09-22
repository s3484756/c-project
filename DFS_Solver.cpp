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
	for(unsigned int i = 0; i < getMaze()->getCell(xcoord,ycoord).getNeighbours().size(); ++i){
		if(xcoord == getMaze()->getWidth()-1 && ycoord == getMaze()->getHeight()-1){
			solved = true;
			return;
		}
		if(solved == true){
			route.push_back(getMaze()->getCell(xcoord,ycoord).getEdges().at(i));
			return;
		}
		if(pathExists(getMaze()->getCell(xcoord,ycoord),*getMaze()->getCell(xcoord,ycoord).getNeighbours().at(i))){
			visitCell(getMaze()->getCell(xcoord,ycoord).getNeighbours().at(i)->getX(), 
			getMaze()->getCell(xcoord,ycoord).getNeighbours().at(i)->getY());
		}
	}	
}




