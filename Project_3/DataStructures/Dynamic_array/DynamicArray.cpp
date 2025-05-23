#include "DynamicArray.hpp"
#include <iostream>
#include <fstream>

DynamicArray::DynamicArray() {
    capacity = 10;
    size = 0;
    data = new arrayNode*[capacity];
}

DynamicArray::~DynamicArray() {
    for (int i = 0; i < size; i++){
        delete data[i];
    }
    delete[] data;
}

void DynamicArray::insert(int key, int value) {
    if (size == capacity) {
        resize();
    }

    arrayNode* newNode = new arrayNode();
    newNode->key = key;
    newNode->value = value;
    data[size++] = newNode;
}

arrayNode* DynamicArray::extractMax(){
    if (size == 0) return nullptr;

    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (data[i]->key > data[maxIndex]->key) {
            maxIndex = i;
        }
    }

    arrayNode* maxNode = data[maxIndex];
    data[maxIndex] = data[size - 1];
    size--;

    return maxNode;  
}

arrayNode* DynamicArray::peek() {
    if (size == 0) return nullptr;

    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (data[i]->key > data[maxIndex]->key) {
            maxIndex = i;
        }
    }

    return data[maxIndex];
}

arrayNode* DynamicArray::find(int value) {
    for (int i = 0; i < size; i++) {
        if (data[i]->value == value) {
            return data[i];
        }
    }
    return nullptr;
}

void DynamicArray::changeKey(arrayNode* node_ptr, int newKey) {
    node_ptr->key = newKey;
}

void DynamicArray::changeKey(int node_index, int newKey) {
    data[node_index] -> key = newKey;
}

void DynamicArray::changeValue(arrayNode* node_ptr, int newValue) {
    node_ptr->value = newValue;
}

void DynamicArray::changeValue(int node_index, int newValue) {
    data[node_index] -> value = newValue;
}

int DynamicArray::getSize() {
    return size;
}

void DynamicArray::resize() {
    capacity *= 2;
    arrayNode** newData = new arrayNode*[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

void DynamicArray::clear() {
    delete[] data;
    capacity = 10;
    size = 0;
    data = new arrayNode*[capacity];
}

void DynamicArray::printElements() {
    for (int i = 0; i < size; i++) {
        std::cout << i << "th element = " << data[i]->value << ", key = " << data[i]->key << std::endl;
    }
}

int DynamicArray::findIndex(arrayNode* node_ptr){
    for(int i = 0; i < size; i++){
        if(data[i] == node_ptr){
            return i;
        }
    }
    return -1;
}

void DynamicArray::deleteLast(){
    delete data[size--];
}