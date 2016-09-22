#include "AldousBroderGen.h"

AldousBroderGen::AldousBroderGen (unsigned int width, unsigned int height,int randGen) 
: Generator(width,height,randGen) {
	seed = randGen;
	visited = 1;
	
}
AldousBroderGen::AldousBroderGen(unsigned int width, unsigned int height) 
: Generator(width,height){
	srand(time(NULL));
	seed = rand();
	visited = 1;
}

bool AldousBroderGen::generate(){
	unsigned int holdX;
	unsigned int holdY;
	unsigned int nextCellIndex;
	// select starting cell
	std::mt19937 gen(getSeed()*100);
	std::uniform_int_distribution<unsigned> distWidth(0,getMaze().getWidth()-1);
	holdY = distWidth(gen);
	std::uniform_int_distribution<unsigned> distHeight(0,getMaze().getHeight()-1);
	holdX =  distHeight(gen);
	//randomly select neighbour of current cell and set as current, if neighbour
	//is unvisited add edge between them. Continue until every cell is visited at least once
	while(visited < getMaze().getHeight()*getMaze().getWidth()){
		genMaze.setVisited(holdX,holdY);
		std::uniform_int_distribution<unsigned> distN(0,getMaze().getCell(holdX,holdY).getNeighbours().size()-1);
		nextCellIndex =  distN(gen);
		if(getMaze().getCell(holdX,holdY).getNeighbours().at(nextCellIndex)->getVisited() != true){
			std::cout <<"Number of cells visited: " << visited << std::endl;
			paths.push_back(getMaze().getCell(holdX,holdY).getEdges().at(nextCellIndex));
			visited++;
		}
		holdX = getMaze().getCell(holdX,holdY).getNeighbours().at(nextCellIndex)->getX();
		holdY = getMaze().getCell(holdX,holdY).getNeighbours().at(nextCellIndex)->getY();
	}
	return true;
}

