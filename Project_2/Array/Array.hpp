#pragma once
#include "../DataStructure/DataStructure.hpp"

class arrayNode {
public:
    int key;
    int value;
};

class PriorityQueueArray : public DataStructure {
protected:
    arrayNode** data;  
    int size;          
    int capacity;      

public:
    PriorityQueueArray();
    ~PriorityQueueArray();

    void insert(int key, int value);
    arrayNode* extractMax();
    arrayNode* peek();
    arrayNode* find(int value);
    void changeKey(arrayNode* node_ptr, int newKey);
    void changeValue(arrayNode* node_ptr, int newValue);
    int getSize();
    void resize();
    void clear();
    void printElements();
};
