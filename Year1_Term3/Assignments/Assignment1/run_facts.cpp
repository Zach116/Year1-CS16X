/******************************************************************************
 ** Program: Assignment1: State Facts
 ** Author: Zach Bishop
 ** Date: 4/14/2018
 ** Description: Creates and fills structs with info from a text file. Then
 								 answers questions relating to the info and either prints
								 to screen or outputs to a file.
 ** Input: Command line arguments, text file, and typing to screen
 ** Output: Screen or text file
*****************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include "state_facts.h"

using namespace std;

int main(int argc, char** argv) {
	ifstream rf;
	char* rfName;
	int numStates, outputOption, income;
	state* states;
	bool heapUsed = false;

	//Get the readfile name and the number of states from the command line arguments
	get_info(&rfName, &numStates, argv, argc, &heapUsed);

	//Call function state* create_states(int) which will create an array of states on the heap and return the memory address
	states = create_states(numStates);

	//Open the read file
	rf.open(rfName, fstream::in);

	//Delete the Readfile name if it was stored on the heap
	if (heapUsed == true) {
		delete [] rfName;
	}

	//Call function void get_state_data(state*, int, ifstream &) that populates student array with information
	get_state_data(states, numStates, rf);

	//Close the read file
	rf.close();

	//Print the entire array of states to the screen
	//print_screen(states, numStates);

	//Call function that asks user for what amount of income they want
	income = income_select();

	//Call function that asks user if they want screen or file
	outputOption = output_choice();

	//If screen was selected, call collect_info_screen, else collect_info_file
	if (outputOption == 1) {
		collect_info_screen(states, numStates, income);
	}
	else {
		collect_info_file(states, numStates, income);
	}

	//Call function that deletes all info on the heap
	delete_info(&states, numStates);
}
