#include <iostream>
#include <string>

#include "Double Linked list.cpp"

using namespace std;


int main(){
    DoubleLinkedList dll;

    dll.addFront(9);

    dll.addFront(8);

    dll.addFront(7);

    dll.addFront(6);

    dll.deleteBack();

    printf("first element: %d, last element: %d\n", dll.firstElement() -> data, dll.lastElement() -> data);

    dll.printElements();



    return 0;
}