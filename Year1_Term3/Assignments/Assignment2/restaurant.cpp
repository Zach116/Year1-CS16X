#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include <string>
#include "restaurant.h"

using namespace std;

//Default Constructor:
Restaurant::Restaurant() {
	Menu default_menu;

	menu = default_menu;
	employees = NULL;
	num_employees = 0;
	num_days_open = 0;
	week = NULL;
	name = "default";
	phone = "default";
	address = "default";
}

//Non-default Constructor:
Restaurant::Restaurant(Menu menu, employee* employees, int num_employees, hours* week, string name, string phone, string address) {
	this->menu = menu;
	this->employees = employees;
	this->num_employees = num_employees;
	this->week = week;
	this->name = name;
	this->phone = phone;
	this->address = address;
}

//Destructor:
Restaurant::~Restaurant() {
	delete [] employees;
	delete [] week;
}

//Copy Constructor:
Restaurant::Restaurant(const Restaurant& copy) {
	this->menu = copy.menu;
	this->name =copy.name;
	this->phone = copy.phone;
	this->address = copy.address;
	this->num_employees = copy.num_employees;

	//Deep copy employees
	if (this->num_employees == 0) {
		this->employees = NULL;
	}
	else {
		this->employees = new employee[this->num_employees];
		for (int i = 0; i < this->num_employees; i++) {
			this->employees[i] = copy.employees[i];
		}
	}

	//Deep copy week
	if (copy.week == NULL) {
		this->week = NULL;
	}
	else {
		this->week = new hours[7];
		for (int i = 0; i < 7; i++) {
			this->week[i] = copy.week[i];
		}
	}
}

//Assignment Operator Overload
const Restaurant& Restaurant::operator=(const Restaurant& copy) {
	this->menu = copy.menu;
	this->name =copy.name;
	this->phone = copy.phone;
	this->address = copy.address;
	this->num_employees = copy.num_employees;

	//Deep copy employees
	if (this->employees != NULL) {
		delete [] employees;
	}
	if (this->num_employees == 0) {
		this->employees = NULL;
	}
	else {
		this->employees = new employee[this->num_employees];
		for (int i = 0; i < this->num_employees; i++) {
			this->employees[i] = copy.employees[i];
		}
	}

	//Deep copy week
	if (this->week != NULL) {
		delete [] week;
	}
	if (copy.week == NULL) {
		this->week = NULL;
	}
	else {
		this->week = new hours[7];
		for (int i = 0; i < 7; i++) {
			this->week[i] = copy.week[i];
		}
	}
}

//Accessors:
Menu Restaurant::get_menu() const {return menu;}
employee* Restaurant::get_employees() const {return employees;}
hours* Restaurant::get_week() const {return week;}
string Restaurant::get_name() const {return name;}
string Restaurant::get_phone() const {return phone;}
string Restaurant::get_address() const {return address;}

//Mutators:
void Restaurant::set_menu(Menu menu) {this->menu = menu;}
void Restaurant::set_employees(employee* employees) {this->employees = employees;}
void Restaurant::set_week(hours* week) {this->week = week;}
void Restaurant::set_name(string name) {this->name = name;}
void Restaurant::set_phone(string phone) {this->phone = phone;}
void Restaurant::set_address(string address) {this->address = address;}

/******************************************************************************
 ** Function: print
 ** Description: Prints the restaurant info
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Restaurant::print() const {
	cout << "----------------------------------------" << endl;
	cout << "RESTAURANT INFO: " << endl;
	cout << "Name: " << name << endl;
	cout << "Phone: " << phone << endl;
	cout << "Address: " << address << endl;
	cout << endl;

	print_hours();

	cout << "Number of Employees: " << num_employees << endl;
	for (int i = 0; i < num_employees; i++) {
		cout << employees[i].id << " " << employees[i].first_name << " " << employees[i].last_name << " " << employees[i].password << endl;
	}

	cout << "Menu: " << endl;
	menu.print();
	cout << "----------------------------------------" << endl;
	cout << endl;
}

/******************************************************************************
 ** Function: print_hours
 ** Description: Prints the hours the restaurant is open
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Restaurant::print_hours() const {
	cout << "Days Open: " << num_days_open << endl;
	for (int i = 0; i < num_days_open; i++) {
		cout << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << endl;
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
void Restaurant::load_data() {
	ifstream rf;
	string trash;

	//Load the info from the restaurant_info.txt file
	rf.open("restaurant_info.txt");
	if (rf.is_open()) {
		getline(rf, this->name);
		getline(rf, this->phone);
		getline(rf, this->address);
		rf >> this->num_days_open;
		this->week = new hours[this->num_days_open];
		for (int i = 0; i < this->num_days_open; i++) {
			rf >> this->week[i].day;
			rf >> this->week[i].open_hour;
			rf >> this->week[i].close_hour;
		}
	}
	else {
		cout << "File could not be found" << endl;
	}
	rf.close();

	//Load the info from the employee.txt file
	rf.open("employee.txt");
	if (rf.is_open()) {
		//Count how many employees there are
		while (!rf.eof()) {
			getline(rf, trash);
			this->num_employees++;
		}
		//Set pointer back to the top
		rf.close();
		rf.open("employee.txt");

		//Allocate the memory needed for the employees and fill the employees
		this->employees = new employee[this->num_employees];
		for (int i = 0; i < this->num_employees; i++) {
			rf >> this->employees[i].id;
			rf >> this->employees[i].first_name;
			rf >> this->employees[i].last_name;
			rf >> this->employees[i].password;
		}
	}
	else {
		cout << "File could not be found" << endl;
	}
	rf.close();

	//Load data into menu with the load data function within menu
	menu.load_data();
}

/******************************************************************************
 ** Function: welcome
 ** Description: Asks the user if they would like to go to customer or employee options or quit
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Restaurant::welcome() {
	string response;

	cout << "Welcome to " << this->name << endl;
	//Ask what the user wants to do
	do {
		cout << "Are you a customer (C) or an employee (E) or do you want to quit (Q)? ";
		cin >> response;
		cout << endl;
		if (response != "C" && response != "E" && response != "Q") {
			cout << "PLEASE ENTER C, E, or Q ONLY!" << endl;
			cout << endl;
		}
	} while (response != "C" && response != "E" && response != "Q");

	//Go to the correct option
	if (response == "C") {
		this->customer_selection();
		welcome();
	}
	else if (response == "E") {
		this->employee_login();
		welcome();
	}
}

/******************************************************************************
 ** Function: customer_selection
 ** Description: Goes to the correct option as chosen by the user
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Restaurant::customer_selection() {
	string response;

	response = print_customer_selection();

	if (response == "1") {
			menu.print();
	}
	else if (response == "2") {
		search_by_cost();
	}
	else if (response == "3") {
		search_by_ingredients();
	}
	else if (response == "4") {
		order_off_menu(this->menu);
	}
	else if (response == "5") {
		print_hours();
	}
	else if (response == "6") {
		cout << "Address: " << address << endl;
		cout << endl;
	}
	else if (response == "7") {
		cout << "Phone: " << phone << endl;
		cout << endl;
	}
	else if (response == "8") {
		return;
	}

	//Allow the customer to select another option
	customer_selection();
}

/******************************************************************************
 ** Function: print_customer_selection
 ** Description: Prints the customer's options and asks what they would like to choose
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
string Restaurant::print_customer_selection() {
	string response;

	cout << "What would you like to do?" << endl;
	cout << "1. View Menu" << endl;
	cout << "2. Search by Cost" << endl;
	cout << "3. Search by Ingredients" << endl;
	cout << "4. Place Order" << endl;
	cout << "5. View Hours" << endl;
	cout << "6. View Address" << endl;
	cout << "7. View Phone" << endl;
	cout << "8. Log Out" << endl;
	cout << endl;
	//Ask the user what option they would like to select
	do {
		cout << "Selection: ";
		cin >> response;
		cout << endl;

		if (!is_int(response) || get_int(response) < 1 || get_int(response) > 8) {
			cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND 8!" << endl;
			cout << endl;
		}
	} while (!is_int(response) || get_int(response) < 1 || get_int(response) > 8);

	return response;
}

/******************************************************************************
 ** Function: search_by_cost
 ** Description: Search the menu by cost
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Restaurant::search_by_cost() {
	string upper_bound;
	string size;
	Menu search_result;

	//Ask what the user wants the max price to be?
	do {
		cout << "What would you like your max cost to be? ";
		cin >> upper_bound;
		cout << endl;

		if (!is_int(upper_bound) || upper_bound < "1") {
			cout << "ENTER ONLY WHOLE NUMBERS ABOVE ZERO!" << endl;
			cout << endl;
		}

	} while (!is_int(upper_bound) || upper_bound < "1");

	//Ask what size they are looking for
	do {
		cout << "What size pizza do you want (S/M/L)? ";
		cin >> size;
		cout << endl;

		if (size != "S" && size != "M" && size != "L") {
			cout << "PLEASE ENTER S, M, OR L ONLY!" << endl;
			cout << endl;
		}
	} while (size != "S" && size != "M" && size != "L");

	search_result = menu.search_pizza_by_cost(get_int(upper_bound), size);

	order_off_search(search_result);
}

/******************************************************************************
 ** Function: search_by_ingredients
 ** Description: Search the menu by ingredients
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Restaurant::search_by_ingredients() {
	string response, response2;
	string* ingredients = new string[1];
	string* temp;
	int num_ingredients = 0;
	int i = 0;
	Menu search_result;

	//Ask the user if they want to include or exclude ingredients
	do {
		cout << "Would you like to search for ingredients you want to include (I) or exclude (E)? ";
		cin >> response;
		cout << endl;

		if (response != "I" && response != "E") {
			cout << "PLEASE ENTER E or I!" << endl;
			cout << endl;
		}
	} while (response != "I" && response != "E");

	//Collect ingredients
	do {
		cout << "What ingredient would you like to include/exclude? ";
		cin >> ingredients[i];
		cout << endl;
		num_ingredients++;

		//Check if the user wants to include another ingredient
		do {
			cout << "Would you like to include/exclude another item (Yes/No)? ";
			cin >> response2;
			cout << endl;

			if (response2 != "Yes" && response2 != "No") {
				cout << "Please enter Yes or No!" << endl;
				cout << endl;
			}
		} while (response2 != "Yes" && response2 != "No");

		//Resize the ingredients array if they want to include another item
		if (response2 == "Yes") {
			temp = new string[num_ingredients + 1];

			for (int j = 0; j < num_ingredients; j++) {
				temp[j] = ingredients[j];
			}

			delete [] ingredients;
			ingredients = new string[num_ingredients + 1];

			for (int j = 0; j < num_ingredients; j++) {
				ingredients[j] = temp[j];
			}

			delete [] temp;

			//Increase the index so the next ingredient entered goes in the end of the ingredients array
			i++;
		}
	} while (response2 == "Yes");

	if (response == "I") {
		search_result = menu.search_pizza_by_ingredients_to_include(ingredients, num_ingredients);
	}
	else if (response == "E") {
		search_result = menu.search_pizza_by_ingredients_to_exclude(ingredients, num_ingredients);
	}

	order_off_search(search_result);
}

/******************************************************************************
 ** Function: order_off_search
 ** Description: Ask the user if they would like to order off of a search_result, if they do collect which pizzas they want
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Restaurant::order_off_search(Menu& search_result) {
	string response2, response;

	//Ask user if they want to place an order off the search result
	do {
		cout << "Would you like to place an order off this search result (Yes/No)? ";
		cin >> response2;
		cout << endl;

		if (response2 != "Yes" && response2 != "No") {
			cout << "Please enter Yes or No!" << endl;
			cout << endl;
		}
	} while (response2 != "Yes" && response2 != "No");

	//Ask which pizza they want to order and pass that through
	if (response2 == "Yes") {
		Pizza* order = new Pizza[1];
		int num_orders = 0;
		int i = 0;

		//Keep asking wich pizza they want to add to the order as long as they want to add pizzas
		do {
			//Ask which pizza they want to order
			do {
				cout << "Which pizza number do you want? ";
				cin >> response;
				cout << endl;

				if (response < "1" || get_int(response) > search_result.get_num_pizzas()) {
					cout << "Please enter a number between 1 and the amount of pizzas from the search result!" << endl;
					cout << endl;
				}
			} while (response < "1" || get_int(response) > search_result.get_num_pizzas());

			num_orders++;

			//Add the pizza to the order list
			order[i] = search_result.get_pizzas()[get_int(response) - 1];

			//Ask if they would like to add a pizza to that order
			do {
				cout << "Would you like to add another pizza to this order (Yes/No)? ";
				cin >> response2;
				cout << endl;

				if (response2 != "Yes" && response2 != "No") {
					cout << "Please enter Yes or No!" << endl;
					cout << endl;
				}
			} while (response2 != "Yes" && response2 != "No");

			//Resize the orders array if they want to include another item
			if (response2 == "Yes") {
				Pizza* temp = new Pizza[num_orders + 1];

				for (int j = 0; j < num_orders; j++) {
					temp[j] = order[j];
				}

				delete [] order;
				order = new Pizza[num_orders + 1];

				for (int j = 0; j < num_orders; j++) {
					order[j] = temp[j];
				}

				delete [] temp;

				//Increase the index so the next order entered goes in the end of the orders array
				i++;
			}
		} while (response2 == "Yes");
		place_order(order, num_orders);
	}
}

/******************************************************************************
 ** Function: order_off_menu
 ** Description: Collect which pizzas the user wants to order off the menu
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Restaurant::order_off_menu(Menu& search_result) {
	Pizza* order = new Pizza[1];
	int num_orders = 0;
	int i = 0;
	string response, response2;

	//Keep asking wich pizza they want to add to the order as long as they want to add pizzas
	do {
		//Ask which pizza they want to order
		do {
			cout << "Which pizza number do you want? ";
			cin >> response;
			cin.ignore();
			cin.clear();
			cout << endl;

			if (response < "1" || get_int(response) > search_result.get_num_pizzas()) {
				cout << "Please enter a number between 1 and the amount of pizzas on the menu!" << endl;
				cout << endl;
			}
		} while (response < "1" || get_int(response) > search_result.get_num_pizzas());

		num_orders++;

		//Add the pizza to the order list
		order[i] = search_result.get_pizzas()[get_int(response) - 1];

		//Ask if they would like to add a pizza to that order
		do {
			cout << "Would you like to add another pizza to this order (Yes/No)? ";
			cin >> response2;
			cout << endl;

			if (response2 != "Yes" && response2 != "No") {
				cout << "Please enter Yes or No!" << endl;
				cout << endl;
			}
		} while (response2 != "Yes" && response2 != "No");

		//Resize the orders array if they want to include another item
		if (response2 == "Yes") {
			Pizza* temp = new Pizza[num_orders + 1];

			for (int j = 0; j < num_orders; j++) {
				temp[j] = order[j];
			}

			delete [] order;
			order = new Pizza[num_orders + 1];

			for (int j = 0; j < num_orders; j++) {
				order[j] = temp[j];
			}

			delete [] temp;

			//Increase the index so the next order entered goes in the end of the orders array
			i++;
		}
	} while (response2 == "Yes");
	place_order(order, num_orders);
}

/******************************************************************************
 ** Function: place_order
 ** Description: Write to the order.txt file with a new order
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: The order.txt file should have an added order
*****************************************************************************/
void Restaurant::place_order(Pizza* order, int num_pizzas) {
	int num_orders = 0;
	string trash, response;
	fstream f;

	f.open("orders.txt", fstream::in);

	if (f.is_open()) {
		//Count the number of orders
		while (!f.eof()) {
			getline(f, trash);
			if (trash != "") {
				num_orders++;
			}
		}

		//Clear the input buffer
		while (cin.get() != '\n');

		//reset cursor to the top
		f.close();
		f.open("orders.txt", fstream::out|fstream::app);

		f << (num_orders + 1) << " ";

		cout << "What is your name? ";
		getline(cin, response);
		cout << endl;
		f << response << " ";

		cout << "What is your credit card number? ";
		getline(cin, response);
		cout << endl;
		f << response << " ";

		cout << "What is your address? ";
		getline(cin, response);
		cout << endl;
		f << response << " ";

		cout << "What is your phone number? ";
		getline(cin, response);
		cout << endl;
		f << response << " ";

		//Ask for the size and quantity for each pizza
		for (int i = 0; i < num_pizzas; i++) {
			f << order[i].get_name() << " ";

			do {
				cout << "What size of the " << order[i].get_name() << " do you want (S/M/L)? ";
				cin >> response;
				cout << endl;

				if (response != "S" && response != "M" && response != "L") {
					cout << "PLEASE ENTER S, M, OR L ONLY!" << endl;
					cout << endl;
				}
			} while (response != "S" && response != "M" && response != "L");
			f << response << " ";

			do {
				cout << "How many of the " << order[i].get_name() << " do you want? ";
				cin >> response;
				cout << endl;

				if (!is_int(response) || response < "1") {
					cout << "PLEASE ENTER A WHOLE NUMBER LARGER THAN 0!" << endl;
					cout << endl;
				}
			} while (!is_int(response) || response < "1");
			f << response << " ";
		}
		f << endl;
	}
	else {
		cout << "File did not open!" << endl;
	}

	delete [] order;
}

/******************************************************************************
 ** Function: employee_login
 ** Description: Checks the employees credentials
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Restaurant::employee_login() {
	string id_input;
	string password_input;
	bool match = false;

	//Ask for password and ID until the user enters correct info or wants to quit
	do {
		cout << "Please enter ID number or (Q) to quit: ";
		cin >> id_input;
		cout << endl;

		//Check if the user wants to quit
		if (id_input == "Q") {
			welcome();
		}

		cout << "Please enter password or (Q) to quit: ";
		cin >> password_input;
		cout << endl;

		//Check if the user wants to quit
		if (password_input == "Q") {
			welcome();
		}

		//Check if the credentials are correct
		for (int i = 0; i < num_employees; i++) {
			if (employees[i].id == id_input) {
				if (employees[i].password == password_input) {
					match = true;
				}
			}

			//If the credentials are correct, stop checking
			if (match == true) {
				break;
			}
		}

		//Give an error message if the credentials are false
		if (match == false) {
			cout << "INCORRECT CREDENTIALS! TRY AGAIN!" << endl;
			cout << endl;
		}

	} while (match == false);

	if (match == true) {
		employee_selection();
	}
}

/******************************************************************************
 ** Function: employee_selection
 ** Description: Goes to the employees correct selection
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Restaurant::employee_selection() {
	string response;

	response = print_employee_selection();

	if (response == "1") {
		change_hours();
	}
	else if (response == "2") {
		view_orders();
	}
	else if (response == "3") {
		remove_order();
	}
	else if (response == "4") {
		add_item();
	}
	else if (response == "5") {
		remove_item();
	}
	else if (response == "6") {
		menu.print();
	}
	else if (response == "7") {
		print_hours();
	}
	else if (response == "8") {
		cout << "Address: " << address << endl;
		cout << endl;
	}
	else if (response == "9") {
		cout << "Phone: " << phone << endl;
		cout << endl;
	}
	else if (response == "10") {
		return;
	}

	//Allow the employee to select another option
	employee_selection();
}

/******************************************************************************
 ** Function: print_employee_selection
 ** Description: Prints the customer's options and asks what they would like to choose
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
string Restaurant::print_employee_selection() {
	string response;

	cout << "What would you like to do?" << endl;
	cout << "1. Change Hours" << endl;
	cout << "2. View Orders" << endl;
	cout << "3. Remove Order" << endl;
	cout << "4. Add Item to Menu" << endl;
	cout << "5. Remove Item from Menu" << endl;
	cout << "6. View Menu" << endl;
	cout << "7. View Hours" << endl;
	cout << "8. View Address" << endl;
	cout << "9. View Phone" << endl;
	cout << "10. Log Out" << endl;
	cout << endl;
	//Ask the user what option they would like to select
	do {
		cout << "Selection: ";
		cin >> response;
		cout << endl;

		if (!is_int(response) || get_int(response) < 1 || get_int(response) > 10) {
			cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND 10!" << endl;
			cout << endl;
		}
	} while (!is_int(response) || get_int(response) < 1 || get_int(response) > 10);

	return response;
}

/******************************************************************************
 ** Function: view_orders
 ** Description: Print the orders
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Restaurant::view_orders() const {
	string current_line;
	ifstream rf;

	rf.open("orders.txt");

	while (!rf.eof()) {
		getline(rf, current_line);
		cout << current_line << endl;
	}

	cout << endl;
}

/******************************************************************************
 ** Function: add_item
 ** Description: Creates a new pizza, gathers new pizza info, and then passes pizza on to be added to the main menu
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: A new pizza is made
*****************************************************************************/
void Restaurant::add_item() {
	Pizza new_pizza;
	string response;
	string* ingredients;

	//Gather all the info needed for the new pizza
	cout << "What is the name of the pizza? ";
	cin >> response;
	cout << endl;
	new_pizza.set_name(response);

	do {
		cout << "What is the small cost of the pizza? ";
		cin >> response;
		cout << endl;

		if (!is_int(response) || response < "1") {
			cout << "PLEASE ENTER A WHOLE NUMBER GREATER THAN 0!" << endl;
			cout << endl;
		}
	} while(!is_int(response) || response < "1");
	new_pizza.set_small_cost(get_int(response));

	do {
		cout << "What is the medium cost of the pizza? ";
		cin >> response;
		cout << endl;

		if (!is_int(response) || response < "1") {
			cout << "PLEASE ENTER A WHOLE NUMBER GREATER THAN 0!" << endl;
			cout << endl;
		}
	} while(!is_int(response) || response < "1");
	new_pizza.set_medium_cost(get_int(response));

	do {
		cout << "What is the large cost of the pizza? ";
		cin >> response;
		cout << endl;

		if (!is_int(response) || response < "1") {
			cout << "PLEASE ENTER A WHOLE NUMBER GREATER THAN 0!" << endl;
			cout << endl;
		}
	} while(!is_int(response) || response < "1");
	new_pizza.set_large_cost(get_int(response));

	do {
		cout << "How many ingredients are on the pizza? ";
		cin >> response;
		cout << endl;

		if (!is_int(response) || response < "1") {
			cout << "PLEASE ENTER A WHOLE NUMBER GREATER THAN 0!" << endl;
			cout << endl;
		}
	} while(!is_int(response) || response < "1");
	new_pizza.set_num_ingredients(get_int(response));

	ingredients = new string[new_pizza.get_num_ingredients()];

	for (int i = 0; i < new_pizza.get_num_ingredients(); i++) {
		cout << "What is ingredient number " << i + 1 << "? ";
		cin >> ingredients[i];
		cout << endl;
	}
	new_pizza.set_ingredients(ingredients);

	//Add the new pizza to the menu
	menu.add_pizza_to_main_menu(new_pizza);
}

/******************************************************************************
 ** Function: remove_item
 ** Description: Asks which pizza should be removed
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Restaurant::remove_item() {
	string response;

	do {
		cout << "Which pizza number do you want to remove? ";
		cin >> response;
		cout << endl;

		if (!is_int(response) || response < "1" || get_int(response) > menu.get_num_pizzas()) {
			cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND " << menu.get_num_pizzas() << "!" << endl;
			cout << endl;
		}
	} while (!is_int(response) || response < "1" || get_int(response) > menu.get_num_pizzas());

	menu.remove_item_from_menu(get_int(response));
}

/******************************************************************************
 ** Function: remove_order
 ** Description: Asks which order should be removed
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Restaurant::remove_order() {
	string response, trash;
	int num_orders = 0;
	ifstream rf;

	rf.open("orders.txt");
	if (rf.is_open()) {
		//Count the number of orders
		while (!rf.eof()) {
			getline(rf, trash);
			if (trash != "") {
				num_orders++;
			}
		}
	}
	else {
		cout << "File did not open" << endl;
	}

	do {
		cout << "Which order number do you want to remove? ";
		cin >> response;
		cout << endl;

		if (!is_int(response) || response < "1" || get_int(response) > num_orders) {
			cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND " << num_orders << "!" << endl;
			cout << endl;
		}
	} while (!is_int(response) || response < "1" || get_int(response) > num_orders);

	remove_order_from_file(get_int(response));
}

/******************************************************************************
 ** Function: remove_order_from_file
 ** Description: Removes a specific order from file
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: There should be one less order on file
*****************************************************************************/
void Restaurant::remove_order_from_file(int remove_num) {
	int line_num = 1;
	int new_line_num = 1;
	ifstream rf;
	ofstream wf;
	string line;

	//Change the menu text file
	rf.open("orders.txt");
	wf.open("temp.txt");
	while(!rf.eof()) {
		getline(rf, line);
		if (line != "") {
			if (line_num != remove_num) {
				line[0] = (new_line_num + 48);

				wf << line << endl;
				new_line_num++;
			}
		}
		line_num++;
	}

	wf.close();
	rf.close();

	remove("orders.txt");
	rename("temp.txt", "orders.txt");
}

/******************************************************************************
 ** Function: change_hours
 ** Description: Change the hours the store is open
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: The week member should be changed
*****************************************************************************/
void Restaurant::change_hours() {
	string index, response;

	do {
		cout << "What day number do you want to change (Sunday = 1, Monday = 2, etc.)? ";
		cin >> index;
		cout << endl;

		if (!is_int(index) || get_int(index) < 1 || get_int(index) > 7) {
			cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND 7!" << endl;
			cout << endl;
		}
	} while (!is_int(index) || get_int(index) < 1 || get_int(index) > 7);

	do {
		cout << "What time do you want to open (pick a number between 1 and 12)? ";
		cin >> response;
		cout << endl;

		if (!is_int(response) || get_int(response) < 1 || get_int(response) > 12) {
			cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND 12!" << endl;
			cout << endl;
		}
	} while (!is_int(response) || get_int(response) < 1 || get_int(response) > 12);
	week[(get_int(index) - 1)].open_hour = response;


	do {
		cout << "What time do you want to close (pick a number between 1 and 12)? ";
		cin >> response;
		cout << endl;

		if (!is_int(response) || get_int(response) < 1 || get_int(response) > 12) {
			cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND 12!" << endl;
			cout << endl;
		}
	} while (!is_int(response) || get_int(response) < 1 || get_int(response) > 12);
	week[(get_int(index) - 1)].close_hour = response;

	write_info();
}

/******************************************************************************
 ** Function: write_info
 ** Description: Write the info file
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: The info file should be updated
*****************************************************************************/
void Restaurant::write_info() {
	ofstream wf;

	remove("restaurant_info.txt");

	//Make the restaurant_info file
	wf.open("restaurant_info.txt");
	wf << name << endl;
	wf << phone << endl;
	wf << address << endl;
	wf << num_days_open << endl;
	for (int i = 0; i < num_days_open; i++) {
		wf << week[i].day << " ";
		wf << week[i].open_hour << " ";
		wf << week[i].close_hour << endl;
	}

	wf.close();
}
