#pragma once

#include <string>
#include <functional>
#include "..\Double linked list\Double linked list.hpp"

class Testing{
    public:

    double test_time(DataStructure& object, std::function<void()> func);
    
    void save_to_csv(std::string saveFilePath, std::string key_name, std::string value_name, int keys[], double values[], int values_count);

};