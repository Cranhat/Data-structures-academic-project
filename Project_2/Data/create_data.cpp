#include <iostream>
#include <string>

#include "../DataStructure/DataStructure.cpp"
#include "../Utilities/Utilities.cpp"


int main(){
    std::string saveFilePath = "C:/Users/cypri/Projects/Data-structures-academic-project/Project_2/Data/";
    // std::string saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_2/Data/";

    int* list;
    int* keys;
    int list_size = 5000000;

    for (int i = 0; i < 2; i++){
        list = create_randomized_list(list_size, list_size);
        keys = create_randomized_list(list_size, list_size * 10);   
        save_array_keys_to_csv(saveFilePath + std::to_string(i) + ".csv", list, keys, list_size);
    }
    return 0;
}