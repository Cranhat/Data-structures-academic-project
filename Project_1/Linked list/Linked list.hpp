#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "../DataStructure/DataStructure.hpp"


struct NodeLL {
    int data;      //przechowywana wartosc
    NodeLL* next;    //wskaznik na nastepny element

    NodeLL(int value) : data(value), next(nullptr) {} //konstruktor 
};

class LinkedList : public DataStructure {
protected:
    NodeLL* head;  //wskaznik na poczatek listy
    int size;    //liczba elementow

public:
    LinkedList();         //konstruktor 
    ~LinkedList();        //destruktor 

    void addFront(int value); //dodanie elementu na poczatku
    void addBack(int value); //dodanie elementu na koncu 

    void deleteBack(); //usuniecie elementu z konca 
    void deleteFront(); //usuniecie elementu z poczatku

    void deleteRandom(int index);//usuniecie elemnentu z okreslona wartoscia 
    void addRandom(int index, int value);

    void printElements();

    int find(int value) const; //sprawdzanie czy element jest w tablicy 

    void clear();

    int getSize() const;        //Liczba elementow 
};

#endif 
