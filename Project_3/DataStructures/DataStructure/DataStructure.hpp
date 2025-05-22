#pragma once

struct NodeBase{
    virtual ~NodeBase() noexcept = default;
};

typedef int (*FUNC_PTR)(int, int);

class DataStructure{
    public:

    DataStructure();

    virtual void printElements();
    
    virtual int getSize();

    virtual void clear();
};