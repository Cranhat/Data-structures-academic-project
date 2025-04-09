#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include "../DataStructure/DataStructure.hpp"

class DynamicArray : public DataStructure {
protected:
	int* data; // wskaznik na dynamiczna tablice
	int size; // aktualny rozmiar tablicy
	int capacity; // max pojemnosc 

	void resize(); //powiekszanie tablicy
public:
	DynamicArray(); //konstruktor
	~DynamicArray(); //dekonstruktor

	void addFront(int value); //dodanie elementu na poczatku
	void addBack(int value); //dodanie elementu na koncu 

	void deleteBack(); //usuniecie elementu z konca 
	void deleteFront(); //usuniecie elementu z poczatku

	void printElements();
	int getSize();

	void addRandom(int index, int element);
	void deleteRandom(int index);

	int find(int value) const; //sprawdzanie czy element jest w tablicy 
};

class DATests : public DynamicArray {
	public:

	using DynamicArray::DynamicArray;

    void allocate_from_csv(std::string FilePath, int size);
};

#endif 