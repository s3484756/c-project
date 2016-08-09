/***********************************************************************
 * Author           : Luke Ellison
 * Student Number   : s3484756
 ***********************************************************************/
#include "generator.h"

Generator::Generator (unsigned int width, unsigned int height,unsigned int randGen)
: genMaze(width,height){
	seed = randGen;
	
}

bool Generator::generate(){
	return true;
}

Maze Generator::getMaze(){
	return genMaze;
}

vector<struct edge> Generator::getPaths(){
	return paths;
}

