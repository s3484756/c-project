#include "heap.cpp"
#include <stdio.h>


int main(void){
	Heap<int> test;
	test . 
	add(10);
	test.add(1);
	test.add(100);
	
	for(int i = 0; i < 10; ++i){
		test.add(i);
	}
	for(int i = 0; i < test.size(); i++)
		printf("%d\n",test.at(i));
	
	printf("\n\n%d\n",3/2);
	return 0;
}