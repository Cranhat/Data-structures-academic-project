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

Node* DoubleLinkedList::firstElement(){

    return head;

}

Node* DoubleLinkedList::lastElement(){

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

        addBack(value);

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

void DoubleLinkedList::deleteInside(Node* delete_after_node){

    if(delete_after_node == tail) printf("recieved tail pointer\n");

    else if ((delete_after_node -> next) == tail){

        deleteBack();

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

void DLLTests::allocate_from_csv(std::string FilePath, int size){
    std::ifstream myFile(FilePath.c_str(), std::ios::in);

    int number;
    int count = 0;

    while (head != nullptr){

        deleteBack();

    }
    
    while (myFile >> number && count < size){
        addBack(number);
        count++;
    }

    
    myFile.close();

};
