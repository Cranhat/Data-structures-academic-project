#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <functional>
#include <iomanip>

#include "Testing.hpp"
#include "..\Double linked list\Double linked list.hpp"

using namespace std;

using namespace std::literals;


double Testing::test_time(DataStructure& object, std::function<void()> func){

    auto start = std::chrono::high_resolution_clock::now();

    func();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    
    double fp_seconds = duration / 1.00s;
    
    return fp_seconds;
}

void Testing::save_to_csv(string saveFilePath, string key_name, string value_name, int keys[], double values[], int values_count){
    ofstream myFile;
    myFile.open(saveFilePath.c_str(), std::ios::out | std::ios::trunc);

    myFile << key_name << ";" << value_name << "\n";

    for(int i = 0; i < values_count; i++){

        myFile << keys[i] << ";" << values[i]<< "\n" << std::setprecision(10); ;

    }

    myFile.close();

}

