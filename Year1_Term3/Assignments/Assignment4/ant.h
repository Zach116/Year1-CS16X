#ifndef ANT_H
#define ANT_H

#include <iostream>
#include <vector>
#include <string>
#include "insect.h"
#include "tools.h"

using namespace std;

class Ant:public Insect {
	private:
		int foodCost;

	public:
		//Constructor
		Ant(); //DONE AND TESTED

		Ant(string symbol, int foodCost, int shield); //DONE AND TESTED

		//Accessors
		int get_foodCost(); //DONE AND TESTED

		//Mutators
		void set_foodCost(int foodCost); //DONE AND TESTED

		//Will attack if the ant is a thrower type, otherwise nothing will happen
		virtual void take_turn(vector<vector<vector<Insect*> > > &board, int currentSpace, int specificInsectIndex); //DONE AND TESTED

		//virtual Ant* copy();
};

#endif
