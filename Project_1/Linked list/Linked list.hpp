#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
using namespace std;

struct Node {
    int data;      //przechowywana wartosc
    Node* next;    //wskaznik na nastepny element

    Node(int value) : data(value), next(nullptr) {} //konstruktor 
};

class LinkedList {
private:
    Node* head;  //wskaznik na poczatek listy
    int size;    //liczba elementow

public:
    LinkedList();         //konstruktor 
    ~LinkedList();        //destruktor 

    void AddFront(int value); //dodanie elementu na poczatku
    void AddBack(int value); //dodanie elementu na koncu 

    void DeleteBack(); //usuniecie elementu z konca 
    void DeleteFront(); //usuniecie elementu z poczatku

    void DeleteValue(int index);//usuniecie elemnentu z okreslona wartoscia 

    int Find(int value) const; //sprawdzanie czy element jest w tablicy 

    int getSize() const;        //Liczba elementow 
};

#endif 
