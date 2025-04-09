#include <iostream>
#include <string>

#include "Double linked list/Double linked list.cpp"
#include "Dynamic list/Dynamic list.cpp"
// #include "Linked list/Linked list.cpp"

#include "Testing/Testing.cpp"

using namespace std;


int main(){

    int values_count = 12;
    int iteration_count = 20;
    int keys[values_count];
    float values[values_count];

    DLLTests dll(4, 5);
    // LLTests ll;
    DATests da;

    Testing testing;

    double time_elapsed;
    double sum_of_time_elapsed;

    dll.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 20);
    dll.printElements();
    printf("\n");
    da.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 20);
    da.printElements();

    // for(int j = 1; j <= values_count; j++){
    //     dll.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 5000 * j);
    //     sum_of_time_elapsed = 0;
    //     for(int i = 0; i < iteration_count ; i++){
        
    //         time_elapsed = testing.test_time(dll, [&dll]() {
    //             dll.addFront(1);
    //         });
    //         dll.deleteFront();
    //         sum_of_time_elapsed += time_elapsed;
    //     }
    //     sum_of_time_elapsed = sum_of_time_elapsed/iteration_count;
    //     keys[j] = dll.getSize();
    //     values[j] = sum_of_time_elapsed;
    // }
        
    
    // string saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Results/ddl add element.csv";
    // string key_name = "count";
    // string value_name = "time";
    

    // testing.save_to_csv(saveFilePath, key_name, value_name, keys, values, values_count);


}