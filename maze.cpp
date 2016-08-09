/***********************************************************************
 * Author           : Luke Ellison
 * Student Number   : s3484756
 ***********************************************************************/
#include "maze.h"
#include <iostream>


Maze::Maze (unsigned int setWidth, unsigned int setHeight){
	height = setHeight;
	width = setWidth;
	//fills Maze with cells 
	for(unsigned int i = 0; i < width;i++){
		vector<struct cell> row;
		for(unsigned int j = 0; j < height;j++){
			struct cell unit;
			unit.x = i;
			unit.y = j;
			if(i < width - 1){
				struct edge newEdge(i,j,i+1,j);
				unit.edges.push_back(newEdge);
			}
			if(i > 0){
				struct edge newEdge(i,j,i-1,j);
				unit.edges.push_back(newEdge);
			}
			if(j < height - 1){
				struct edge newEdge(i,j,i,j+1);
				unit.edges.push_back(newEdge);
			}
			if(j > 0){
				struct edge newEdge(i,j,i,j-1);
				unit.edges.push_back(newEdge);
			}
			row.push_back(unit);
		}
		cells.push_back(row);
	}
	// create list of neighbour cells for each cell
	for(unsigned int i = 0; i < cells.size();i++){
		for(unsigned int j = 0; j < cells.at(i).size();j++){
			if(i < width - 1){
				cells.at(i).at(j).neighbours.push_back(cells.at(i+1).at(j));
			}
			if(i > 0){
				cells.at(i).at(j).neighbours.push_back(cells.at(i-1).at(j));
			}
			if(j < height - 1){
				cells.at(i).at(j).neighbours.push_back(cells.at(i).at(j+1));
			}
			if(j > 0){
				cells.at(i).at(j).neighbours.push_back(cells.at(i).at(j-1));
			}
		}
	}
}

edge::edge (unsigned int x1coord, unsigned int y1coord, unsigned int x2coord, unsigned int y2coord){
	x1 = x1coord;
	y1 = y1coord;
	x2 = x2coord;
	y2 = y2coord;
}	

unsigned int Maze::getHeight(){
	return height;
}

unsigned int Maze::getWidth(){
	return width;
}

struct cell Maze::getCell(unsigned int x,unsigned int y){
	return cells.at(x).at(y);
}
