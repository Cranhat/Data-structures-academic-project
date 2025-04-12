#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <functional>
#include <iomanip>
#include <random>


#include "Testing.hpp"
#include "..\Double linked list\Double linked list.hpp"
#include "..\DataStructure/DataStructure.hpp"
#include "..\Utilities\Utilities.hpp"


using namespace std::literals;



double Testing::test_time(DataStructure& object, std::function<void()> func){

    auto start = std::chrono::high_resolution_clock::now();

    func();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    
    double fp_seconds = duration / 1.00s;
    
    return fp_seconds;
}

void Testing::save_to_csv(std::string saveFilePath, std::string key_name, std::string value_name, int keys[], double values[], int values_count){
    std::ofstream myFile;
    myFile.open(saveFilePath.c_str(), std::ios::out | std::ios::trunc);

    myFile << key_name << ";" << value_name << "\n";

    for(int i = 0; i < values_count; i++){

        myFile << keys[i] << ";" << values[i]<< "\n" << std::setprecision(12);

    }

    myFile.close();

}

void Testing::test_add_front_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name = "count", std::string value_name = "time"){
    double sum_of_time_elapsed = 0;
    int keys[number_of_measurements];
    double values[number_of_measurements];

    for(int j = 0; j < number_of_measurements; j++){
        allocate_from_csv(object, dataFilePath, 5000 * (j + 1) * (j + 1));
        sum_of_time_elapsed = 0;
        for(int i = 0; i < mean_of_operations ; i++){
        
            sum_of_time_elapsed = test_time(object, [&object]() {
                object.addFront(1);
            });
            object.deleteFront();
            sum_of_time_elapsed += sum_of_time_elapsed;
        }
        sum_of_time_elapsed = sum_of_time_elapsed/mean_of_operations;
        keys[j] = object.getSize();
        values[j] = sum_of_time_elapsed;
    }
    save_to_csv(saveFilePath, key_name, value_name, keys, values, number_of_measurements);    
}

void Testing::test_add_back_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name = "count", std::string value_name = "time"){
    double sum_of_time_elapsed = 0;
    int keys[number_of_measurements];
    double values[number_of_measurements];

    for(int j = 0; j < number_of_measurements; j++){
        allocate_from_csv(object, dataFilePath, 5000 * (j + 1) * (j + 1));
        sum_of_time_elapsed = 0;
        for(int i = 0; i < mean_of_operations ; i++){
        
            sum_of_time_elapsed = test_time(object, [&object]() {
                object.addBack(1);
            });
            object.deleteBack();
            sum_of_time_elapsed += sum_of_time_elapsed;
        }
        sum_of_time_elapsed = sum_of_time_elapsed/mean_of_operations;
        keys[j] = object.getSize();
        values[j] = sum_of_time_elapsed;
    }
    save_to_csv(saveFilePath, key_name, value_name, keys, values, number_of_measurements);    
}

void Testing::test_add_random_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name = "count", std::string value_name = "time"){
    double sum_of_time_elapsed = 0;
    int keys[number_of_measurements];
    double values[number_of_measurements];
    int index;

    for(int j = 0; j < number_of_measurements; j++){
        allocate_from_csv(object, dataFilePath, 5000 * (j + 1) * (j + 1));
        sum_of_time_elapsed = 0;
        for(int i = 0; i < mean_of_operations ; i++){
            
            sum_of_time_elapsed = test_time(object, [&object]() {
                int index = rand() % (object.getSize() - 1);
                object.addIndex(1, index);
            });
            object.deleteIndex(1);
            sum_of_time_elapsed += sum_of_time_elapsed;
        }
        sum_of_time_elapsed = sum_of_time_elapsed/mean_of_operations;
        keys[j] = object.getSize();
        values[j] = sum_of_time_elapsed;
    }
    save_to_csv(saveFilePath, key_name, value_name, keys, values, number_of_measurements);    
}

void Testing::test_del_front_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name = "count", std::string value_name = "time"){
    double sum_of_time_elapsed = 0;
    int keys[number_of_measurements];
    double values[number_of_measurements];

    for(int j = 0; j < number_of_measurements; j++){
        allocate_from_csv(object, dataFilePath, 5000 * (j + 1) * (j + 1));
        sum_of_time_elapsed = 0;
        for(int i = 0; i < mean_of_operations ; i++){
        
            sum_of_time_elapsed = test_time(object, [&object]() {
                object.deleteFront();
            });
            object.addFront(1);
            sum_of_time_elapsed += sum_of_time_elapsed;
        }
        sum_of_time_elapsed = sum_of_time_elapsed/mean_of_operations;
        keys[j] = object.getSize();
        values[j] = sum_of_time_elapsed;
    }
    save_to_csv(saveFilePath, key_name, value_name, keys, values, number_of_measurements);    
}
void Testing::test_del_back_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name = "count", std::string value_name = "time"){
    double sum_of_time_elapsed = 0;
    int keys[number_of_measurements];
    double values[number_of_measurements];

    for(int j = 0; j < number_of_measurements; j++){
        allocate_from_csv(object, dataFilePath, 5000 * (j + 1) * (j + 1));
        sum_of_time_elapsed = 0;
        for(int i = 0; i < mean_of_operations ; i++){
        
            sum_of_time_elapsed = test_time(object, [&object]() {
                object.deleteBack();
            });
            object.addBack(1);
            sum_of_time_elapsed += sum_of_time_elapsed;
        }
        sum_of_time_elapsed = sum_of_time_elapsed/mean_of_operations;
        keys[j] = object.getSize();
        values[j] = sum_of_time_elapsed;
    }
    save_to_csv(saveFilePath, key_name, value_name, keys, values, number_of_measurements);    
}

void Testing::test_del_random_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name = "count", std::string value_name = "time"){
    double sum_of_time_elapsed = 0;
    int keys[number_of_measurements];
    double values[number_of_measurements];
    int index;

    for(int j = 0; j < number_of_measurements; j++){
        allocate_from_csv(object, dataFilePath, 5000 * (j + 1) * (j + 1));
        sum_of_time_elapsed = 0;
        for(int i = 0; i < mean_of_operations ; i++){
            
            sum_of_time_elapsed = test_time(object, [&object]() {
                int index = rand() % (object.getSize() - 1);
                object.deleteIndex(index);
            });
            object.addIndex(1, 1);
            sum_of_time_elapsed += sum_of_time_elapsed;
        }
        sum_of_time_elapsed = sum_of_time_elapsed/mean_of_operations;
        keys[j] = object.getSize();
        values[j] = sum_of_time_elapsed;
    }
    save_to_csv(saveFilePath, key_name, value_name, keys, values, number_of_measurements);    
}

void Testing::test_contains_random_existing_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name = "count", std::string value_name = "time"){
    double sum_of_time_elapsed = 0;
    int keys[number_of_measurements];
    double values[number_of_measurements];
    int index;

    for(int j = 0; j < number_of_measurements; j++){
        allocate_from_csv(object, dataFilePath, 5000 * (j + 1) * (j + 1));
        sum_of_time_elapsed = 0;
        for(int i = 0; i < mean_of_operations ; i++){
            
            sum_of_time_elapsed = test_time(object, [&object]() {
                object.contains(object.lastElement());
            });
            sum_of_time_elapsed += sum_of_time_elapsed;
        }
        sum_of_time_elapsed = sum_of_time_elapsed/mean_of_operations;
        keys[j] = object.getSize();
        values[j] = sum_of_time_elapsed;
    }
    save_to_csv(saveFilePath, key_name, value_name, keys, values, number_of_measurements);    
}


void Testing::test_contains_non_existing_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name = "count", std::string value_name = "time"){
    double sum_of_time_elapsed = 0;
    int keys[number_of_measurements];
    double values[number_of_measurements];
    int index;

    for(int j = 0; j < number_of_measurements; j++){
        allocate_from_csv(object, dataFilePath, 5000 * (j + 1) * (j + 1));
        sum_of_time_elapsed = 0;
        for(int i = 0; i < mean_of_operations ; i++){
            
            sum_of_time_elapsed = test_time(object, [&object]() {
                object.contains(-1);
            });
            sum_of_time_elapsed += sum_of_time_elapsed;
        }
        sum_of_time_elapsed = sum_of_time_elapsed/mean_of_operations;
        keys[j] = object.getSize();
        values[j] = sum_of_time_elapsed;
    }
    save_to_csv(saveFilePath, key_name, value_name, keys, values, number_of_measurements);    
}

