#include <iostream>

#include "../DataStructure/DataStructure.cpp"
#include "Heap.cpp"

int main(){
    Heap hp;
    hp.insert(1, 1);

    hp.insert(2, 10);

    hp.insert(6, 100);

    hp.insert(8, 200);

    hp.insert(3, 400);

    
    hp.insert(17, 100);

    hp.insert(3, 200);

    hp.insert(2, 400);

    hp.insert(1, 250);

    hp.insert(8, 400);


    hp.buildHeap();

    heapNode* node_ptr = hp.find(250);
    hp.changeKey(node_ptr, 100);

    printf("------\n");
    hp.printElements();
    printf("------\n");


    return 0;
}