#include <iostream>
#include <string>

#include "../DataStructure/DataStructure.cpp"
#include "../Double linked list/Double linked list.cpp"
#include "../Utilities/Utilities.cpp"

using namespace std;


int main(){

    int* list100000000 = create_randomized_list(100000000, 100000000);
    string saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data";
    save_array_to_csv(saveFilePath, list100000000 , 100000000);

    list100000000 = create_randomized_list(100000000, 100000000);
    saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/2.csv";
    save_array_to_csv(saveFilePath, list100000000 , 100000000);

    list100000000 = create_randomized_list(100000000, 100000000);
    saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/3.csv";
    save_array_to_csv(saveFilePath, list100000000 , 100000000);

    return 0;
}