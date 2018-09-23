#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include "menu.h"

using namespace std;

//Default Constructor:
Menu::Menu() {
	num_pizzas = 0;
	pizzas = NULL;
}

//Non-default Constructor:
Menu::Menu(int num, Pizza* pizzas) {
	num_pizzas = num;
	this->pizzas = pizzas;
}

//Destructor:
Menu::~Menu() {
	delete [] pizzas;
}

//Copy Constructor:
Menu::Menu(const Menu& copy) {
	this->num_pizzas = copy.num_pizzas;

	//Deep copy pizzas
	if (this->num_pizzas == 0) {
		this->pizzas = NULL;
	}
	else {
		this->pizzas = new Pizza[this->num_pizzas];
		for (int i = 0; i < this->num_pizzas; i++) {
			this->pizzas[i] = copy.pizzas[i];
		}
	}
}

//Assignment Operator Overload
const Menu& Menu::operator=(const Menu& copy) {
	this->num_pizzas = copy.num_pizzas;

	//Deep copy pizzas
	if (this->pizzas != NULL) {
		delete [] pizzas;
	}
	if (this->num_pizzas == 0) {
		this->pizzas = NULL;
	}
	else {
		this->pizzas = new Pizza[this->num_pizzas];
		for (int i = 0; i < this->num_pizzas; i++) {
			this->pizzas[i] = copy.pizzas[i];
		}
	}
}

//Accessors:
int Menu::get_num_pizzas() const {return num_pizzas;}
Pizza* Menu::get_pizzas() const {return pizzas;}

//Mutators:
void Menu::set_num_pizzas(int num) {num_pizzas = num;}
void Menu::set_pizzas(Pizza* pizzas) {this->pizzas = pizzas;}

/******************************************************************************
 ** Function: print
 ** Description: Prints the menu info
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Menu::print() const {
	cout << "Number of Pizzas: " << num_pizzas << endl;
	cout << endl;
	//Print out all the Pizzas
	for (int i = 0; i < this->num_pizzas; i++) {
		cout << "Pizza Number " << i + 1 << ":" << endl;
		this->pizzas[i].print();
	}
}

/******************************************************************************
 ** Function: load_data
 ** Description: Populates the classes with info from text files
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: The classes shoud be populated
*****************************************************************************/
void Menu::load_data() {
	ifstream rf;
	string trash;

	rf.open("menu.txt");

	//Load the info from the menu.txt file
	if (rf.is_open()) {
		//Count how many pizzas there are
		while (!rf.eof()) {
			getline(rf, trash);
			//Only add to the number of pizzas if there is a pizza on the current line
			if (trash != "") {
				this->num_pizzas++;
			}
		}

		//Allocate the memory needed for the pizzas and fill the pizzas
		this->pizzas = new Pizza[this->num_pizzas];

		//Set pointer back to the top of the file
		rf.close();
		rf.open("menu.txt");

		for (int i = 0; i < this->num_pizzas; i++) {
			this->pizzas[i].load_data(rf);
		}
	}
	else {
		cout << "File could not be found" << endl;
	}
	rf.close();
}

/******************************************************************************
 ** Function: search_pizza_by_cost
 ** Description: Make a search result of pizzas that are below a certain price for a certain size
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
Menu Menu::search_pizza_by_cost(int upper_bound, string size) {
	Menu search_result;

	//Add pizzas with below the cost for smalls
	if (size == "S") {
		for (int i = 0; i < num_pizzas; i++) {
			if (pizzas[i].get_small_cost() <= upper_bound) {
				search_result.add_pizza(pizzas[i]);
			}
		}

		cout << "Here are the pizzas we found that are below the given price for a small:" << endl;
	}

	//Add pizzas with below the cost for mediums
	if (size == "M") {
		for (int i = 0; i < num_pizzas; i++) {
			if (pizzas[i].get_medium_cost() <= upper_bound) {
				search_result.add_pizza(pizzas[i]);
			}
		}

		cout << "Here are the pizzas we found that are below the given price for a medium:" << endl;
	}


	//Add pizzas with below the cost for larges
	if (size == "L") {
		for (int i = 0; i < num_pizzas; i++) {
			if (pizzas[i].get_large_cost() <= upper_bound) {
				search_result.add_pizza(pizzas[i]);
			}
		}

		cout << "Here are the pizzas we found that are below the given price for a large:" << endl;
	}

	//Print the pizzas found
	cout << endl;
	search_result.print();

	return search_result;
}

/******************************************************************************
 ** Function: search_pizza_by_ingredients_to_include
 ** Description: Make a search result of pizzas that have certain ingredients
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
Menu Menu::search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients) {
	Menu search_result;
	bool added = false;
	string response;
	//Add pizzas with the desired ingredients to the search result
	for (int i = 0; i < num_pizzas; i++) {
		for (int j = 0; j < pizzas[i].get_num_ingredients(); j++) {
			for (int k = 0; k < num_ingredients; k++) {
				if (lowercase(pizzas[i].get_ingredients()[j]) == lowercase(ingredients[k])) {
					search_result.add_pizza(pizzas[i]);
					added = true;
					break;
				}
			}
			//If this pizza has already been added, stop looking through this pizza's Ingredients
			if (added == true) {
				added = false;
				break;
			}
		}
	}
	//Print the pizzas found
	cout << "Here are the pizzas we found:" << endl;
	cout << endl;
	search_result.print();
	delete [] ingredients;

	//Ask if the user wants to reduce the search list
	do {
		cout << "Would you like to reduce your search by excluding some ingredients (Yes/No)? ";
		cin >> response;
		cout << endl;

		if (response != "Yes" && response != "No") {
			cout << "Please enter Yes or No!" << endl;
			cout << endl;
		}
	} while (response != "Yes" && response != "No");

	//Collect ingredients from user and then pass to exclude
	if (response == "Yes") {
		ingredients = new string[1];
		num_ingredients = 0;
		int i = 0;

		//Collect ingredients
		do {
			cout << "What ingredient would you like to exclude? ";
			cin >> ingredients[i];
			cout << endl;
			num_ingredients++;

			//Check if the user wants to include another ingredient
			do {
				cout << "Would you like to exclude another item (Yes/No)? ";
				cin >> response;
				cout << endl;

				if (response != "Yes" && response != "No") {
					cout << "Please enter Yes or No!" << endl;
					cout << endl;
				}
			} while (response != "Yes" && response != "No");
		} while (response == "Yes");

		search_result = search_result.search_pizza_by_ingredients_to_exclude(ingredients, num_ingredients);
	}

	return search_result;
}

/******************************************************************************
 ** Function: add_pizza
 ** Description: Add a pizza to the menu
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: The object should have one more pizza
*****************************************************************************/
void Menu::add_pizza(Pizza new_pizza) {
	Pizza* temp;

	this->num_pizzas++;

	//Resize the pizzas array
	temp = new Pizza[this->num_pizzas];

	for (int i = 0; i < this->num_pizzas - 1; i++) {
		temp[i] = pizzas[i];
	}

	delete [] pizzas;
	this->pizzas = new Pizza[this->num_pizzas];

	for (int i = 0; i < this->num_pizzas; i++) {
		pizzas[i] = temp[i];
	}

	delete [] temp;

	//Add the new pizza
	pizzas[this->num_pizzas - 1] = new_pizza;

}

/******************************************************************************
 ** Function: add_pizza_to_main_menu
 ** Description: Add a pizza to the main menu
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: The object should have one more pizza
*****************************************************************************/
void Menu::add_pizza_to_main_menu(Pizza new_pizza) {
	Pizza* temp;
	ifstream rf;
	ofstream wf;
	string line;

	this->num_pizzas++;

	//Resize the pizzas array
	temp = new Pizza[this->num_pizzas];

	for (int i = 0; i < this->num_pizzas - 1; i++) {
		temp[i] = pizzas[i];
	}

	delete [] pizzas;
	this->pizzas = new Pizza[this->num_pizzas];

	for (int i = 0; i < this->num_pizzas; i++) {
		pizzas[i] = temp[i];
	}

	delete [] temp;

	//Add the new pizza
	pizzas[this->num_pizzas - 1] = new_pizza;

	//Change the menu text file
	rf.open("menu.txt");
	wf.open("temp.txt");
	while(!rf.eof()) {
		getline(rf, line);
		if (line != "") {
			wf << line << endl;
		}
	}
	//Write in the new pizza
	wf << pizzas[this->num_pizzas - 1].get_name() << " ";
	wf << pizzas[this->num_pizzas - 1].get_small_cost() << " ";
	wf << pizzas[this->num_pizzas - 1].get_medium_cost() << " ";
	wf << pizzas[this->num_pizzas - 1].get_large_cost() << " ";
	wf << pizzas[this->num_pizzas - 1].get_num_ingredients() << " ";
	for (int i = 0; i <  pizzas[this->num_pizzas - 1].get_num_ingredients(); i++){
		wf << pizzas[this->num_pizzas - 1].get_ingredients()[i] << " ";
	}

	wf.close();
	rf.close();

	remove("menu.txt");
	rename("temp.txt", "menu.txt");
}

/******************************************************************************
 ** Function: remove_item_from_menu
 ** Description: Remove a pizza from the main menu
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: The object should have one less pizza
*****************************************************************************/
void Menu::remove_item_from_menu(int pizza_num) {
	Pizza* temp;
	ifstream rf;
	ofstream wf;
	string line;
	int line_num = 1;
	int j = 0;

	this->num_pizzas--;

	//Resize the pizzas array
	temp = new Pizza[this->num_pizzas];

	for (int i = 0; i < this->num_pizzas + 1; i++) {
		if (i != (pizza_num - 1)) {
			temp[j] = pizzas[i];
			//j should only be incremented when pizzas are added
			j++;
		}
	}

	delete [] pizzas;
	this->pizzas = new Pizza[this->num_pizzas];

	for (int i = 0; i < this->num_pizzas; i++) {
		pizzas[i] = temp[i];
	}

	delete [] temp;

	//Change the menu text file
	rf.open("menu.txt");
	wf.open("temp.txt");
	while(!rf.eof()) {
		getline(rf, line);
		if (line != "") {
			if (line_num != pizza_num) {
				wf << line << endl;
			}
		}
		line_num++;
	}

	wf.close();
	rf.close();

	remove("menu.txt");
	rename("temp.txt", "menu.txt");
}

/******************************************************************************
 ** Function: search_pizza_by_ingredients_to_exclude
 ** Description: Make a search result of pizzas that do not have certain ingredients
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
Menu Menu::search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients) {
	Menu search_result;
	bool disqualified = false;
	string response;

	//Add pizzas without the desired ingredients to the search result
	for (int i = 0; i < num_pizzas; i++) {
		for (int j = 0; j < pizzas[i].get_num_ingredients(); j++) {
			for (int k = 0; k < num_ingredients; k++) {
				if (lowercase(pizzas[i].get_ingredients()[j]) == lowercase(ingredients[k])) {
					disqualified = true;
					break;
				}
				else if (j == pizzas[i].get_num_ingredients() - 1 && k == num_ingredients - 1) {
					search_result.add_pizza(pizzas[i]);
				}
			}
			//If this pizza has already been added, stop looking through this pizza's Ingredients
			if (disqualified == true) {
				disqualified = false;
				break;
			}
		}
	}

	//Print the pizzas found
	cout << "Here are the pizzas we found:" << endl;
	cout << endl;
	search_result.print();
	delete [] ingredients;

	//Ask if the user wants to reduce the search list
	do {
		cout << "Would you like to reduce your search by including some ingredients (Yes/No)? ";
		cin >> response;
		cout << endl;

		if (response != "Yes" && response != "No") {
			cout << "Please enter Yes or No!" << endl;
			cout << endl;
		}
	} while (response != "Yes" && response != "No");

	//Collect ingredients from user and then pass to exclude
	if (response == "Yes") {
		ingredients = new string[1];
		num_ingredients = 0;
		int i = 0;

		//Collect ingredients
		do {
			cout << "What ingredient would you like to include? ";
			cin >> ingredients[i];
			cout << endl;
			num_ingredients++;

			//Check if the user wants to include another ingredient
			do {
				cout << "Would you like to include another item (Yes/No)? ";
				cin >> response;
				cout << endl;

				if (response != "Yes" && response != "No") {
					cout << "Please enter Yes or No!" << endl;
					cout << endl;
				}
			} while (response != "Yes" && response != "No");
		} while (response == "Yes");

		search_result = search_result.search_pizza_by_ingredients_to_include(ingredients, num_ingredients);
	}

	return search_result;
}
