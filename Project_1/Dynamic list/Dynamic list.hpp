#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

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

	void printElements();

	void addFront(int value); //dodanie elementu na poczatku

	void addBack(int value); //dodanie elementu na koncu 

	void addIndex(int element, int index);

	void deleteBack(); //usuniecie elementu z konca 

	void deleteFront(); //usuniecie elementu z poczatku

	void deleteIndex(int index);

	int getSize();

	int firstElement();

	int lastElement();

	void clear();
	
	bool contains(int value); //sprawdzanie czy element jest w tablicy 

};

#endif 