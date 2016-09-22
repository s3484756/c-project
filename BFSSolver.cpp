#include "BFSSolver.h"

BFSSolver::BFSSolver(Maze * genMaze, vector<Edge> route) : Solver(genMaze, route){
	for(unsigned int i = 0; i < getMaze()->getWidth(); ++i){
		vector<int> tempVec;
		for(unsigned int j = 0; j < getMaze()->getHeight();++j){
			tempVec.push_back(0);
		}
		map.push_back(tempVec);
	}
	
	return;
}

bool BFSSolver::solve(){
	unsigned int index = 1;
	Cell currentCell = getMaze()->getCell(0,0);
	vector<Cell> cellQueue;
	cellQueue.push_back(currentCell);
	while(currentCell.getX() != getMaze()->getWidth() 
		&& currentCell.getY() != getMaze()->getHeight()){
		
		for(unsigned int i = 0; i < currentCell.getNeighbours().size();++i){
			if(pathExists(currentCell, *currentCell.getNeighbours().at(i))){
				cellQueue.push_back(*currentCell.getNeighbours().at(i));
				map.at(currentCell.getX()).at(currentCell.getY()) =
				map.at(currentCell.getX()).at(currentCell.getY()) + 1;
			}
		}
		if(index == cellQueue.size()){
			return false;
		}
		currentCell = cellQueue.at(index);
		index++;
		
	}
	//will reach the end of the maze but still need to 'build' path back to the start
	return false;
}