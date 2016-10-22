#include "Solver.h"

#include "cellDijstkra.h"
#include "heap.cpp"
class dijstkraSolver : public Solver{
	bool solved;
	vector<vector<int>> map;
	public:dijstkraSolver(Maze &maze, vector<Edge> paths);
	bool solve();
};