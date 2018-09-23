#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	int uppercaseAmount = 0, lowercaseAmount = 0, numberAmount = 0, passwordLength = 0, useLetters = 0, useUppercase = 0, useLowercase = 0, useNumbers = 0, createPassword = 1;
	srand(time(NULL));

	cout << "Hi, I see you would like to make a password!" << endl  << endl;
	while (createPassword) {
		cout << "How long would you like your password to be? ";
		cin >> passwordLength;
		cout << endl;

		//Letter info
		cout << "Would you like to use letters (0-No 1-Yes): ";
		cin >> useLetters;
		cout << endl;
		if (useLetters) {
			//Uppercase info
			cout << "Would you like to use uppercase letters? (0-No 1-Yes): ";
			cin >> useUppercase;
			cout << endl;
			if (useUppercase == 1) {
				cout << "How many uppercase letters would you like to use? ";
				cin >> uppercaseAmount;
				cout << endl;
			}
			
			//Lowercase info
			cout << "Would you like to use lowercase letters? (0-No 1-Yes): ";
			cin >> useLowercase;
			cout << endl;
			if (useLowercase == 1) {
				cout << "How many lowercase letters would you like to use? ";
				cin >> lowercaseAmount;
				cout << endl;
			}
		}
		
		//Number info
		cout << "Would you like to use numbers? (0-No 1-Yes): ";
		cin >> useNumbers;
		cout << endl;
		if (useNumbers == 1) {
			cout << "How many numbers would you like to use? ";
			cin >> numberAmount;
			cout << endl;
		}
	
		//Creating password
		//Check if the user wants letters
		if (useLetters == 1) {
			//Check if the user wants uppercase, if so generate a random uppercase and print it, do this over for the amount they want
			if (useUppercase == 1) {
				for (int j = 0; j < uppercaseAmount; j++) {
					cout << ((char) ((rand() % 26) + 65));
				}
			}

			//Check if the user wants lowercase, if so generate a random uppercase and print it, do this over for the amount they want
			if (useLowercase == 1) {
				for (int k = 0; k < lowercaseAmount; k++) {
					cout << ((char) ((rand() % 26) + 97));
				}	
			}
		}

		//Check if the user wants numbers, if so generate a random number between 0-9 and print it, do this over for the amount they want
		if (useNumbers == 1) {
			for (int l = 0; l < numberAmount; l++) {
				cout << (rand() % 10);
			}
		}
		cout << endl;
		cout << endl;

		//Check if the user want to make another password
		cout << "Would you like to make another password? (0-No 1-Yes): ";
		cin >> createPassword;
	}
}
