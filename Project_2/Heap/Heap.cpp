#include <iostream>
#include "Heap.hpp"
#include <optional>

Heap::Heap(){
    capacity = 1000;
    size = 0;
    data = new heapNode*[capacity];
}

Heap::~Heap(){
    for (int i = 0; i < size; i++){
        delete data[i];
    }
    delete[] data;
}

void Heap::insert(int key, int value) {
    if (size == capacity){
        resize();
    }
    heapNode* newNode = new heapNode();
    newNode -> value = value;
    newNode -> key = key;
    data[size] = newNode;

    siftUp(size);

    size = size + 1;
}

void Heap::siftUp(int index){
    int parent_index;
    while(index > 0){
        parent_index = (index - 1) / 2;
        if (data[parent_index] -> key < data[index] -> key){
            swap(parent_index, index);
        }else{
            break;
        }
        index = parent_index;
    }
}

heapNode* Heap::peek(){
    return data[0];
}



heapNode* Heap::find(int value){
    for(int i = 0; i < size; i++){
        if (data[i] -> value == value){
            return data[i];
        }
    }
    return nullptr;

}

void Heap::buildHeap(){
    for(int i = size/2 - 1; i >= 0; i--){
        heapify(i);
    }
}

void Heap::heapify(int i){
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
        heapify(largest);
    }
}




heapNode* Heap::extractMax(){
    heapNode* extracted_node =  data[0];
    deleteMax();
    return extracted_node;
};

void Heap::deleteMax(){
    if (size > 1){

        data[0] = data[size-- - 1];

        heapify(0);

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

void Heap::changeValue(int node_index, int value){
    data[node_index] -> value = value;
}

void Heap::changeKey(heapNode* node_ptr, int key){
    if(key > node_ptr -> key){
        node_ptr -> key = key;
        siftUp(findIndex(node_ptr));
    }else{
        node_ptr -> key = key;
        heapify(findIndex(node_ptr));
    }
}

void Heap::changeKey(int node_index, int new_key){
    if(new_key == data[node_index] -> key){
        return;
    }else if(new_key > data[node_index] -> key){
        data[node_index] -> key = new_key;
        siftUp(node_index);
    }else{
        data[node_index] -> key = new_key;
        heapify(node_index);
    }
}

int Heap::findIndex(heapNode* node_ptr){
    for(int i = 0; i < size; i++){
        if(data[i] == node_ptr){
            return i;
        }
    }
    return -1;
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

void Heap::deleteLast(){
    delete data[size--];
}