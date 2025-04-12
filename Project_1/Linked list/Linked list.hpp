#pragma once

#include "../DataStructure/DataStructure.hpp"
#include "../Double linked list/Double linked list.hpp"

class LinkedList : public DataStructure {
public:

    Node* head;  
    Node* tail;

    LinkedList();         

    ~LinkedList();         

    void printElements();

    void addFront(int value); 

    void addBack(int value); 

    void addIndex(int value, int index);

    void deleteBack();

    void deleteFront();

    void deleteIndex(int index);

    bool contains(int value);

    int firstElement();

    int lastElement();

    void clear();

    int getSize(); 

};
