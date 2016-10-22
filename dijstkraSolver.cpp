#include "dijstkraSolver.h"

dijstkraSolver::dijstkraSolver(Maze &genMaze, vector<Edge> route) : Solver(genMaze, route){
	solved = false;
	//builds a weight map for the cells
	for(unsigned int i = 0; i < getMaze()->getWidth(); ++i){
		vector<int> tempVec;
		//default distance value for unvisited cell set to -1
		for(unsigned int j = 0; j < getMaze()->getHeight();++j){
			tempVec.push_back(-1);
		}
		map.push_back(tempVec);
	}
	return;
}
//uses manhatten distance only (currently)
bool dijstkraSolver::solve(){
	Heap<CellDijistkra> queue;
	CellDijistkra currCell(getMaze()->getCell(4,4));
	printf("%d\n",currCell.getOriginal()->getNeighbours().size());
	for(int i =1; i < currCell.getOriginal()->getNeighbours().size();++i){
		printf("cell coord %d,%d\n",currCell.getOriginal()->getNeighbours().at(i)->getX(),
		currCell.getOriginal()->getNeighbours().at(i)->getY());
	}
		
	printf("cell coord %d,%d\n",getMaze()->getCell(1,1).getNeighbours().at(1)->getX(),
		getMaze()->getCell(1,1).getNeighbours().at(1)->getY());
	currCell.setWeight(getMaze()->getHeight()+getMaze()->getWidth()-2);
	map.at(0).at(0) = currCell.getWeight();
	while(queue.size() >= 0){
		printf("while loop\n");
		if(currCell.getOriginal()->getX() == getMaze()->getWidth()-1 
			&& currCell.getOriginal()->getY() == getMaze()->getHeight()-1){
				break;
		}
		// checks current cell and for each neighbour with a path adds it to the queue
		// the weight of the neighbour being set beforehand 
		printf("be for\n");
		
		for(unsigned int i = 0; i < currCell.getOriginal()->getNeighbours().size();++i){
			printf("inner llop\n");
			if(pathExists(*currCell.getOriginal(),*currCell.getOriginal()->getNeighbours().at(i))){ 
				printf("herererer\n");
				if(map.at(currCell.getOriginal()->getNeighbours().at(i)
					->getX()).at(currCell.getOriginal()->getNeighbours().at(i)->getY()) == -1){
						printf("here\n");
						CellDijistkra neighCell(*currCell.getOriginal()->getNeighbours().at(i));
						printf("nohere\n");
						neighCell.setWeight((getMaze()->getWidth()-currCell.getOriginal()->getX()-1)+(
							getMaze()->getHeight()-currCell.getOriginal()->getY()-1));
						map.at(neighCell.getOriginal()->getX()).at(neighCell.getOriginal()->getY()) 
							= currCell.getWeight()+1;
						queue.add(neighCell);
				}
			}
		}
		// cennot reach end cell, maze isunsolveable
		if(queue.size() == 1)
			return false;
		currCell = queue.popQueue();
	}
	printf("found last cell\n");
	Cell currentCell(getMaze()->getCell(getMaze()->getWidth()-1,getMaze()->getHeight()-1));
	//steps back from the end of the maze by going through cells 
	//with one less weight until the start cell is reached
	while(currentCell.getX() != 0 && currentCell.getY() != 0){
		printf("cell coord %d,%d\n",currentCell.getX(),currentCell.getY());
		for(unsigned int i = 0; i < currentCell.getNeighbours().size();++i){
			//checks if there is a path between the two neighbouring cells and if the neighbouring
			//cells weight is one more than the current
			if(pathExists(currentCell, *currentCell.getNeighbours().at(i)) 
				&& map.at(currentCell.getNeighbours().at(i)->getX())
					.at(currentCell.getNeighbours().at(i)->getY()) 
						== map.at(currentCell.getX()).at(currentCell.getY())+1){
				route.push_back(currentCell.getEdges().at(i));
				currentCell = *currentCell.getNeighbours().at(i);
				break;
			}
		}
		
		
	}
	return true;
	
}