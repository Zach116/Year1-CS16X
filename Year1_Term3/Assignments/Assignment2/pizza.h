#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include "tools.h"

using namespace std;

class Pizza {
	private:
		string name;
		int small_cost;
		int medium_cost;
		int large_cost;
		int num_ingredients;
		string* ingredients;

	public:
		//Constructors:
		Pizza();
		Pizza(string name, int small_cost, int medium_cost, int large_cost, int num_ingredients, string* ingredients);

		//Destructor
		~Pizza();

		//Copy Constructor
		Pizza(const Pizza& copy);

		//Assignment Operator Overload
		const Pizza& operator=(const Pizza& copy);

		//Accessors:
		string get_name() const;
		int get_small_cost() const;
		int get_medium_cost() const;
		int get_large_cost() const;
		int get_num_ingredients() const;
		string* get_ingredients() const;

		//Mutators:
		void set_name(string name);
		void set_small_cost(int cost);
		void set_medium_cost(int cost);
		void set_large_cost(int cost);
		void set_num_ingredients(int num);
		void set_ingredients(string* ingredients);

		//Other functions:
		void print() const;
		void load_data(ifstream& rf);
};
