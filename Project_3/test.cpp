#include <iostream>

#include "Hash_table/Separate_chaining/SeparateChaining.cpp"
#include "Hash_table/Open_addressing/OpenAddressing.cpp"
#include "Hash_table/Hashing_functions/Hashing_functions.cpp"
#include "DataStructures/Dynamic_array/DynamicArray.cpp"
#include "DataStructures/Double_linked_list/DoubleLinkedList.cpp"
#include "DataStructures/DataStructure/DataStructure.cpp"
#include "Hash_table/AVL/avl.cpp"
#include "Testing/Testing.cpp"

int main(){

    int sizes[] = {500, 10000, 25000, 50000, 75000, 100000, 175000, 250000};
    int sizes_size = 8;

    int mean_of_operations = 20;

    Testing testing;
    
    HashTableOA oa(modulo_hash_function);
    HashTableSC sc(modulo_hash_function);
    AVLTree avl;
    
    std::string dataFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_3/Data/";
    std::string saveFilePath;
    
    saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_3/ResultsAVL/";
    printf("testing started\n");
    testing.test_operation(saveFilePath + "avl add.csv", dataFilePath, avl, "addHash", sizes, sizes_size, mean_of_operations, 1);
    testing.test_operation(saveFilePath + "avl delete.csv", dataFilePath, avl, "deleteHash", sizes, sizes_size, mean_of_operations, 1);

    
    saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_3/ResultsModulo/";
    testing.test_operation(saveFilePath + "oa add 0.5.csv", dataFilePath, oa, "addHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "oa add 0.7.csv", dataFilePath, oa, "addHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "oa add 0.9.csv", dataFilePath, oa, "addHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "oa add 0.99.csv", dataFilePath, oa, "addHash", sizes, sizes_size, mean_of_operations, 0.99);

    testing.test_operation(saveFilePath + "oa delete 0.5.csv", dataFilePath, oa, "deleteHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "oa delete 0.7.csv", dataFilePath, oa, "deleteHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "oa delete 0.9.csv", dataFilePath, oa, "deleteHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "oa delete 0.99.csv", dataFilePath, oa, "deleteHash", sizes, sizes_size, mean_of_operations, 0.99);

    testing.test_operation(saveFilePath + "sc add 0.5.csv", dataFilePath, sc, "addHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "sc add 0.7.csv", dataFilePath, sc, "addHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "sc add 0.9.csv", dataFilePath, sc, "addHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "sc add 0.99.csv", dataFilePath, sc, "addHash", sizes, sizes_size, mean_of_operations, 0.99);
    testing.test_operation(saveFilePath + "sc add 2.csv", dataFilePath, sc, "addHash", sizes, sizes_size, mean_of_operations, 2);
    testing.test_operation(saveFilePath + "sc add 4.csv", dataFilePath, sc, "addHash", sizes, sizes_size, mean_of_operations, 4);

    testing.test_operation(saveFilePath + "sc delete 0.5.csv", dataFilePath, sc, "deleteHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "sc delete 0.7.csv", dataFilePath, sc, "deleteHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "sc delete 0.9.csv", dataFilePath, sc, "deleteHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "sc delete 0.99.csv", dataFilePath, sc, "deleteHash", sizes, sizes_size, mean_of_operations, 0.99);
    testing.test_operation(saveFilePath + "sc delete 2.csv", dataFilePath, sc, "deleteHash", sizes, sizes_size, mean_of_operations, 2);
    testing.test_operation(saveFilePath + "sc delete 4.csv", dataFilePath, sc, "deleteHash", sizes, sizes_size, mean_of_operations, 4);

    HashTableOA oa1(multiplication_hash_function);
    HashTableSC sc1(multiplication_hash_function);
    saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_3/ResultsMultiplication/";

    testing.test_operation(saveFilePath + "oa1 add 0.5.csv", dataFilePath, oa1, "addHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "oa1 add 0.7.csv", dataFilePath, oa1, "addHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "oa1 add 0.9.csv", dataFilePath, oa1, "addHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "oa1 add 0.99.csv", dataFilePath, oa1, "addHash", sizes, sizes_size, mean_of_operations, 0.99);

    testing.test_operation(saveFilePath + "oa1 delete 0.5.csv", dataFilePath, oa1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "oa1 delete 0.7.csv", dataFilePath, oa1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "oa1 delete 0.9.csv", dataFilePath, oa1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "oa1 delete 0.99.csv", dataFilePath, oa1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.99);

    testing.test_operation(saveFilePath + "sc1 add 0.5.csv", dataFilePath, sc1, "addHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "sc1 add 0.7.csv", dataFilePath, sc1, "addHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "sc1 add 0.9.csv", dataFilePath, sc1, "addHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "sc1 add 0.99.csv", dataFilePath, sc1, "addHash", sizes, sizes_size, mean_of_operations, 0.99);
    testing.test_operation(saveFilePath + "sc1 add 2.csv", dataFilePath, sc1, "addHash", sizes, sizes_size, mean_of_operations, 2);
    testing.test_operation(saveFilePath + "sc1 add 4.csv", dataFilePath, sc1, "addHash", sizes, sizes_size, mean_of_operations, 4);

    testing.test_operation(saveFilePath + "sc1 delete 0.5.csv", dataFilePath, sc1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.5);
    testing.test_operation(saveFilePath + "sc1 delete 0.7.csv", dataFilePath, sc1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.7);
    testing.test_operation(saveFilePath + "sc1 delete 0.9.csv", dataFilePath, sc1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.9);
    testing.test_operation(saveFilePath + "sc1 delete 0.99.csv", dataFilePath, sc1, "deleteHash", sizes, sizes_size, mean_of_operations, 0.99);
    testing.test_operation(saveFilePath + "sc1 delete 2.csv", dataFilePath, sc1, "deleteHash", sizes, sizes_size, mean_of_operations, 2);
    testing.test_operation(saveFilePath + "sc1 delete 4.csv", dataFilePath, sc1, "deleteHash", sizes, sizes_size, mean_of_operations, 4);

    printf("testing finished\n");
    return 0;
}