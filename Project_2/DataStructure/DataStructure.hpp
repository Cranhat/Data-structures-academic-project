#pragma once

class DataStructure{
    public:

    DataStructure();

    virtual void printElements();

    virtual void addFront(int value); 

    virtual void addBack(int value);

    virtual void addIndex(int value, int index);

    virtual void deleteIndex(int index);

    virtual void deleteFront();

    virtual void deleteBack();

    virtual bool contains(int value);
    
    virtual int getSize();

    virtual void insert(int data, int key);

    virtual int firstElement();
    
    virtual int lastElement();

    virtual void clear();

    virtual int findMax();

    virtual void changeKey(void* node_ptr, int key);

    virtual void* extractMax();

    virtual void* peek();

    virtual void* find(int value);
};