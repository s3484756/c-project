/***********************************************************************
 * Author           : Luke Ellison
 * Student Number   : s3484756
 ***********************************************************************/
#include <vector>
#ifndef MAZE
#define MAZE
using namespace std;
struct edge{
	unsigned int x1;
	unsigned int y1;
	unsigned int x2;
	unsigned int y2;
	public:edge(unsigned int, unsigned int, unsigned int, unsigned int);
};

struct cell{
	bool visited = false;
	unsigned int x;
	unsigned int y;
	vector<struct edge> edges;
	vector<struct cell> neighbours;
};

class Maze{
	unsigned int height;
	unsigned int width;
	vector<vector<struct cell>> cells;
	public:Maze (unsigned int,unsigned int);
		unsigned int getHeight();
		unsigned int getWidth();
		struct cell getCell(unsigned int,unsigned int);
		
	
};

#endif