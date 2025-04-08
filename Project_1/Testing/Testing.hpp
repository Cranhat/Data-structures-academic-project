#pragma once
#include <string>
#include <functional>
#include "..\Double linked list\Double linked list.hpp"

using namespace std;


class Testing{


    public:

    double test_time(DoubleLinkedList& object, std::function<void()> func);
    
    void save_to_csv(string saveFilePath, int keys[], float values[], int values_count);

};