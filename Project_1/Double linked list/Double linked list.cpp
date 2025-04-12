#include <iostream>
#include <string>
#include <fstream>

#include "Double linked list.hpp"

DoubleLinkedList::DoubleLinkedList(){

    head = nullptr;
    tail = nullptr;

}

DoubleLinkedList::~DoubleLinkedList(){
    while (head != nullptr) {
        deleteBack();
    }
}

int DoubleLinkedList::firstElement(){

    return head -> data;

}

int DoubleLinkedList::lastElement(){

    return tail -> data;

}

void DoubleLinkedList::printElements(){
    if (head == nullptr) return;
    
    Node* next_element = head;
    int i = 0;

    do{

        printf("%dith element = %d\n", i, next_element -> data);
        next_element = next_element -> next; i++;

    }while(next_element != nullptr);
    
}

void DoubleLinkedList::addFront(int value){
    Node* newNode = new Node();
    newNode -> data = value;
    newNode -> previous = nullptr;

    if (head == nullptr){
        newNode -> next = nullptr;
        head = newNode;
    } else if (tail == nullptr){
        newNode -> next = head;
        head -> previous = newNode;
        tail = head;
        head = newNode;
    }else {
        newNode -> next = head;
        head -> previous = newNode;
        head = newNode;
    }
}

void DoubleLinkedList::addBack(int value){
    Node* newNode = new Node();
    newNode -> data = value;
    newNode -> next = nullptr;

    if (head == nullptr) {
        newNode -> previous = nullptr;
        head = newNode;
    }else if (tail == nullptr) {
        newNode -> previous = head;
        head -> next = newNode;
        tail = newNode;
    }else{
        newNode -> previous = tail;
        tail -> next = newNode;
        tail = newNode;
    }
}

void DoubleLinkedList::deleteBack(){  
    if (head == nullptr){
        return;
    }
    if (head -> next == nullptr){

        delete head;

        head = nullptr;

        tail = nullptr;

        return;
    }
    else if (head -> next == tail){

        delete tail;

        head -> next = nullptr;

        tail = nullptr;

        return;
    }


    Node* new_tail = tail -> previous;
    new_tail -> next = nullptr;
    delete tail;
    tail = new_tail;

}



void DoubleLinkedList::deleteFront(){ 
    if (head == nullptr) return;
    if (head -> next == nullptr){
        delete head;
        head = nullptr;

    }else if(head -> next == tail){
        delete head;
        head = tail;
        head -> previous = nullptr;
        tail = nullptr;
    }else{
        Node* temp_ptr = head -> next;
        delete head;
        head = temp_ptr;
        head -> previous = nullptr;
    }
}
void DoubleLinkedList::deleteIndex(int index){
    if (index > getSize()){
        return;
    }else if (index == 0){
        deleteFront();
    }else if (index == getSize()){
        deleteBack();
    }else{

        int counter = 0;
        Node* next_item = head;

        while (counter++ != index){
            next_item = next_item -> next;
        }
        (next_item -> previous) -> next = next_item -> next;
        (next_item -> next) -> previous = next_item -> previous;
        delete next_item;
    }
}

void DoubleLinkedList::addIndex(int value, int index){

    if (index > getSize()){
        return;
    }else if (index == getSize() + 1){
        addBack(value);
    }else{
        int counter = 0;
        Node* next_item = head;
        Node* newNode = new Node();
        while (counter++ != index){
            next_item = next_item -> next;
        }
        newNode -> data = value; 
        newNode -> next = next_item;
        newNode -> previous = next_item -> previous;

        (next_item -> previous) -> next = newNode;
        next_item -> previous = newNode;

    }
}


bool DoubleLinkedList::contains(int value){

    Node* next_element = head;

    while(next_element -> next != nullptr){

        if (next_element -> data == value) return true;

        next_element = next_element -> next;

    }

    return false;
    
}

Node* DoubleLinkedList::givePointer(int value){ 

    Node* next_element = head;

    while(next_element -> next != nullptr){

        if (next_element -> data == value) return next_element;

        next_element = next_element -> next;

    }

    return nullptr;


    
}



int DoubleLinkedList::getSize(){

    Node* next_element = head;

    int size = 1;

    while(next_element -> next != nullptr){

        next_element = next_element -> next;

        size += 1;

    }

    return size;

}

void DoubleLinkedList::clear(){
    
    while(head != nullptr) deleteFront();

}

