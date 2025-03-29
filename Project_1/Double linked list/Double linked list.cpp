#include "Double linked list.hpp"
#include <iostream>

DoubleLinkedList::DoubleLinkedList(int head_data, int tail_data){

    head = new Node();
    tail = new Node();

    head -> previous = nullptr;
    head -> next = tail;
    head -> data = head_data;
    tail -> next = nullptr;
    tail -> previous = head;
    tail -> data = tail_data;

    
}

DoubleLinkedList::~DoubleLinkedList(){ // smth is wrong
    while (head != nullptr) {
        deleteFront();
    }
}

Node* DoubleLinkedList::elementFromFront(){

    return tail;

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
    Node* temp_ptr = newNode;
    tail -> next = newNode;
    newNode -> data = value;
    newNode -> next = nullptr;
    newNode -> previous = tail;
    newNode = tail;
    tail = temp_ptr;
    
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
    if (add_after_node != tail){

        Node* temp_node = add_after_node -> next;
        Node* new_node = new Node();

        new_node -> data = value;
        add_after_node -> next = new_node;
        new_node -> next = temp_node;
        temp_node -> previous = new_node;
        new_node -> previous = add_after_node;

    }else {

        addFront(value);

    }
}


void DoubleLinkedList::deleteFront(){

    if (tail != nullptr) {  
        Node* deleted_element_ptr = tail;
        tail = tail->previous; 

        if (tail != nullptr) {
            
            tail->next = nullptr;

        } else {

            head = nullptr; 

        }

        delete deleted_element_ptr;
    }
}

void DoubleLinkedList::deleteBack(){

    if (head -> next != nullptr){

        Node* temp_ptr = head -> next;
        delete head;
        head = temp_ptr;

    }

}

void DoubleLinkedList::deleteInside(Node* delete_after_node){

    if(delete_after_node == tail) printf("recieved tail pointer\n");

    else if ((delete_after_node -> next) == tail){

        deleteFront();

    }else{

        Node* temp_ptr = (delete_after_node -> next) -> next;
        delete delete_after_node -> next;
        delete_after_node -> next = temp_ptr;
        temp_ptr -> previous = delete_after_node;

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