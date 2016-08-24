/***********************************************************************
 * Author           : Luke Ellison
 * Student Number   : s3484756
 ***********************************************************************/
#include "generator.h"

Generator::Generator (unsigned int width, unsigned int height,int randGen)
: genMaze(width,height){
	seed = randGen;
	visited = 1;
	
}

bool Generator::generate(){
	unsigned int holdX;
	unsigned int holdY;
	unsigned int nextCellIndex;
	// select starting cell
	std::mt19937 gen(seed);
	std::uniform_int_distribution<unsigned> distWidth(0,genMaze.getWidth()-1);
	holdX = distWidth(gen);
	std::uniform_int_distribution<unsigned> distHeight(0,genMaze.getHeight()-1);
	holdY =  distHeight(gen);
	while(visited != genMaze.getHeight()*genMaze.getWidth()){
		genMaze.setVisited(holdX,holdY);
		std::uniform_int_distribution<unsigned> distN(0,genMaze.getCell(holdX,holdY).getNeighbours().size()-1);
		nextCellIndex =  distN(gen);
		if(genMaze.getCell(holdX,holdY).getNeighbours().at(nextCellIndex).getVisited() != true){
			std::cout << visited << std::endl;
			paths.push_back(genMaze.getCell(holdX,holdY).getEdges().at(nextCellIndex));
			visited++;
		}
		holdX = genMaze.getCell(holdX,holdY).getNeighbours().at(nextCellIndex).getX();
		holdY = genMaze.getCell(holdX,holdY).getNeighbours().at(nextCellIndex).getY();
	}
	
	
	return true;
}

Maze Generator::getMaze(){
	return genMaze;
}

vector<Edge> Generator::getPaths(){
	return paths;
}



