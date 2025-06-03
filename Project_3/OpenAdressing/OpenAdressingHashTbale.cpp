#include "OpenAddressingHashTable.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>


OpenAddressingHashTable::OpenAddressingHashTable(int capacity)
    : size(0), capacity(capacity) {
    data = new arrayNode*[capacity];
    for (int i = 0; i < capacity; i++) {
        data[i] = nullptr;
    }
}

OpenAddressingHashTable::~OpenAddressingHashTable() {
    clear();
    delete[] data;
}

int OpenAddressingHashTable::hashFunction(int key) {
    return key % capacity;
}

void OpenAddressingHashTable::insert(int key, int value) {
    if (size == capacity) {
        std::cout << "Hash table full!\n";
        return;
    }

    int i = hashFunction(key);
    while (data[i] != nullptr) {
        if (data[i]->key == key) {
            data[i]->value = value; 
            return;
        }
        i = (i + 1) % capacity;
    }

    data[i] = new arrayNode{key, value};
    size++;
}

int OpenAddressingHashTable::search(int key) {
    int i = hashFunction(key);
    int count = 0;

    while (data[i] != nullptr && count < capacity) {
        if (data[i]->key == key)
            return data[i]->value;
        i = (i + 1) % capacity;
        count++;
    }

    return -1; 
}

void OpenAddressingHashTable::remove(int key) {
    int i = hashFunction(key);
    int count = 0;

    while (data[i] != nullptr && count < capacity) {
        if (data[i]->key == key) {
            delete data[i];
            data[i] = nullptr;
            size--;
            return;
        }
        i = (i + 1) % capacity;
        count++;
    }
}
}
