#include "maze.h"
#include <iostream>
#include <fstream>
void write_svg(vector<Edge> edges, vector<Edge> route, char * filename, int width, int height){
	ofstream file (filename, ios::out);
	std::cout << filename << std::endl;
	char line[100];
	sprintf(line, "<svg viewBox='0 0 %d %d' width='500' height='500' xmlns='http://www.w3.org/2000/svg'>\n", width, height);
	file << line;
	sprintf(line, "<rect width='%d' height='%d' style='fill: black' />\n",height,width);
	file << line;
	std::cout << "\n" << std::endl;
	for(unsigned int i = 0; i < edges.size();i++){
		sprintf(line, "<line stroke='white' stroke-width='0.5' x1='%d' y1='%d' x2='%d' y2='%d'/>\n",edges.at(i).getX2(), edges.at(i).getY1(),
		edges.at(i).getX1(), edges.at(i).getY2());
		file << line;
	}
	for(unsigned int i = 0; i < route.size();i++){
		sprintf(line, "<line stroke='red' stroke-width='0.1' x1='%d' y1='%d' x2='%d' y2='%d'/>\n",route.at(i).getX1(), route.at(i).getY1(),
		route.at(i).getX2(), route.at(i).getY2());
		file << line;
	}
	file << "//<svg>\n";
}
