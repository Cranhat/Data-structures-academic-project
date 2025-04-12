#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

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

    void printElements();

    void addFront(int value); //dodanie elementu na poczatku

    void addBack(int value); //dodanie elementu na koncu 

    void addIndex(int value, int index);

    void deleteBack(); //usuniecie elementu z konca 

    void deleteFront(); //usuniecie elementu z poczatku

    void deleteIndex(int index);//usuniecie elemnentu z okreslona wartoscia 

    bool contains(int value); //sprawdzanie czy element jest w tablicy 

    int firstElement();

    int lastElement();

    void clear();

    int getSize();        //Liczba elementow 

};

#endif 
