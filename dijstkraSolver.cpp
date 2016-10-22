#include "dijstkraSolver.h"

dijstkraSolver::dijstkraSolver(Maze &genMaze, vector<Edge> route) : Solver(genMaze, route){
	solved = false;
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
	CellDijistkra newCell(getMaze()->getCell(0,0));
	newCell.setWeight(getMaze()->getHeight()+getMaze()->getWidth()-2);
	map.at(newCell.getOriginal()->getX()).at(newCell.getOriginal()->getY()) = newCell.getWeight();
	queue.add(newCell);
	CellDijistkra currCell = queue.popQueue();
	while(queue.size() >= 0){
		if(currCell.getOriginal()->getX() == getMaze()->getWidth()-1 
			&& currCell.getOriginal()->getY() == getMaze()->getHeight()-1){
				break;
		}
		// checks current cell and for each neighbour with a path adds it to the queue
		// the weight of the neighbour being set beforehand 
		for(unsigned int i = 0; i < currCell.getOriginal()->getNeighbours().size();++i){
			if(pathExists(*currCell.getOriginal(),*currCell.getOriginal()->getNeighbours().at(i)) && 
				map.at(currCell.getOriginal()->getNeighbours().at(i)->getX())
					.at(currCell.getOriginal()->getNeighbours().at(i)->getY()) == -1){
					
					CellDijistkra neighCell(*currCell.getOriginal()->getNeighbours().at(i));
					
					neighCell.setWeight((getMaze()->getWidth()-currCell.getOriginal()->getX()-1)+(
						getMaze()->getHeight()-currCell.getOriginal()->getY()-1));
					map.at(neighCell.getOriginal()->getX()).at(neighCell.getOriginal()->getY()) 
						= currCell.getWeight()+1;
					queue.add(neighCell);
			}
		}
		if(queue.size() == 0)
			return false;
		currCell = queue.popQueue();
	}
	Cell currentCell(getMaze()->getCell(getMaze()->getWidth()-1,getMaze()->getHeight()-1));
	while(currentCell.getX() != 0 && currentCell.getY() != 0){
		for(unsigned int i = 0; i < currentCell.getNeighbours().size();++i){
			//checks if there is a path between the two neighbouring cells and if the neighbouring
			//cells step-size is one less than the current
			if(pathExists(currentCell, *currentCell.getNeighbours().at(i)) 
				&& map.at(currentCell.getNeighbours().at(i)->getX()).at(currentCell.getNeighbours().at(i)->getY()) 
			    == map.at(currentCell.getX()).at(currentCell.getY())+1){
				route.push_back(currentCell.getEdges().at(i));
				currentCell = *currentCell.getNeighbours().at(i);
				break;
			}
		}
		
		
	}
	return true;
	
}