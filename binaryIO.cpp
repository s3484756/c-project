/***********************************************************************
 * Author           : Luke Ellison
 * Student Number   : s3484756
 ***********************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

char * binaryRead(char * filename){
  streampos size;
  char * memblock;
  ifstream file (filename, ios::in|ios::binary|ios::ate);
  if (file.is_open())
  {
    printf("found file\n");
    size = file.tellg();
    memblock = new char [size];
    file.seekg (0, ios::beg);
    file.read (memblock, size);
    file.close();

    cout << "the entire file content is in memory";
	return memblock;
  }
  else 
	cout << "Unable to open file";
  return memblock;
}


bool binaryWrite(char * filename, char * memblock){
  ofstream file (filename, ios::out | ios::binary);
  if (file.is_open())
  {
	file.write(memblock,sizeof(memblock));
    file.close();
	return true;
  }
  else 
	cout << "Unable to open file";
  return false;
}

