#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int get_search_replace(char charSrch, char* userStr, char* cpyStr); 
void set_replace_string(char* userStr, char* cpyStr);
void get_string(char* userStr, int strLength); 

int main() {
	int strLength;
	cout << "How long do you want your string to be? ";
	cin >> strLength;
	strLength += 1;
	
	while (cin.get() != '\n');

	char* userStr = new char[strLength];
	char* cpyStr = new char[strLength];
	char charSrch;
	int letterCount = 0;

	get_string(userStr, strLength);
	set_replace_string(userStr, cpyStr);
	letterCount = get_search_replace(charSrch, userStr, cpyStr);
	
	cout << "There are " << letterCount << " of that letter!" << endl;

	delete [] userStr;
	delete [] cpyStr;
}

void get_string(char* userStr, int strLength) {
	cout << "Please input a string: ";
	cin.get(userStr, strLength, '\n');
	cout << endl;
}

void set_replace_string(char* userStr, char* cpyStr) {
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

int get_search_replace(char charSrch, char* userStr, char* cpyStr) {
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

