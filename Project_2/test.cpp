#include <iostream>
#include <string>

#include "DataStructure/DataStructure.cpp"
#include "Utilities/Utilities.hpp"
#include "Heap/Heap.cpp"

#include "Testing/Testing.cpp"



int main(){

    // int sizes[] = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 2000000};
    // int sizes_size = 10;
    int sizes[] = {100, 500, 1000, 5000, 10000};
    int sizes_size = 5;

    int mean_of_operations = 1;


    Testing testing;
    
    Heap hp;
    
    std::string dataFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_2/Data/1.csv";
    std::string saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_2/Results/";

    printf("a\n");

    testing.test_operation(saveFilePath + "hp insert.csv", dataFilePath, hp, "insert", sizes, sizes_size, mean_of_operations);
    testing.test_operation(saveFilePath + "hp extractMax.csv", dataFilePath, hp, "extractMax", sizes, sizes_size, mean_of_operations);
    testing.test_operation(saveFilePath + "hp findMax.csv", dataFilePath, hp, "findMax", sizes, sizes_size, mean_of_operations);
    testing.test_operation(saveFilePath + "hp getSize.csv", dataFilePath, hp, "getSize", sizes, sizes_size, mean_of_operations);

    printf("b\n");

    return 0;
}