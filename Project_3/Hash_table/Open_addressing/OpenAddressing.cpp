#include "OpenAddressing.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <random>


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
        insert(i, key,  value);
        size++;
    }
}

void HashTableOA::deleteHash(int key, int value){
    int i = addresing_function(key, capacity);
    for(;i < capacity; i++){
        if (data[i] -> key == key && data[i] -> value == value){
            delete data[i];
            data[i] = nullptr;
            break;
        }
        if (i == (capacity - 1)){
            i = 0;
        }
    }
    size--;
}


void HashTableOA::insert(int i, int key, int value) {

    arrayNode* newNode = new arrayNode();
    newNode->key = key;
    newNode->value = value;
    data[i] = newNode;
}

void HashTableOA::printElements() {
    for (int i = 0; i < capacity; i++) {
        if (data[i] != nullptr){
            std::cout << i << "th element = " << data[i]->value << ", key = " << data[i]->key << std::endl;
        }
    }
}

void HashTableOA::clear() {
    for (int i = 0; i < capacity; i++){
        delete data[i];
    }
    delete[] data;
    size = 0;
}

void HashTableOA::initialize(int new_capacity) {
    this -> capacity = new_capacity;
    data = new arrayNode*[capacity];
    for (int i = 0; i < capacity; i++){
        data[i] = nullptr;
    }
}

void HashTableOA::allocate_from_csv(std::string dataFilePath, int elements_allocated, int new_capacity){
    clear();
    initialize(new_capacity);

    std::ifstream myFile(dataFilePath.c_str(), std::ios::in);

    int number, key, location, count = 0;
    std::string line;

    while (std::getline(myFile, line) && elements_allocated > count){

        location = line.find(';');

        number = stoi(line.substr(0, location));
        key = stoi(line.substr(location + 1));
        
        addHash(number, key);
        count++;
    }    
    myFile.close();
}

arrayNode* HashTableOA::getRandom(){ // returned value is off, fix needed
    if (capacity < 1){
        return nullptr;
    }

    int start = rand() % capacity;

    for(int offset = 0; offset < capacity; offset++){
        int i = (start + offset) % capacity;

        if (data[i] != nullptr){
            return data[i];
        }
    }
    return nullptr;
}
