#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include "restaurant.h"

using namespace std;

/******************************************************************************
 ** Function: main
 ** Description: where the program starts
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
int main() {
	Restaurant pizza_restaurant;
	ofstream wf;
	//Create an orders text file in case there is not one
	wf.open("orders.txt");
	wf.close();

	pizza_restaurant.load_data();
	pizza_restaurant.welcome();
}
