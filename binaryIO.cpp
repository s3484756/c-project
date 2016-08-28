/***********************************************************************
 * Author           : Luke Ellison - Joshua Theeuf
 * Student Number   : s3484756 -  s3234575
 ***********************************************************************/
#include <iostream>
#include <fstream>
#include "generator.h"
using namespace std;

bool binaryRead(char * filename, vector<int> * data){
  int holder;
  ifstream file(filename, ios::in|ios::binary|ios::ate);
  if (file.is_open())
  {
    while(file){
		cout << "reading data" << endl;
		file.read((char*)&holder, sizeof(int));
		if(!file)
			break;
		data->push_back(holder);
	}
	file.close();
	cout << "herererere" << endl;
    return true;
  }
  else{
	return false;
  }
}


bool binaryWrite(char * filename, Generator gen){
  ofstream file; 
  int x;
  file.open(filename, ios::binary | ios::out);
  if (file.is_open())
  {
	x = gen.getMaze().getWidth();
	file.write((char*)&x, sizeof(int));
	x = gen.getMaze().getHeight();
	file.write((char*)&x, sizeof(int));
	x = gen.getPaths().size();
	file.write((char*)&x, sizeof(int));
	for(unsigned int i = 0; i < gen.getPaths().size();++i){
		x = gen.getPaths().at(i).getX1();
		file.write((char*)&x, sizeof(int));
		x = gen.getPaths().at(i).getY1();
		file.write((char*)&x, sizeof(int));
		x = gen.getPaths().at(i).getX2();
		file.write((char*)&x, sizeof(int));
		x = gen.getPaths().at(i).getY2();
		file.write((char*)&x, sizeof(int));
	}
    file.close();
	return true;
  }
  else 
	cout << "Unable to open file";
  return false;
}

