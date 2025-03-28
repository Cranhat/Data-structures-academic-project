#include <iostream>
#include "Double linked list.cpp"

int main(){
    DoubleLinkedList dll(5);
    printf("%d\n", dll.getSize());
    printf("dll.elementFromFront: %d\n", dll.elementFromFront() -> data);
    dll.addFront(10);
    
    printf("dll.elementFromFront: %d\n", dll.elementFromFront() -> data);
    dll.addFront(20);
    Node* after_20 = dll.elementFromFront();
    printf("dll.elementFromFront: %d\n", dll.elementFromFront() -> data);
    dll.addFront(30);
    
    
    printf("dll.elementFromFront: %d\n", dll.elementFromFront() -> data);
    dll.printElements();
    dll.addBack(40);
    printf("dll.elementFromBack: %d\n", dll.head -> data);
    printf("\n\n\n");
    dll.printElements();
    printf("dsdasdsa");
    dll.deleteBack();
    dll.printElements();
    printf("dsdasdsav2\n");
    printf("%d\n", dll.getSize());
    // dll.deleteInside(after_20);
    dll.deleteFront();
    dll.printElements();

    return 0;
}