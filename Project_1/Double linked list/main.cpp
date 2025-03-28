#include <iostream>
#include "Double linked list.cpp"

int main(){
    DoubleLinkedList dll(5);
    printf("dll.elementFromFront: %d\n", dll.elementFromFront() -> data);
    dll.addFront(10);
    printf("dll.elementFromFront: %d\n", dll.elementFromFront() -> data);
    dll.addFront(20);
    printf("dll.elementFromFront: %d\n", dll.elementFromFront() -> data);
    dll.addFront(30);
    printf("dll.elementFromFront: %d\n", dll.elementFromFront() -> data);
    printf("dsdasdsa");

    return 0;
}