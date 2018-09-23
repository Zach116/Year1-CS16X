#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include "student_db.h"

using namespace std;

int get_num_students(char* fileName) {
	int numStudents;
	fstream rf;
	//Opens the read file
	rf.open(fileName, fstream::in|fstream::out|fstream::app);
	//Stores how many students need to be created
	rf >> numStudents;
	//Closes file
	rf.close();
	//returns numStudents
	return numStudents;
}

student* create_student_db(int numStudents) {
	//Create a student pointer
	student* students;

	//point pointer to an array made on the heap of size numStudents
	students = new student[numStudents];
	//return pointer
	return students;
}

void get_student_db_info(student* students, int numStudents, fstream* rf) {
	string dummyLine;
	//Skip a line
	getline(*rf, dummyLine);
	//Have a for loop run for numStudents
	for (int i = 0; i < numStudents; i++) {
		//For the current student, assign the info from the readfile to the correct attributes. Done based on space flags and known order
		*rf >> students[i].ID;
		*rf >> students[i].firstName;
		*rf >> students[i].lastName;
		*rf >> students[i].major;
	}
}

//Sort the students by ID number by comparing and switching based on predefined rules
void sort_ID(student* students, int numStudents) {
	//Run through all the students
	for (int i = numStudents - 1; i >= 0; i--) {
		//Run through the students that have not been sorted yet
		for (int j = 1; j <= i; j++) {
			//If the student IDs are out of order, switch them
			if (students[j-1].ID > students[j].ID) {
				student temp = students[j-1];
				students[j-1] = students[j];
				students[j] = temp;
			}
		}
	}
}

//Sort the students by last name by comparing and switching based on predefined rules
void sort_last_name(student* students, int numStudents) {
	//Loop through all students
	for (int i = numStudents - 1; i >= 0; i--) {
		//Loop through the students that are yet to be fully sorted
		for (int j = 1; j <= i; j++) {
			//Loop through the letters of the current names
			for (int k = 0; k < min_length(students[j-1].lastName, students[j].lastName); k++) {
				//Compare letters and if the words are out of order, switch and break to the next words
				if (students[j-1].lastName[k] > students[j].lastName[k]) {
					student temp = students[j-1];
					students[j-1] = students[j];
					students[j] = temp;
					break;

				}
				//If the words are already sorted alphabetically, stop sorting the current words and switch to the next ones
				else if (students[j-1].lastName[k] < students[j].lastName[k]) {
					break;
				}
				//If the words have been the same so for and the end of one of the words has been reached, make the shorter word first
				else if (k == (min_length(students[j-1].lastName,students[j].lastName) - 1)) {
					if (students[j-1].lastName.length() > students[j].lastName.length()) {
						student temp = students[j-1];
						students[j-1] = students[j];
						students[j] = temp;
					}
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

//Output functions
void output_info(student* students, int numStudents) {
	//Create an output file object
	ofstream wf;
	//Open the output file
	wf.open("StudentInfo.txt", fstream::out|fstream::app);

	//For loop runs for numStudents
	for (int i = 0; i < numStudents; i++) {
		//Current student info printed to file
		wf << students[i].ID << " " << students[i].firstName << " " << students[i].lastName << " " << students[i].major << endl;
	}

	//Close file
	wf.close();
}
void output_sorted_last(student* students, int numStudents) {
	//Create an output file object
	ofstream wf;
	//Open the output file
	wf.open("StudentInfo.txt", fstream::out|fstream::app);

	wf << "SORTED BY LAST NAME: ";
	//For loop runs for numStudents
	for (int i = 0; i < numStudents; i++) {
		//Current student info printed to file
		wf << students[i].lastName << " ";
	}
	wf << endl << endl;;

	//Close file
	wf.close();
}
void output_sorted_ID(student* students, int numStudents) {
	//Create an output file object
	ofstream wf;
	//Open the output file
	wf.open("StudentInfo.txt", fstream::out|fstream::app);

	wf << "SORTED BY ID NUMBER: ";
	//For loop runs for numStudents
	for (int i = 0; i < numStudents; i++) {
		//Current student info printed to file
		wf << students[i].firstName << " " << students[i].ID << " ";
	}
	wf << endl << endl;;

	//Close file
	wf.close();
}
void output_num_majors(int numMajors) {
	//Create an output file object
	ofstream wf;
	//Open the output file
	wf.open("StudentInfo.txt", fstream::out|fstream::app);

	wf << "NUMBER OF UNIQUE MAJORS: " << numMajors;

	//Close file
	wf.close();
}

int get_num_majors(student* students, int numStudents) {
	//Create int numMajors
	int numMajors = 0;
	//Create string currentMajor
	string currentMajor;
	//For loop runs through numStudents
	for (int i = 0; i < (numStudents); i++) {
		//Store current students major in a variable
		currentMajor = students[i].major;
		//For loop starts one ahead of previous for loop and runs through numStudents
		for (int j = (i+1); j < numStudents; j++) {
				//If stored major equals current students major, break out of loop
				if (currentMajor == students[j].major) {
					break;
				}
				//else if the last index is reached, add one to numMajors
				else if (j == numStudents - 1) {
					numMajors++;
				}
		}
	}

	//Add one to numMajors to account for the last guy not being counted, his will be unique because if someone had his before, it would not have been counted because of him
	numMajors++;

	//Output the number of unique numMajors
	output_num_majors(numMajors);
}

void delete_student_db_info(student** students, int numStudents) {
	//Delete memory on heap
	delete [] *students;

	//Point pointer to NULL
	*students = NULL;
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
	cout << "Please enter a file name to read from: ";
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
