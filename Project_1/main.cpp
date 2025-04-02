#include <iostream>
#include <vector>
#include <random>
#include "Dynamic list.hpp"
#include "Linked list.hpp"

using namespace std;

int main(){
	// ======================Dodawanie elementow na pocz¹tek========================
	DynamicArray dynamicarray;
	LinkedList linkedlist;


	for (int i = 0; i <= 70; ++i) {
		dynamicarray.AddFront(i); //dodawanie elementow do pustej listy
		linkedlist.addFront(i);
		}

	//czas start
	dynamicarray.AddFront(4); //mierzenie czasu dodawania 
	//czas stop

	//czas start
	linkedlist.addFront(4); //mierzenie czasu dodawania 
	//czas stop



	// ======================Dodawanie elementow na koniec========================

	DynamicArray dynamicarray;
	LinkedList linkedlist;

	for (int i = 0; i <= 70; ++i) {
		dynamicarray.AddBack(i);
		linkedlist.addBack(i);
	}

	//czas start
	dynamicarray.AddBack(4); //mierzenie czasu dodawania 
	//czas stop

	//czas start
	linkedlist.addBack(4); //mierzenie czasu dodawania 
	//czas stop


	//======================Usuwanie elementow z pocz¹tku========================
	DynamicArray dynamicarray;
	LinkedList linkedlist;

	for (int i = 0; i <= 70; ++i) {
		dynamicarray.AddBack(i);
		linkedlist.addBack(i);//dodawanie elementow do pustej listy
	}

	//czas start
	dynamicarray.DeleteFront(); //mierzenie czasu dodawania 
	//czas stop

	//czas start
	linkedlist.deleteFront(); //mierzenie czasu dodawania 
	//czas stop


	//======================Usuwanie elementow z koñca=======================
	DynamicArray dynamicarray;
	LinkedList linkedlist;

	for (int i = 0; i <= 70; ++i) {
		dynamicarray.AddBack(i);
		linkedlist.addBack(i)//dodawanie elementow do pustej listy
	}

	//czas start
	dynamicarray.DeleteBack(); //mierzenie czasu usuwania
	//czas stop

	//czas start
	linkedlist.deleteBack(); //mierzenie czasu usuwania
	//czas stop


	//======================Dodawanie elementów losowo=======================
	DynamicArray dynamicarray;
	LinkedList linkedlist;

	for (int i = 0; i <= 70; ++i) {
		dynamicarray.AddBack(i);
		linkedlist.addBack(i);//dodawanie elementow do pustej listy
	}

	int index = rand() % 70;
	int x = 5;
	//czas start
	dynamicarray.AddRandom(index,x); //mierzenie czasu dodawania  na losowej pozycji 
	//czas stop

	//czas start
	linkedlist.addRandom(index,x); //mierzenie czasu dodawania na losowej pozycji
	//czas stop



	//======================Usuwanie elementów losowo=======================
	DynamicArray dynamicarray;
	LinkedList linkedlist;

	for (int i = 0; i <= 70; ++i) {
		dynamicarray.AddBack(i);
		linkedlist.addBack(i);//dodawanie elementow do pustej listy
	}

	int index = rand() % 70;
	
	//czas start
	dynamicarray.DeleteRandom(index); //mierzenie czasu dodawania  na losowej pozycji 
	//czas stop

	//czas start
	linkedlist.deleteRandom(index); //mierzenie czasu dodawania na losowej pozycji
	//czas stop




	//======================Wyszukiwanie danego elementu=======================
	DynamicArray dynamicarray;
	LinkedList linkedlist;

	for (int i = 0; i <= 70; ++i) {
		dynamicarray.AddBack(i);
		linkedlist.addBack(i);//dodawanie elementow do pustej listy
	}

	//czas start
	dynamicarray.Find(12); //wyszukiwanie czy element "12" znajduje sie w tablicy 
	//czas stop

	//czas start
	linkedlist.find(12); //wyszukiwanie czy element "12" znaduje sie w liscie 
	//czas stop




}