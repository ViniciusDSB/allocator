#ifndef __GC_h
#define __GC_h

#include <new>

//////////////////////////////////////////////////////////
// Begin namespace tcii::ex
namespace tcii::ex{


// BlockInfo class
struct BlockInfo{

	unsigned flag;
	unsigned size;
	BlockInfo* prev;
	BlockInfo* next;

}; // BlockInfo

// This is the actual free block item with a pointer to a free block:
struct FreeBlock : BlockInfo{

	BlockInfo* blockHeader;

};


//////////////////////////////////////////////////////////
// Allocator class
class Allocator{

public:
	static constexpr auto MIN_BLOCK_SIZE = 16u;
	static constexpr auto HEADP_SIZE = 1048576u;

	static void initialize(unsigned = HEADP_SIZE);

	template <typename T> static T* allocate(unsigned = 1);
	static void free(void*);
	static void printMemoryMap();

	static void exit();

private:
	static Allocator* _instance;
	// insert your code here
	//Method for dealing with double linked circular list
	

}; // Allocator

} // begin namespace tcii::ex

#endif // __GC_h
