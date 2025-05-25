#pragma once

#include "../DataStructure/DataStructure.hpp"

struct arrayNode : public NodeBase{
    ~arrayNode() {}
};

class DynamicArray : public DataStructure {
protected:

	arrayNode** data;
	int size; 
	int capacity;

	void resize();

public:

	DynamicArray();

	~DynamicArray();

	void printElements();

    void insert(int key, int value);

	void addFront(int value);

	void addHash(int key, int value);

	void addBack(int value);

	void addIndex(int element, int index);

	void deleteBack();

	void deleteFront();

	void deleteIndex(int index);

	int getSize();

	int firstElement();

	int lastElement();

	void clear();
	
	bool contains(int value);

    arrayNode* extractMax();

    arrayNode* peek();

    arrayNode* find(int value);
    
    void changeKey(arrayNode* node_ptr, int newKey);

    void changeKey(int node_index, int newKey);

    void changeValue(arrayNode* node_ptr, int newValue);

    void changeValue(int node_index, int newValue);

    int findIndex(arrayNode* node_ptr);

    void deleteLast();

	NodeBase* getRandom();

	void allocate_from_csv(std::string dataFilePath, int elements_allocated, int new_capacity);
};