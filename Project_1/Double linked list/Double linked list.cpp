#include "Double linked list.hpp"
#include <iostream>

DoubleLinkedList::DoubleLinkedList(int value){

    head = new Node();
    head -> previous = nullptr;
    head -> next = nullptr;
    head -> data = value;
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

void DoubleLinkedList::printElements(){

    Node* next_element = head;
    int i = 0;

    do{

        printf("%dith element = %d\n", i, next_element -> data);
        next_element = next_element -> next; i++;

    }while(next_element != nullptr);
    
}


void DoubleLinkedList::addFront(int value){

    Node* newNode = new Node();

    elementFromFront() -> next = newNode;
    newNode -> data = value;
    newNode -> next = nullptr;
    newNode -> previous = elementFromFront();
    
}

void DoubleLinkedList::addBack(int value){
    Node* newNode = new Node();

    int head_value = head -> data;

    newNode -> data = value;
    newNode -> next = this -> head;
    newNode -> previous = nullptr;
    this -> head -> previous = newNode;
    this -> head = newNode;
}

void DoubleLinkedList::addInside(Node* add_after_node, int value){
    if (add_after_node -> next == nullptr){

        addFront(value);

    }else{

        Node* temp_node = add_after_node -> next;
        Node* new_node = new Node();

        new_node -> data = value;
        add_after_node -> next = new_node;
        new_node -> next = temp_node;
        temp_node -> previous = new_node;
        new_node -> previous = add_after_node;
    }
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

    if (head -> next != nullptr){

        Node* temp_ptr = head -> next;
        delete(head);
        head = temp_ptr;

    }
}

void DoubleLinkedList::deleteInside(Node* delete_after_node){
    if ((delete_after_node -> next) -> next != nullptr){

        Node* temp_ptr = (delete_after_node -> next) -> next;
        delete delete_after_node -> next;
        delete_after_node -> next = temp_ptr;
        temp_ptr -> previous = delete_after_node;

    }else if ((delete_after_node -> next) != nullptr){
        printf("tryin to delete from front\n");
        deleteFront();
        printf("tryin to delete from front\n");
    }else {

        throw std::invalid_argument( "recieved last node" );

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

Node* DoubleLinkedList::givePointer(){

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