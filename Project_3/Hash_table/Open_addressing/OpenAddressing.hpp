#pragma once

#include "../../DataStructures/Dynamic_array/DynamicArray.hpp"
#include "../../DataStructures/DataStructure/DataStructure.hpp"

class HashTableOA : public DynamicArray{
    protected:
    // arrayNode** data;
    FUNC_PTR addresing_function;

    public:
    HashTableOA(int capacity, FUNC_PTR addresing_function){ // Open Addressing have load factor limitation of 1, it's not dynamic object.
	    data = new arrayNode*[capacity];
        size = 0;
        this -> addresing_function = addresing_function;
    }

    ~HashTableOA(){
        for (int i = 0; i < capacity; i++){
            delete data[i];
        }
        delete data;
    }

    void addHash(int key, int value);

    void deleteHash(int key, int value);

    void deleteHashKeyOnly(int key);

    void insert(int key, int value);

    void printElements();
};
