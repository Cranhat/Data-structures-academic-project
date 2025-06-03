#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
public:
    virtual ~HashTable() = default;

    virtual void insert(int key, int value) = 0;
    virtual int search(int key) = 0;
    virtual void remove(int key) = 0;
};

#endif // HASHTABLE_H
