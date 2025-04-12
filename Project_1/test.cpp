#include <iostream>
#include <string>

#include "Double linked list/Double linked list.cpp"
#include "DataStructure/DataStructure.cpp"
#include "Dynamic list/Dynamic list.cpp"
#include "Linked list/Linked list.cpp"
#include "Utilities/Utilities.cpp"

#include "Testing/Testing.cpp"


int main(){

    int number_of_measurements = 11;
    int mean_of_operations = 2;

    Testing testing;
    
    DoubleLinkedList dll;
    LinkedList ll;
    DynamicArray da;
    
    std::string dataFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/1.csv";
    std::string saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Results/";

    printf("1\n");

    testing.test_add_front_operation(saveFilePath + "dll addFront.csv", dataFilePath, dll, number_of_measurements, mean_of_operations);
    testing.test_add_front_operation(saveFilePath + "ll addFront.csv", dataFilePath, ll, number_of_measurements, mean_of_operations);
    testing.test_add_front_operation(saveFilePath + "da addFront.csv", dataFilePath, da, number_of_measurements, mean_of_operations);

    printf("2\n");

    testing.test_del_front_operation(saveFilePath + "dll delFront.csv", dataFilePath, dll, number_of_measurements, mean_of_operations);
    testing.test_del_front_operation(saveFilePath + "ll delFront.csv", dataFilePath, ll, number_of_measurements, mean_of_operations);
    testing.test_del_front_operation(saveFilePath + "da delFront.csv", dataFilePath, da, number_of_measurements, mean_of_operations);

    printf("3\n");

    testing.test_add_back_operation(saveFilePath + "dll addBack.csv", dataFilePath, dll, number_of_measurements, mean_of_operations);
    testing.test_add_back_operation(saveFilePath + "ll addBack.csv", dataFilePath, ll, number_of_measurements, mean_of_operations);
    testing.test_add_back_operation(saveFilePath + "da addBack.csv", dataFilePath, da, number_of_measurements, mean_of_operations);

    printf("4\n");

    testing.test_del_back_operation(saveFilePath + "dll delBack.csv", dataFilePath, dll, number_of_measurements, mean_of_operations);
    testing.test_del_back_operation(saveFilePath + "ll delBack.csv", dataFilePath, ll, number_of_measurements, mean_of_operations);
    testing.test_del_back_operation(saveFilePath + "da delBack.csv", dataFilePath, da, number_of_measurements, mean_of_operations);

    printf("5\n");

    testing.test_add_random_operation(saveFilePath + "dll addRandom.csv", dataFilePath, dll, number_of_measurements, mean_of_operations);
    testing.test_add_random_operation(saveFilePath + "ll addRandom.csv", dataFilePath, ll, number_of_measurements, mean_of_operations);
    testing.test_add_random_operation(saveFilePath + "da addRandom.csv", dataFilePath, da, number_of_measurements, mean_of_operations);

    printf("6\n");

    testing.test_del_random_operation(saveFilePath + "dll delRandom.csv", dataFilePath, dll, number_of_measurements, mean_of_operations);
    testing.test_del_random_operation(saveFilePath + "ll delRandom.csv", dataFilePath, ll, number_of_measurements, mean_of_operations);
    testing.test_del_random_operation(saveFilePath + "da delRandom.csv", dataFilePath, da, number_of_measurements, mean_of_operations);

    printf("7\n");

    testing.test_contains_random_existing_operation(saveFilePath + "dll contains existent.csv", dataFilePath, dll, number_of_measurements, mean_of_operations);
    testing.test_contains_random_existing_operation(saveFilePath + "ll contains existent.csv", dataFilePath, ll, number_of_measurements, mean_of_operations);
    testing.test_contains_random_existing_operation(saveFilePath + "da contains existent.csv", dataFilePath, da, number_of_measurements, mean_of_operations);

    printf("8\n");

    testing.test_contains_non_existing_operation(saveFilePath + "dll contains non existent.csv", dataFilePath, dll, number_of_measurements, mean_of_operations);
    testing.test_contains_non_existing_operation(saveFilePath + "ll contains non existent.csv", dataFilePath, ll, number_of_measurements, mean_of_operations);
    testing.test_contains_non_existing_operation(saveFilePath + "da contains non existent.csv", dataFilePath, da, number_of_measurements, mean_of_operations);
    
    printf("9\n");

    return 0;
}