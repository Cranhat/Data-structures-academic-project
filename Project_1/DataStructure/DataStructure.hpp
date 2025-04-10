#pragma once

class DataStructure{
    public:

    DataStructure();

    virtual void printElements();

    virtual void addFront(int value); 

    virtual void addBack(int value);

    // virtual void addInside(Node* index, int value);

    virtual void deleteFront();

    virtual void deleteBack();

    virtual void clear();
};