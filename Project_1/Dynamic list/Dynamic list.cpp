#include "Dynamic list.hpp"
#include <iostream>
#include <fstream>

DynamicArray::DynamicArray() {
	capacity = 10;
	size = 0;
	data = new int[capacity];
}

DynamicArray::~DynamicArray() {
	delete[] data;
}

void DynamicArray::resize() { //zwiekszanie rozmiaru
	capacity = capacity * 2;
	int* newData = new int[capacity];

	for (int i = 0; i < size; i++) {
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
}

int DynamicArray::getSize(){
	return size;
} 

void DynamicArray::addFront(int value) {//dodawanie wartosci na poczatek
	if (size == capacity) {

		resize();
	}

	for (int i = size; i > 0; i--) {

		data[i] = data[i - 1];
	}
	data[0] = value;
	size++;
}

void DynamicArray::printElements(){
	for(int i = 0; i < size; i++){
		printf("%dith element = %d\n", i, data[i]);
	}
}

void DynamicArray::addBack(int value) {//dodawnaie wartosci na koniec
	if (size == capacity) {
		resize();
		data[size] = value;
		size++;
	}
	else {
		data[size] = value;
		size++;
	}
}

void DynamicArray::deleteFront() {//usuwanie z poczatku
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			data[i] = data[i + 1];
		}
		size--;
	}
}

void DynamicArray::deleteBack() {//usuwanie z konca 
	if (size > 0) {
		size--;
	}
}

void DynamicArray::addRandom(int index, int element) {//dodawanie elementu na losowa pozycje
	if (index < 0 || index > size) {
		std::cout << "Nieprawidłowy indeks!" << std::endl;
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

void DynamicArray::deleteRandom(int index) {//usuwanie elementu z losowej pozycji
	if (index < 0 || index >= size) {
		std::cout << "Nieprawidłowy indeks!" << std::endl;
		return;
	}
	for (int i = index; i < size - 1; i++) {
		data[i] = data[i + 1];
	}
	size--;
}

int DynamicArray::find(int value) const {//wyszukiwanie danego elementu
	for (int i = 0; i < size; i++) {
		if (data[i] == value) {
			return i;
		}
	}
	return -1;
}

void DynamicArray::clear(){
	delete[] data;
	capacity = 10;
	size = 0;
	data = new int[capacity];
}