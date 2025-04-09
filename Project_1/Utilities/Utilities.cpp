#include "Utilities.hpp"
#include <string>
#include <fstream>


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

void save_array_to_csv(std::string saveFilePath, int values[], int values_count){

    std::ofstream myFile;
    
    myFile.open(saveFilePath.c_str(), std::ios::out | std::ios::trunc);

    for(int i = 0; i < values_count; i++){

        myFile << values[i] << "\n";

    }

    myFile.close();
}