#include "OpenAddressingHashTable.hpp"

OpenAddressingHashTable::OpenAddressingHashTable(int size) : capacity(size) {
    table.resize(capacity);
}

int OpenAddressingHashTable::hashFunction(int key) {
	return key % capacity;
}

int OpenAddressingHashTable::probe(int key, int i) {
	return (hashFunction(key) + i) % capacity;
}

void OpenAddressingHashTable::insert(int key, int value) {
	for (int i = 0; i < capacity; ++i) {
		int index = probe(key, i);
		if (table[index].isEmpty || table[index].isDeleted) {
			table[index] = Entry(key, value);
			return;
		}
	}
}

int OpenAddressingHashTable::search(int key) {
	for (int i = 0; i < capacity; ++i) {
		int index = probe(key, i);
		if (table[index].isEmpty) {
			return -1; 
		}
		if (!table[index].isDeleted && table[index].key == key) {
			return table[index].value;
		}
	}
	return -1; 
}

void OpenAddressingHashTable::remove(int key) {
	for (int i = 0; i < capacity; ++i) {
		int index = probe(key, i);
		if (table[index].isEmpty) {
			return; 
		}
		if (!table[index].isDeleted && table[index].key == key) {
			table[index].isDeleted = true;
			return;
		}
	}
}
