#include <iostream>
#include <string>
#include <fstream>

#include "Linked list.hpp"


LinkedList::LinkedList() { //konstruktor 

    head = nullptr;
    tail = nullptr;

}

LinkedList::~LinkedList() { //destruktor 
    while (head != nullptr) {
        deleteFront();
    }
}

void LinkedList::addFront(int value) {//dodanie elemntu na poczatek listy 
    Node* newNode = new Node();
    newNode -> data = value;

    if (head == nullptr){
        newNode -> next = nullptr;
        head = newNode;
    } else if (tail == nullptr){
        newNode -> next = head;
        tail = head;
        head = newNode;
    }else {
        newNode -> next = head;
        head = newNode;
    }
}

void LinkedList::addBack(int value) { //dodanie elementu na koniec listy
    Node* newNode = new Node();
    newNode -> data = value;
    newNode -> next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }else if (tail == nullptr) {
        head -> next = newNode;
        tail = newNode;
    }else{
        tail -> next = newNode;
        tail = newNode;
    }
}

void LinkedList::deleteFront() {//usuniecie pierwszego elemetnu 
    if (head == nullptr) return;
    if (head -> next == nullptr){
        delete head;
        head = nullptr;

    }else if(head -> next == tail){
        delete head;
        head = tail;
        tail = nullptr;
    }else{
        Node* temp_ptr = head -> next;
        delete head;
        head = temp_ptr;
    }
}

void LinkedList::printElements(){
    if (head == nullptr) return;

    Node* next_element = head;
    int i = 0;

    do{

        printf("%dith element = %d\n", i, next_element -> data);
        next_element = next_element -> next; i++;

    }while(next_element != nullptr);
    
}

void LinkedList::deleteBack() { // nie dziala
    if (head == nullptr || head -> next == nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node* next_item = head;

    while(next_item -> next != tail){
        next_item = next_item -> next;

    };

    delete tail;
    tail = next_item;
    tail -> next = nullptr;

}


void LinkedList::deleteIndex(int index) {//usuniecie elemntu losowego
    if (index > getSize()){
        return;
    }else if (index == 0){
        deleteFront();
    }else if (index == getSize()){
        deleteBack();
    }else{

        int counter = 0;
        Node* next_item = head;
        Node* previous_item;

        while (counter++ != index){
            previous_item = next_item;
            next_item = next_item -> next;
        }
        previous_item -> next = next_item -> next;
        delete next_item;
    }
}


void LinkedList::addIndex(int value, int index) {
    if (index > getSize()){
        return;
    }else if (index == getSize() + 1){
        addBack(value);
    }else{
        int counter = 0;
        Node* next_item = head;
        Node* previous_item;
        Node* newNode = new Node();
        while (counter++ != index){
            previous_item = next_item;
            next_item = next_item -> next;
        }
        newNode -> data = value; 
        newNode -> next = next_item;
        previous_item -> next = newNode;
    }
}
int LinkedList::firstElement(){
    return head -> data;
}

int LinkedList::lastElement(){
    return tail -> data;
}   

bool LinkedList::contains(int value){ //wyszukiwanie 
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}


int LinkedList::getSize(){
    Node* next_element = head;

    int size = 1;

    while(next_element -> next != nullptr){

        next_element = next_element -> next;

        size += 1;

    }

    return size;

}

void LinkedList::clear(){
    while (head != nullptr) deleteFront();
}