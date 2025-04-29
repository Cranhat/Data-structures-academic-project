#include <string>
#include <fstream>

#include "Utilities.hpp"
#include "../DataStructure/DataStructure.hpp"
#include "../Double linked list/Double linked list.hpp"


int* create_randomized_list(int size, int max_value){
    int* lista = (int *) malloc(sizeof(int) * size);

    if (!lista) {

        printf("Memory allocation failed!\n");
        exit(1);

    }
    int randomNum;
    for (int i = 0; i < size; i++){

        randomNum = rand() % max_value;
        lista[i] = randomNum;

    }
    return lista;
}

void save_array_keys_to_csv(std::string saveFilePath, int values[], int keys[], int values_count){

    std::ofstream myFile;
    
    myFile.open(saveFilePath.c_str(), std::ios::out | std::ios::trunc);

    for(int i = 0; i < values_count; i++){

        myFile << values[i] << ";" << keys[i] << "\n";

    }

    myFile.close();
}


void allocate_from_csv(DataStructure& object, std::string FilePath, int size){

    std::ifstream myFile(FilePath.c_str(), std::ios::in);

    

    int number, key, location;
    std::string line;
    int count = 0;

    object.clear();

    while (std::getline(myFile, line) && size > count){
        

        location = line.find(';');


        number = stoi(line.substr(0, location));
        key = stoi(line.substr(location + 1));

        object.insert(number, key);


        count++;
    }    


    myFile.close();
}