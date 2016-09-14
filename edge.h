/***********************************************************************
 * Author           : Luke Ellison | Joshua Theeuf
 * Student Number   : s3484756 | s3234575
 ***********************************************************************/
#ifndef EDGE
#define EDGE

class Edge{
	unsigned int x1;
	unsigned int y1;
	unsigned int x2;
	unsigned int y2;
	public:Edge(unsigned int, unsigned int, unsigned int, unsigned int);
		unsigned int getX1();
		unsigned int getX2();
		unsigned int getY1();
		unsigned int getY2();	

};

#endif