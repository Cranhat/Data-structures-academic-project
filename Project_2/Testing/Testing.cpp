#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <functional>
#include <iomanip>
#include <random>


#include "Testing.hpp"
#include "..\DataStructure/DataStructure.hpp"
#include "..\Utilities\Utilities.cpp"



double Testing::test_time(DataStructure& object, std::function<void()> func){

    auto start = std::chrono::high_resolution_clock::now();

    func();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::nano> duration = end - start;
    
    return duration.count(); 
}

void Testing::save_to_csv(std::string saveFilePath, std::string key_name, std::string value_name, int keys[], double values[], int values_count){
    std::ofstream myFile;
    myFile.open(saveFilePath.c_str(), std::ios::out | std::ios::trunc);

    myFile << key_name << ";" << value_name << "\n";

    for(int i = 0; i < values_count; i++){

        myFile << keys[i] << ";" << values[i]<< "\n" << std::setprecision(16);

    }

    myFile.close();

}

void Testing::test_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, std::string operation, int sizes[], int sizes_size, int mean_of_operations, std::string key_name = "count", std::string value_name = "time"){

    double sum_of_time_elapsed = 0;
    double time_elapsed;
    int keys[sizes_size];
    double values[sizes_size];

    for(int j = 0; j < sizes_size; j++){
        allocate_from_csv(object, dataFilePath, sizes[j]);

        sum_of_time_elapsed = 0;
        for(int i = 0; i < mean_of_operations ; i++){

            time_elapsed = test_time(object, [&object, operation]() {
                if (operation == "insert"){
                    object.insert(1, 1);
                }else if (operation == "extractMax"){
                    object.extractMax();
                }else if (operation == "findMax"){
                    object.findMax();
                }else if (operation == "modifyKey"){
                    // object.modifyKey()
                    printf("currently no operation\n");
                }else if(operation == "getSize"){
                    object.getSize();
                }else{
                    printf("invalid testing operation\n");
                }
                
            });
            if (operation == "insert"){
                object.extractMax();
            }else if (operation == "extractMax"){
                object.insert(1, 1);
            }
            sum_of_time_elapsed += time_elapsed;
        }
        sum_of_time_elapsed = sum_of_time_elapsed/mean_of_operations;
        keys[j] = object.getSize();
        values[j] = sum_of_time_elapsed;
    }
    
    save_to_csv(saveFilePath, key_name, value_name, keys, values, sizes_size);
}
