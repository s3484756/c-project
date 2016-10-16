#include "DFS_Solver.h"

DFSSolver::DFSSolver(Maze * genMaze, vector<Edge> route) : Solver(genMaze, route){
	solved = false;
	for(unsigned int i = 0; i < getMaze()->getWidth(); ++i){
		vector<bool> tempVec;
		for(unsigned int j = 0; j < getMaze()->getHeight();++j){
			tempVec.push_back(false);
		}
		map.push_back(tempVec);
	}
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
		if(pathExists(getMaze()->getCell(xcoord,ycoord),*getMaze()->getCell(xcoord,ycoord).getNeighbours().at(i))
			&& map.at(getMaze()->getCell(xcoord,ycoord).getNeighbours().at(i)->getX()).at(
			getMaze()->getCell(xcoord,ycoord).getNeighbours().at(i)->getY()) == false)
		{
			
			visitCell(getMaze()->getCell(xcoord,ycoord).getNeighbours().at(i)->getX(), 
			getMaze()->getCell(xcoord,ycoord).getNeighbours().at(i)->getY());
		}
	}	
}




