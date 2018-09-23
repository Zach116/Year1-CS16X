#include <iostream>
#include <string>

using namespace std;

int get_search_replace(char charSrch, string userStr, string & cpyStr); 
void set_replace_string(string userStr, string* cpyStr);
void get_string(string * userStr); 

int main() {
	string userStr, cpyStr;
	char charSrch;
	int letterCount = 0;

	get_string(&userStr);
	set_replace_string(userStr, &cpyStr);
	letterCount = get_search_replace(charSrch, userStr, cpyStr);
	
	cout << "There are " << letterCount << " of that letter!" << endl;
}

void get_string(string * userStr) {
	cout << "Please input a string: ";
	getline(cin, *userStr);
	cout << endl;
}

void set_replace_string(string userStr, string* cpyStr) {
	*cpyStr = userStr;

	cout << "userStr = " << userStr << endl;
	cout << "cpyStr = " << *cpyStr << endl;
	cout << endl;
	cout << "Changing cpyStr to just dashes..." << endl;

	for (int i = 0; i < userStr.length(); i++) {
		if (userStr[i] != ' ') {
			userStr[i] = '-';
		}
	}
	*cpyStr = userStr;

	cout << "cpyStr = " << *cpyStr << endl;
	cout << endl;
}

int get_search_replace(char charSrch, string userStr, string & cpyStr) {
	int letterCount = 0;

	cout << "What character would you like to search for? ";
	cin >> charSrch;

	for (int i = 0; i < cpyStr.length(); i++) {
		if (userStr[i] == charSrch) {
			cpyStr[i] = charSrch;
			letterCount++;
		}
	}
	cout << "cpyStr = " << cpyStr << endl;
	return letterCount;
}
