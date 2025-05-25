#pragma once

#include "../DataStructures/DataStructure/DataStructure.hpp" 
#include <string>
#include <functional>

class Testing{
    
    public:

    double test_time(DataStructure& object, std::function<void()> func);

    void allocate_from_csv(DataStructure& object, std::string FilePath, int size);
    
    void save_to_csv(std::string saveFilePath, std::string key_name, std::string value_name, int keys[], double values[], int values_count);

    void test_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, std::string operation, int sizes[], int sizes_size, int mean_of_operations, float load_factor, std::string key_name, std::string value_name);

};