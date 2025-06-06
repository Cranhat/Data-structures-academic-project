#pragma once

#include "../DataStructure/DataStructure.hpp"

// template <typename T>
// struct heapNode{
//     T value;
//     int key;
// };

struct heapNode : public NodeBase{
    ~heapNode() override {}
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

    heapNode* peek();

    heapNode* find(int value);
    
    int findIndex(heapNode* node_ptr);

    void deleteMax();

    void siftUp(int i);

    void heapify(int i);

    void buildHeap();

    int getSize();

    void changeValue(heapNode* node_ptr, int value);

    void changeValue(int arrayIndex, int value);

    void changeKey(heapNode* node_ptr, int key);

    void changeKey(int arrayIndex, int key);

    void deleteLast();


};