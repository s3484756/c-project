#include "Solver.cpp"

class DFSSolver : public Solver{
	bool solved;
	public:DFSSolver(Maze * maze, vector<Edge> paths);
	bool solve();
	void visitCell(unsigned int xcoord, unsigned int ycoord);
};