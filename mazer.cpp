/***********************************************************************
 * Author           : Luke Ellison - Joshua Theeuf
 * Student Number   : s3484756 -  s3234575
 ***********************************************************************/
#include "generator.h"
#include "userValidation.cpp"
#include "binaryIO.cpp"
#include "svgWriter.cpp"
#include <iostream>
#include <fstream>
#include <string.h>

int main(int argc, char * argv[]){
	int option;
	int nextIndex = 0;
	if(argc>=8){
		cout << "Too many inputs" << endl;
		return 0;
	}
	if (argc <= 1){
		cout << "Too few inputs" << endl;
		return 0;
	}
	option = seedInput(argv, argc); 
	if(option == 1){ //seed, width and height specified
		cout << "input" <<endl;
		Generator newMaze(atoi(argv[3]),atoi(argv[4]),atoi(argv[2]));
		newMaze.generate();
		nextIndex = 5;
		binaryWrite("test.maze",newMaze);
	}
	else if(option == 2){//no seed, width or height specified
		cout << "No height or width specified, using default height of 100, and width of 100." << endl;
		int h = 100;
		int w = 100;
		Generator newMaze(h,w);
		newMaze.generate();
		nextIndex = 2;
	}
	else if(option == 3){ //no width or heoght specified, seed specified
		cout << "No height or width specified, using default height of 100, and width of 100." << endl;
		int h = 100;
		int w = 100;
		Generator newMaze(h,w,atoi(argv[2]));
		newMaze.generate();
		nextIndex = 3;
	}
	else if(option == 4){//width and height specifed, seed not specified
		cout << "here" << endl;
		Generator newMaze(atoi(argv[2]),atoi(argv[3]));
		newMaze.generate();
		nextIndex = 4;
	}
	else if(option == 5){//loading maze from binary file
		vector<int> data;
		binaryRead("test.maze",&data);
		vector<Edge> paths;
		int x1,y1,x2,y2;
	    int width = data.at(0);
		int height = data.at(1);
		int edgeNum = data.at(2);
		cout << "herre" << endl;
		for(int i =3; i < edgeNum-3; i+=4){
			x1 = data.at(i);
			y1 = data.at(i+1);
			x2 = data.at(i+2);
			y2 = data.at(i+3);
			Edge newEdge(x1,y1,x2,y2);
			paths.push_back(newEdge);
		}
		write_svg(paths, argv[5], width, height);
		return 0;
	}
/*	char str*;
	strncpy(str,"maze.svg",sizeof("maze.svg"));
	str[sizeof(str)-1] = '\0';
	write_svg(newMaze.getPaths(), "maze_generator_test.svg", newMaze.getMaze().getWidth(), newMaze.getMaze().getHeight());
*/
	
	return 0;
}
