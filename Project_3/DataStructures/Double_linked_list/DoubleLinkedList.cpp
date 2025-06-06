#include <iostream>
#include <string>

#include "DoubleLinkedList.hpp"

DoubleLinkedList::DoubleLinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

DoubleLinkedList::~DoubleLinkedList(){

    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int DoubleLinkedList::firstElement(){
    return head -> value;
}

int DoubleLinkedList::lastElement(){
    return tail -> value;
}

void DoubleLinkedList::printElements(){
    if (head == nullptr) return;

    Node* next_element = head;
    int i = 0;

    do{
        printf("%dith element = %d\n", i, next_element -> value);
        next_element = next_element -> next; i++;

    }while(next_element != nullptr);
    
}

void DoubleLinkedList::addFront(int key, int value){
    Node* newNode = new Node();
    newNode -> value = value;
    newNode -> key = key;
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
    size++;
}

void DoubleLinkedList::addBack(int key, int value){
    Node* newNode = new Node();
    newNode -> value = value;
    newNode -> key = key;
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
    size++;
}

void DoubleLinkedList::deleteElement(int key, int value){  

    Node* current = head;

    while (current != nullptr){
        if (current -> key == key && current -> value == value){
            if (current -> previous != nullptr){
                current -> previous -> next = current -> next;
            }else{
                head = current -> next;
            }
            if (current -> next != nullptr){
                current->next->previous = current->previous;
            }
            delete current;
            size--;
            return;
        }
        current = current -> next;
    }   
    
    std::cout << "not found" << std::endl;
}

void DoubleLinkedList::deleteBack(){  
    if (head == nullptr){
        return;
    }
    if (head -> next == nullptr){
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return;
    }
    else if (head -> next == tail){
        delete tail;
        head -> next = nullptr;
        tail = nullptr;
        size--;
        return;
    }

    Node* new_tail = tail -> previous;
    new_tail -> next = nullptr;
    delete tail;
    tail = new_tail;
    size--;
}

void DoubleLinkedList::addHash(int number, int key){}

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
    size--;
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
        size--;
    }
}

void DoubleLinkedList::addIndex(int key, int value, int index){

    if (index > getSize()){
        return;
    }else if (index == getSize() + 1){
        addBack(key, value);
    }else{
        int counter = 0;
        Node* next_item = head;
        Node* newNode = new Node();
        while (counter++ != index){
            next_item = next_item -> next;
        }
        newNode -> value = value; 
        newNode -> key = key;
        newNode -> next = next_item;
        newNode -> previous = next_item -> previous;
        (next_item -> previous) -> next = newNode;
        next_item -> previous = newNode;
    }
    size++;
}


bool DoubleLinkedList::contains(int key, int value){
    Node* next_element = head;
    while(next_element -> next != nullptr){
        if (next_element -> value == value) return true;
        next_element = next_element -> next;
    }

    return false;

}

Node* DoubleLinkedList::givePointer(int value){ 
    Node* next_element = head;
    while(next_element -> next != nullptr){
        if (next_element -> value == value) return next_element;
        next_element = next_element -> next;
    }
    return nullptr;
}



int DoubleLinkedList::getSize(){
    return size;
}

void DoubleLinkedList::clear(){
    while(head != nullptr) deleteFront();
    size = 0;
}

Node* DoubleLinkedList::getRandom(){
    int break_value = rand() % size;
    int i = 0;
    Node* next_element = head;

    while(i++ < break_value){
        next_element = next_element -> next;

    }
    return next_element;
}

void DoubleLinkedList::allocate_from_csv(std::string dataFilePath, int elements_allocated, int new_capacity){}
