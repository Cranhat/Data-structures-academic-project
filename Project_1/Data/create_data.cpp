#include <iostream>
#include <string>

#include "../Double linked list/Double linked list.cpp"
#include "../Testing/Testing.cpp"

using namespace std;


int main(){

    int* list100000000 = create_randomized_list(100000000, 100000000);
    string saveFilePath = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_1/Data/100000000.csv";
    save_array_to_csv(saveFilePath, list100000000 , 100000000);

    return 0;
}