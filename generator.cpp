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
Generator::Generator(unsigned int width, unsigned int height) : genMaze(width,height){
	srand(time(NULL));
	seed = rand();
	visited = 1;
}

bool Generator::generate(){
	return true;
}

Maze Generator::getMaze(){
	return genMaze;
}

vector<Edge> Generator::getPaths(){
	return paths;
}

int Generator::getSeed(){
	return seed;
}

Generator::~Generator(){
	return;
}

