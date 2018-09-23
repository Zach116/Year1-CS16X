#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "./mult_div.h"

using namespace std;

bool run_again() {
	bool answer;

	cout << "Would you like to see a different size matrix (0-no, 1-yes)? ";
	cin >> answer;
	cin.ignore();
	cin.clear();

	if (answer == 1) {
		return true;
	}
	return false;
}

mult_div_values** create_table(int m, int n) {
	mult_div_values** table = new mult_div_values*[m];
	for (int i = 0; i < m; i++) {
		table[i] = new mult_div_values[n];
	}

	return table;
}

void set_mult_values(mult_div_values **table, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			table[i][j].mult = (i+1)*(j+1);
		}
	}
}

void set_div_values(mult_div_values **table, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			table[i][j].div = (float) ((i+1.0)/(j+1.0));
		}
	}
}

void print_mult(mult_div_values **table, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << table[i][j].mult << " ";
		}
		cout << endl;
	}
}

void print_div(mult_div_values **table, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << table[i][j].div << " ";
		}
		cout << endl;
	}
}

void delete_table(mult_div_values **table, int m) {
	for (int i = 0; i < m; i++) {
		delete [] table[i];
	}
	delete [] table;
}

bool is_valid_dimensions(char *m, char *n) {
	if ((!is_int(m) || *m < 1) || (!is_int(n) || *n < 1)) {
		return false;
	}

	return true;
}

/******************************************************************************
 ** Function: is_int
 ** Description: Indicates if a given string is an integer
 ** Parameters: string num
 ** Pre-Conditions: Determined what num is
 ** Post-Conditions: Return true or false
*****************************************************************************/
bool is_int (char* num) {
	//Check every character of num
	for (int i = 0; i < strlen(num); i++) {
		//Check if the current character is a num
		if ((num[i] >= 65 && num[i] <= 90) || (num[i] >= 97 && num[i] <= 122)) {
			return false;
		}
		//Check if the current character is a decimal
		if (num[i] == '.') {
			return false;
		}
	}
	//If the for loop runs all the way through, then the string must be an int
	return true;
}

/******************************************************************************
 ** Function: get_input
 ** Description: Gets input from the user to store in a c-style string
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
char* get_input() {
	char* str = new char;
	*str = '\0';
	while (cin.peek() != '\n') {
		add_one_char(&str, cin.get());
	}
	cin.ignore();
	cin.clear();
	
	return str;
}

/******************************************************************************
 ** Function: add_one_char
 ** Description: Adds a character to the end of a c-style string
 ** Parameters: char** str, char c
 ** Pre-Conditions: None
 ** Post-Conditions: str should have a character ended to the end of it
*****************************************************************************/
void add_one_char(char** str, char c) {
	char* temp = new char[strlen(*str) + 2];
	for (int i = 0; i < strlen(*str); i ++) {
		temp[i] = (*str)[i];
	}
	temp[strlen(*str)] = c;
	temp[strlen(*str) + 1] = '\0';
	
	delete [] (*str);

	(*str) = new char[strlen(temp) + 1];
	strcpy((*str), temp);
	delete [] temp;
}


