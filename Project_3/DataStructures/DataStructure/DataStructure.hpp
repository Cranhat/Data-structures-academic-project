#pragma once

struct NodeBase{
    int value;
    int key;
    virtual ~NodeBase() noexcept = default;
};

typedef int (*FUNC_PTR)(int, int);

class DataStructure{
    public:

    DataStructure();

    virtual void printElements();
    
    virtual int getSize();

    virtual void clear();

    virtual void addHash(int key, int value);

    virtual void deleteBack();
    
    virtual void deleteHash(int key, int value);

    virtual void deleteElement(int key, int value);

    virtual NodeBase* getRandom();

    virtual void allocate_from_csv(std::string dataFilePath, int elements_allocated, int new_capacity);
};