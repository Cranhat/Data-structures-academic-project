#pragma once

#include "../DataStructure/DataStructure.hpp"

// template <typename T>
// struct heapNode{
//     T value;
//     int key;
// };
struct heapNode{
    int value;
    int key;
};


class Heap  : public DataStructure{
    protected:
        heapNode** data;

        int size; 
        int capacity; 

    public:

    Heap();

    ~Heap();

    void resize();

    void clear();

    void swap(int firstIndex, int secondIndex);

    void printElements();

    void printElement(heapNode* node_ptr);

    void insert(int data, int key);
    
    heapNode* extractMax();

    heapNode* findMax();

    heapNode* find(int value);

    void deleteMax();

    void heapify(int size, int i); // sift up

    void buildHeap();

    int getSize();

    void changeValue(heapNode* node_ptr, int value);

    void changeKey(heapNode* node_ptr, int key);


};