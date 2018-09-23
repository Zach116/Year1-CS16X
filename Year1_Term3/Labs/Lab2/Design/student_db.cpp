#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include "student_db.h"

using namespace std;

string get_file_name() {
	//Ask the user for a file name and return it
}

int get_num_students(string rf) {
	//Creates file object
	//Opens the read file
	//Stores how many students need to be created
	//Closes file
	//returns numStudents
}

state* create_student_db(int numStudents) {
	//Create a state pointer
	//point pointer to an array made on the heap of size numStudents
	//return pointer
}

void get_student_db_info(student* students, int numStudents, fstream* rf) {
	//Have a for loop run for numStudents
	//For the current student, assign the info from the readfile to the correct attributes. Done based on space flags and known order
	//Exit for loop
}

void sort_ID(student* students, int numStudents) {
	//Sort the students by ID number by comparing and switching based on predefined rules
}

void output_info(student* students, int numStudents) {
	//Create an output file object
	//Open the output file
	//For loop runs for numStudents
	//Current student info printed to screen
	//Exit for loop
	//Close file
}

void sort_last_name(student* students, int numStudents) {
	//Sort the students by last name by comparing and switching based on predefined rules
}

int get_num_majors(student* students, int numStudents) {
	//Create int numMajors
	//Create string currentMajor
	//Set all values in array to '0'
	//For loop runs through numStudents
	//Store current students major in a variable
	//For loop starts one ahead of previous for loop and runs through numStudents
	//If stored major equals current students major, break out of loop
	//else if the last index is reached, add one to numMajors
	//Exit for loop
	//Exit for loop
	//return numMajors
}

void output_majors(student* students, int numStudents) {
	//Create an output file object
	//Open the output file
	//For loop runs for numStudents
	//Current student's major printed to screen
	//Exit for loop
	//Close file
}

void delete_student_db_info(student** studentes, int numStudents) {
	//For loop runs through numStudents
	//Delete memory on the heap
	//exit for loop
	//Delete memory on heap
	//Point pointer to NULL
}
