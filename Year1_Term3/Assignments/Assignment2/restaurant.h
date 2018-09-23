#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include "menu.h"
#include "employee.h"
#include "hours.h"

using namespace std;

class Restaurant {
	private:
		Menu menu;
		int num_employees;
		int num_days_open;
		employee* employees;
		hours* week;
		string name;
		string phone;
		string address;
	public:
		//Constructors:
		Restaurant();
		Restaurant(Menu menu, employee* employees, int num_employees, hours* week, string name, string phone, string address);

		//Destructor:
		~Restaurant();

		//Copy Constructor:
		Restaurant(const Restaurant& copy);

		//Assignment Operator Overload:
		const Restaurant& operator=(const Restaurant& copy);

		//Accessors:
		Menu get_menu() const;
		employee* get_employees() const;
		hours* get_week() const;
		string get_name() const;
		string get_phone() const;
		string get_address() const;

		//Mutators:
		void set_menu(Menu menu);
		void set_employees(employee* employees);
		void set_week(hours* week);
		void set_name(string name);
		void set_phone(string phone);
		void set_address(string address);

		//Other Functions:
		void print() const;
		void print_hours() const;
		void load_data();
		void welcome();
		void customer_selection();
		string print_customer_selection();
		void search_by_cost();
		void search_by_ingredients();
		void order_off_search(Menu& search_result);
		void order_off_menu(Menu& search_result);
		void place_order(Pizza* order, int num_pizzas);
		void employee_login();
		void employee_selection();
		string print_employee_selection();
		void view_orders() const;
		void add_item();
		void remove_item();
		void remove_order();
		void remove_order_from_file(int remove_num);
		void change_hours();
		void write_info();
};
