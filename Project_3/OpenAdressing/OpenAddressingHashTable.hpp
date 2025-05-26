#ifndef OPENADDRESSINGHASHTABLE_H
#define OPENADDRESSINGHASHTABLE_H

#include <vector>
#include "HashTable.h"

class OpenAddressingHashTable : public HashTable {
private:
    struct Entry {
        int key;
        int value;
        bool isEmpty;
        bool isDeleted;

        Entry() : key(-1), value(-1), isEmpty(true), isDeleted(false) {}
        Entry(int k, int v) : key(k), value(v), isEmpty(false), isDeleted(false) {}
    };

    std::vector<Entry> table;
    int capacity;

    int hashFunction(int key);
    int probe(int key, int i);

public:
    OpenAddressingHashTable(int size);
    void insert(int key, int value) override;
    int search(int key) override;
    void remove(int key) override;
};

#endif // OPENADDRESSINGHASHTABLE_H
