#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

struct county {
	//Name of county
	string name;

	//Array of city names in county
	string *city;

	//Number of cities in county
	int cities;

	//total population of county
	int population;

	//avg household income
	float avg_income;

	//avg household price
	float avg_house;
};

struct state {
	//Name of state
	string name;

	//Array of counties
	county *c;

	//Number of counties in state
	int counties;

	//Total population of state
	int population;
};

state* create_states(int numStates);
void get_state_data(state* states, int numStates, ifstream& rf);
county* create_counties(int numCounties);
void get_county_data(county* currCounties, int numCounties, ifstream& rf);
void print_screen(state* states, int numStates);
int output_choice();
int income_select();
void collect_info_screen(state* states, int numStates, int income);
void collect_info_file(state* states, int numStates, int income);
string largest_pop_state(state* states, int numStates);
string largest_pop_county(state* states, int numStates);
void states_above_income(state* states, int numStates, int income);
void states_above_income(state* states, int numStates, int income, ofstream& wf);
void avg_house_cost(state* states, int numStates, int income);
void avg_house_cost(state* states, int numStates, int income, ofstream& wf);
void sort_state_name(state* states, int numStates);
void sort_state_pop(state* states, int numStates);
void sort_county_name(state* states, int numStates);
void sort_county_pop(state* states, int numStates);
int min_length(string word1, string word2);
void print_state_name(state* states, int numStates);
void print_state_name(state* states, int numStates, ofstream& wf);
void print_state_pop(state* states, int numStates);
void print_state_pop(state* states, int numStates, ofstream& wf);
void print_county_name(state* states, int numStates);
void print_county_name(state* states, int numStates, ofstream& wf);
void print_county_pop(state* states, int numStates);
void print_county_pop(state* states, int numStates, ofstream& wf);
void delete_info(state** states, int numStates);
void get_info(char** rfName, int* numStates, char** argv, int argc, bool* heapUsed);
bool is_valid_arguments(char** argv, int argc);
bool missing_sf(char** argv);
bool info_valid(char** argv);
bool valid_file(char* filename);
bool is_int (char* num);
bool is_int (string num);
int get_int(char* prompt);
int get_int(string prompt);
char* get_input();
void add_one_char(char** str, char c);
