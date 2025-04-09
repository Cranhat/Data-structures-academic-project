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
        deleteFront();
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

void DoubleLinkedList::addFront(int value){ //good
    if (head == nullptr){
        head = new Node();
        head -> previous = nullptr;
        head -> next = nullptr;
        head -> data = value;

    }else if (tail == nullptr){
        tail = new Node();
        int head_value = head -> data;

        Node* temp_ptr = tail;

        tail -> data = value;
        tail -> next = head;
        tail -> previous = nullptr;
        tail = head;
        head = temp_ptr;
        
    }else{
        Node* newNode = new Node();
        Node* temp_ptr = head;

        newNode -> data = value;
        newNode -> next = head;
        newNode -> previous = nullptr;
        head -> previous = newNode;
        head = newNode;
        newNode = temp_ptr;
    }
}

void DoubleLinkedList::addBack(int value){ // good
    Node* newNode = new Node();
    Node* temp_ptr = newNode;

    tail -> next = newNode;
    newNode -> data = value;
    newNode -> next = nullptr;
    newNode -> previous = tail;
    newNode = tail;
    tail = temp_ptr;
    
}


void DoubleLinkedList::addInside(Node* add_after_node, int value){ // good 
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


void DoubleLinkedList::deleteBack(){  // for god's sake why can't you work like other functions...
    if (head == nullptr){
        return;
    }
    else if (head -> next == nullptr){

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

    if (tail == nullptr) {
        tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
    }

    Node* new_tail = tail -> previous;
    new_tail -> next = nullptr;
    delete tail;
    tail = new_tail;

}

void DoubleLinkedList::deleteFront(){ // good

    if (head -> next != nullptr){

        Node* temp_ptr = head -> next;
        delete head;
        head = temp_ptr;
        head -> previous = nullptr;

    }else{

        delete head;

    }

}

void DoubleLinkedList::deleteInside(Node* delete_after_node){ // good

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

bool DoubleLinkedList::contains(int value){ // good 

    Node* next_element = head;

    while(next_element -> next != nullptr){

        if (next_element -> data == value) return true;

        next_element = next_element -> next;

    }

    return false;
    
}

Node* DoubleLinkedList::givePointer(int value){ // good

    Node* next_element = head;

    while(next_element -> next != nullptr){

        if (next_element -> data == value) return next_element;

        next_element = next_element -> next;

    }

    return nullptr;

}

int DoubleLinkedList::getSize(){  // good 

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

    while (getSize() > 0){

        deleteFront();

    }
    
    while (myFile >> number && count < size){
        addBack(number);
        count++;
    }

    
    myFile.close();

};
