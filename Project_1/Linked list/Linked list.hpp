#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "../DataStructure/DataStructure.hpp"


struct Node {
    int data;      //przechowywana wartosc
    Node* next;    //wskaznik na nastepny element

    Node(int value) : data(value), next(nullptr) {} //konstruktor 
};

class LinkedList : public DataStructure {
protected:
    Node* head;  //wskaznik na poczatek listy
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

    int find(int value) const; //sprawdzanie czy element jest w tablicy 

    int getSize() const;        //Liczba elementow 
};

class LLTests : public LinkedList {
    public:
    using LinkedList::LinkedList;

    void allocate_from_csv(std::string FilePath, int size);
};

#endif 
