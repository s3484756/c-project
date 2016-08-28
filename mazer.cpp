/***********************************************************************
 * Author           : Luke Ellison
 * Student Number   : s3484756
 ***********************************************************************/
#include "generator.h"
#include "userValidation.cpp"
#include <iostream>
#include <fstream>
#include <string.h>
int main(int argc, char * argv[]){
	int option;
	if(argc>=8){
		cout << "Too many inputs" << endl;
		return 0;
	}
	if (argc <= 1){
		cout << "Too few inputs" << endl;
		return 0;
	}
	option = seedInput(argv, argc); 
	if(option == 1){
		cout << "input" <<endl;
		Generator newMaze(atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
		newMaze.generate();
	}
	else if(option == 2){
		cout << "No height or width specified, using default height of 100, and width of 100." << endl;
		int h = 100;
		int w = 100;
		Generator newMaze(h,w,10);
		newMaze.generate();
	}
/*	char str*;
	strncpy(str,"maze.svg",sizeof("maze.svg"));
	str[sizeof(str)-1] = '\0';
	write_svg(newMaze.getPaths(), "maze_generator_test.svg", newMaze.getMaze().getWidth(), newMaze.getMaze().getHeight());
*/
	
	return 0;
}
