#include "GC.h"

inline 
void allocatorTest(){

	using namespace tcii::ex;

	// insert your code here
	Allocator* myHeap;
	myHeap->initialize();
	myHeap->printMemoryMap();
}

//////////////////////////////////////////////////////////
// Main function
int main(){

	allocatorTest();
	
	return 0;
}
