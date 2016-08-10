/***********************************************************************
 * Author           : Luke Ellison
 * Student Number   : s3484756
 ***********************************************************************/
#include "maze.h"
#ifndef MAZE_GENERATOR
#define MAZE_GENERATOR

#include <random>
#include <chrono>
#include <cstdlib>


class Generator{
	Maze genMaze;
	int seed;
	unsigned int visited;
	vector<Edge> paths; 
	public:Generator(unsigned int,unsigned int, int);
	    bool generate();
		Maze getMaze();
		vector<Edge> getPaths();
		
};

#endif