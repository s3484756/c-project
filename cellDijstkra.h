#include "cell.h"

class CellDijistkra{
	unsigned int weight;
	Cell * original;
	public:CellDijistkra(Cell cell);
		int getWeight();
		void setWeight(int newWeight);
		Cell * getOriginal();
		friend bool operator>(const CellDijistkra& a, const CellDijistkra& b);
		
};


