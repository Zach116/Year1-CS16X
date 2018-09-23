#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include "state_facts.h"

using namespace std;

/******************************************************************************
 ** Function: create_states
 ** Description: Creates an array of struct state on the heap
 ** Parameters: int numStates
 ** Pre-Conditions: numStates must be greater than 0
 ** Post-Conditions: None
*****************************************************************************/
state* create_states(int numStates) {
	//Create a state pointer
	state* states;

	//point pointer to an array made on the heap of size numStates
	states = new state[numStates];

	//return pointer
	return states;
}

/******************************************************************************
 ** Function: get_state_data
 ** Description: Populate the states from the read file
 ** Parameters: state* states, int numStates, ifstream& rf
 ** Pre-Conditions: The read file must be opened
 ** Post-Conditions: states should be populated
*****************************************************************************/
void get_state_data(state* states, int numStates, ifstream& rf) {
	//Within that function, call county* create_counties(int) and void get_county_data(county*, int, ifstream&)
	for (int i = 0; i < numStates; i++) {
		//For the current state, assign the info from the readfile to the correct attributes. Done based on space flags and known order
		rf >> states[i].name;
		rf >> states[i].population;
		rf >> states[i].counties;

		//Create an array of counties for the current state
		states[i].c = new county[states[i].counties];

		//Populate the current counties
		get_county_data(states[i].c, states[i].counties, rf);
	}
}

/******************************************************************************
 ** Function: create_counties
 ** Description: Creates an array of counties
 ** Parameters: int numCounties
 ** Pre-Conditions: numCounties is a positive number
 ** Post-Conditions: None
*****************************************************************************/
county* create_counties(int numCounties) {
	//Create a county pointer
	county* currCounties;

	//point pointer to an array made on the heap of size numCounties
	currCounties = new county[numCounties];

	//return pointer
	return currCounties;

}

/******************************************************************************
 ** Function: get_county_data
 ** Description: Populates the current counties
 ** Parameters: county* currCounties, int numCounties, ifstream& rd
 ** Pre-Conditions: The read file must be open
 ** Post-Conditions: currCounties is populated
*****************************************************************************/
void get_county_data(county* currCounties, int numCounties, ifstream& rf) {
	for (int i = 0; i < numCounties; i++) {
		//For the current county, assign the info from the readfile to the correct attributes. Done based on space flags and known order
		rf >> currCounties[i].name;
		rf >> currCounties[i].population;
		rf >> currCounties[i].avg_income;
		rf >> currCounties[i].avg_house;
		rf >> currCounties[i].cities;

		//Create a string array of cities for the current county
		currCounties[i].city = new string[currCounties[i].cities];

		//Populate the city string
		for (int j = 0; j < currCounties[i].cities; j++) {
			rf >> currCounties[i].city[j];
		}
	}
}

/******************************************************************************
 ** Function: print_screen
 ** Description: Prints the structs to the screen
 ** Parameters: state* states, int numStates
 ** Pre-Conditions: numStates is not larger than the number of states
 ** Post-Conditions: None
*****************************************************************************/
void print_screen(state* states, int numStates) {
	//Print state info
	for (int i = 0; i < numStates; i++) {
		cout << states[i].name << " ";
		cout << states[i].population << " ";
		cout << states[i].counties << " ";
		cout << endl;

		//Print current state's county info
		for (int j = 0; j < states[i].counties; j++) {
			cout << states[i].c[j].name << " ";
			cout << states[i].c[j].population << " ";
			cout << states[i].c[j].avg_income << " ";
			cout << states[i].c[j].avg_house << " ";
			cout << states[i].c[j].cities << " ";

			//Print current counties cities
			for (int k = 0; k < states[i].c[j].cities; k++) {
				cout << states[i].c[j].city[k] << " ";
			}
			cout << endl;
		}
	}
	cout << endl;
}

/******************************************************************************
 ** Function: output_choice
 ** Description: Asks the user how they want the info outputted
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
int output_choice() {
	string tempNum;

	do {
		cout << "Would you like the state facts printed to a screen or outputted to a file?" << endl;
		cout << "1) Screen" << endl;
		cout << "2) File" << endl;
		cin >> tempNum;
		cin.ignore();
		cin.clear();
		cout << endl;

		//Error handle
		if (!is_int(tempNum) || get_int(tempNum) < 1 || get_int(tempNum) > 2) {
			cout << "PLEASE ENTER 1 OR 2!" << endl;
		}
	} while (!is_int(tempNum) || get_int(tempNum) < 1 || get_int(tempNum) > 2);

	return (get_int(tempNum));
}

/******************************************************************************
 ** Function: income_select
 ** Description: Ask the user for the income amount they want to use
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
int income_select() {
	string income;

	do {
		cout << "What income amount would you like to be the bar for the counties' average incomes? ";
		cin >> income;
		cin.ignore();
		cin.clear();
		cout << endl;

		//Error handle
		if (!is_int(income) || get_int(income) < 1) {
			cout << "PLEASE ENTER A WHOLE NUMBER ABOVE ZERO AND LESS THAN 2,147,483,648!" << endl;
		}
	} while (!is_int(income) || get_int(income) < 1);

	return get_int(income);

}

/******************************************************************************
 ** Function: collect_info_screen
 ** Description: Collects info on the states and prints it to the screen
 ** Parameters: state* states, int numStates, int income
 ** Pre-Conditions: numStates is not greater than the amount of states in the array
 ** Post-Conditions: None
*****************************************************************************/
void collect_info_screen(state* states, int numStates, int income) {
	//Call function that will calc state with the largest pop and output
	cout << "State with the largest population: " << largest_pop_state(states, numStates) << endl;

	//Call function that will calc county with the largest pop and output
	cout << "County with the largest population: " << largest_pop_county(states, numStates) << endl;

	//Call function that will calc counties with an income above a specific amount and output
	cout << "Counties with an income above " << income << ": ";
	states_above_income(states, numStates, income);
	cout << endl;

	//Call function that calculates the average household cost for all counties in each state and output
	avg_house_cost(states, numStates, income);

	//Call function that sorts states by name
	sort_state_name(states, numStates);
	//Print all the state names now that they are sorted alphabetically
	cout << "States sorted alphabetically by name: ";
	print_state_name(states, numStates);
	cout << endl;

	//Call function that sorts states by pop and output
	sort_state_pop(states, numStates);
	//Print all the state names now that they are sorted by pop
	cout << "States sorted by population: ";
	print_state_pop(states, numStates);
	cout << endl;

	//Call function that sorts counties within states by name and output
	sort_county_name(states, numStates);
	//Print all the county names now that they are sorted alphabetically
	cout << endl;
	cout << "Counties within states sorted alphabetically by name:" << endl;
	print_county_name(states, numStates);

	//Call function that sorts counties within states by pop and output
	sort_county_pop(states, numStates);
	//Print all the county names now that they are sorted by pop
	cout << endl;
	cout << "Counties within states sorted alphabetically by pop:" << endl;
	print_county_pop(states, numStates);
}

/******************************************************************************
 ** Function: collect_info_file
 ** Description: Collects info on the states and outputs it to a file
 ** Parameters: state* states, int numStates, int income
 ** Pre-Conditions: numStates is not greater than the amount of states in the array
 ** Post-Conditions: None
*****************************************************************************/
void collect_info_file(state* states, int numStates, int income) {
	char* filename;
	ofstream wf;

	//call function that asks the user for filename
	cout << "What would you like the ouput file to be called? ";
	filename = get_input();

	//Open output file
	wf.open(filename, fstream::out|fstream::app);

	//Delete the filename from the stack
	delete [] filename;

	//Call function that will calc state with the largest pop and output
	wf << "State with the largest population: " << largest_pop_state(states, numStates) << endl;

	//Call function that will calc county with the largest pop and output
	wf << "County with the largest population: " << largest_pop_county(states, numStates) << endl;

	//Call function that will calc counties with an income above a specific amount and output
	wf << "Counties with an income above " << income << ": ";
	states_above_income(states, numStates, income, wf);
	wf << endl;

	//Call function that calculates the average household cost for all counties in each state and output
	avg_house_cost(states, numStates, income, wf);

	//Call function that sorts states by name
	sort_state_name(states, numStates);
	//Print all the state names now that they are sorted alphabetically
	wf << "States sorted alphabetically by name: ";
	print_state_name(states, numStates, wf);
	wf << endl;

	//Call function that sorts states by pop and output
	sort_state_pop(states, numStates);
	//Print all the state names now that they are sorted by pop
	wf << "States sorted by population: ";
	print_state_pop(states, numStates, wf);
	wf << endl;

	//Call function that sorts counties within states by name and output
	sort_county_name(states, numStates);
	//Print all the county names now that they are sorted alphabetically
	wf << endl;
	wf << "Counties within states sorted alphabetically by name:" << endl;
	print_county_name(states, numStates, wf);

	//Call function that sorts counties within states by pop and output
	sort_county_pop(states, numStates);
	//Print all the county names now that they are sorted by pop
	wf << endl;
	wf << "Counties within states sorted alphabetically by pop:" << endl;
	print_county_pop(states, numStates, wf);

	//Close the file
	wf.close();
}

/******************************************************************************
 ** Function: largest_pop
 ** Description: Calculate the state with the largest population
 ** Parameters: state* states, numStates
 ** Pre-Conditions: numStates must not be bigger than the number of states
 ** Post-Conditions: None
*****************************************************************************/
string largest_pop_state(state* states, int numStates) {
	int largestPop = states[0].population;
	string winner = states[0].name;

	//Run through all of the states and compare their populations, keep the one with the largest population
	for (int i = 0; i < numStates; i++) {
			if (states[i].population > largestPop) {
				largestPop = states[i].population;
				winner = states[i].name;
			}
	}

	return winner;
}

/******************************************************************************
 ** Function: largest_pop_county
 ** Description: Calculate the county with the largest population
 ** Parameters: state* states, numStates
 ** Pre-Conditions: numStates must not be bigger than the number of states
 ** Post-Conditions: None
*****************************************************************************/
string largest_pop_county(state* states, int numStates) {
	int largestPop = states[0].c[0].population;
	string winner = states[0].c[0].name;

	//Run through all of the states and their counties and compare their populations, keep the one with the largest population
	for (int i = 0; i < numStates; i++) {
		for (int j = 0; j < states[i].counties; j++) {
			if (states[i].c[j].population > largestPop) {
				largestPop = states[i].c[j].population;
				winner = states[i].c[j].name;
			}
		}
	}

	return winner;
}

/******************************************************************************
 ** Function:  states_above_income
 ** Description: Prints the states above a certain income to the screen
 ** Parameters: state* states, int numStates, int income
 ** Pre-Conditions: numStates is not greater than the number of states in the array
 ** Post-Conditions: None
*****************************************************************************/
void states_above_income(state* states, int numStates, int income) {
	//Run through all of the states and their counties and print the ones above the income bar
	for (int i = 0; i < numStates; i++) {
		for (int j = 0; j < states[i].counties; j++) {
			if (states[i].c[j].avg_income > income) {
				cout << states[i].c[j].name << " " << states[i].c[j].avg_income << " ";
			}
		}
	}
}

/******************************************************************************
 ** Function:  states_above_income
 ** Description: Output the states above a certain income to a file
 ** Parameters: state* states, int numStates, int income
 ** Pre-Conditions: numStates is not greater than the number of states in the array
 ** Post-Conditions: None
*****************************************************************************/
void states_above_income(state* states, int numStates, int income, ofstream& wf) {
	//Run through all of the states and their counties and print the ones above the income bar
	for (int i = 0; i < numStates; i++) {
		for (int j = 0; j < states[i].counties; j++) {
			if (states[i].c[j].avg_income > income) {
				wf << states[i].c[j].name << " " << states[i].c[j].avg_income << " ";
			}
		}
	}
}

/******************************************************************************
 ** Function: avg_house_cost
 ** Description: Calculate the average household cost for all counties in each state and print to screen
 ** Parameters: state* states, int numStates, int income
 ** Pre-Conditions: numStates is not greater than the number of states in the array
 ** Post-Conditions: None
*****************************************************************************/
void avg_house_cost(state* states, int numStates, int income) {
	float houseCostTotal = 0;

	//Run through all of the states and their counties and print the average household cost for all counties in each state
	for (int i = 0; i < numStates; i++) {
		for (int j = 0; j < states[i].counties; j++) {
			houseCostTotal += states[i].c[j].avg_house;
		}
		cout << "The average household cost for " << states[i].name << " is: " << (houseCostTotal/states[i].counties) << endl;

		//reset the houseCostTotal for the next state
		houseCostTotal = 0;
	}
}

/******************************************************************************
 ** Function: avg_house_cost
 ** Description: Calculate the average household cost for all counties in each state and output to file
 ** Parameters: state* states, int numStates, int income
 ** Pre-Conditions: numStates is not greater than the number of states in the array
 ** Post-Conditions: None
*****************************************************************************/
void avg_house_cost(state* states, int numStates, int income, ofstream& wf) {
	float houseCostTotal = 0;

	//Run through all of the states and their counties and print the average household cost for all counties in each state
	for (int i = 0; i < numStates; i++) {
		for (int j = 0; j < states[i].counties; j++) {
			houseCostTotal += states[i].c[j].avg_house;
		}
		wf << "The average household cost for " << states[i].name << " is: " << (houseCostTotal/states[i].counties) << endl;

		//reset the houseCostTotal for the next state
		houseCostTotal = 0;
	}
}

/******************************************************************************
 ** Function: sort_state_name
 ** Description: Sort the states alphabetically by name
 ** Parameters: state* states, int numStates
 ** Pre-Conditions: numStates is at least 2 and is not greater than the number of states in the array
 ** Post-Conditions: States names sorted alphabetically
*****************************************************************************/
void sort_state_name(state* states, int numStates) {
	//Loop through all states
	for (int i = numStates - 1; i >= 0; i--) {
		//Loop through the states that are yet to be fully sorted
		for (int j = 1; j <= i; j++) {
			//Loop through the letters of the current names
			for (int k = 0; k < min_length(states[j-1].name, states[j].name); k++) {
				//Compare letters and if the words are out of order, switch and break to the next words
				if (states[j-1].name[k] > states[j].name[k]) {
					state temp = states[j-1];
					states[j-1] = states[j];
					states[j] = temp;
					break;

				}
				//If the words are already sorted alphabetically, stop sorting the current words and switch to the next ones
				else if (states[j-1].name[k] < states[j].name[k]) {
					break;
				}
				//If the words have been the same so for and the end of one of the words has been reached, make the shorter word first
				else if (k == (min_length(states[j-1].name,states[j].name) - 1)) {
					if (states[j-1].name.length() > states[j].name.length()) {
						state temp = states[j-1];
						states[j-1] = states[j];
						states[j] = temp;
					}
				}
			}
   	}
	}
}

/******************************************************************************
 ** Function: sort_state_pop
 ** Description: Sort the states by population
 ** Parameters: state* states, int numStates
 ** Pre-Conditions: numStates is at least 2 and is not greater than the number of states in the array
 ** Post-Conditions: States sorted by population
*****************************************************************************/
void sort_state_pop(state* states, int numStates) {
	//Run through all the states
	for (int i = numStates - 1; i >= 0; i--) {
		//Run through the states that have not been sorted yet
		for (int j = 1; j <= i; j++) {
			//If the states are out of order, switch them
			if (states[j-1].population > states[j].population) {
				state temp = states[j-1];
				states[j-1] = states[j];
				states[j] = temp;
			}
		}
	}
}

/******************************************************************************
 ** Function: sort_county_name
 ** Description: Sort the counties within states alphabetically by name
 ** Parameters: state* states, int numStates
 ** Pre-Conditions: numStates is at least 2 and is not greater than the number of states in the array
 ** Post-Conditions: County names within states sorted alphabetically
*****************************************************************************/
void sort_county_name(state* states, int numStates) {
	//Loop through the states
	for (int i = 0; i < numStates; i++) {
		//Loop through all of the counties starting at the top
		for (int j = (states[i].counties - 1); j >= 0; j--) {
			//Loop through the counties that are yet to be fully sorted
			for (int k = 1; k <= j; k++) {
				//Loop through the letters of the current names
				for (int l = 0; l < min_length(states[i].c[k-1].name, states[i].c[k].name); l++) {
					if (states[i].c[k-1].name[l] > states[i].c[k].name[l]) {
						county temp = states[i].c[k-1];
						states[i].c[k-1] = states[i].c[k];
						states[i].c[k] = temp;
						break;
					}
					//If the words are already sorted alphabetically, stop sorting the current words and switch to the next ones
					else if (states[i].c[k-1].name[l] < states[i].c[k].name[l]) {
						break;
					}
					//If the words have been the same so for and the end of one of the words has been reached, make the shorter word first
					else if (l == (min_length(states[i].c[k-1].name, states[i].c[k].name) - 1)) {
						if (states[j-1].name.length() > states[j].name.length()) {
							county temp = states[i].c[k-1];
							states[i].c[k-1] = states[i].c[k];
							states[i].c[k] = temp;
						}
					}
				}
   		}
		}
	}
}

/******************************************************************************
 ** Function: sort_county_pop
 ** Description: Sort the counties within states by population
 ** Parameters: state* states, int numStates
 ** Pre-Conditions: numStates is at least 2 and is not greater than the number of states in the array
 ** Post-Conditions: Counties within states sorted by population
*****************************************************************************/
void sort_county_pop(state* states, int numStates) {
	//Loop through the states
	for (int i = 0; i < numStates; i++) {
		//Run through all the counties within the state
		for (int j = (states[i].counties - 1); j >= 0; j--) {
			//Run through the counties that have not been sorted yet
			for (int k = 1; k <= j; k++) {
				//If the counties are out of order, switch them
				if (states[i].c[k-1].population > states[i].c[k].population) {
					county temp = states[i].c[k-1];
					states[i].c[k-1] = states[i].c[k];
					states[i].c[k] = temp;
				}
			}
		}
	}
}

/******************************************************************************
 ** Function: min_length
 ** Description: Returns the smallest length of two words
 ** Parameters: string word1, string word2
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
int min_length(string word1, string word2) {
	//Return the number that is the smallest
	if (word1.length() < word2.length()) {
		return word1.length();
	}
	return word2.length();
}

/******************************************************************************
 ** Function: print_state_name
 ** Description: Prints the state names to screen
 ** Parameters: state* states, int numStates
 ** Pre-Conditions: numStates is not greater than the number of states in the array
 ** Post-Conditions: None
*****************************************************************************/
void print_state_name(state* states, int numStates) {
	for (int i = 0; i < numStates; i++) {
		cout << states[i].name << " ";
	}
}

/******************************************************************************
 ** Function: print_state_name
 ** Description: Outputs the state names to file
 ** Parameters: state* states, int numStates
 ** Pre-Conditions: numStates is not greater than the number of states in the array
 ** Post-Conditions: None
*****************************************************************************/
void print_state_name(state* states, int numStates, ofstream& wf) {
	for (int i = 0; i < numStates; i++) {
		wf << states[i].name << " ";
	}
}

/******************************************************************************
 ** Function: print_state_pop
 ** Description: Prints the state names to screen with populations
 ** Parameters: state* states, int numStates
 ** Pre-Conditions: numStates is not greater than the number of states in the array
 ** Post-Conditions: None
*****************************************************************************/
void print_state_pop(state* states, int numStates) {
	for (int i = 0; i < numStates; i++) {
		cout << states[i].name << " " << states[i].population << " ";
	}
}

/******************************************************************************
 ** Function: print_state_pop
 ** Description: Output the state names to file with populations
 ** Parameters: state* states, int numStates
 ** Pre-Conditions: numStates is not greater than the number of states in the array
 ** Post-Conditions: None
*****************************************************************************/
void print_state_pop(state* states, int numStates, ofstream& wf) {
	for (int i = 0; i < numStates; i++) {
		wf << states[i].name << " " << states[i].population << " ";
	}
}

/******************************************************************************
 ** Function: print_county_name
 ** Description: Prints the county names within states
 ** Parameters: state* states, int numStates
 ** Pre-Conditions: numStates is not greater than the number of states in the array
 ** Post-Conditions: None
*****************************************************************************/
void print_county_name(state* states, int numStates) {
	for (int i = 0; i < numStates; i++) {
		cout << states[i].name << ": ";
		for (int j = 0; j < states[i].counties; j++) {
			cout << states[i].c[j].name << " ";
		}
		cout << endl;
	}
}

/******************************************************************************
 ** Function: print_county_name
 ** Description: Outputs the county names within states to a file
 ** Parameters: state* states, int numStates
 ** Pre-Conditions: numStates is not greater than the number of states in the array
 ** Post-Conditions: None
*****************************************************************************/
void print_county_name(state* states, int numStates, ofstream& wf) {
	for (int i = 0; i < numStates; i++) {
		wf << states[i].name << ": ";
		for (int j = 0; j < states[i].counties; j++) {
			wf << states[i].c[j].name << " ";
		}
		wf << endl;
	}
}

/******************************************************************************
 ** Function: print_county_pop
 ** Description: Prints the county names within states with population
 ** Parameters: state* states, int numStates
 ** Pre-Conditions: numStates is not greater than the number of states in the array
 ** Post-Conditions: None
*****************************************************************************/
void print_county_pop(state* states, int numStates) {
	for (int i = 0; i < numStates; i++) {
		cout << states[i].name << ": ";
		for (int j = 0; j < states[i].counties; j++) {
			cout << states[i].c[j].name << " " << states[i].c[j].population << " ";
		}
		cout << endl;
	}
}

/******************************************************************************
 ** Function: print_county_pop
 ** Description: Outputs the county names within states with population to a file
 ** Parameters: state* states, int numStates
 ** Pre-Conditions: numStates is not greater than the number of states in the array
 ** Post-Conditions: None
*****************************************************************************/
void print_county_pop(state* states, int numStates, ofstream& wf) {
	for (int i = 0; i < numStates; i++) {
		wf << states[i].name << ": ";
		for (int j = 0; j < states[i].counties; j++) {
			wf << states[i].c[j].name << " " << states[i].c[j].population << " ";
		}
		wf << endl;
	}
}

/******************************************************************************
 ** Function: delete_info
 ** Description: Delete all the memory on the heap related to the state struct
 ** Parameters: state** states, int numStates
 ** Pre-Conditions: numStates is not greater than the amount of states in the array
 ** Post-Conditions: All memory on the heap relating to the state struct is deleted
*****************************************************************************/
void delete_info(state** states, int numStates) {
	for (int i = 0; i < numStates; i++) {
		for (int j = 0; j < (*states)[i].counties; j++) {
			//Delete the array of strings holding the city names for this county on the heap
			delete [] (*states)[i].c[j].city;
		}
		//Delete the array of counties for this particular state on the heap
		delete [] (*states)[i].c;
	}
	//Delete the array of states on the heap
	delete [] *states;
	//Point the states pointer back to NULL
	*states = NULL;
}

/******************************************************************************
 ** Function: get_info
 ** Description: Gets the readfile name and the number of states from the command line arguments or reprompts for them if the args are bad
 ** Parameters: char** rfName, int* numStates, char*[] argv, int argc
 ** Pre-Conditions: None
 ** Post-Conditions: rfName and numStates contain correct info
*****************************************************************************/
void get_info(char** rfName, int* numStates, char** argv, int argc, bool* heapUsed) {
	char* tempFilename;
	char* tempNum;

	//If command line arguments are bad, ask for needed info
	if (is_valid_arguments(argv, argc) != true) {
		//Set heapUsed to true so the code knows there is extra memory to be deleted on the heap
		*heapUsed = true;

		cout << endl;
		cout << "INVALID COMMAND LINE ARGUMENTS!" << endl;

		do {
			cout << "Please input a text filename to read from: ";
			tempFilename = get_input();

			cout << "Please input the number of states within the text file: ";
			tempNum = get_input();
			cout << endl;

			//If the user enters an input that is not valid notify them
			if (!is_int(tempNum) || get_int(tempNum) < 1 || valid_file(tempFilename) != true) {
				cout << "YOUR TEXT FILENAME OR NUMBER OF STATES IS INVALID!" << endl;
				delete [] tempFilename;
				delete [] tempNum;
			}
		} while(!is_int(tempNum) || (get_int(tempNum) < 1) || valid_file(tempFilename) != true);

		*rfName = tempFilename;
		*numStates = get_int(tempNum);
		delete [] tempNum;
	}
	//Get number of states and filename from command line arguments if the command line arguments are valid
	else {
		if (argv[1][1] == 's') {
			*numStates = get_int(argv[2]);
			*rfName = argv[4];
		}
		else {
			*numStates = get_int(argv[4]);
			*rfName = argv[2];
		}
	}
}

/******************************************************************************
 ** Function: is_valid_arguments
 ** Description: Check if the command line argunments are valid
 ** Parameters: string num
 ** Pre-Conditions: Determined what num is
 ** Post-Conditions: Return true or false
*****************************************************************************/
bool is_valid_arguments(char** argv, int argc) {
	//Deal with command line arguments
	if (argc != 5) {
		cout << "NOT ENOUGH COMMAND LINE ARGUMENTS!" << endl;
		exit(0);
	}
	else if (missing_sf(argv) == true) {
		cout << "MISSING -S or -F FROM COMMAND LINE ARGUMENTS!" << endl;
		exit(0);
	}
	else if (info_valid(argv) != true){
		return false;
	}

	return true;
}

/******************************************************************************
 ** Function: missing_sf
 ** Description: Makes sure the s and f options are present with the correct format
 ** Parameters: char** argv
 ** Pre-Conditions: There are at least 4 arguments
 ** Post-Conditions: None
*****************************************************************************/
bool missing_sf(char** argv) {
	bool s = false, f = false;

	//Check that the dashed were entered
	if (argv[1][0] != '-' || argv[3][0] != '-') {
		return true;
	}

	//Make sure s and f are both present in the correct locations
	if (argv[1][1] == 's'|| argv[3][1] == 's') {
		s = true;
	}
	if (argv[1][1] == 'f' || argv[3][1] == 'f') {
		f = true;
	}
	if (s == false || f == false) {
		return true;
	}

	return false;
}

/******************************************************************************
 ** Function: info_valid
 ** Description: Makes sure the information inside of the command arguments is valid
 ** Parameters: char** argv
 ** Pre-Conditions: -s and -f are included in the command line arguments
 ** Post-Conditions: None
*****************************************************************************/
bool info_valid(char** argv) {
	ifstream rf;
	if (argv[1][1] == 's') {
		//Make sure the number of states is a positive nonzero number
		if (is_int(argv[2]) != true || get_int(argv[2]) < 1) {
			return false;
		}

		//Make sure the readfile exists
		if (valid_file(argv[4]) != true) {
			return false;
		}

	}
	else {
		//Make sure the number of states is a positive nonzero number
		if (is_int(argv[4]) != true || get_int(argv[4]) < 1) {
			return false;
		}

		//Make sure the readfile exists
		if (valid_file(argv[2]) != true) {
			return false;
		}
	}

	return true;
}

/******************************************************************************
 ** Function: valid_file
 ** Description: Determines if a file exists
 ** Parameters: char* filename
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool valid_file(char* filename) {
	ifstream rf;

	//Make sure the readfile exists
	rf.open(filename);
	if (rf.good() != true) {
		rf.close();
		return false;
	}
	rf.close();

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
 ** Function: get_int
 ** Description: Takes a prompt from the user as a string literal, checks if input is a valid integer, returns the provided integer
 ** Parameters: string prompt
 ** Pre-Conditions: Determined what prompt is
 ** Post-Conditions: Return the prompt as an int if it is a valid int
*****************************************************************************/
int get_int(char* prompt) {
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

/******************************************************************************
 ** Function: get_input
 ** Description: Gets input from the user to store in a c-style string
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
char* get_input() {
	char* str = new char[1];
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
 ** Post-Conditions: str should have a character added to the end of it
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
