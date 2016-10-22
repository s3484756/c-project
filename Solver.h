#ifndef SolveMaze
#define SolveMaze
#endif
#include "maze.h"
class Solver {
	Maze * maze;
	vector<Edge> paths;
	protected : vector<Edge> route;
	public:Solver(Maze &maze, vector<Edge> paths);
		virtual bool solve();
		Maze * getMaze();
		bool pathExists(Cell current, Cell neighbour); 
		vector<Edge> getPaths();
};
