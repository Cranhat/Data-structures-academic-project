#include "Dynamic list.hpp"
#include <iostream>

using namespace std; 

DynamicArray::DynamicArray() {
	capacity = 10;
	size = 0;
	data = new int[capacity];
}

DynamicArray::~DynamicArray() {
	delete[] data;
}

void DynamicArray::Resize() {
	capacity = capacity * 2;
	int* newData = new int[capacity];

	for (int i = 0; i < size; i++) {
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
}

void DynamicArray::AddFront(int value) {
	if (size == capacity) {
		Resize();
	}
	else {
		for (int i = size; i > 0; i++) {
			data[i] = data[i - 1];
		}
		data[0] = value;
		size++;
	}
}

void DynamicArray::AddBack(int value) {
	if (size == capacity) {
		Resize();
	}
	else {
		data[size] = value;
		size++;
	}
}

void DynamicArray::DeleteFront() {
	if (size > 0) {
		for (int i = 0, i < size, i++) {
			data[i] = data[i + 1];
		}
		size--;
	}
}

void DynamicArray::DeleteBack() {
	if (size > 0) {
		size--;
	}
}

void DynamicArray::AddRandom(int index, int element) {
	if (index < 0 || index > size) {
		cout << "Nieprawid³owy indeks!" << endl;
		return;
	}
	if (size == capacity) {
		resize();
	}
	for (int i = size; i > index; i--) {
		data[i] = data[i - 1];
	}
	data[index] = element;
	size++;
}

void DynamicArray::DeleteRandom(int index) {
	if (index < 0 || index >= size) {
		cout << "Nieprawid³owy indeks!" << endl;
		return;
	}
	for (int i = index; i < size - 1; i++) {
		data[i] = data[i + 1];
	}
	size--;
}

int DynamicArray::Find(int value) const {
	for (int i = 0; i < size; i++) {
		if (data[i] == value) {
			return i;
		}
	}
	return -1;
}