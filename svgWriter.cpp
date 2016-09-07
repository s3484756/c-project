#include "maze.h"
#include <iostream>
#include <fstream>
void write_svg(vector<Edge> edges, char * filename, int width, int height){
	ofstream file (filename, ios::out);
	std::cout << filename << std::endl;
	char line[100];
	sprintf(line, "<svg viewBox='500 500 %d %d' width='%d' height='%d' xmlns='http://www.w3.org/2000/svg'>\n", width, height,width,height);
	file << line;
	sprintf(line, "<rect width='%d' height='%d' style='fill: black' />\n",width,height);
	file << line;
	for(unsigned int i = 0; i < edges.size();i++){
		sprintf(line, "<line stroke='white' stroke-width='0.5' x1='%d' y1='%d' x2='%d' y2='%d'/>\n",edges.at(i).getX1(), edges.at(i).getY1(),
		edges.at(i).getX2(), edges.at(i).getY2());
		file << line;
	}
	file << "//<svg>\n";
}
