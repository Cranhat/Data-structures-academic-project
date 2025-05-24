#pragma once

#include "../../DataStructures/Dynamic_array/DynamicArray.hpp"
#include "../../DataStructures/DataStructure/DataStructure.hpp"

class HashTableOA : public DynamicArray{
    protected:
	arrayNode** data;
	int size; 

    FUNC_PTR addresing_function;
    int capacity = 10;

    public:
    HashTableOA(FUNC_PTR addresing_function){ // Open Addressing have load factor limitation of 1, it's not dynamic object.
        size = 0;
	    data = new arrayNode*[capacity];
        this -> addresing_function = addresing_function;

        for (int i = 0; i < capacity; i++){
            data[i] = nullptr;
        }
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

    void insert(int i, int key, int value);

    void printElements();

    void allocate_from_csv(std::string dataFilePath, int elements_allocated, int new_capacity);

    arrayNode* getRandom();

    void initialize(int new_capacity);

    void clear();
};
