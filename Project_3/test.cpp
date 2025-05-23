#include <iostream>

#include "Hash_table/Open_addressing/OpenAddressing.cpp"
#include "Hash_table/Hashing_functions/Modulo/Modulo.cpp"
#include "DataStructures/Dynamic_array/DynamicArray.cpp"
#include "DataStructures/DataStructure/DataStructure.cpp"

int main(){

    FUNC_PTR addressing_function = modulo_hash_function;
    HashTableOA ht(200, addressing_function);

    ht.addHash(1, 1);

    ht.addHash(3, 3);

    ht.addHash(1, 1);

    ht.addHash(1, 1);

    // ht.addHash(3, 3);

    // ht.addHash(1, 1);

    // ht.addHash(190, 190);

    // ht.addHash(90, 90);

    // ht.addHash(20, 20);

    // ht.addHash(4, 4);2

    // ht.addHash(5, 5);

    // ht.addHash(5, 5);

    ht.printElements();
    
    return 0;
}