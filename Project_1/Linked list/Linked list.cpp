#include "Linked list.hpp"
#include <fstream>

LinkedList::LinkedList() { //konstruktor 
    head = nullptr;
    size = 0;
}

LinkedList::~LinkedList() { //destruktor 
    while (head != nullptr) {
        deleteFront();
    }
}

void LinkedList::addFront(int value) {//dodanie elemntu na poczatek listy 
    NodeLL* newNodeLL = new NodeLL(value);
    newNodeLL->next = head;
    head = newNodeLL;
    size++;
}

void LinkedList::addBack(int value) { //dodanie elementu na koniec listy
    NodeLL* newNodeLL = new NodeLL(value);
    if (head == nullptr) {
        head = newNodeLL;
    }
    else {
        NodeLL* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNodeLL;
    }
    size++;
}

void LinkedList::deleteFront() {//usuniecie pierwszego elemetnu 
    if (head != nullptr) {
        NodeLL* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

void LinkedList::printElements(){

    NodeLL* next_element = head;
    int i = 0;

    do{

        printf("%dith element = %d\n", i, next_element -> data);
        next_element = next_element -> next; i++;

    }while(next_element != nullptr);
    
}

void LinkedList::deleteBack() {//usuniecie ostatniego elementu 
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    }
    else {
        NodeLL* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    size--;
}

void LinkedList::deleteRandom(int value) {//usuniecie elemntu losowego
    if (head == nullptr) return;

    if (head->data == value) {
        deleteFront();
        return;
    }

    NodeLL* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next != nullptr) {
        NodeLL* temp = current->next;
        current->next = current->next->next;
        delete temp;
        size--;
    }
}


void LinkedList::addRandom(int index, int value) {
    if (index < 0 || index > size) {
        std::cout << "Invalid index!" << std::endl;
        return;  
    }

    NodeLL* newNodeLL = new NodeLL(value);
    newNodeLL->data = value;
    newNodeLL->next = nullptr;

    if (index == 0) {
        newNodeLL->next = head;
        head = newNodeLL;
    }
    else {
        NodeLL* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNodeLL->next = current->next;
        current->next = newNodeLL;
    }

    size++;  
}



int LinkedList::find(int value) const { //wyszukiwanie 
    NodeLL* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}


int LinkedList::getSize() const {
    return size;
}

void LLTests::allocate_from_csv(std::string FilePath, int size){
    std::ifstream myFile(FilePath.c_str(), std::ios::in);

    int number;
    int count = 0;

    while (getSize() > 0){

        deleteBack();

    }
    
    while (myFile >> number && count < size){
        addFront(number);
        count++;
    }
    
    myFile.close();

};
