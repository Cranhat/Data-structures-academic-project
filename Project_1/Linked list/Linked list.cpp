#include "Linked list.hpp"

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
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;
}

void LinkedList::addBack(int value) { //dodanie elementu na koniec listy
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

void LinkedList::deleteFront() {//usuniecie pierwszego elemetnu 
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

void LinkedList::deleteBack() {//usuniecie ostatniego elementu 
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    }
    else {
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    size--;
}

void LinkedList::deleteValue(int value) {//usuniecie elemntu o wskazanej wartosci 
    if (head == nullptr) return;

    if (head->data == value) {
        deleteFront();
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        size--;
    }
}

int LinkedList::find(int value) const { //wyszukiwanie 
    Node* current = head;
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
