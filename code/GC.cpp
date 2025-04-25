#include "GC.h"

//////////////////////////////////////////////////////////
// Begin namespace tcii::ex
namespace tcii::ex{


//////////////////////////////////////////////////////////
// Allocator implementation
Allocator* Allocator::_instance;

// insert your code here

void Allocator::initialize(unsigned size){

    freeBlocksList = reinterpret_cast<BlockInfo*>(heap); // Remember, heap is a pointer the first position of heap[]
    freeBlocksList->flag = 0;
    freeBlocksList->size - size;
    freeBlocksList->next = nullptr;
    freeBlocksList->prev = nullptr;

    BlockInfo* footer = reinterpret_cast<BlockInfo*>(heap + size - sizeof(BlockInfo));
    *footer = *freeBlocksList;

}

template <typename T> 
T* Allocator::allocate(unsigned reqSize){

    // A block has a header and a footer of the same size, we consider it to find the actual allocation size needed
    const auto fullReqSize = ( (2*sizeof(BlockInfo)) + reqSize );

    // By doing the following we guaratee only full blocks are allocated:
    const auto blocksNeeded = ( ( (fullReqSize - 1) / MIN_BLOCK_SIZE ) + 1  );
    const auto actualSize = blocksNeeded * MIN_BLOCK_SIZE;

    // Verificar se há na lista de blocks livres o tamanho requisitado, n;
    //  Se houver um bloco de tamanho b = n então todo o bloco é alocado
    //  Se houver um bloco de tamanho b > n então aloca parte desse bloco
    //      e o que sobrar é deixado como livre na lista de blocos livres

    return nullptr;
}

//void Allocator::free(void* ptr){
//
//    // Verificar os blocos adjacentes
//    //  se
//    //  ...
//    // Marcar o bloco apontado por ptr como livre
//
//    return;
//}

//void printMemoryMap(){
//    return;
//}

//template <typename T> static T* allocate(unsigned = 1);
//static void free(void*);
//static ;


} // begin namespace tcii::ex
