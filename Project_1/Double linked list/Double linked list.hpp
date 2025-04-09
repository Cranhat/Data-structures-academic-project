#pragma once

#include "../DataStructure/DataStructure.hpp"
#include <string>

struct Node{
    int data;
    Node* next;
    Node* previous;
};

class DoubleLinkedList : public DataStructure{
    public:

    Node* head;
    Node* tail;

    DoubleLinkedList(int head_data, int tail_data); // Constructor

    ~DoubleLinkedList(); // Destructor 

    Node* elementFromFront(); // gets element from front, last that indicates nullptr

    Node* firstElement(); 

    void printElements();

    void addFront(int value); // This and below is self-explanatory

    void addBack(int value);

    void addInside(Node* add_after_node, int value);

    void deleteFront();

    void deleteBack();

    void deleteInside(Node* delete_after_node);

    bool contains(int value);

    int getSize(); 

    Node* givePointer(int value); // return a pointer to first node containing value


};

class DLLTests : public DoubleLinkedList{
    public: 
    using DoubleLinkedList::DoubleLinkedList;

    void allocate_from_csv(std::string FilePath, int size);
};