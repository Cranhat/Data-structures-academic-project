#include <iostream>

#include "Double linked list/Double linked list.cpp"
#include "Testing/Testing.cpp"

using namespace std;

int some_function(int number){
    return number * 2;
}

int main(){
    DoubleLinkedList dll(5, 10);

    Testing testing;

    double time_elapsed_on_addition;

    for(int i = 0; i < 100; i++){
        time_elapsed_on_addition = testing.test_time(dll, [&dll]() {
            for(int j = 0; j < 100; j++){
                dll.addFront(10);
            }
        });
        dll.deleteFront();
    
    
        printf("time elapsed: %.20fs\n", time_elapsed_on_addition);
    }

    

}