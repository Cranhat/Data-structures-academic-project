#pragma once

#include <string>
#include <functional>
#include "..\Double linked list\Double linked list.hpp"

class Testing{
    public:

    double test_time(DataStructure& object, std::function<void()> func);
    
    void save_to_csv(std::string saveFilePath, std::string key_name, std::string value_name, int keys[], double values[], int values_count);

    void test_add_front_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name, std::string value_name);

    void test_add_back_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name, std::string value_name);

    void test_add_random_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name, std::string value_name);

    void test_del_front_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name, std::string value_name);

    void test_del_back_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name, std::string value_name);

    void test_del_random_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name, std::string value_name);

    void test_find_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name, std::string value_name);

    void test_contains_random_existing_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name, std::string value_name);

    void test_contains_non_existing_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, std::string key_name, std::string value_name);

};