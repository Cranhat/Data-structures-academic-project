#include "Double linked list.hpp"

DoubleLinkedList::DoubleLinkedList(int data){
    head = new Node();
    head -> previous = nullptr;
    head -> next = nullptr;
}

DoubleLinkedList::~DoubleLinkedList(){
    while (this -> head != nullptr) {
        deleteFront();
    }
}

Node* DoubleLinkedList::elementFromFront(){
    Node* next_element = head;
    while(next_element -> next != nullptr){
        next_element = next_element -> next;
    }
    return next_element;
}


void DoubleLinkedList::addFront(int value){
    Node* newNode = new Node();
    elementFromFront() -> next = newNode;
    newNode -> data = value;
    newNode -> next = nullptr;
    newNode -> previous = elementFromFront();
    
}

void DoubleLinkedList::addBack(int value){
    
}

void DoubleLinkedList::addInside(int value){
    
}

void DoubleLinkedList::addMiddle(int value){
    
}

void DoubleLinkedList::deleteFront(){
    Node* next_to_be_deleted =  elementFromFront();
    do{
        Node* temp_ptr = next_to_be_deleted -> previous;
        delete next_to_be_deleted;
        next_to_be_deleted = temp_ptr;
    }while(next_to_be_deleted != head);
}

void DoubleLinkedList::deleteBack(){
    
}

void DoubleLinkedList::deleteInside(){
    
}

void DoubleLinkedList::deleteMiddle(){
    
}

bool DoubleLinkedList::contains(int value){

}

Node* DoubleLinkedList::givePointer(){

}

int DoubleLinkedList::getSize(){
    
}