#include <iostream>
#include <string>
using namespace std;

int main() {
	string my_str;
	cout << "Please give a string without spaces: ";
	cin >> my_str;
	//Missing semicolon
	int length = my_str.length();
	bool flag = true;
	for(int i=0; i<(length/2); i++) {
		//Changed -1 to -(i+1)
		if (my_str[i] != my_str[length-(i+1)]) {
			//Changed from true to false
			flag = false;	
		}	
	}
	if (flag) {
		cout << "It's a palindrome" << endl;	
	}
	else {
		//Changed >> to <<
		cout << "It's not a palindrome" << endl;	
	}

	return 0;	
}
