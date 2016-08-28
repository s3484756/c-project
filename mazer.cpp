/***********************************************************************
 * Author           : Luke Ellison
 * Student Number   : s3484756
 ***********************************************************************/
#include "generator.h"
#include "userValidation.h"
#include "binaryIO.h"
#include "svgWriter.cpp"
#include <iostream>
#include <fstream>
#include <string.h>

//control for generated maze output
void genOutput(char *argv[], int argc, int nextIndex, Generator gen){
	int outputOpt = outputOptions(argv,argc,nextIndex);
	if (outputOpt == 1){
		write_svg(gen.getPaths(), argv[nextIndex+1], gen.getMaze().getWidth(), gen.getMaze().getHeight());
		binaryWrite(argv[nextIndex+3], gen);
	}
	if(outputOpt == 2){
		write_svg(gen.getPaths(), argv[nextIndex+3], gen.getMaze().getWidth(), gen.getMaze().getHeight());
		binaryWrite(argv[nextIndex+1], gen);
	}
	if(outputOpt == 3){
		binaryWrite(argv[nextIndex+1], gen);
	}
	if(outputOpt == 4){
		write_svg(gen.getPaths(), argv[nextIndex+1], gen.getMaze().getWidth(), gen.getMaze().getHeight());
	}
}

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
		Generator newMaze(atoi(argv[3]),atoi(argv[4]),atoi(argv[2]));
		newMaze.generate();
		nextIndex = 5;
		genOutput(argv,argc,nextIndex,newMaze);
		
	}
	else if(option == 2){//no seed, width or height specified
		cout << "No height or width specified, using default height of 100, and width of 100." << endl;
		int h = 100;
		int w = 100;
		Generator newMaze(h,w);
		newMaze.generate();
		nextIndex = 2;
		genOutput(argv,argc,nextIndex,newMaze);
		cout << "seed used is" << newMaze.getSeed() << endl;
	}
	else if(option == 3){ //no width or heoght specified, seed specified
		int h = 100;
		int w = 100;
		Generator newMaze(h,w,atoi(argv[2]));
		newMaze.generate();
		nextIndex = 3;
		genOutput(argv,argc,nextIndex,newMaze);
	}
	else if(option == 4){//width and height specifed, seed not specified
		Generator newMaze(atoi(argv[2]),atoi(argv[3]));
		newMaze.generate();
		nextIndex = 4;
		genOutput(argv,argc,nextIndex,newMaze);
		cout << "seed used is" << newMaze.getSeed() << endl;
	}
	// DOES NOT WORK
	else if(option == 5){//loading maze from binary file and write it to svg
		vector<int> data;
		binaryRead(argv[2],&data);
		vector<Edge> paths;
		int x1,y1,x2,y2;
	    int width = data.at(0);
		int height = data.at(1);
		int edgeNum = data.at(2);
		cout << edgeNum << endl;
		cout << width << endl;
		cout << height << endl;
		cout << data.size() << endl;
		
		for(int i =3; i < edgeNum-3; i+=4){
			x1 = data.at(i);
			y1 = data.at(i+1);
			x2 = data.at(i+2);
			y2 = data.at(i+3);
			Edge newEdge(x1,y1,x2,y2);
			paths.push_back(newEdge);
		}
		write_svg(paths, argv[4], width, height);
		return 0;
	}

	
	return 0;
}
