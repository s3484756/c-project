/***********************************************************************
 * Author           : Luke Ellison - Joshua Theeuf
 * Student Number   : s3484756 -  s3234575
 ***********************************************************************/
#include "edge.h"


Edge::Edge (unsigned int x1coord, unsigned int y1coord, unsigned int x2coord, unsigned int y2coord){
	x1 = x1coord;
	y1 = y1coord;
	x2 = x2coord;
	y2 = y2coord;
}

unsigned int Edge::getX1(){
	return x1;
}

unsigned int Edge::getX2(){
	return x2;
}	

unsigned int Edge::getY1(){
	return y1;
}	

unsigned int Edge::getY2(){
	return y2;
}		