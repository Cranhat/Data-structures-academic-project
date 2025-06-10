#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <functional>
#include <iomanip>
#include <random>


#include "Testing.hpp"
#include "../DataStructures/DataStructure/DataStructure.hpp"
#include "../Utilities/Utilities.cpp"


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
        myFile << keys[i] << ";" << values[i]<< "\n" << std::setprecision(20);
    }
    myFile.close();
}

void Testing::test_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, std::string operation, int sizes[], int sizes_size, int mean_of_operations, float load_factor, std::string key_name = "count", std::string value_name = "time"){

    double time_elapsed; double sum_of_time_elapsed = 0;
    int keys[sizes_size];
    double values[sizes_size];

    for(int j = 0; j < sizes_size; j++){
        std::cout << "current size: " << sizes[j] << std::endl;
        sum_of_time_elapsed = 0;

        for(int i = 0; i < mean_of_operations ; i++){
            object.allocate_from_csv(dataFilePath + std::to_string(i) + ".csv", sizes[j], sizes[j] / load_factor);
            NodeBase* random_existing_object = object.getRandom();
            
            int deleted_node_key = random_existing_object -> key;
            int deleted_node_value = random_existing_object -> value;


            
            time_elapsed = test_time(object, [&object, operation, deleted_node_key, deleted_node_value]() {
                if (operation == "insert"){
                    object.addHash(rand() % object.getSize(), rand() % object.getSize());
                }else if (operation == "deleteHash"){
                    object.deleteHash(deleted_node_key, deleted_node_value);
                }
            });
            sum_of_time_elapsed += time_elapsed;
            if (operation == "insertHash"){
                object.deleteBack(); 
            }
            else if (operation == "deleteHash"){
                object.addHash(rand() % object.getSize(), rand() % object.getSize());
            }
        }
        sum_of_time_elapsed = sum_of_time_elapsed/mean_of_operations;
        keys[j] = object.getSize();
        values[j] = sum_of_time_elapsed; 
        
    }
    save_to_csv(saveFilePath, key_name, value_name, keys, values, sizes_size);
}
