/********************************
 ** Program Filename: HelloWorld
 ** Author: Zach Bishop
 ** Date: 1/11/2018
 ** Description: The classic HelloWorld C++ code
 ** Input: Nothing
 ** Output: "Hello World" text to screen
 *******************************/

#include <iostream>

int main() {
	int number;

	std::cout << "Hello World" << std::endl;

	std::cout << "Enter an integer whole number: ";
	std::cin >> number;
	std::cout << number << std::endl;

	return 0;
}



