#include <iostream>
#include <string>

#include "Double linked list/Double linked list.cpp"
#include "Testing/Testing.cpp"

using namespace std;


int main(){

    // int values_count = 2;
    // int keys[values_count];
    // float values[values_count];

    // DoubleLinkedList dll(5, 10);

    // Testing testing;

    // double time_elapsed_on_addition;
    // int iteration_count = 1000;
    // double sum;


    // for(int j = 0; j < 2; j++){
    //     sum = 0;
    //     for(int i = 0; i < iteration_count ; i++){
        
    //         time_elapsed_on_addition = testing.test_time(dll, [&dll]() {
    //             dll.addFront(1);
    //         });
    //         dll.deleteFront();
    //         sum += time_elapsed_on_addition;
    //     }
    //     sum = sum/iteration_count;
    //     keys[j] = dll.getSize();
    //     values[j] = sum;
    // }
        
    
    // string saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Results/ddl add element.csv";
    // string key_name = "count";
    // string value_name = "time";

    // testing.save_to_csv(saveFilePath, key_name, value_name, keys, values, values_count);


    
    DDLTests ddl(4, 5);

    ddl.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/100000000.csv", 100000000);

    ddl.printElements();
    


}