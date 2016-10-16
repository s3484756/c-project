#include "Solver.cpp"

class DFSSolver : public Solver{
	bool solved;
	vector<vector<bool>> map;
	public:DFSSolver(Maze * maze, vector<Edge> paths);
	bool solve();
	void visitCell(unsigned int xcoord, unsigned int ycoord);
};