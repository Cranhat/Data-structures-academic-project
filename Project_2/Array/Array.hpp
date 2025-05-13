#pragma once
#include "../DataStructure/DataStructure.hpp"

struct arrayNode : public NodeBase{
    ~arrayNode() {}
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
    void changeKey(int node_index, int newKey);
    void changeValue(arrayNode* node_ptr, int newValue);
    void changeValue(int node_index, int newValue);

    int getSize();
    void resize();
    void clear();
    void printElements();
    int findIndex(arrayNode* node_ptr);
    void deleteLast();
};
