#include "Array.hpp"
#include <iostream>
#include <stdexcept>

PriorityQueueArray::PriorityQueueArray() {
    capacity = 10;
    size = 0;
    data = new arrayNode*[capacity];
}

PriorityQueueArray::~PriorityQueueArray() {
    for (int i = 0; i < size; i++){
        delete data[i];
    }
    delete[] data;
}

void PriorityQueueArray::insert(int key, int value) {
    if (size == capacity) {
        resize();
    }

    arrayNode* newNode = new arrayNode();
    newNode->key = key;
    newNode->value = value;
    data[size++] = newNode;

}

arrayNode* PriorityQueueArray::extractMax(){
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

arrayNode* PriorityQueueArray::peek() {
    if (size == 0) return nullptr;

    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (data[i]->key > data[maxIndex]->key) {
            maxIndex = i;
        }
    }

    return data[maxIndex];
}

arrayNode* PriorityQueueArray::find(int value) {
    for (int i = 0; i < size; i++) {
        if (data[i]->value == value) {
            return data[i];
        }
    }
    return nullptr;
}

void PriorityQueueArray::changeKey(arrayNode* node_ptr, int newKey) {
    node_ptr->key = newKey;
}

void PriorityQueueArray::changeKey(int node_index, int newKey) {
    data[node_index] -> key = newKey;
}

void PriorityQueueArray::changeValue(arrayNode* node_ptr, int newValue) {
    node_ptr->value = newValue;
}

void PriorityQueueArray::changeValue(int node_index, int newValue) {
    data[node_index] -> value = newValue;
}

int PriorityQueueArray::getSize() {
    return size;
}

void PriorityQueueArray::resize() {
    capacity *= 2;
    arrayNode** newData = new arrayNode*[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

void PriorityQueueArray::clear() {
    for (int i = 0; i < size; i++){
        delete data[i];
    }
    delete[] data;
    capacity = 10;
    size = 0;
    data = new arrayNode*[capacity];
}

void PriorityQueueArray::printElements() {
    for (int i = 0; i < size; i++) {
        std::cout << i << "th element = " << data[i]->value << ", key = " << data[i]->key << std::endl;
    }
}

int PriorityQueueArray::findIndex(arrayNode* node_ptr){
    for(int i = 0; i < size; i++){
        if(data[i] == node_ptr){
            return i;
        }
    }
    return -1;
}

void PriorityQueueArray::deleteLast(){
    if (size > 0){
        delete data[size-- - 1];
    }
}
