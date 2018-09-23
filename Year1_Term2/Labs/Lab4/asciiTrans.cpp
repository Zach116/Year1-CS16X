#include <iostream>
using namespace std;


int a_to_i(char character);
int i_to_a(int decimal);

int main() {
	char character;
	int decimal;

	cout << "Please enter a character:" << endl;
	cin >> character;
	cout << endl;

	decimal = a_to_i(character);
	
	cout << "That character's ascii decimal value is:" << endl;
	cout << decimal << endl;
	cout << endl;

	cout << "Please enter an integer:" << endl;
	cin >> decimal;
	cout << endl;

	character = i_to_a(decimal);

	cout << "That decimal represents the character: " << endl;
	cout << character << endl;
	cout << endl;
}

int a_to_i(char character) {
	int decimal;

	decimal = (int) character;

	return decimal;
}

int i_to_a(int decimal) {
	char character;

	character = (char) decimal;

	return decimal;
}
