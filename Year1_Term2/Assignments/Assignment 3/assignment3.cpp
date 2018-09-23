/*************************************************************************************************
 ** Program Filename: Assignment3: Functions
 ** Author: Zach Bishop
 ** Date: 2/1/2018
 ** Description: Test self-made functions and print whether or not the expected result was given
 ** Input: Nothing
 ** Output: Print test results to the screen
*************************************************************************************************/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/******************************************************************************
 ** Function: check_range
 ** Description: Indicates if the provided number is in the specified range
 ** Parameters: int lower_bound, int upper_bound, int test_value
 ** Pre-Conditions: Determined what lower_bound, upper_bound, and test_value are
 ** Post-Conditions: Return true or false
*****************************************************************************/
bool check_range(int lower_bound, int upper_bound, int test_value) {
	//Check if valid limits were inputted
	if (lower_bound > upper_bound || lower_bound == upper_bound) {
		cout << "The upper and lower limits are not valid! ";
		return false;
	}
	
	//Check if test_value is between the limits
	if (test_value <= upper_bound && test_value >= lower_bound) {
		return true;
	}
	else {
		return false;
	}
}

void unit_test_check_range() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing check_range()" << endl;
	cout << "Input: lower_bound = 50, upper_bound = 40, test_value = 45, Expected Output: False and error message, Actual Output: ";
	if (check_range(50, 40, 45)) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << endl;
	
	cout << "Input: lower_bound = 20, upper_bound = 40, test_value = 25, Expected Output: True, Actual Output: ";
	if (check_range(20, 40, 25)) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}	
	cout << endl;

	cout << "Input: lower_bound = 20, upper_bound = 40, test_value = 45, Expected Output: False, Actual Output: ";
	if (check_range(20, 40, 45)) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

/******************************************************************************
 ** Function: is_int
 ** Description: Indicates if a given string is an integer
 ** Parameters: string num
 ** Pre-Conditions: Determined what num is
 ** Post-Conditions: Return true or false
*****************************************************************************/
bool is_int (string num) {
	//Check every character of num
	for (int i = 0; i < num.length(); i++) {
		//Check if the current character is a num
		if ((num[i] >= 65 && num[i] <=90) || (num[i] >= 97 && num[i] <= 122)) {
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

void unit_test_is_int() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing is_int()" << endl;
	cout << "Input: num = \"20\", Expected Output: True, Actual Output: ";
	if (is_int("20")) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	cout << endl;
	
	cout << "Input: num = \"30.2\", Expected Output: False, Actual Output: ";
	if (is_int("30.2")) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}	
	cout << endl;

	cout << "Input: num = \"hi\", Expected Output: False, Actual Output: ";
	if (is_int("hi")) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

/******************************************************************************
 ** Function: is_float
 ** Description: Indicated if a given string is a float
 ** Parameters: string num
 ** Pre-Conditions: Determined what num is
 ** Post-Conditions: Return true or false
*****************************************************************************/
bool is_float(string num) {
	//A float must be at least 3 characters in length
	if (num.length() < 3) {
		return false;
	}
	
	//If the float is a negative, start checking each character one to the right
	int i = 0;
	if (num[0] == '-') {
		i += 1;
	}

	//Check each character and make sure it is a number until a decimal or the end of the string is hit
	for (; num[i] != '.' && i < num.length(); i++) {
		if (!(num[i] <= '9' && num[i] >= '0')) {
			return false;
		}
	}
	
	//If the end of the string has already been hit, there is either not a decimal or the decimal is at the end, making this not a float
	if (i == num.length() || (i == (num.length() - 1) && num[i] == '.')) {
		return false;
	}

	//Check after the deciaml and make sure everything is a number
	for (i++; i < num.length(); i++) {
		if (!(num[i] <= '9' && num[i] >= '0')) {
			return false;
		}
	}
	
	//If all previous tests were passed, the string must be a float
	return true;
}

void unit_test_is_float() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing is_float()" << endl;
	cout << "Input: num = \"20\", Expected Output: False, Actual Output: ";
	if (is_float("20")) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << endl;
	
	cout << "Input: num = \"2159\", Expected Output: False, Actual Output: ";
	if (is_float("2159")) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << endl;

	cout << "Input: num = \"30.2\", Expected Output: True, Actual Output: ";
	if (is_float("30.2")) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}	
	cout << endl;

	cout << "Input: num = \"hello\", Expected Output: False, Actual Output: ";
	if (is_float("hi")) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << endl;

	cout << "Input: num = \"30.\", Expected Output: False, Actual Output: ";
	if (is_float("30.")) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}	
	cout << endl;

	cout << "Input: num = \"-30.2\", Expected Output: True, Actual Output: ";
	if (is_float("-30.2")) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}	
	cout << endl;

	cout << "Input: num = \"-30\", Expected Output: False, Actual Output: ";
	if (is_float("-30")) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}	
	cout << endl;

	cout << "Input: num = \"30a.2\", Expected Output: False, Actual Output: ";
	if (is_float("30a.2")) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}	
	cout << endl;

	cout << "Input: num = \"30.a2\", Expected Output: False, Actual Output: ";
	if (is_float("30.a2")) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

/******************************************************************************
 ** Function: is_capital
 ** Description: Indicates if a given character is a capital letter
 ** Parameters: char letter
 ** Pre-Conditions: Determined what letter is
 ** Post-Conditions: Return true or false
*****************************************************************************/
bool is_capital(char letter) {
	//Check if the letter is a capital according to the ascii chart
	if (letter >= 65 && letter <= 90) {
		return true;
	}
	else {
		return false;
	}
}

void unit_test_is_capital() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing is_capital()" << endl;
	cout << "Input: letter = \'a\', Expected Output: False, Actual Output: ";
	if (is_capital('a')) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << endl;
	
	cout << "Input: letter = \'/\', Expected Output: False, Actual Output: ";
	if (is_capital('/')) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}	
	cout << endl;

	cout << "Input: letter = \'A\', Expected Output: True, Actual Output: ";
	if (is_capital('A')) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}
/******************************************************************************
 ** Function: is_even
 ** Description: Indicates if a given number is even
 ** Parameters: int num
 ** Pre-Conditions: Determined what num is
 ** Post-Conditions: Return true or false
*****************************************************************************/
bool is_even(int num) {
	//Check if the number is even by modding it by 2, the remainder should be 0
	if ((num % 2) == 0) {
		return true;
	}
	else {
		return false;
	}
}

void unit_test_is_even() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing is_even()" << endl;
	cout << "Input: num = 4, Expected Output: True, Actual Output: ";
	if (is_even(4)) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	cout << endl;
	
	cout << "Input: num = 3, Expected Output: False, Actual Output: ";
	if (is_even(3)) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}	
	cout << endl;
	
	cout << "Input: num = -1, Expected Output: False, Actual Output: ";
	if (is_even(-1)) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}	
	cout << endl;

	cout << "Input: num = -6, Expected Output: True, Actual Output: ";
	if (is_even(-6)) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}	
	cout << endl;


	cout << "Input: num = 0, Expected Output: True, Actual Output: ";
	if (is_even(0)) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

/******************************************************************************
 ** Function: is_odd
 ** Description: Indicates if a given number is odd
 ** Parameters: int num
 ** Pre-Conditions: Determined what num is
 ** Post-Conditions: Return true or false
*****************************************************************************/
bool is_odd(int num) {
	//Check if the number is odd by modding it by 2, the remainder should be 1 or -1
	if ((num % 2) == 1 || (num % 2) == -1) {
		return true;
	}
	else {
		return false;
	}
}

void unit_test_is_odd() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing is_odd()" << endl;
	cout << "Input: num = 4, Expected Output: False, Actual Output: ";
	if (is_odd(4)) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << endl;
	
	cout << "Input: num = 3, Expected Output: True, Actual Output: ";
	if (is_odd(3)) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}	
	cout << endl;
	
	cout << "Input: num = -1, Expected Output: True, Actual Output: ";
	if (is_odd(-1)) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}	
	cout << endl;

	cout << "Input: num = -6, Expected Output: False, Actual Output: ";
	if (is_odd(-6)) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}	
	cout << endl;


	cout << "Input: num = 0, Expected Output: False, Actual Output: ";
	if (is_odd(0)) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

/***************************************************************************************************************************
 ** Function: equality_test
 ** Description: Tests num1 against num2 and returns -1 if num1 < num2, returns 0 if num1 == num2, returns 1 if num1 > num2
 ** Parameters: int num1, int num2
 ** Pre-Conditions: Determined what num1 and num2 are
 ** Post-Conditions: Return -1, 0, or 1
****************************************************************************************************************************/
int equality_test(int num1, int num2) {
	//Check if num1 is less than, greater than, or equal to num2. Then return the correct integer
	if (num1 < num2) {
		return -1;
	}
	else if (num1 > num2) {
		return 1;
	}
	else if (num1 == num2) {
		return 0;
	}
}

void unit_test_equality_test() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing equality_test()" << endl;
	cout << "Input: num1 = 0, num2 = 0, Expected Output: 0, Actual Output: ";
	if (equality_test(0, 0) == 0) {
		cout << "0, PASS" << endl;
	}
	else if (equality_test(0, 0) == -1) {
		cout << "-1, FAIL" << endl;
	}
	else if (equality_test(0, 0) == 1) {
		cout << "1, FAIL" << endl;
	}
	cout << endl;
	
	cout << "Input: num1 = 1, num2 = 0, Expected Output: 1, Actual Output: ";
	if (equality_test(1, 0) == 0) {
		cout << "0, FAIL" << endl;
	}
	else if (equality_test(1, 0) == -1) {
		cout << "-1, FAIL" << endl;
	}
	else if (equality_test(1, 0) == 1) {
		cout << "1, PASS" << endl;
	}
	cout << endl;

	cout << "Input: num1 = 0, num2 = 1, Expected Output: -1, Actual Output: ";
	if (equality_test(0, 1) == 0) {
		cout << "0, FAIL" << endl;
	}
	else if (equality_test(0, 1) == -1) {
		cout << "-1, PASS" << endl;
	}
	else if (equality_test(0, 1) == 1) {
		cout << "1, FAIL" << endl;
	}
	cout << endl;

	cout << "Input: num1 = -10, num2 = 8, Expected Output: -1, Actual Output: ";
	if (equality_test(-10, 8) == 0) {
		cout << "0, FAIL" << endl;
	}
	else if (equality_test(-10, 8) == -1) {
		cout << "-1, PASS" << endl;
	}
	else if (equality_test(-10, 8) == 1) {
		cout << "1, FAIL" << endl;
	}
	cout << endl;

	cout << "Input: num1 = 8, num2 = -10, Expected Output: 1, Actual Output: ";
	if (equality_test(8, -10) == 0) {
		cout << "0, FAIL" << endl;
	}
	else if (equality_test(8, -10) == -1) {
		cout << "-1, FAIL" << endl;
	}
	else if (equality_test(8, -10) == 1) {
		cout << "1, PASS" << endl;
	}
	cout << endl;

	cout << "Input: num1 = -10, num2 = -10, Expected Output: 0, Actual Output: ";
	if (equality_test(-10, -10) == 0) {
		cout << "0, PASS" << endl;
	}
	else if (equality_test(-10, -10) == -1) {
		cout << "-1, FAIL" << endl;
	}
	else if (equality_test(-10, -10) == 1) {
		cout << "1, FAIL" << endl;
	}
	cout << endl;

	cout << "Input: num1 = 20, num2 = 20, Expected Output: 0, Actual Output: ";
	if (equality_test(20, 20) == 0) {
		cout << "0, PASS" << endl;
	}
	else if (equality_test(20, 20) == -1) {
		cout << "-1, FAIL" << endl;
	}
	else if (equality_test(20, 20) == 1) {
		cout << "1, FAIL" << endl;
	}
	cout << endl;

	cout << "Input: num1 = 5, num2 = 20, Expected Output: -1, Actual Output: ";
	if (equality_test(5, 20) == 0) {
		cout << "0, FAIL" << endl;
	}
	else if (equality_test(5, 20) == -1) {
		cout << "-1, PASS" << endl;
	}
	else if (equality_test(5, 20) == 1) {
		cout << "1, FAIL" << endl;
	}
	cout << endl;

	cout << "Input: num1 = 20, num2 = 5, Expected Output: 1, Actual Output: ";
	if (equality_test(20, 5) == 0) {
		cout << "0, FAIL" << endl;
	}
	else if (equality_test(20, 5) == -1) {
		cout << "-1, FAIL" << endl;
	}
	else if (equality_test(20, 5) == 1) {
		cout << "1, PASS" << endl;
	}

	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

/******************************************************************************
 ** Function: float_is_equal
 ** Description: Tests if num1 and num2 are equal to each other within a certain precision
 ** Parameters: float num1, float num2, float precision
 ** Pre-Conditions: Determined what num1, num2, and precision are
 ** Post-Conditions: Return true or false
*****************************************************************************/
bool float_is_equal(float num1, float num2, float precision) {
	//Add the precision to the smallest number, if the sum is bigger than the other number then the two numbers are equal within that precision
	if (num1 > num2) {
		if ((num2 + precision) >= num1) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (num1 < num2) {
		if ((num1 + precision) >= num2) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return true;
	}
}

void unit_test_float_is_equal() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing float_is_equal()" << endl;
	cout << "Input: num1 = 22.4, num2 = 22.5, precision = 0.1, Expected Output: True, Actual Output: ";
	if (float_is_equal(22.4, 22.5, 0.1)) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	cout << endl;
	
	cout << "Input: num1 = 22.4, num2 = 22.7, precision = 0.2, Expected Output: False, Actual Output: ";
	if (float_is_equal(22.4, 22.7, 0.2)) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << endl;



	cout << "Input: num1 = 22.4, num2 = 22.5, precision = 0.2, Expected Output: True, Actual Output: ";
	if (float_is_equal(22.4, 22.5, 0.2)) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	cout << endl;

	cout << "Input: num1 = 22.4, num2 = 22.5, precision = 0.1, Expected Output: True, Actual Output: ";
	if (float_is_equal(22.4, 22.5, 0.1)) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	cout << endl;

	cout << "Input: num1 = 22.45, num2 = 22.5, precision = 0.1, Expected Output: True, Actual Output: ";
	if (float_is_equal(22.45, 22.5, 0.1)) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	cout << endl;

	cout << "Input: num1 = 22.5, num2 = 22.4, precision = 0.1, Expected Output: True, Actual Output: ";
	if (float_is_equal(22.5, 22.4, 0.1)) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	cout << endl;

	cout << "Input: num1 = 21.6, num2 = 21.6, precision = 0.2, Expected Output: True, Actual Output: ";
	if (float_is_equal(21.6, 21.6, 0.2)) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}

	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

/******************************************************************************
 ** Function: numbers_present
 ** Description: Indicates if the provided string contains numbers
 ** Parameters: string sentence
 ** Pre-Conditions: Determined what sentence is
 ** Post-Conditions: Return true or false
*****************************************************************************/
bool numbers_present(string sentence) {
	//Check each character and see if it is a number
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] <= '9' && sentence[i] >= '0') {
			return true;
		}
	}
	return false;

}

void unit_test_numbers_present() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing numbers_present()" << endl;
	cout << "Input: sentence = \"abcde\", Expected Output: False, Actual Output: ";
	if (numbers_present("abcde")) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << endl;
	
	cout << "Input: sentence = \"a1bc2de\", Expected Output: True, Actual Output: ";
	if (numbers_present("a1bc2de")) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	cout << endl;

	cout << "Input: sentence = \" \", Expected Output: False, Actual Output: ";
	if (numbers_present(" ")) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << endl;

	cout << "Input: sentence = \"1234\", Expected Output: True, Actual Output: ";
	if (numbers_present("1234")) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}

	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

/******************************************************************************
 ** Function: letters_present
 ** Description: Indicates if the provided string contains letters
 ** Parameters: string sentence
 ** Pre-Conditions: Determined what sentence is
 ** Post-Conditions: Return true or false
*****************************************************************************/
bool letters_present(string sentence) {
	//Check each character and see if it is a letter
	for (int i = 0; i < sentence.length(); i++) {
		if ((sentence[i] >= 65 && sentence[i] <= 90) || (sentence[i] >= 97 && sentence[i] <= 122)) {
			return true;
		}
		return false;
	} 
}

void unit_test_letters_present() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing letters_present()" << endl;
	cout << "Input: sentence = \"1234\", Expected Output: False, Actual Output: ";
	if (numbers_present("abcde")) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << endl;
	
	cout << "Input: sentence = \"a1bc2de\", Expected Output: True, Actual Output: ";
	if (numbers_present("a1bc2de")) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	cout << endl;

	cout << "Input: sentence = \" \", Expected Output: False, Actual Output: ";
	if (numbers_present(" ")) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << endl;

	cout << "Input: sentence = \"abcd\", Expected Output: True, Actual Output: ";
	if (numbers_present("1234")) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}

	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

/******************************************************************************
 ** Function: contains_sub_string
 ** Description: Indicates if substring exists in sentence
 ** Parameters: string sentence, string sub_string
 ** Pre-Conditions: Determined what sentence and sub_string are
 ** Post-Conditions: Return true or false
*****************************************************************************/
bool contains_sub_string(string sentence, string sub_string) {
	//Go through every character and compare it to the first character in sub_string
	for (int i = 0; i < sentence.length(); i++) {
		//When a match is found, start comparing the rest of the letters in sentence to the letters in sub_String
		if (sentence[i] == sub_string[0]) {
			for (int j = 0; j < sub_string.length(); j++) {
				//If one of the letters in sentence does not match with sub_string, stop comparing and go back to the first loop and see if sub_string begins somewhere else in sentence. Otherwise, keep comparing until the end of sub_string is reached and return true
				if (sentence[i+j] != sub_string[j]) {
					break;
				}
				else if (sentence[i+j] == sub_string[j] && j == (sub_string.length() - 1)) {
					return true;
				}
			}
		}
	}
	return false;
}

void unit_test_contains_sub_string() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing contains_sub_string()" << endl;
	cout << "Input: sentence = \"abcd1234\", sub_string = \"dcba\", Expected Output: False, Actual Output: ";
	if (contains_sub_string("abcd1234", "dcba" )) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	cout << endl;

	cout << "Input: sentence = \"abcd1234\", sub_string = \"a\", Expected Output: True, Actual Output: ";
	if (contains_sub_string("abcd1234", "a" )) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	cout << endl;

	cout << "Input: sentence = \"abcd1234\", sub_string = \"cd12\", Expected Output: True, Actual Output: ";
	if (contains_sub_string("abcd1234", "cd12" )) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
		
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}


/******************************************************************************
 ** Function: word_count
 ** Description: Provides the number of words in a given string 
 ** Parameters: string sentence
 ** Pre-Conditions: Determined what sentence is
 ** Post-Conditions: Returns an int
*****************************************************************************/
int word_count(string sentence) {
	int wordCount = 0;
	
	//Run through all the characters in sentence except for the first one
	for (int i = 1; i < sentence.length(); i++) {
		// if the current character is a space and the one before is not, then a word was just passed. Or, if the end of sentence is reached and it does not end in a space, there is a word at the end of the sentence
		if ((sentence[i] == ' ' && sentence[i-1] != ' ') || (i == (sentence.length() - 1) && sentence[i] != ' ')) {
			wordCount++;
		}
	}
	return wordCount;
}

void unit_test_word_count() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing word_count()" << endl;
	cout << "Input: sentence = \"Hi\", Expected Output: 1, Actual Output: ";
	if (word_count("Hi") == 1) {
		cout << "1, PASS" << endl;
	}
	else {
		cout << word_count("Hi") << ", FAIL" << endl;
	}
	cout << endl;

	cout << "Input: sentence = \"Hi \", Expected Output: 1, Actual Output: ";
	if (word_count("Hi ") == 1) {
		cout << "1, PASS" << endl;
	}
	else {
		cout << word_count("Hi ") << ", FAIL" << endl;
	}
	cout << endl;

	cout << "Input: sentence = \" Hi\", Expected Output: 1, Actual Output: ";
	if (word_count(" Hi") == 1) {
		cout << "1, PASS" << endl;
	}
	else {
		cout << word_count(" Hi") << ", FAIL" << endl;
	}
	cout << endl;

	cout << "Input: sentence = \"Hello there, how are you?\", Expected Output: 5, Actual Output: ";
	if (word_count("Hello there, how are you?") == 5) {
		cout << "5, PASS" << endl;
	}
	else {
		cout << word_count("Hello there, how are you?") << ", FAIL" << endl;
	}

	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}


/******************************************************************************
 ** Function: to_upper
 ** Description: Capitalizes all letters in a given string and leave all non-letter characters unchanged
 ** Parameters: string sentence
 ** Pre-Conditions: Determined what sentence is
 ** Post-Conditions: Returns the inputed string with all letters capitalized
*****************************************************************************/
string to_upper(string sentence) {
	//Run through all the characters in sentence
	for (int i = 0; i < sentence.length(); i++) {
		//Check if the current character is a lowercase based on the ascii chart, if it is, change it to uppercase
		if (sentence[i] >= 97 && sentence[i] <= 122) {
			sentence[i] -= 32;
		}
	}
	return sentence;
}

void unit_test_to_upper() {	
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing to_upper()" << endl;
	cout << "Input: sentence = \"abcd\", Expected Output: \"ABCD\", Actual Output: ";
	if (to_upper("abcd") == "ABCD") {
		cout << "\"ABCD\", PASS" << endl;
	}
	else {
		cout << "\"" << to_upper("abcd") << "\"" << ", FAIL" << endl;
	}
	cout << endl;

	cout << "Input: sentence = \"ABCD\", Expected Output: \"ABCD\", Actual Output: ";
	if (to_upper("ABCD") == "ABCD") {
		cout << "\"ABCD\", PASS" << endl;
	}
	else {
		cout << "\"" << to_upper("ABCD") << "\"" << ", FAIL" << endl;
	}
	cout << endl;

	cout << "Input: sentence = \"aBcDe1F2g\", Expected Output: \"ABCDE1F2G\", Actual Output: ";
	if (to_upper("aBcDe1F2g") == "ABCDE1F2G") {
		cout << "\"ABCDE1F2G\", PASS" << endl;
	}
	else {
		cout << "\"" << to_upper("aBcDe1F2g") << "\"" << ", FAIL" << endl;
	}
	
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

/******************************************************************************
 ** Function: to_lower
 ** Description: Makes all letters lowercase in a given string
 ** Parameters: string sentence
 ** Pre-Conditions: Determined what sentence is
 ** Post-Conditions: Returns the inputed string with all letters lowercase
*****************************************************************************/
string to_lower(string sentence) {
	//Run through all the characters in sentence
	for (int i = 0; i < sentence.length(); i++) {
		//Check if the current character is an uppercase based on the ascii chart, if it is, change it to lowercase
		if (sentence[i] >= 65 && sentence[i] <= 90) {
			sentence[i] += 32;
		}
	}
	return sentence;
}

void unit_test_to_lower() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing to_lower()" << endl;
	cout << "Input: sentence = \"abcd\", Expected Output: \"abcd\", Actual Output: ";
	if (to_lower("abcd") == "abcd") {
		cout << "\"abcd\", PASS" << endl;
	}
	else {
		cout << "\"" << to_upper("abcd") << "\"" << ", FAIL" << endl;
	}
	cout << endl;

	cout << "Input: sentence = \"ABCD\", Expected Output: \"abcd\", Actual Output: ";
	if (to_lower("ABCD") == "abcd") {
		cout << "\"abcd\", PASS" << endl;
	}
	else {
		cout << "\"" << to_upper("ABCD") << "\"" << ", FAIL" << endl;
	}
	cout << endl;

	cout << "Input: sentence = \"aBcDe1F2g\", Expected Output: \"abcde1f2g\", Actual Output: ";
	if (to_lower("aBcDe1F2g") == "abcde1f2g") {
		cout << "\"ABCDE1F2G\", PASS" << endl;
	}
	else {
		cout << "\"" << to_upper("aBcDe1F2g") << "\"" << ", FAIL" << endl;
	}
	
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}


/******************************************************************************
 ** Function: get_int
 ** Description: Takes a prompt from the user as a string literal, checks if input is a valid integer, returns the provided integer
 ** Parameters: string prompt
 ** Pre-Conditions: Determined what prompt is
 ** Post-Conditions: Return the prompt as an int if it is a valid int
*****************************************************************************/
int get_int(string prompt) {
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

void unit_test_get_int() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing get_int()" << endl;
	cout << "Input: prompt = \"abcd1\", Expected Output: \"Error message and reprompt\", Actual Output: ";
	cout << get_int("abcd1");
	cout << endl;
	cout << endl;

	cout << "Input: prompt = \"34\", Expected Output: 34, Actual Output: ";
	if (get_int("34") == 34) {
		cout << "34, PASS" << endl;
	}
	else {
		cout <<  get_int("34")  << ", FAIL" << endl;
	}
	cout << endl;
	
	cout << "Input: prompt = \"34.2\", Expected Output: \"Error message and reprompt\", Actual Output: ";
	cout << get_int("34.2");
	cout << endl;

	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

/******************************************************************************
 ** Function: get_float
 ** Description: Takes a prompt from the user as a string literal, checks if input is a valid float, returns the provided float
 ** Parameters: string prompt
 ** Pre-Conditions: Determined what prompt is
 ** Post-Conditions: Return the prompt as a float if it is a valid float
*****************************************************************************/
float get_float(string prompt) {
	bool trueFloat;
	bool negative = false;
	float returnFloat = 0;
	int decimalPlace = 0;


	//Keep checking if prompt is a valid float until it is
	do {
		trueFloat = is_float(prompt);
		if (trueFloat == false) {
			cout << "That is not a valid float! Please input a valid float: ";
			cin >> prompt;
		}
	}
	while (trueFloat == false);
	
	//Determine where the decimal is to convert the string to a float
	for (; prompt[decimalPlace] != '.'; decimalPlace++) {
	}

	//Turn the string into a float
	int i = 0;

	//Adjust i in case of a negative
	if (prompt[0] == '-') {
		i++;
		negative = true;
	}

	for (; prompt[i] != '.'; i++) {
		returnFloat += ((prompt[i] - 48) * (pow(10, decimalPlace - (i + 1))));
	}

	//Start converting the rest of the string after the decimal
	i++;

	for (; i < prompt.length(); i++) {
		returnFloat += ((prompt[i] - 48) * (pow(10, decimalPlace - i)));
	}

	//Turn the float negative if needed
	if (negative == true) {
		returnFloat *= -1;
	}

	return returnFloat;
}

void unit_test_get_float() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Testing get_float()" << endl;
	cout << "Input: prompt = \"abcd1\", Expected Output: \"Error message and reprompt\", Actual Output: ";
	cout << get_float("abcd1");
	cout << endl;
	cout << endl;

	cout << "Input: prompt = \"34\", Expected Output: \"Error message and reprompt\", Actual Output: ";
	cout << get_float("34");
	cout << endl;
	cout << endl;
		
	cout << "Input: prompt = \"34.5\", Expected Output: 34.5, Actual Output: ";
	if (get_float("34.5") == 34.5) {
		cout << "34.5, PASS" << endl;
	}
	else {
		cout <<  get_float("34.5")  << ", FAIL" << endl;
	}

	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

/******************************************************************************
 ** Function: main
 ** Description: Where the program starts, will test all the other functions
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Print results of all the tests
*****************************************************************************/
int main() {
	unit_test_check_range();
	unit_test_is_int();
	unit_test_is_float();
	unit_test_is_capital();
	unit_test_is_even();
	unit_test_is_odd();
	unit_test_equality_test();
	unit_test_float_is_equal();
	unit_test_numbers_present();
	unit_test_letters_present();
	unit_test_contains_sub_string();
	unit_test_word_count();
	unit_test_to_upper();
	unit_test_to_lower();
	unit_test_get_int();
	unit_test_get_float();
}

