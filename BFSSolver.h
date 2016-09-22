#include "Solver.cpp"

class BFSSolver : public Solver{
	bool solved;
	vector<vector<int>> map;
	public:BFSSolver(Maze * maze, vector<Edge> paths);
	bool solve();
	void visitCell(unsigned int xcoord, unsigned int ycoord);
};