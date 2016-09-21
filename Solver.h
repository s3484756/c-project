#include "maze.h"

class Solver {
	Maze * maze;
	vector<Edge> paths;
	vector<Edge> route;
	public:Solver(Maze * maze, vector<Edge> paths);
		virtual bool solve();
		bool pathExists(Cell current, Cell neighbour); 
};