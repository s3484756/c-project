/***********************************************************************
 * Author           : Luke Ellison - Joshua Theeuf
 * Student Number   : s3484756 -  s3234575
 ***********************************************************************/

#include "cell.h"
#include <iostream>
#ifndef MAZE
#define MAZE

class Maze{
	unsigned int height;
	unsigned int width;
	vector<vector<Cell>> cells;
	public:Maze (unsigned int,unsigned int);
		unsigned int getHeight();
		unsigned int getWidth();
		Cell getCell(unsigned int,unsigned int);
		void setVisited(unsigned int,unsigned int);
		
	
};

#endif