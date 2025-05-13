#include <iostream>
#include <string>

#include "DataStructure/DataStructure.cpp"
#include "Utilities/Utilities.hpp"
#include "Heap/Heap.cpp"
#include "Array/Array.cpp"

#include "Testing/Testing.cpp"

using namespace std;

void operations(){

}

int main(){
	char choice;
	int number, key;
    Testing testing;
	DataStructure* object = nullptr;


		printf("Choose data structure:\n1 - Heap\n2 -PriorityQueueArray\n");

		std::cin >> choice;

		if (choice == '1'){
			object = new Heap();
		}else if(choice == '2'){
			object = new PriorityQueueArray();
		}else{
			printf("Wrong operation.\n");
		}
		while(1){

			printf("Choose operation:\n1 - build from file\n2 - add element\n3 - delete element\n4 - print elements\n5 - exit\n");
			std::cin >> choice;
			std::string filePath;
			int size;
			
			switch (choice)
			{
			case '1':
				
				printf("Type file path:");
				std::cin >> filePath;
				std::cout << endl;
				printf("Type size you want to allocate:");
				std::cin >> size;
				std::cout << endl;
				testing.allocate_from_csv(*object, filePath, size);
				break;
			
			case '2':

                std::cout << "Type a number: ";
				std::cin >> number;
                std::cout << "Type a key: ";
				std::cin >> key;
				object -> insert(key, number);
				break;

			case '3':

				object -> extractMax();
				break;


			case '4':
				printf("-------------------------\n");
				object -> printElements();
				printf("-------------------------\n");
				break;
			case '5':
				return 0;
			default:
				printf("Wrong operation!\n");
				break;
			}
		
	}
	delete object;
	return 0;
}