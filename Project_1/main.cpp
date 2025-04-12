#include <iostream>
#include <string>


#include "Double linked list/Double linked list.cpp"
#include "DataStructure/DataStructure.cpp"
#include "Dynamic list/Dynamic list.cpp"
#include "Linked list/Linked list.cpp"
#include "Utilities/Utilities.cpp"

#include "Testing/Testing.cpp"

using namespace std;

void operations(){

}

int main(){
	char choice, innerchoice;
	int number, index;
	DataStructure* object = nullptr;


		printf("Choose data structure:\n1 - Dynamic Array\n2 - Linked List\n3 - Double Linked List\n");

		std::cin >> choice;

		if (choice == '1'){
			object = new DynamicArray();
		}else if(choice == '2'){
			object = new LinkedList();
		}else if (choice == '3'){
			object = new DoubleLinkedList();
		}else{
			printf("Wrong operation.\n");
		}
		while(1){
			printf("Choose operation:\n1 - build from file\n2 - add element\n3 - delete element\n4 - find element\n5 - print elements\n6 - exit\n");
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
				allocate_from_csv(*object, filePath, size);
				break;
			
			case '2':
				printf("Where do you want to add:\n1 - addFront\n2 - addBack\n 3 - addIndex\n 4 - addRandom\n");
				std::cin >> innerchoice;
				switch (innerchoice)
				{
				case '1':
					printf("Type a number to add: ");	
					std::cin >> number;
					object -> addFront(number);
					break;

				case '2':
					printf("Type a number to add: ");	
					std::cin >> number;
					object -> addBack(number);
					break;

				case '3':
					printf("Type a number to add: ");	
					std::cin >> number;
					printf("Type an index: ");	
					std::cin >> index;
					object -> addIndex(number, index);
					break;

				case '4':
					printf("Type a number to add: ");	
					std::cin >> number;

					object -> addIndex(number, index);
					break;
				
				default:
					printf("Wrong operation!\n");
					break;
				}
				break;

				case '3':
					printf("Where do you want to delete: 1 - deleteFront\n2 - deleteBack\n3 - deleteIndex\n4 - deleteRandom\n");
					std::cin >> innerchoice;
					switch (innerchoice)
					{
					case '1':
						object ->deleteFront();
						break;

					case '2':
						object -> deleteBack();
						break;

					case '3':
						printf("Type an index: ");	
						std::cin >> index;
						object -> deleteIndex(index);
						break;

					case '4':
						number = rand() % object -> getSize();
						object -> deleteIndex(index);
						break;
					
					default:
						printf("Wrong operation!\n");
						break;
					}
			break;
			case '4':
				printf("Type element you want to find: \n");
				std::cin >> number;
				std::cout << endl;

				if (object -> contains(number)){
					printf("Element is contained\n");
				}else{
					printf("Element is NOT contained\n");
				}
				break;
			case '5':
				printf("-------------------------\n");
				object -> printElements();
				printf("-------------------------\n");
				break;
			case '6':
				delete object;
				return 0;
			default:
				printf("Wrong operation!\n");
				break;
			}
		
	}
	delete object;
	return 0;
}