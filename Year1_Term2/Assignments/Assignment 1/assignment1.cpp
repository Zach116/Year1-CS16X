/******************************************************
 ** Program Filename: Assignment1: Math and Variables
 ** Author: Zach Bishop
 ** Date: 1/13/2018
 ** Description: Calculates math operations using the
 cmath library and variables
 ** Input: Nothing
 ** Output: Results printed to screen
 *****************************************************/ 

#include <iostream>
#include <cmath>
using namespace std;

/*************************************************
 ** Function: main
 ** Description: Calculates various equations
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Condition: Prints results to the screen
 ************************************************/
int main() {
	cout << "Result of cos(2/3): " << cos(2.0/3.0) << endl;
	cout << "Result of 2sin(2/3): " << 2.0 * (sin(2.0/3.0)) << endl;
	cout << "Result of tan(-3/4): " << tan(-3.0/4.0) << endl;
	cout << "Result of log base 10 of 55: " << log10(55.0) << endl;
	cout << "Result of ln(60): " << log(60.0) << endl;
	cout << endl;

	cout << "Steps for solving the log base 2 of 15: " << endl;
	cout << "ln(x) = " << log(15.0) << endl;
	cout << "ln(b) = " << log(2.0) << endl;
	cout << "ln(x)/ln(b) = " << (log(15.0))/(log(2.0)) << endl;
	cout << endl;

	cout << "Steps for solving the log base 4 of 40: " << endl;
	cout << "ln(x) = " << log(40.0) << endl;
	cout << "ln(b) = " << log(4.0) << endl;
	cout << "ln(x)/ln(b) = " << (log(40.0))/(log(4.0)) << endl;
	cout << endl;

	for (float x = 1.0; x <= 100; x *= 10) {
		cout << "Steps for solving 3^sin(x) when x = " << x << ":" << endl;
		cout << "sin(x) = " << sin(x) << endl;
		cout << "3^sin(x) = " << pow(3.0, sin(x)) << endl;
		cout << endl;

		cout << "Steps for solving log base 2 of (x^2 + 1) when x = " << x << ":" << endl;
		cout << "x^2 + 1 = " << (pow(x, 2.0)) + 1 << endl;
		cout << "ln(x^2 +1) = " << log((pow(x, 2.0)) + 1) << endl;
		cout << "ln(2) = " << log(2) << endl;
		cout << "ln(x^2 +1)/ln(2) = " << (log((pow(x, 2.0)) +1))/(log(2)) << endl;
		cout << endl;
	}
}
