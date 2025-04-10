#include <iostream>
#include <string>

#include "Double linked list/Double linked list.cpp"
#include "DataStructure/DataStructure.cpp"
#include "Dynamic list/Dynamic list.cpp"
#include "Linked list/Linked list.cpp"
#include "Utilities/Utilities.cpp"

#include "Testing/Testing.cpp"


int main(){

    int values_count = 12;
    int iteration_count = 10;
    int keys[values_count];
    double values[values_count];
    double time_elapsed;
    double sum_of_time_elapsed;
    string key_name = "count";
    string value_name = "time";


    
    DoubleLinkedList dll;
    LinkedList ll;
    DynamicArray da;




    allocate_from_csv(dll, "C:/Users/cypri/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 10);

    dll.printElements();

    allocate_from_csv(ll, "C:/Users/cypri/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 10);

    ll.printElements();

    allocate_from_csv(da, "C:/Users/cypri/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 10);

    da.printElements();
  

    // // addFront(1) for ddl
    // for(int j = 0; j < values_count; j++){
    //     dll.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 5000 * (j + 1));
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
    // string saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Results/dll addFront.csv";

    // testing.save_to_csv(saveFilePath, key_name, value_name, keys, values, values_count);

    // // deleteFront for ddl
    // for(int j = 0; j < values_count; j++){
    //     dll.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 5000 * (j + 1));
    //     sum_of_time_elapsed = 0;
    //     for(int i = 0; i < iteration_count ; i++){
        
    //         time_elapsed = testing.test_time(dll, [&dll]() {
    //             dll.deleteFront();
    //         });
    //         dll.addFront(1);
    //         sum_of_time_elapsed += time_elapsed;
    //     }
    //     sum_of_time_elapsed = sum_of_time_elapsed/iteration_count;
    //     keys[j] = dll.getSize();
    //     values[j] = sum_of_time_elapsed;
    // }
    // saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Results/dll deleteFront.csv";
    // testing.save_to_csv(saveFilePath, key_name, value_name, keys, values, values_count);

    // // addBack(1) for ddl
    // for(int j = 0; j < values_count; j++){
    //     dll.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 5000 * (j + 1));
    //     sum_of_time_elapsed = 0;
    //     for(int i = 0; i < iteration_count ; i++){
        
    //         time_elapsed = testing.test_time(dll, [&dll]() {
    //             dll.addBack(1);
    //         });
    //         dll.deleteBack();
    //         sum_of_time_elapsed += time_elapsed;
    //     }
    //     sum_of_time_elapsed = sum_of_time_elapsed/iteration_count;
    //     keys[j] = dll.getSize();
    //     values[j] = sum_of_time_elapsed;
    // }
    // saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Results/dll addBack.csv";
    // testing.save_to_csv(saveFilePath, key_name, value_name, keys, values, values_count);

    // // deleteBack for ddl
    // for(int j = 0; j < values_count; j++){
    //     dll.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 5000 * (j + 1));
    //     sum_of_time_elapsed = 0;
    //     for(int i = 0; i < iteration_count ; i++){
        
    //         time_elapsed = testing.test_time(dll, [&dll]() {
    //             dll.deleteBack();
    //         });
    //         dll.addBack(1);
    //         sum_of_time_elapsed += time_elapsed;
    //     }
    //     sum_of_time_elapsed = sum_of_time_elapsed/iteration_count;
    //     keys[j] = dll.getSize();
    //     values[j] = sum_of_time_elapsed;
    // }
    // saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Results/dll deleteBack.csv";
    // testing.save_to_csv(saveFilePath, key_name, value_name, keys, values, values_count);


    // // --- --- --- --- ---


    // // addFront(1) for da
    // for(int j = 0; j < values_count; j++){

    //     da.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 5000 * (j + 1));

    //     sum_of_time_elapsed = 0;

    //     for(int i = 0; i < iteration_count ; i++){
        
    //         time_elapsed = testing.test_time(da, [&da]() {

    //             da.addFront(1);

    //         });

    //         da.deleteFront();
    //         sum_of_time_elapsed += time_elapsed;
    //     }

    //     sum_of_time_elapsed = sum_of_time_elapsed/iteration_count;
    //     keys[j] = da.getSize();
    //     values[j] = sum_of_time_elapsed;

    // }
    // saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Results/da addFront.csv";
    // testing.save_to_csv(saveFilePath, key_name, value_name, keys, values, values_count);

    // // deleteFront for da
    // for(int j = 0; j < values_count; j++){

    //     da.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 5000 * (j + 1));

    //     sum_of_time_elapsed = 0;

    //     for(int i = 0; i < iteration_count ; i++){
        
    //         time_elapsed = testing.test_time(da, [&da]() {

                
    //             da.deleteFront();

    //         });

    //         da.addFront(1);
    //         sum_of_time_elapsed += time_elapsed;
    //     }

    //     sum_of_time_elapsed = sum_of_time_elapsed/iteration_count;
    //     keys[j] = da.getSize();
    //     values[j] = sum_of_time_elapsed;

    // }
    // saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Results/da deleteFront.csv";
    // testing.save_to_csv(saveFilePath, key_name, value_name, keys, values, values_count);

    // // addBack(1) for da
    // for(int j = 0; j < values_count; j++){

    //     da.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 5000 * (j + 1));

    //     sum_of_time_elapsed = 0;

    //     for(int i = 0; i < iteration_count ; i++){
        
    //         time_elapsed = testing.test_time(da, [&da]() {

    //             da.addBack(1);

    //         });

    //         da.deleteBack();
    //         sum_of_time_elapsed += time_elapsed;
    //     }

    //     sum_of_time_elapsed = sum_of_time_elapsed/iteration_count;
    //     keys[j] = da.getSize();
    //     values[j] = sum_of_time_elapsed;

    // }
    // saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Results/da addBack.csv";
    // testing.save_to_csv(saveFilePath, key_name, value_name, keys, values, values_count);

    // // deleteBack for da
    // for(int j = 0; j < values_count; j++){

    //     da.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 5000 * (j + 1));

    //     sum_of_time_elapsed = 0;

    //     for(int i = 0; i < iteration_count ; i++){
        
    //         time_elapsed = testing.test_time(da, [&da]() {

                
    //             da.deleteBack();

    //         });

    //         da.addBack(1);
    //         sum_of_time_elapsed += time_elapsed;
    //     }

    //     sum_of_time_elapsed = sum_of_time_elapsed/iteration_count;
    //     keys[j] = da.getSize();
    //     values[j] = sum_of_time_elapsed;

    // }
    // saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Results/da deleteBack.csv";
    // testing.save_to_csv(saveFilePath, key_name, value_name, keys, values, values_count);

    // // --- --- --- --- ---


    // // addFront(1) for ll
    // for(int j = 0; j < values_count; j++){

    //     ll.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 5000 * (j + 1));

    //     sum_of_time_elapsed = 0;

    //     for(int i = 0; i < iteration_count ; i++){
        
    //         time_elapsed = testing.test_time(ll, [&ll]() {

    //             ll.addFront(1);

    //         });

    //         ll.deleteFront();
    //         sum_of_time_elapsed += time_elapsed;
    //     }

    //     sum_of_time_elapsed = sum_of_time_elapsed/iteration_count;
    //     keys[j] = ll.getSize();
    //     values[j] = sum_of_time_elapsed;

    // }
    // saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Results/ll addFront.csv";
    // testing.save_to_csv(saveFilePath, key_name, value_name, keys, values, values_count);

    // // delFront for ll
    // for(int j = 0; j < values_count; j++){

    //     ll.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 5000 * (j + 1));

    //     sum_of_time_elapsed = 0;

    //     for(int i = 0; i < iteration_count ; i++){
        
    //         time_elapsed = testing.test_time(ll, [&ll]() {

    //             ll.deleteFront();

    //         });

    //         ll.addFront(1);
    //         sum_of_time_elapsed += time_elapsed;
    //     }

    //     sum_of_time_elapsed = sum_of_time_elapsed/iteration_count;
    //     keys[j] = ll.getSize();
    //     values[j] = sum_of_time_elapsed;

    // }
    // saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Results/ll deleteFront.csv";
    // testing.save_to_csv(saveFilePath, key_name, value_name, keys, values, values_count);

    // // addBack(1) for ll
    // for(int j = 0; j < values_count; j++){

    //     ll.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 5000 * (j + 1));

    //     sum_of_time_elapsed = 0;

    //     for(int i = 0; i < iteration_count ; i++){
        
    //         time_elapsed = testing.test_time(ll, [&ll]() {

    //             ll.addBack(1);

    //         });

    //         ll.deleteBack();
    //         sum_of_time_elapsed += time_elapsed;
    //     }

    //     sum_of_time_elapsed = sum_of_time_elapsed/iteration_count;
    //     keys[j] = ll.getSize();
    //     values[j] = sum_of_time_elapsed;

    // }
    // saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Results/ll addBack.csv";
    // testing.save_to_csv(saveFilePath, key_name, value_name, keys, values, values_count);

    // // delBack for ll
    // for(int j = 0; j < values_count; j++){

    //     ll.allocate_from_csv("C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv", 5000 * (j + 1));

    //     sum_of_time_elapsed = 0;

    //     for(int i = 0; i < iteration_count ; i++){
        
    //         time_elapsed = testing.test_time(ll, [&ll]() {

    //             ll.deleteBack();

    //         });

    //         ll.addBack(1);
    //         sum_of_time_elapsed += time_elapsed;
    //     }

    //     sum_of_time_elapsed = sum_of_time_elapsed/iteration_count;
    //     keys[j] = ll.getSize();
    //     values[j] = sum_of_time_elapsed;

    // }
    // saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Results/ll deleteBack.csv";
    // testing.save_to_csv(saveFilePath, key_name, value_name, keys, values, values_count);

    return 0;
}