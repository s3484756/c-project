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
	// continues until final cell (width-1,height-1) is reached
	while(currentCell.getX() != getMaze()->getWidth()-1 
		&& currentCell.getY() != getMaze()->getHeight()-1){
		
		for(unsigned int i = 0; i < currentCell.getNeighbours().size();++i){
			//checks if there is a path between the two neighbouring cells and if the neighbouring
			//cell has been visited yet, if path exists and cell has not been visited adds the neighbouring cell
			// to the queue
			if(pathExists(currentCell, *currentCell.getNeighbours().at(i)) 
				&& map.at(currentCell.getNeighbours().at(i)->getX()).at(currentCell.getNeighbours().at(i)->getY()) == 0){
				cellQueue.push_back(*currentCell.getNeighbours().at(i));
				map.at(currentCell.getX()).at(currentCell.getY()) =
				map.at(currentCell.getX()).at(currentCell.getY()) + 1;
			}
		}
		//If no more cells in the queue maze is unsolveable
		if(index == cellQueue.size()){
			return false;
		}
		currentCell = cellQueue.at(index);
		index++;
		
	}
	//builds path by stepping back through the maze
	while(currentCell.getX() != 0 && currentCell.getY() != 0){
		for(unsigned int i = 0; i < currentCell.getNeighbours().size();++i){
			//checks if there is a path between the two neighbouring cells and if the neighbouring
			//cells step-size is one less than the current
			if(pathExists(currentCell, *currentCell.getNeighbours().at(i)) 
				&& map.at(currentCell.getNeighbours().at(i)->getX()).at(currentCell.getNeighbours().at(i)->getY()) 
			    == map.at(currentCell.getX()).at(currentCell.getY())-1){
				route.push_back(currentCell.getEdges().at(i));
				currentCell = *currentCell.getNeighbours().at(i);
				break;
			}
		}
		
		
	}
	return true;
}