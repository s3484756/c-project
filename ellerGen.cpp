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
	std::uniform_int_distribution<unsigned> distWidth(0,1);
	int randBool;
	bool cont = true;
	for(unsigned int i = 0; i < map.size();++i){
		vector<int> setList;
		for(unsigned int j = 0; j < map.at(i).size();++j){
			if(map.at(i).at(j) == 0){
				map.at(i).at(j) = (10*i)+j+1;
				printf("%d\n",(10*i)+j+1);
				setList.push_back((10*i)+j+1);
			}
			randBool = distWidth(gen);
			if(randBool == 0 && j < map.at(i).size()-1){
				joinSet(map.at(i).at(j+1),map.at(i).at(j));
			}
			randBool = distWidth(gen);
			if(randBool == 0 && i < map.size()-1){
				joinSet(map.at(i+1).at(j),map.at(i).at(j));
			}
		}
		if(i < map.size()-1)
			for(unsigned int z = 0; z < setList.size();++z){
				cont = true;
				for(unsigned int j = 0; j < map.at(i).size();++j){
					if(setList.at(z) == map.at(i).at(j)){
						if(!hasVertical(i,map.at(i).at(j))){
							i--;
							break;
						}
					}
				}
			}
			
					
	}
	
	printf("done\n");
	printf("%d\n",map.size());
	for(unsigned int i = 0; i< map.size();++i){
		for(unsigned int j = 0; j < map.at(i).size();++j){
			printf(" %d ",map.at(i).at(j));
		}
		printf("\n");
	}
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
		if(map.at(row).at(i) == set 
			&& map.at(row).at(i) == map.at(row+1).at(i))
			return true;
	}
	return false;
}


