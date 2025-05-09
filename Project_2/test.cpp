#include <iostream>
#include <string>

#include "DataStructure/DataStructure.cpp"
#include "Utilities/Utilities.hpp"
#include "Heap/Heap.cpp"
#include "Array/Array.cpp"

#include "Testing/Testing.cpp"



int main(){

    int sizes[] = {500, 10000, 25000, 50000, 75000, 100000, 175000, 250000, 375000, 500000, 625000, 750000, 875000, 1000000};
    int sizes_size = 14;

    int mean_of_operations = 1000;

    int a = 0;
    for (int i = 0; i<100000000; i++){
        a = i;
    }

    Testing testing;
    
    Heap hp;
    PriorityQueueArray ar;
    
    std::string dataFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_2/Data/1.csv";
    std::string saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_2/Results/";

    // std::string dataFilePath = "C:/Users/cypri/Projects/Data-structures-academic-project/Project_2/Data/1.csv";
    // std::string saveFilePath = "C:/Users/cypri/Projects/Data-structures-academic-project/Project_2/Results/";

    printf("a\n");

    testing.test_operation(saveFilePath + "hp insert.csv", dataFilePath, hp, "insert", sizes, sizes_size, mean_of_operations);
    testing.test_operation(saveFilePath + "hp extractMax.csv", dataFilePath, hp, "extractMax", sizes, sizes_size, mean_of_operations);
    testing.test_operation(saveFilePath + "hp peek.csv", dataFilePath, hp, "peek", sizes, sizes_size, mean_of_operations);
    testing.test_operation(saveFilePath + "hp getSize.csv", dataFilePath, hp, "getSize", sizes, sizes_size, mean_of_operations);
    testing.test_operation(saveFilePath + "hp changeKey.csv", dataFilePath, hp, "changeKey", sizes, sizes_size, mean_of_operations);

    testing.test_operation(saveFilePath + "ar insert.csv", dataFilePath, ar, "insert", sizes, sizes_size, mean_of_operations);
    testing.test_operation(saveFilePath + "ar extractMax.csv", dataFilePath, ar, "extractMax", sizes, sizes_size, mean_of_operations);
    testing.test_operation(saveFilePath + "ar peek.csv", dataFilePath, ar, "peek", sizes, sizes_size, mean_of_operations);
    testing.test_operation(saveFilePath + "ar getSize.csv", dataFilePath, ar, "getSize", sizes, sizes_size, mean_of_operations);
    testing.test_operation(saveFilePath + "ar changeKey.csv", dataFilePath, ar, "changeKey", sizes, sizes_size, mean_of_operations);

    printf("b\n");

    return 0;
}