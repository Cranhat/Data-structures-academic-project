#pragma once

#include "../DataStructure/DataStructure.hpp"

struct Node : public NodeBase{

    int value;
    int key;
    Node* next;
    Node* previous;

};

class DoubleLinkedList : public DataStructure{
    public:

    Node* head;
    Node* tail;

    DoubleLinkedList(); // Constructor

    ~DoubleLinkedList(); // Destructor 

    int lastElement(); // gets element from front, last that indicates nullptr

    int firstElement(); 

    void printElements();

    void addFront(int key, int value); // This and below is self-explanatory

    void addBack(int key,int value);

    void addIndex(int key, int value, int index);

    void deleteFront();

    void deleteBack();

    void deleteIndex(int index);

    void clear();

    bool contains(int key, int value);

    int getSize(); 

    void deleteLast();

    void addHash(int key, int number);

    Node* givePointer(int value); // return a pointer to first node containing value

    Node* getRandom();

    void allocate_from_csv(std::string dataFilePath, int elements_allocated, int new_capacity);

};