#include <iostream>

#include "Hash_table/Open_addressing/OpenAddressing.cpp"
#include "Hash_table/Hashing_functions/Hashing_functions.cpp"
#include "DataStructures/Dynamic_array/DynamicArray.cpp"
#include "DataStructures/DataStructure/DataStructure.cpp"
#include "Testing/Testing.cpp"

int main(){

    int sizes[] = {500, 10000, 25000, 50000, 75000, 100000, 175000, 250000, 375000, 500000, 625000, 750000, 875000, 1000000};
    int sizes_size = 3;

    int mean_of_operations = 2;

    Testing testing;
    
    HashTableOA oa(modulo_hash_function);
    
    // std::string dataFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_2/Data/1.csv";
    // std::string saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_2/Results/";

    std::string dataFilePath = "C:/Users/cypri/Projects/Data-structures-academic-project/Project_3/Data/0.csv";
    std::string saveFilePath = "C:/Users/cypri/Projects/Data-structures-academic-project/Project_3/Results/";
    
    // oa.addHash(10, 10);
    // oa.printElements();

    oa.allocate_from_csv(dataFilePath, 100, 200);

    oa.printElements();

    NodeBase* node_ptr = oa.getRandom(); // program dziala, nie da sie odczytac wwartoci

    arrayNode* node_ptr = oa.getRandom();// program dziala, da sie odczytac wwartoci


    // printf("a\n");
    // testing.test_operation(saveFilePath + "oa add.csv", dataFilePath, oa, "addHash", sizes, sizes_size, mean_of_operations);
    // testing.test_operation(saveFilePath + "oa delete.csv", dataFilePath, oa, "deleteHash", sizes, sizes_size, mean_of_operations);

    // printf("aa\n");
    return 0;
}