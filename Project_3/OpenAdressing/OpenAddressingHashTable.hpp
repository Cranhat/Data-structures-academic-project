#ifndef OPENADDRESSINGHASHTABLE_H
#define OPENADDRESSINGHASHTABLE_H

#include <string>
#include "HashTable.h"

struct aarayNode {
    int key;
    int value;
};

class OpenAddressingHashTable : public HashTable {
private:
    arrayNode** data;
    int size;
    int capacity;

    int hashFunction(int key);

public:
    OpenAddressingHashTable(int capacity = 10;);
    ~OpenAddressingHashTable();

    void insert(int key, int value) override;
    int search(int key) override;
    void remove(int key) override;
};

#endif // OPENADDRESSINGHASHTABLE_H
