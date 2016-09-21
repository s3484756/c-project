#include "Solver.cpp"

class DFSSolver : public Solver{
	public:DFSSolver(Maze * maze, vector<Edge> paths);
	bool solve();
	
};