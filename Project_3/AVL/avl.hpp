#ifndef HASHTABLEAVL_H
#define HASHTABLEAVL_H

#include <vector>
#include "HashTable.h"
#include "avl.hpp"

class HashTableAVL : public HashTable {
private:
    std::vector<AVLTree> table;
    int capacity;

    int hashFunction(int key);

public:
    HashTableAVL(int size);
    void insert(int key, int value) override;
    int search(int key) override;
    void remove(int key) override;
};

#endif // HASHTABLEAVL_H
