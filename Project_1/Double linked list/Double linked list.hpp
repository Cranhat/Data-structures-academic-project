#pragma once

struct Node{
    int data;
    Node* next;
    Node* previous;
};

class DoubleLinkedList{
    // private:
        Node* head;

    public:

    DoubleLinkedList(int data); // Constructor

    ~DoubleLinkedList(); // Destructor 

    Node* elementFromFront(); // gets element from front, last that indicates nullptr

    void addFront(int value); // This and below is self-explanatory

    void addBack(int value);

    void addInside(int value);

    void addMiddle(int value);

    void deleteFront();

    void deleteBack();

    void deleteInside();

    void deleteMiddle();

    bool contains(int value);

    int getSize(); 

    Node* givePointer(); // return a pointer to first node containing value

    


};
