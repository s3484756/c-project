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
	binaryLoad(argv);
	svgFile(argv);
	//Generator newMaze(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
	//newMaze.generate();
/*	char str*;
	strncpy(str,"maze.svg",sizeof("maze.svg"));
	str[sizeof(str)-1] = '\0';
	write_svg(newMaze.getPaths(), "maze_generator_test.svg", newMaze.getMaze().getWidth(), newMaze.getMaze().getHeight());
*/
	return 0;
}
