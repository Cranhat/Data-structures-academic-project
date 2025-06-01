#include <iostream>

#include "Hash_table/Separate_chaining/SeparateChaining.cpp"
#include "Hash_table/Open_addressing/OpenAddressing.cpp"
#include "Hash_table/Hashing_functions/Hashing_functions.cpp"
#include "DataStructures/Dynamic_array/DynamicArray.cpp"
#include "DataStructures/Double_linked_list/DoubleLinkedList.cpp"
#include "DataStructures/DataStructure/DataStructure.cpp"
#include "Testing/Testing.cpp"

int main(){

    int sizes[] = {500, 10000, 25000, 50000, 75000, 100000, 175000, 250000};
    int sizes_size = 2;

    int mean_of_operations = 3;

    Testing testing;
    
    HashTableOA oa(modulo_hash_function);
    HashTableSC sc(modulo_hash_function);
    
    // std::string dataFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_2/Data/1.csv";
    // std::string saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_2/Results/";
    std::string dataFilePath = "C:/Users/cypri/Projects/Data-structures-academic-project/Project_3/Data/";
    std::string saveFilePath = "C:/Users/cypri/Projects/Data-structures-academic-project/Project_3/Results/";
    

    printf("a\n");
    testing.test_operation(saveFilePath + "oa add 0.5.csv", dataFilePath, oa, "addHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "oa add 0.7.csv", dataFilePath, oa, "addHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "oa add 0.9.csv", dataFilePath, oa, "addHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "oa add 0.99.csv", dataFilePath, oa, "addHash", sizes, sizes_size, mean_of_operations, 0.99);

    testing.test_operation(saveFilePath + "oa delete 0.5.csv", dataFilePath, oa, "deleteHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "oa delete 0.7.csv", dataFilePath, oa, "deleteHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "oa delete 0.9.csv", dataFilePath, oa, "deleteHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "oa delete 0.99.csv", dataFilePath, oa, "deleteHash", sizes, sizes_size, mean_of_operations, 0.99);

    testing.test_operation(saveFilePath + "sc add 0.5.csv", dataFilePath, sc, "addHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "sc add 0.6.csv", dataFilePath, sc, "addHash", sizes, sizes_size, mean_of_operations, 0.6);
    testing.test_operation(saveFilePath + "sc add 0.7.csv", dataFilePath, sc, "addHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "sc add 0.8.csv", dataFilePath, sc, "addHash", sizes, sizes_size, mean_of_operations, 0.8);
    testing.test_operation(saveFilePath + "sc add 0.9.csv", dataFilePath, sc, "addHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "sc add 0.95.csv", dataFilePath, sc, "addHash", sizes, sizes_size, mean_of_operations, 0.95);
    testing.test_operation(saveFilePath + "sc add 1.5.csv", dataFilePath, sc, "addHash", sizes, sizes_size, mean_of_operations, 1.5);
    testing.test_operation(saveFilePath + "sc add 2.5.csv", dataFilePath, sc, "addHash", sizes, sizes_size, mean_of_operations, 2.5);
    testing.test_operation(saveFilePath + "sc add 5.csv", dataFilePath, sc, "addHash", sizes, sizes_size, mean_of_operations, 5);

    testing.test_operation(saveFilePath + "sc delete 0.5.csv", dataFilePath, sc, "deleteHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "sc delete 0.6.csv", dataFilePath, sc, "deleteHash", sizes, sizes_size, mean_of_operations, 0.6);
    testing.test_operation(saveFilePath + "sc delete 0.7.csv", dataFilePath, sc, "deleteHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "sc delete 0.8.csv", dataFilePath, sc, "deleteHash", sizes, sizes_size, mean_of_operations, 0.8);
    testing.test_operation(saveFilePath + "sc delete 0.9.csv", dataFilePath, sc, "deleteHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "sc delete 0.95.csv", dataFilePath, sc, "deleteHash", sizes, sizes_size, mean_of_operations, 0.95);
    testing.test_operation(saveFilePath + "sc delete 1.5.csv", dataFilePath, sc, "deleteHash", sizes, sizes_size, mean_of_operations, 1.5);
    testing.test_operation(saveFilePath + "sc delete 2.5.csv", dataFilePath, sc, "deleteHash", sizes, sizes_size, mean_of_operations, 2.5);
    testing.test_operation(saveFilePath + "sc delete 5.csv", dataFilePath, sc, "deleteHash", sizes, sizes_size, mean_of_operations, 5);

    HashTableOA oa1(multiplication_hash_function);
    HashTableSC sc1(multiplication_hash_function);
    dataFilePath = "C:/Users/cypri/Projects/Data-structures-academic-project/Project_3/Data/";
    saveFilePath = "C:/Users/cypri/Projects/Data-structures-academic-project/Project_3/ResultsMultiplication/";
    

    testing.test_operation(saveFilePath + "oa1 add 0.5.csv", dataFilePath, oa1, "addHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "oa1 add 0.7.csv", dataFilePath, oa1, "addHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "oa1 add 0.9.csv", dataFilePath, oa1, "addHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "oa1 add 0.99.csv", dataFilePath, oa1, "addHash", sizes, sizes_size, mean_of_operations, 0.99);

    testing.test_operation(saveFilePath + "oa1 delete 0.5.csv", dataFilePath, oa1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "oa1 delete 0.7.csv", dataFilePath, oa1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "oa1 delete 0.9.csv", dataFilePath, oa1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "oa1 delete 0.99.csv", dataFilePath, oa1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.99);

    testing.test_operation(saveFilePath + "sc1 add 0.5.csv", dataFilePath, sc1, "addHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "sc1 add 0.6.csv", dataFilePath, sc1, "addHash", sizes, sizes_size, mean_of_operations, 0.6);
    testing.test_operation(saveFilePath + "sc1 add 0.7.csv", dataFilePath, sc1, "addHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "sc1 add 0.8.csv", dataFilePath, sc1, "addHash", sizes, sizes_size, mean_of_operations, 0.8);
    testing.test_operation(saveFilePath + "sc1 add 0.9.csv", dataFilePath, sc1, "addHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "sc1 add 0.95.csv", dataFilePath, sc1, "addHash", sizes, sizes_size, mean_of_operations, 0.95);
    testing.test_operation(saveFilePath + "sc1 add 1.5.csv", dataFilePath, sc1, "addHash", sizes, sizes_size, mean_of_operations, 1.5);
    testing.test_operation(saveFilePath + "sc1 add 2.5.csv", dataFilePath, sc1, "addHash", sizes, sizes_size, mean_of_operations, 2.5);
    testing.test_operation(saveFilePath + "sc1 add 5.csv", dataFilePath, sc1, "addHash", sizes, sizes_size, mean_of_operations, 5);

    testing.test_operation(saveFilePath + "sc1 delete 0.5.csv", dataFilePath, sc1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "sc1 delete 0.6.csv", dataFilePath, sc1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.6);
    testing.test_operation(saveFilePath + "sc1 delete 0.7.csv", dataFilePath, sc1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "sc1 delete 0.8.csv", dataFilePath, sc1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.8);
    testing.test_operation(saveFilePath + "sc1 delete 0.9.csv", dataFilePath, sc1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "sc1 delete 0.95.csv", dataFilePath, sc1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.95);
    testing.test_operation(saveFilePath + "sc1 delete 1.5.csv", dataFilePath, sc1, "deleteHash", sizes, sizes_size, mean_of_operations, 1.5);
    testing.test_operation(saveFilePath + "sc1 delete 2.5.csv", dataFilePath, sc1, "deleteHash", sizes, sizes_size, mean_of_operations, 2.5);
    testing.test_operation(saveFilePath + "sc1 delete 5.csv", dataFilePath, sc1, "deleteHash", sizes, sizes_size, mean_of_operations, 5);


    printf("aa\n");
    return 0;
}