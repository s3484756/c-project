#include "generator.h"

class EllerGen : public Generator{
	vector<vector<int>> map;
	public:EllerGen(unsigned int height,unsigned int width, int seed);
	public:EllerGen(unsigned int height,unsigned int width);
		bool generate();
		void joinSet(int newSet, int oldSet);
		bool hasVertical(int row, int set);
		
		
};
