#include <iostream>

using namespace std;

void init_pointer(int** pointer);

int main() {
	int* origPointer = NULL;
	cout << "Points to address: " << origPointer << endl;
	
	init_pointer(&origPointer);
	
	cout << endl;
	cout << "Now points to address: " << origPointer << endl;
	cout << "Now points to contents: " << *origPointer << endl;

	delete origPointer;
} 

void init_pointer(int** origPointer) {
	int* pointer = new int;
	*pointer = 10;
	*origPointer = pointer;
}

