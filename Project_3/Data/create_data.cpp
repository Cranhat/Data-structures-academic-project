#include <iostream>
#include <string>

#include "../Utilities/Utilities.cpp"


int main(){
    std::string saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_3/Data/";

    int* list;
    int* keys;
    int list_size = 500000;

    for (int i = 0; i < 100; i++){
        list = create_randomized_list(list_size, list_size);
        keys = create_randomized_list(list_size, list_size * 10);   
        save_array_keys_to_csv(saveFilePath + std::to_string(i) + ".csv", list, keys, list_size);
    }   
    return 0;
}