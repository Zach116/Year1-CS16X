//#include <iostream>
#include <stdlib.h>
#include <stdio.h>
//#include <cstring>
//#include <fstream>
#include <math.h>
#include <string.h>
#include "tools.h"

//using namespace std;

/******************************************************************************
 ** Function: add_one_char
 ** Description: Adds a character to the end of a c-style string
 ** Parameters: char** str, char c
 ** Pre-Conditions: None
 ** Post-Conditions: str should have a character added to the end of it
*****************************************************************************/
/*void add_one_char(char** str, char c) {
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
}*/
void add_one_char(char** str, char c) {
	char* temp = (char*) malloc(sizeof(char)* (strlen(*str) + 2));
	for (int i = 0; i < strlen(*str); i ++) {
		temp[i] = (*str)[i];
	}
	temp[strlen(*str)] = c;
	temp[strlen(*str) + 1] = '\0';
	free(*str);
	(*str) = (char*) malloc(sizeof(char)*(strlen(temp) + 1));
	strcpy((*str), temp);
	free(temp);
}
/******************************************************************************
 ** Function: get_input
 ** Description: Gets input from the user to store in a c-style string
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
/*char* get_input() {
	char* str = new char[1];
	*str = '\0';
	while (cin.peek() != '\n') {
		add_one_char(&str, cin.get());
	}
	cin.ignore();
	cin.clear();

	return str;
}
*/
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
 ** Function: is_int
 ** Description: Indicates if a given string is an integer
 ** Parameters: string num
 ** Pre-Conditions: Determined what num is
 ** Post-Conditions: Return true or false
*****************************************************************************/
/*bool is_int (string num) {
	//Check every character of num
	for (int i = 0; i < num.length(); i++) {
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
*/
/******************************************************************************
 ** Function: get_int
 ** Description: Takes a prompt from the user as a string literal, checks if input is a valid integer, returns the provided integer
 ** Parameters: string prompt
 ** Pre-Conditions: Determined what prompt is
 ** Post-Conditions: Return the prompt as an int if it is a valid int
*****************************************************************************/
/*int get_int(char* prompt) {
	bool trueInt = true;
	int returnInt = 0;
	bool negative = false;
	bool deletion = false;

	//Keep checking if prompt is a valid integer until it is
	do {
		trueInt = is_int(prompt);
		if (trueInt == false) {
			cout << "That is not a valid integer! Please input a valid integer: ";
			prompt = get_input();
			deletion = true;
		}
	} while (trueInt == false);

	int i = 0;
	//Adjust i in case of a negative
	if (prompt[0] == '-') {
		i++;
		negative = true;
	}

	//Turn the string into an int
	for (; i < strlen(prompt); i++) {
		returnInt += ((prompt[i] - 48) * (pow(10, strlen(prompt) - (i + 1))));
	}

	//Turn the int negative if needed
	if (negative == true) {
		returnInt *= -1;
	}
	//Delete prompt from the heap if it was obtained using get_input
	if (deletion == true) {
		delete [] prompt;
	}
	return returnInt;
}*/

int get_int(char* prompt) {
	bool trueInt = true;
	int returnInt = 0;
	bool negative = false;
	bool deletion = false;

	//Keep checking if prompt is a valid integer until it is
	/*do {
		trueInt = is_int(prompt);
		if (trueInt == false) {
			//cout << "That is not a valid integer! Please input a valid integer: ";
			prompt = get_input();
			deletion = true;
		}
	} while (trueInt == false);
*/
	int i = 0;
	//Adjust i in case of a negative
	if (prompt[0] == '-') {
		i++;
		negative = true;
	}

	//Turn the string into an int
	for (; i < strlen(prompt); i++) {
		returnInt += ((prompt[i] - 48) * (pow(10, (strlen(prompt) - (i + 1)))));
	}

	//Turn the int negative if needed
	if (negative == true) {
		returnInt *= -1;
	}
	//Delete prompt from the heap if it was obtained using get_input
	if (deletion == true) {
		free(prompt);
	}
	return returnInt;
}


/******************************************************************************
 ** Function: get_int
 ** Description: Takes a prompt from the user as a string literal, checks if input is a valid integer, returns the provided integer
 ** Parameters: string prompt
 ** Pre-Conditions: Determined what prompt is
 ** Post-Conditions: Return the prompt as an int if it is a valid int
*****************************************************************************/
/*int get_int(string prompt) {
	bool trueInt;
	int returnInt = 0;
	bool negative = false;

	//Keep checking if prompt is a valid integer until it is
	do {
		trueInt = is_int(prompt);
		if (trueInt == false) {
			cout << "That is not a valid integer! Please input a valid integer: ";
			cin >> prompt;
		}
	}
	while (trueInt == false);


	int i = 0;
	//Adjust i in case of a negative
	if (prompt[0] == '-') {
		i++;
		negative = true;
	}

	//Turn the string into an int
	for (; i < prompt.length(); i++) {
		returnInt += ((prompt[i] - 48) * (pow(10, prompt.length() - (i + 1))));
	}

	//Turn the int negative if needed
	if (negative == true) {
		returnInt *= -1;
	}

	return returnInt;
}
*/
/******************************************************************************
 ** Function: lowercase
 ** Description: changes all uppercase letters to lowercase
 ** Parameters: string word
 ** Pre-Conditions: None
 ** Post-Conditions: changes all uppercase letters to lowercase
*****************************************************************************/
/*string lowercase(string word) {
	for (int i = 0; i < word.length(); i++) {
		if (word[i] >= 'A' && word[i] <= 'Z') {
			word[i] = word[i] + 32;
		}
	}
	return word;
}*/
