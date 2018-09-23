#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "./mult_div.h"

using namespace std;

int main(int argc, char** argv) {
	bool runAgain;
	int rows, cols;
	mult_div_values** table;

	//Validate and fix command line arguments
	if (argc < 3 || !is_valid_dimensions(argv[1], argv[2])) {
		cout << "Invlaid command line arguments, please enter a row size greater than 0! ";
		rows = atoi(get_input());

		cout << "Please enter a column size greater than 0! ";
		cols = atoi(get_input());
	}
	else {
		rows = atoi(argv[1]);
		cols = atoi(argv[2]);
	}
	
	do {
		table = create_table(rows, cols);
		set_mult_values(table, rows, cols);
		set_div_values(table, rows, cols);

		cout << "Multiplication Table: " << endl;
		print_mult(table, rows, cols);
		cout << endl << "Division Table: " << endl;
		print_div(table, rows, cols);

		delete_table(table, rows);
		
		runAgain = run_again();

		if (runAgain == true) {
			cout << "Please enter a row size greater than 0! ";
			rows = atoi(get_input());
	
			cout << "Please enter a column size greater than 0! ";
			cols = atoi(get_input());
		}

	} while (runAgain == true);
}
