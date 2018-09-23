#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int get_search_replace(char charSrch, char userStr[256], char* cpyStr); 
void set_replace_string(char userStr[256], char* cpyStr);
void get_string(char* userStr); 

int main() {
	char userStr[256], cpyStr[256];
	char charSrch;
	int letterCount = 0;

	get_string(userStr);
	set_replace_string(userStr, cpyStr);
	letterCount = get_search_replace(charSrch, userStr, cpyStr);
	
	cout << "There are " << letterCount << " of that letter!" << endl;

}

void get_string(char* userStr) {
	cout << "Please input a string: ";
	cin.get(userStr, 256, '\n');
	cout << endl;
}

void set_replace_string(char userStr[256], char* cpyStr) {
	for (int i = 0; i < strlen(userStr); i++) {
		cpyStr[i] = userStr[i];
	}

	cout << "userStr = ";
	for (int i = 0; i < strlen(userStr); i++) {
		cout << userStr[i];
	}
	cout << endl;

	cout << "cpyStr = ";
	for (int i = 0; i < strlen(userStr); i++) {
		cout << cpyStr[i];
	}
	cout << endl;

	cout << endl;
	cout << "Changing cpyStr to just dashes..." << endl;

	for (int i = 0; i < strlen(userStr); i++) {
		if (userStr[i] != ' ') {
			cpyStr[i] = '-';
		}
	}
	
	cout << "cpyStr = ";
	for (int i = 0; i < strlen(userStr); i++) {
		cout << cpyStr[i];
	}
	cout << endl;
	
	cout << endl;
}

int get_search_replace(char charSrch, char userStr[256], char* cpyStr) {
	int letterCount = 0;

	cout << "What character would you like to search for? ";
	cin >> charSrch;
	
	for (int i = 0; i < strlen(userStr); i++) {
		if (userStr[i] == charSrch) {
			cpyStr[i] = charSrch;
			letterCount++;
		}
	}
	cout << "cpyStr = ";
	for (int i = 0; i < strlen(userStr); i++) {
		cout  << cpyStr[i];
	}
	cout << endl;
	
	return letterCount;
}

