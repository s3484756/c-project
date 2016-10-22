#include "ellerGen.h"

EllerGen::EllerGen (unsigned int width, unsigned int height,int randGen) 
: Generator(width,height,randGen) {
	seed = randGen;
	visited = 1;
	for(unsigned int i = 0; i < width; ++i){
		printf("%d\n",map.size());
		vector<int> tempVec;
		for(unsigned int j = 0; j < height; ++j)
			tempVec.push_back(0);
		map.push_back(tempVec);
	}
	
}
EllerGen::EllerGen(unsigned int width, unsigned int height) 
: Generator(width,height){
	srand(time(NULL));
	seed = rand();
	visited = 1;
	for(unsigned int i = 0; i < width; ++i){
		vector<int> tempVec;
		for(unsigned int j = 0;j < height; ++j)
			tempVec.push_back(0);
		map.push_back(tempVec);
	}

}

bool EllerGen::generate(){
	std::mt19937 gen(getSeed()*100);
	std::uniform_int_distribution<unsigned> dist(0,1);
	int randBool;
	bool vertical = true;
	for(int i = 0; i < map.size();++i){
		vector<int> setList;
		for(int j = 0; j < map.at(i).size();++j){
			if(map.at(i).at(j) == 0){
				map.at(i).at(j) = (i*map.size())+j+1;
			}
			if(j == map.at(i).size()-1)
				setList.push_back(map.at(i).at(j));
			randBool = dist(gen);
			if(j < map.at(0).size()-1 && randBool == 0
				 && map.at(i).at(j+1) != map.at(i).at(j)){
				
				if(map.at(i).at(j+1) == 0){
					map.at(i).at(j+1) = map.at(i).at(j);
					Edge newEdge(i,j,i,j+1);
					paths.push_back(newEdge);
				}	
				else{
					joinSet(map.at(i).at(j), map.at(i).at(j+1));
					Edge newEdge(i,j,i,j+1);
					paths.push_back(newEdge);
				}
				
				
			}
			
		}
		//updates vector with list of sets in the row
		
		for(int j = 0; j < map.at(i).size();++j){
			for(unsigned int z = 0; z < setList.size();++z){
				if(setList.at(z) == map.at(i).at(j))
					break;
				if(z == setList.size()-1){
					setList.push_back(map.at(i).at(j));
				}
			}
		}
		//randomly joins cell from current row to the next row
		//also checks that each set has at least one cell below it
		if(i < map.size()- 1)
			do{
				vertical = true;
				for(int j = 0; j < map.at(i).size();++j){
					randBool = dist(gen);
					if(randBool == 0){
						if(j > 0 && map.at(i+1).at(j-1) == map.at(i).at(j)
							&& map.at(i).at(j-1) == map.at(i).at(j))
							continue;
						if(map.at(i+1).at(j) == map.at(i).at(j))
							continue;
						if(map.at(i+1).at(j) == 0){
							map.at(i+1).at(j) = map.at(i).at(j);
							Edge newEdge(i+1,j,i,j);
							paths.push_back(newEdge);
						}
						else{
							joinSet(map.at(i).at(j), map.at(i+1).at(j));
							Edge newEdge(i+1,j,i,j);
							paths.push_back(newEdge);
						}
						
					}
				}
				for(int j = 0; j < setList.size();++j){
					if(!hasVertical(i,setList.at(j))){
						vertical = false;
						break;
					}
				}
			}while(!vertical);
		//cleans up the last row to insure that each of the cells are properly connected	
		if(i == map.size()-1){
			for(unsigned int j = 0; j < map.at(i-1).size()-1;++j){
				if(map.at(i).at(j+1) != map.at(i).at(j)){
					printf("joinging\n");
					joinSet(map.at(i).at(j), map.at(i).at(j+1));
					Edge newEdge(i,j,i,j+1);
					paths.push_back(newEdge);
				}
					
			}
				
		}
		
	}
	/*
	for(int i = 0; i < map.size();++i){
		for(int j = 0; j < map.at(i).size();++j){
			printf(" %d ",map.at(i).at(j));
		}
		printf("\n");
	}
	*/
	return true;

}

void EllerGen::joinSet(int newSet, int oldSet){
		
	for(unsigned int i = 0; i < map.size(); ++i){
		for(unsigned int j = 0;j <  map.at(i).size(); ++j){
			if(map.at(i).at(j) == oldSet)
				map.at(i).at(j) = newSet;
		}
	}
}

bool EllerGen::hasVertical(int row, int set){
	for(int i = 0; i < map.at(row).size();++i){
		if(map.at(row).at(i) == set && map.at(row).at(i) == map.at(row+1).at(i))
			return true;
	}
	return false;
}


