#include "heap.cpp"
#include <stdio.h>


int main(void){
	Heap<int> test;
	test.add(2);
	printf("\n%d\n",test.popQueue());
	return 0;
}