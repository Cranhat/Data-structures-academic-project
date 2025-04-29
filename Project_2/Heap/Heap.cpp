#include <iostream>
#include "Heap.hpp"
#include <optional>


Heap::Heap(){
    capacity = 10;
    size = 0;
    data = new heapNode*[capacity];
}

Heap::~Heap(){
    delete[] data;
}

void Heap::insert(int key, int value) {
    if (size == capacity){
        resize();
    }
    heapNode* newNode = new heapNode();
    newNode -> value = value;
    newNode -> key = key;
    data[size++] = newNode;

    buildHeap();
}

int Heap::findMax(){
    return data[0] -> value;
}
void Heap::buildHeap(){
    for(int i = size/2 - 1; i >= 0; i--){
        heapify(size, i);
    }
}

heapNode* Heap::find(int value){
    for(int i = 0; i < size; i++){
        if (data[i] -> value == value){
            return data[i];
        }
    }
    return nullptr;

}

void Heap::heapify(int size, int i){
    int largest = i;
    int leftNode = i * 2 + 1;
    int rightNode = i * 2 + 2;

    if (leftNode < size && data[leftNode] -> key > data[largest] -> key){
        largest = leftNode;
    }
    if (rightNode < size && data[rightNode] -> key > data[largest] -> key){
        largest = rightNode;
    }
    if (largest != i){
        swap(i, largest);

        heapify(size, largest);
    }
}

int Heap::extractMax(){
    heapNode* extracted_node =  data[0];
    deleteMax();
    return extracted_node -> value;
};

void Heap::deleteMax(){
    if (size > 1){

        data[0] = data[size-- - 1];

        heapify(size, 0);

    }else if (size == 1){

        data[0] = nullptr;
        size--;

    }else{
        
        printf("exception");
    }
}

int Heap::getSize(){
    return size;
}   

void Heap::changeValue(heapNode* node_ptr, int value){
    node_ptr -> value = value;
}

void Heap::changeKey(heapNode* node_ptr, int key){
    node_ptr -> key = key;
    buildHeap();

}

void Heap::resize() {
	capacity = capacity * 2;
	heapNode** newData = new heapNode*[capacity];

	for (int i = 0; i < size; i++) {
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
}

void Heap::clear(){
    delete[] data;

    capacity = 10;
    size = 0;
    data = new heapNode*[capacity];
}

void Heap::swap(int firstIndex, int secondIndex){
    heapNode* tempNode = data[firstIndex];
    data[firstIndex] = data[secondIndex];
    data[secondIndex] = tempNode;
}  

void Heap::printElements(){
	for(int i = 0; i < size; i++){
		printf("%dith element = %d, key = %d\n", i, data[i] -> value, data[i] -> key);
	}
}