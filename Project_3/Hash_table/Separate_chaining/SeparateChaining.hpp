#pragma once

#include <string>

#include "../../DataStructures/Double_linked_list/DoubleLinkedList.hpp"
#include "../../DataStructures/DataStructure/DataStructure.hpp"

class HashTableSC : public DoubleLinkedList{
    protected:

	DoubleLinkedList** data;
    int bucket_amount = 10;
    FUNC_PTR addresing_function;


    public:
    HashTableSC(FUNC_PTR addresing_function){ 
        size = 0;
	    data = new DoubleLinkedList*[bucket_amount];
        this -> addresing_function = addresing_function;

        for (int i = 0; i < bucket_amount; i++){
            data[i] = new DoubleLinkedList();
        }
    }

    ~HashTableSC(){
        delete data;
    }

    void addHash(int key, int value);

    void deleteHash(int key, int value);

    void insert(int i, int key, int value);

    void printElements();

    void allocate_from_csv(std::string dataFilePath, int elements_allocated, int bucket_amount);

    Node* getRandom();

    void initialize(int bucket_amount);

    void clear();
};
