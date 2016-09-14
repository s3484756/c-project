/***********************************************************************
 * Author           : Luke Ellison | Joshua Theeuf
 * Student Number   : s3484756 | s3234575
 ***********************************************************************/
#include "maze.h"
#ifndef MAZE_GENERATOR
#define MAZE_GENERATOR
#include <random>
#include <chrono>
#include <cstdlib>
#include <time.h>

class Generator{
	Maze genMaze;
	int seed;
	unsigned int visited;
	vector<Edge> paths; 
	public:Generator(unsigned int height,unsigned int width, int seed);
	public:Generator(unsigned int height, unsigned int width);
	    bool generate();
		Maze getMaze();
		vector<Edge> getPaths();
		int getSeed();
		
};

#endif
