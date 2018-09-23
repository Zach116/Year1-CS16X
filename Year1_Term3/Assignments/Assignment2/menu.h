#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include "pizza.h"

using namespace std;

class Menu {
	private:
		int num_pizzas;
		Pizza* pizzas;
	public:
		//Constructors:
		Menu();
		Menu(int num, Pizza* pizzas);

		//Destructor
		~Menu();

		//Copy Constructor
		Menu(const Menu& copy);

		//Assignment Operator Overload
		const Menu& operator=(const Menu& copy);

		//Accessors:
		int get_num_pizzas() const;
		Pizza* get_pizzas() const;

		//Mutators:
		void set_num_pizzas(int num);
		void set_pizzas(Pizza* pizzas);

		//Other Functions:
		void print() const;
		void load_data();
		Menu search_pizza_by_cost(int upper_bound, string size);
		Menu search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients);
		void add_pizza(Pizza new_pizza);
		void add_pizza_to_main_menu(Pizza new_pizza);
		void remove_item_from_menu(int pizza_num);
		Menu search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients);
};
