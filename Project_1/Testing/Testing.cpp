#include "Testing.hpp"

#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdio>
#include <string>
#include <functional>

#include "..\Double linked list\Double linked list.hpp"


using namespace std::literals;

void Testing::save_to_csv(string saveFilePath, int keys[], float values[], int values_count){
    ofstream myFile;
    myFile.open(saveFilePath.c_str(), std::ios::out | std::ios::trunc);

    myFile << "Size" << ";" << saveFilePath << "\n";

    for(int i = 0; i < values_count; i++){

        myFile << keys[i]<< ";"<< values[i]<< "\n";

    }

    myFile.close();

}

double Testing::test_time(DoubleLinkedList& object, std::function<void()> func){

    auto start = std::chrono::high_resolution_clock::now();

    func();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    
    double fp_seconds = duration / 1.01s;
    
    return fp_seconds;
}

