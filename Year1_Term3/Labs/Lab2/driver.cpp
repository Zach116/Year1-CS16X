#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include "student_db.h"

using namespace std;

int main(int argc, char** argv) {
	student* students;
	char* fileName;
	int numStudents;
	//Create read file object
	fstream rf;
	//Make sure read file exists, otherwise ask for new read file name
	do {
		fileName = get_input();
		rf.open(fileName, fstream::in);
		if (rf.good() != true) {
			cout << "ERROR THAT FILE DOES NOT EXIST!" << endl;
		}
	} while (rf.good() != true);

	//Call a function that opens the read file and checks how many students need to be created
	numStudents = get_num_students(fileName);

	delete [] fileName;

	//Call function state* create_student_db(int) which will create an array of students on the heap and return the memory address
	students = create_student_db(numStudents);

	//Call function void get_student_db_info(student*, int, fstream &) that populates student array with information
	get_student_db_info(students, numStudents, &rf);
	//Close the read file
	rf.close();

	//Call function that will sort the students by last name
	sort_last_name(students, numStudents);
	//Call function that will output the students to an output file sorted by last name
	output_sorted_last(students, numStudents);
	//Call function that will sort the students by ID Number
	sort_ID(students, numStudents);
	//Call function that will output the students sorted ID to an output file
	output_sorted_ID(students, numStudents);
	//Call function that will calc and output the number of unique majors
	get_num_majors(students, numStudents);
	//Call function void delete_student_db_info(student**, int) that willdelete the memory on the heap
	delete_student_db_info(&students, numStudents);

}
