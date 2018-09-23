#include <cstring>

using namespace std;

struct student {
	int ID;
	string firstName;
	string lastName;
	string major;
};

int get_num_students(char* fileName);
student* create_student_db(int numStudents);
void get_student_db_info(student* students, int numStudents, fstream* rf);
void sort_last_name(student* students, int numStudents);
void sort_ID(student* students, int numStudents);
int get_num_majors(student* students, int numStudents);
void output_info(student* students, int numStudents);
void output_sorted_last(student* students, int numStudents);
void output_sorted_ID(student* students, int numStudents);
void output_num_majors(int numMajors);
int min_length(string word1, string word2);

void delete_student_db_info(student** students, int numStudents);




char* get_input();
void add_one_char(char** str, char c);
