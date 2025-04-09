#pragma once
#include <string>

int* create_randomized_list(int size, int max_value);

void save_array_to_csv(std::string saveFilePath, int values[], int values_count);