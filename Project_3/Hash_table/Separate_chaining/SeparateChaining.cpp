#include "SeparateChaining.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <random>



void HashTableSC::addHash(int key, int value){
    data[addresing_function(key, bucket_amount)] -> addBack(key, value);
    size++;
}

void HashTableSC::deleteHash(int key, int value){
    data[addresing_function(key, bucket_amount)] -> deleteElement(key, value);
    size--;
}

void HashTableSC::printElements() {
    for (int i = 0; i < bucket_amount; i++) {
        std::cout << "Bucket with index = " << i << std::endl;
        data[i] -> printElements ();
    }
}

void HashTableSC::clear() {
    if (!bucket_amount) return;
    for (int i = 0; i < bucket_amount; i++){
        delete data[i];
    }
    delete[] data;
    size = 0;
    bucket_amount = 0;
}

void HashTableSC::initialize(int bucket_amount) {
    clear();
    this -> bucket_amount = bucket_amount;
    data = new DoubleLinkedList*[bucket_amount];
    for (int i = 0; i < bucket_amount; ++i) {
        data[i] = new DoubleLinkedList();
    }
}

void HashTableSC::allocate_from_csv(std::string dataFilePath, int elements_allocated, int bucket_amount){

    initialize(bucket_amount);

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

Node* HashTableSC::getRandom(){ // returned value is off, fix needed
    std::cout << "a\n";
    if (bucket_amount < 1){
        return nullptr;
    }
    std::cout << "aa\n";
    int start = rand() % bucket_amount;

    for(int offset = 0; offset < bucket_amount; offset++){
        int i = (start + offset) % bucket_amount;
        if (data[i] -> getSize() > 0){
            return data[i] -> getRandom();
        }
    }
    std::cout << "aaa\n";
    return nullptr;
}
