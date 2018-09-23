/**************************************************************************************************************************************************
 ** Program Filename: Assignment 4: Calculator
 ** Author: Zach Bishop
 ** Date: 2/16/2018
 ** Description: This program is a calculator with four different modes: standard calculations, decimal to binary, binary to decimal, and grade calculator.
 ** Input: User input
 ** Output: Various results printed to screen
**************************************************************************************************************************************************/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Function declarations:
void mode_sel();
void stand_calc(); 
void bin_to_dec();
void dec_to_bin();
void grade_calc();
bool is_valid_bin(string binInput); 
bool is_valid_dec(string num); 
int get_int(string prompt); 
void dec_to_bin_exe(int input); 
float get_float(string prompt);
bool is_float(string num); 
bool is_int (string num);
bool is_int (char character); 
bool valid_number(string sentence);
void weighted_average(float average); 
bool valid_equation(string equation);
bool is_operator(char character);
bool is_operator(string str);

/**************************************************************************************************************************************************
 ** Function: main
 ** Description: Where the program starts, continually asks user if they want to rerun the program until they say no
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
int main() {
	string runProgram;
	
	//Run the program until the user does not want to anymore
	do {
		mode_sel();
		
		//Continually ask if the user would like to run the program again until 1 or 2 is entered
		do {
			cout << "Would you like to do another calculation? (enter 1 or 2)" << endl;
			cout << "1) Yes" << endl;
			cout << "2) No" << endl;
			getline (cin, runProgram);
		 	cout << endl;
						
			//Prints error message
			if (!(runProgram == "1" || runProgram == "2")) {
				cout << "PLEASE ENTER 1 OR 2 " << endl;
			}
		} while (!(runProgram == "1" || runProgram == "2"));
	} while (runProgram == "1");
}

/**************************************************************************************************************************************************
 ** Function: mode_sel
 ** Description: Determines what mode the user wants to run
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
void mode_sel() {
	string modeChoice;
	
	//Continue to ask the user which mode they want until a valid input is given
	do {
		cout << "Which mode would you like to run?" << endl;
		cout << "1) Standard Calculator" << endl;
		cout << "2) Binary to Decimal" << endl;
		cout << "3) Decimal to Binary" << endl;
		cout << "4) Grade Calculator" << endl;
		getline(cin, modeChoice);
		cout << endl;

		//Prints error message if invalid option is entered
		if (!(modeChoice == "1" || modeChoice == "2" || modeChoice == "3" || modeChoice == "4")) {
			cout << "PLEASE ENTER 1, 2, 3, OR 4" << endl;
		} 
	} while (!(modeChoice == "1" || modeChoice == "2" || modeChoice == "3" || modeChoice == "4"));

	//Run the appropriate program
	if (modeChoice == "1") {
		stand_calc();
	}
	else if (modeChoice == "2") {
		bin_to_dec();
	}
	else if (modeChoice == "3") {
		dec_to_bin();
	}
	else if (modeChoice == "4") {
		grade_calc();
	}
}

/**************************************************************************************************************************************************
 ** Function: stand_calc
 ** Description: Does general calculations (+, -, /, *) according to a single line string inputted by the user
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
void stand_calc() {
	string equation, curOpperator = "0", subStr = "0";
	int space1 = 0, space2 = 0;
	float total = 0;

	//Continue to ask the user for an equation until they put in a valid equation
	do {
		cout << "Please input an equation with spaces between the operand and operator. The operand can only be positive. Cannot divide by zero" << endl;
		getline (cin, equation);
		cout << endl;

		if (!valid_equation(equation)) {
			cout << "PUT SPACES BETWEEN OPERATOR AND OPERAND ONLY! ONLY INPUT POSITIVE NUMBERS!" << endl;	
		}
	} while(!valid_equation(equation));

	//Determine what the first number is and set the total to it
	for (int i = 0; i < equation.length(); i++) {
		if (equation[i] == ' ') {
			space2 = i;
			subStr = equation.substr(space1, (space2 - space1));

			//Convert the substring to a float or int and add to total
			if (is_int(subStr)) {
				total = get_int(subStr);
			}
			else if (is_float(subStr)) {
				total = get_float(subStr);
			}

			//Assign space1 to the beginning of the next substring
			space1 = space2 + 1;
			break;
		}
	}

	//Carry out the rest of the equation dependent on what the operator is
	for (int i = (space1); i < equation.length(); i++) {
		if (equation[i] == ' ' || i == (equation.length() - 1)) {
			//Set space2 to the end point of the substring
			space2 = i;
		
			//Set the subStr according to whether or not the end of the equation has been reached	
			if (i == (equation.length() - 1)) {	
				subStr = equation.substr(space1, ((space2 + 1) - space1));
			}
			else {
				subStr = equation.substr(space1, (space2 - space1));
			}
			
			//Either assign a new curOpperator or carry out a calculation according to what substring is
			if (is_operator(subStr)) {
				curOpperator = subStr;
			}
			else if (is_float(subStr)) {
				if (curOpperator == "+") {
					total += get_float(subStr);
				}
				else if (curOpperator == "-") {
					total -= get_float(subStr);
				}
				else if (curOpperator == "*") {
					total *= get_float(subStr);
				}
				else if (curOpperator == "/") {
					total /= get_float(subStr);
				}
			}
			else if (is_int (subStr)) {
				if (curOpperator == "+") {
					total += get_int(subStr);
				}
				else if (curOpperator == "-") {
					total -= get_int(subStr);
				}
				else if (curOpperator == "*") {
					total *= get_int(subStr);
				}
				else if (curOpperator == "/") {
					total /= get_int(subStr);
				}
			}

			//Assign space1 to the beginning of the next substring
			space1 = space2 + 1;
		}
	}
	cout << "The answer to your equation is: " << total << endl;

}

/**************************************************************************************************************************************************
 ** Function: valid_equation
 ** Description: Checks to see if the inputted equation fits the required format
 ** Parameters: string equation
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
bool valid_equation(string equation) {
	int operatorCount = 0, space1 = 0, space2 = 0;
	string curOpperator = "0", subStr = "0";
	float total = 0;
	
	//Check first and last character and make sure they are numbers
	if ((equation[0] < '0' || equation[0] > '9')  || (equation[equation.length() - 1] < '0' || equation[equation.length() - 1] > '9')) {
		return false;	
	}	
	
	//Make sure there is an operator in the equation and there are only numbers on either side after the spaces and there is no divide by zero
	for (int i = 0; i < equation.length(); i++) {
		if (is_operator(equation[i])) {
			//Make sure there are numbers before and after the operator after the spaces
			if (!is_int(equation[i-2]) || !is_int(equation[i+2])) {
				return false;
			}
			//Make sure there is no divide by zero
			if (equation[i] == '/' && equation[i+2] == '0') {
				return false;
			}

			operatorCount++;
		}
	}
	
	if (operatorCount == 0) {
		return false;
	}

	//Make sure that all continuous characters are floats, ints, or operators. Also make sure there are not two spaces next to each other
	for (int i = 0; i < equation.length(); i++) {
		//Check if there are two spaces next to each other
		if (equation[i] == ' ' && equation[i+1] == ' ') {
			return false;
		}
	
		if (equation[i] == ' ' || i == (equation.length() - 1)) {
			//Set space2 to the end point of the substring
			space2 = i;

			//Set the subStr according to whether or not the end of the equation has been reached	
			if (i == (equation.length() - 1)) {	
				subStr = equation.substr(space1, ((space2 + 1) - space1));
			}
			else {
				subStr = equation.substr(space1, (space2 - space1));
			}			
			
			//Check to see if subStr is an opperator, float, or an int. If it is not, then the equation is not valid
			if (!is_operator(subStr) && !is_float(subStr) && !is_int(subStr)) {
				return false;
			}
			
			//Set space1 to the beginning of the next substring
			space1 = space2 + 1;
		}
	}
	//If all tests are passed the equation must be valid
	return true;
}

/**************************************************************************************************************************************************
 ** Function: is_operator
 ** Description: Checks if a character is an operator
 ** Parameters: char character
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
bool is_operator(char character) {
	//Check if the character is an operator
	if (character == '+' || character == '-' || character == '/' || character == '*') {
		return true;
	}
	return false;
}

/**************************************************************************************************************************************************
 ** Function: is_operator
 ** Description: Checks if a string is an operator
 ** Parameters: string str
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
bool is_operator(string str) {
	//Check if the string is an operator
	if (str == "+" || str == "-" || str == "/" || str == "*") {
		return true;
	}
	return false;
}


/**************************************************************************************************************************************************
 ** Function: bin_to_dec
 ** Description: Takes a string input of binary and turns it into its decimal value
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
void bin_to_dec() {
	string binInput;
	int total = 0;

	//Get the users binary number
	do {
		cout << "Please input a valid unsigned binary number, can be 8 digits long maximum: ";
		getline(cin, binInput);

		if (!(is_valid_bin(binInput))) {
			cout << endl;
			cout << "NOT VALID BINARY, ONLY ENTER ONES AND ZEROS WITH A MAXIMUM LENGTH OF 8!" << endl;
		}
	} while (!(is_valid_bin(binInput)));

	//Calculate the decimal value by converting each number to its appropriate decimal value and adding them all
	for (int i = 0; i < binInput.length(); i++) {
		total += (pow(2, (binInput.length() - (i + 1)))) * (binInput[i] - 48);	
	}
	
	cout << endl;
	cout << "The decimal value of that binary is: " << total << endl;
}

/**************************************************************************************************************************************************
 ** Function: is_valid_bin
 ** Description: Checks to see if the input is a valid binary by checking if all the characters are 1's or 0's
 ** Parameters: string binInput
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
bool is_valid_bin(string binInput) {
	//Make sure the length is less than 9
	if (binInput.length() > 8) {
		return false;
	}
	
	//Runs through every character and checks to see if it is a one or zero, if it is not the string is not in binary
	for (int i = 0; i < binInput.length(); i++) {
		if (!(binInput[i] == '1' || binInput[i] == '0')) {
			return false;
		}
	}
	return true;
}

/**************************************************************************************************************************************************
 ** Function: dec_to_bin
 ** Description: Takes an int input from the user and turns it into binary
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
void dec_to_bin() {
	string decInput;

	//Continue to ask the user for input until they give a valid input
	do {
		cout << "Please input a whole number between 0 and 255: ";
		getline(cin, decInput);
		
		if (!(is_valid_dec(decInput))) {
			cout << endl;
			cout << "ENTER ONLY A WHOLE NUMBER BETWEEN 0 AND 255" << endl;			
		}
	} while (!(is_valid_dec(decInput)));
	
	//Change the input from string to int and calculate what the input decimal is in binary and print to screen
	cout << endl;
	dec_to_bin_exe(get_int(decInput));
	cout << endl;
}

/**************************************************************************************************************************************************
 ** Function: is_valid_dec
 ** Description: Checks to see if the input is a valid integer between 0 and 255, uses code from assignment3
 ** Parameters: string num
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
bool is_valid_dec(string num) {
	//Check every character of num
	for (int i = 0; i < num.length(); i++) {
		//Check if the current character is a number
		if ((num[i] >= 65 && num[i] <=90) || (num[i] >= 97 && num[i] <= 122)) {
			return false;
		}
		//Check if the current character is a decimal
		if (num[i] == '.') {
			return false;
		}
	}

	//Check to see if the string is a number between 0 and 255
	if (get_int(num) < 0 || get_int(num) > 255) {
		return false;
	}

	//If the for loop runs all the way through, then the string must be an int
	return true;

}

/******************************************************************************
 ** Function: get_int
 ** Description: Takes a prompt from the user as a string literal, checks if input is a valid integer, returns the provided integer
 ** Parameters: string prompt
 ** Pre-Conditions: Prompt must be an integer stored as a string
 ** Post-Conditions: None
*****************************************************************************/
int get_int(string prompt) {
	int returnInt = 0;
	bool negative = false;
		
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

/**************************************************************************************************************************************************
 ** Function: dec_to_bin_exe
 ** Description: Takes an integer and turns it into binary
 ** Parameters: int input
 ** Pre-Conditions: decInput must be an integer between 0 and 255
 ** Post-Conditions: None
**************************************************************************************************************************************************/
void dec_to_bin_exe(int decInput) {
	int remainder = 0;

	//If the base case is reached, print out the current input
	if (decInput == 0 || decInput == 1) {
		cout << "The binary value for that decimal is: " << decInput;
	}
	//recursively mod decInput by 2 and store the remainder until decInput is down to 0 or 1. Print out all the remainders in reverse
	else {
		remainder = decInput % 2;
		decInput = decInput/2;
		dec_to_bin_exe(decInput);
		cout << remainder;
	}
}

/**************************************************************************************************************************************************
 ** Function: grade_calc
 ** Description: Takes a number of grades specified by the user, adds them, and divides by the number of grades to give the average. Will also give the weighted average if the user chooses that option. The weight is given by the user
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
void grade_calc() {
	string numberStr = "0", grade = "0";
	float average = 0, total = 0; 
	int numberInt = 0;

	//Continually ask user how many grades they want until a valid input is given
	do {
		cout << "How many grades would you like to input? (Must be greater than 0) ";
		getline (cin,numberStr);
		cout << endl;
			
		if (numberStr <= "0" || !is_int(numberStr)) {
			cout << "PLEASE ONLY INPUT WHOLE NUMBERS GREATER THAN 0!" << endl;
		}
			
	} while (numberStr <= "0" || !is_int(numberStr));
	
	//Change the number of grades from string to float
	numberInt = get_int(numberStr);

	//Asks the user for the specified number of grades and adds them all together
	for (int i = 0; i < numberInt; i++) {
		//Continually asks the user for the current grade until a valid input is given
		do {
			cout << "Please enter a positive number for grade " << (i + 1) << ": ";
			getline(cin, grade);

			if (grade < "0" || !valid_number(grade)) {
				cout << endl;
				cout << "ONLY ENTER POSITIVE NUMBERS" << endl;
			}
		} while (grade < "0" || !valid_number(grade));
		
		//Refresh the new total according to whether or not the grade is an int or float
		if (is_int(grade)) {
			total += get_int(grade);
		}
		else if (is_float(grade)) {
			total += get_float(grade);
		}
	}

	//Calculate the average
	cout << endl;
	average = total/numberInt;
	cout << "The average for the grades inputted is: " << average << endl;
	
	//Run the weighted average calculation
	weighted_average(average);
}

/**************************************************************************************************************************************************
 ** Function: weighted_average
 ** Description: Makes a weighted avearage based on an already calculated average
 ** Parameters: float average
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
void weighted_average(float average) {
	string weight = "0", runProgram;

	//Ask the user if they would like to run this program until a valid input is given
	do {
		cout << "Would you like to calculate the weighted average for this average?" << endl;
		cout << "1) Yes" << endl;
		cout << "2) No" << endl;
		getline (cin, runProgram);
	 	cout << endl;
					
		//Prints error message
		if (!(runProgram == "1" || runProgram == "2")) {
			cout << "PLEASE ENTER 1 OR 2 " << endl;
		}
	} while (!(runProgram == "1" || runProgram == "2"));	
	
	if (runProgram == "1") {
		//Continually ask the user for a weight until a valid weight is given
		do {
			cout << "Please enter a positive weight: ";
			getline(cin, weight);
		
			if (weight < "0" || !valid_number(weight)) {
				cout << endl;
				cout << "ONLY ENTER POSITIVE NUMBERS" << endl;
			}
		} while (weight < "0" || !valid_number(weight));
		
		//Calculate the weighted average depending on if the weight is an int or float
		cout << endl;
		if (is_int(weight)) {
			cout << "The weighted average is: " << average * get_int(weight) << endl;
		}
		else if (is_float(weight)) {
			cout << "The weighted average is: " << average * get_float(weight) << endl;
		}
	}
}
	

/**************************************************************************************************************************************************
  ** Function: get_float
 ** Description: Takes a prompt from the user as a string literal, checks if input is a valid float, returns the provided float
 ** Parameters: string prompt
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
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



/**************************************************************************************************************************************************
 ** Function: is_float
 ** Description: Indicated if a given string is a float
 ** Parameters: string num
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
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


/**************************************************************************************************************************************************
 ** Function: is_int
 ** Description: Indicates if a given string is an integer
 ** Parameters: string num
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
bool is_int (string num) {
	//Check every character of num
	for (int i = 0; i < num.length(); i++) {
		//Check if the current character is a num
		if ((num[i] < '0' || num[i] >'9')) {
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

/**************************************************************************************************************************************************
 ** Function: is_int
 ** Description: Indicates if a given char is an integer
 ** Parameters: char character
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
bool is_int (char character) {
	//Check if the current character is a num
	if ((character < '0' || character >'9')) {
		return false;
	}
	//Check if the current character is a decimal
	if (character == '.') {
		return false;
	}
		
	//If the tests are passed then the char must be an int
	return true;
}

/**************************************************************************************************************************************************
 ** Function: valid_number
 ** Description: Indicates if the provided string contains anything that is not a number or decimal
 ** Parameters: string sentence
 ** Pre-Conditions: None
 ** Post-Conditions: None
**************************************************************************************************************************************************/
bool valid_number(string sentence) {
	//Check each character and see if it is not a number or decimal
	for (int i = 0; i < sentence.length(); i++) {
		if (!(sentence[i] <= '9' && sentence[i] >= '0') && sentence[i] != '.') {
			return false;
		}
	}
	return true;

}

