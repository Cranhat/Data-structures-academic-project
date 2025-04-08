#pragma once
#include <string>
#include <functional>
#include "..\Double linked list\Double linked list.hpp"

using namespace std;


class Testing{
    public:

    double test_time(DoubleLinkedList& object, std::function<void()> func);
    
    void save_to_csv(string saveFilePath, string key_name, string value_name, int keys[], float values[], int values_count);

};

int* create_randomized_list(int size, int max_value);

void save_array_to_csv(string saveFilePath, int values[], int values_count);