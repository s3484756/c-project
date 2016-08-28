/***********************************************************************
 * Author           : Luke Ellison
 * Student Number   : s3484756
 ***********************************************************************/
#include "maze.h"

Maze::Maze (unsigned int setWidth, unsigned int setHeight){
	height = setHeight;
	width = setWidth;
	//fills Maze with cells 
	std::cout << "creating cells" << std::endl;
	for(unsigned int i = 0; i < height;i++){
		vector<Cell> row;
		for(unsigned int j = 0; j < width;j++){
			Cell newCell(i,j);
			if(i < width - 1){
				Edge newEdge(i,j,i+1,j);
				newCell.addEdge(newEdge);
			}
			if(i > 0){
				Edge newEdge(i,j,i-1,j);
				newCell.addEdge(newEdge);
			}
			if(j < height - 1){
				Edge newEdge(i,j,i,j+1);
				newCell.addEdge(newEdge);
			}
			if(j > 0){
				Edge newEdge(i,j,i,j-1);
				newCell.addEdge(newEdge);
			}
			row.push_back(newCell);
		}
		cells.push_back(row);
	}
	// create list of neighbour cells for each cell
	std::cout << "doing neighbours" << std::endl;
	for(unsigned int i = 0; i < cells.size();i++){
		for(unsigned int j = 0; j < cells.at(i).size();j++){
			std::cout << j << std::endl; 
			if(i < cells.size() - 1){
				cells.at(i).at(j).addNeighbour(&cells.at(i+1).at(j));
			}
			if(i > 0){
				cells.at(i).at(j).addNeighbour(&cells.at(i-1).at(j));
			}
			if(j < cells.at(i).size() - 1){
				cells.at(i).at(j).addNeighbour(&cells.at(i).at(j+1));
			}
			if(j > 0){
				cells.at(i).at(j).addNeighbour(&cells.at(i).at(j-1));
			}
		}
	}
	std::cout << "finished maze initialisation" << std::endl; 
}



unsigned int Maze::getHeight(){
	return height;
}

unsigned int Maze::getWidth(){
	return width;
}

Cell Maze::getCell(unsigned int x,unsigned int y){
	return cells.at(x).at(y);
}

void Maze::setVisited(unsigned int x,unsigned int y){
	cells.at(x).at(y).setVisited();
}