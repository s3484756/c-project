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
#include <time.h>

class Generator{
	protected : Maze genMaze;
	protected : int seed;
	protected : vector<Edge> paths;
	protected : unsigned int visited; 	
	public:Generator(unsigned int height,unsigned int width, int seed);
	public:Generator(unsigned int height, unsigned int width);
	    virtual bool generate();
		Maze getMaze();
		vector<Edge> getPaths();
		int getSeed();
		virtual ~Generator();
		
};

#endif
