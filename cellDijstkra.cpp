#include "cellDijstkra.h"

CellDijistkra::CellDijistkra(Cell old){
	original = &old;
}


int CellDijistkra::getWeight(){
	return weight;
}

void CellDijistkra::setWeight(int newWeight){
	weight = newWeight;
}
Cell * CellDijistkra::getOriginal(){
	return original;
}

bool operator>(const CellDijistkra& a, const CellDijistkra& b){
	if(a.weight > b.weight)
		return true;
	return false;
}