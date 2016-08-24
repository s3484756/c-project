/***********************************************************************
 * Author           : Luke Ellison
 * Student Number   : s3484756
 ***********************************************************************/

#include "generator.h"
#include <iostream>
#include <fstream>
void write_svg(vector<Edge> edges, char * filename, int width, int height){
	ofstream file (filename, ios::out);
	char line[100];
	sprintf(line, "<svg viewBox='0 0 %d %d' width='%d' height='%d' xmlns='http://www.w3.org/2000/svg'>\n", width, height,width,height);
	file << line;
	sprintf(line, "<rect width='%d' height='%d' style='fill: black' />\n",width,height);
	file << line;
	for(unsigned int i = 0; i < edges.size();i++){
		sprintf(line, "<line stroke='white' stroke-width='0.8' x1='%d' y1='%d' x2='%d' y2='%d'/>\n",edges.at(i).getX1(), edges.at(i).getY1(),
		edges.at(i).getX2(), edges.at(i).getY2());
		file << line;
	}
	file << "//<svg>\n";
}

int main(){
	Generator newMaze(20,20,1);
	newMaze.generate();
	write_svg(newMaze.getPaths(), "maze_generator_test.svg", newMaze.getMaze().getWidth(), newMaze.getMaze().getHeight());
	return 0;
}
