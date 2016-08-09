/***********************************************************************
 * Author           : Luke Ellison
 * Student Number   : s3484756
 ***********************************************************************/
#include "maze.h"
#ifndef MAZE_GENERATOR
#define MAZE_GENERATOR
class Generator{
	Maze genMaze;
	int seed;
	vector<struct edge> paths; 
	public:Generator(unsigned int,unsigned int, unsigned int);
	
		bool generate();
		Maze getMaze();
		vector<struct edge> getPaths();
		
};

#endif