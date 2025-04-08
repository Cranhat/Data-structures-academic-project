#include "Testing.hpp"

#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdio>
#include <string>
#include <functional>

#include "..\Double linked list\Double linked list.hpp"

using namespace std;

using namespace std::literals;


double Testing::test_time(DoubleLinkedList& object, std::function<void()> func){

    auto start = std::chrono::high_resolution_clock::now();

    func();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    
    double fp_seconds = duration / 1.00s;
    
    return fp_seconds;
}

void Testing::save_to_csv(string saveFilePath, string key_name, string value_name, int keys[], float values[], int values_count){
    ofstream myFile;
    myFile.open(saveFilePath.c_str(), std::ios::out | std::ios::trunc);

    myFile << key_name << ";" << value_name << "\n";

    for(int i = 0; i < values_count; i++){

        myFile << keys[i] << ";" << values[i]<< "\n";

    }

    myFile.close();

}


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

void save_array_to_csv(string saveFilePath, int values[], int values_count){
    std::ofstream myFile;
    myFile.open(saveFilePath.c_str(), std::ios::out | std::ios::trunc);

    for(int i = 0; i < values_count; i++){

        myFile << values[i] << "\n";

    }

    myFile.close();
}