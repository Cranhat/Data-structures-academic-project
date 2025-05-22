#include "OpenAddressing.hpp"
#include <iostream>



void HashTableOA::addHash(int key, int value){
    if (size == capacity){
        std::cout << "hash table full!\n";
    }else{
        int i = addresing_function(key, capacity);
        while (data[i] != nullptr){
            if(i == capacity - 1){
                i = 0;
            }
            i += 1;
        }
        insert(i,  value);
        size++;
    }
}

void HashTableOA::deleteHash(int key, int value){
    int i = addresing_function(key, capacity);
    for(;i < capacity; i++){
        if (data[i] -> key == key && data[i] -> value == value){
            delete data[i];
        }
        if (i == (capacity - 1)){
            i = 0;
        }
    }
    size--;
}

void HashTableOA::deleteHashKeyOnly(int key){
    int i = addresing_function(key, capacity);
    for(;i < capacity; i++){
        if (data[i] -> key == key){
            delete data[i];
        }
        if (i == (capacity - 1)){
            i = 0;
        }
    }
    size--;
}

void HashTableOA::insert(int key, int value) {

    arrayNode* newNode = new arrayNode();
    newNode->key = key;
    newNode->value = value;
    data[key] = newNode;
}

void HashTableOA::printElements() {
    for (int i = 0; i < capacity; i++) {
        if (data[i] != nullptr){
            std::cout << i << "th element = " << data[i]->value << ", key = " << data[i]->key << std::endl;
        }
    }
}