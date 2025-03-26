#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

class DynamicArray {
private:
	int* data; // wskaznik na dynamiczna tablice
	int size; // aktualny rozmiar tablicy
	int capacity; // max pojemnosc 

	void Resize(); //powiêkszanie tablicy
public:
	DynamicArray(); //konstruktor
	~DynamicArray(); //dekonstruktor

	void AddFront(int value); //dodanie elementu na poczatku
	void AddBack(int value); //dodanie elementu na koncu 

	void DeleteBack(); //usuniecie elementu z konca 
	void DeleteFront(); //usuniecie elementu z poczatku

	void AddRandom(int index, int element);
	void DeleteRandom(int index);

	int Find(int value) const; //sprawdzanie czy element jest w tablicy 
};

#endif 