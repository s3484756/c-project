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
	if(argc>=8){
			cout << "Too many inputs" << endl;
	}
	if(seedInput(argv, argc)== 1){	
		Generator newMaze(atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
		newMaze.generate();
	}
	else if(seedInput(argv,argc) == 2){
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
