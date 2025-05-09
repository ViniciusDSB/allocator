#include "GC.h"

//////////////////////////////////////////////////////////
// Begin namespace tcii::ex


namespace tcii::ex{


//////////////////////////////////////////////////////////
// Allocator implementation
Allocator* Allocator::_instance;
char Allocator::_heap[HEAP_SIZE];
BlockInfo* Allocator::freeBlocksList;

// insert your code here

void Allocator::initialize(unsigned size){

    freeBlocksList = reinterpret_cast<BlockInfo*>(_heap); // Remember, heap is a pointer the first position of heap[]
    freeBlocksList->flag = 0;
    freeBlocksList->size = HEAP_SIZE - 2*sizeof(BlockInfo); //FAZER O CALCULO EXATO!!!!!!!!!!!!
    freeBlocksList->next = freeBlocksList;
    freeBlocksList->prev = nullptr;

    BlockInfo* footer = reinterpret_cast<BlockInfo*>(_heap + size - sizeof(BlockInfo));
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


void Allocator::printMemoryMap(){

    using namespace std;

    auto* listItem = freeBlocksList; // Reference to the first BlockInfo

    if(listItem != NULL){

        do{
            
            cout << endl;
            
            cout << (void*)listItem <<endl;
            cout << listItem->size <<endl;
            cout << listItem->flag <<endl;

            cout << "---------------" <<endl;

            listItem = listItem->next;

        }while( listItem != freeBlocksList );

    }


    return;
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

//template <typename T> static T* allocate(unsigned = 1);
//static void free(void*);
//static ;


} // begin namespace tcii::ex
