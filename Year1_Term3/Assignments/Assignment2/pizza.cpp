#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include "pizza.h"

using namespace std;

//Default Constructor:
Pizza::Pizza() {
	name = "Default";
	small_cost = 0;
	medium_cost = 0;
	large_cost = 0;
	num_ingredients = 0;
	ingredients = NULL;
}

//Non-default Constructor:
Pizza::Pizza(string name, int small_cost, int medium_cost, int large_cost, int num_ingredients, string* ingredients) {
	this->name = name;
	this->small_cost = small_cost;
	this->medium_cost = medium_cost;
	this->large_cost = large_cost;
	this->num_ingredients = num_ingredients;
	this->ingredients = ingredients;
}

//Destructor:
Pizza::~Pizza() {
	delete [] ingredients;
}

//Copy Constructor:
Pizza::Pizza(const Pizza& copy) {
	this->name =copy.name;
	this->small_cost = copy.small_cost;
	this->medium_cost = copy.medium_cost;
	this->large_cost = copy.large_cost;
	this->num_ingredients = copy.num_ingredients;

	//Deep copy ingredients
	if (this->num_ingredients == 0) {
		this->ingredients = NULL;
	}
	else {
		this->ingredients = new string[this->num_ingredients];
		for (int i = 0; i < this->num_ingredients; i++) {
			this->ingredients[i] = copy.ingredients[i];
		}
	}
}

//Assignment Operator Overload
const Pizza& Pizza::operator=(const Pizza& copy) {
	this->name =copy.name;
	this->small_cost = copy.small_cost;
	this->medium_cost = copy.medium_cost;
	this->large_cost = copy.large_cost;
	this->num_ingredients = copy.num_ingredients;

	//Deep copy ingredients
	if (this->ingredients != NULL) {
		delete [] ingredients;
	}
	if (this->num_ingredients == 0) {
		this->ingredients = NULL;
	}
	else {
		this->ingredients = new string[this->num_ingredients];
		for (int i = 0; i < this->num_ingredients; i++) {
			this->ingredients[i] = copy.ingredients[i];
		}
	}
}

//Accessors:
string Pizza::get_name() const {return name;}
int Pizza::get_small_cost() const {return small_cost;}
int Pizza::get_medium_cost() const {return medium_cost;}
int Pizza::get_large_cost() const {return large_cost;}
int Pizza::get_num_ingredients() const {return num_ingredients;}
string* Pizza::get_ingredients() const {return ingredients;}

//Mutators:
void Pizza::set_name(string name) {this->name = name;}
void Pizza::set_small_cost(int cost) {small_cost = cost;}
void Pizza::set_medium_cost(int cost) {medium_cost = cost;}
void Pizza::set_large_cost(int cost) {large_cost = cost;}
void Pizza::set_num_ingredients(int num) {num_ingredients = num;}
void Pizza::set_ingredients(string* ingredients) {this->ingredients = ingredients;}

/******************************************************************************
 ** Function: print
 ** Description: Prints the pizza info
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Pizza::print() const {
	cout << "Name: " << this->name << endl;
	cout << "Small Cost: " << this->small_cost << endl;
	cout << "Medium Cost: " << this->medium_cost << endl;
	cout << "Large Cost: " << this->large_cost << endl;
	cout << "Number of Ingredients: " << this->num_ingredients << endl;
	for (int i = 0; i < this->num_ingredients; i++) {
		cout << "Ingredient " << i + 1 << ": " << this->ingredients[i] << endl;
	}
	cout << endl;


}

/******************************************************************************
 ** Function: load_data
 ** Description: Populates the classes with info from text files
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: The classes shoud be populated
*****************************************************************************/
void Pizza::load_data(ifstream& rf) {
	rf >> this->name;
	rf >> this->small_cost;
	rf >> this->medium_cost;
	rf >> this->large_cost;
	rf >> this->num_ingredients;
	//Run through the ingredients for the current pizza in the text file and load them in
	this->ingredients = new string[this->num_ingredients];
	for (int i = 0; i < this->num_ingredients; i++) {
		rf >> this->ingredients[i];
	}
}
