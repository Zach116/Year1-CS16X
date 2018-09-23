#ifndef INSECT_H
#define INSECT_H

#include <iostream>
#include <string>
#include <vector>
#include "insect.h"
#include "tools.h"

using namespace std;


class Insect {
	protected:
		string name;
		string symbol;
		int shield;

	public:
		//Constructor
		Insect(); //DONE AND TESTED

		//Accessors
		string get_symbol(); //DONE AND TESTED
		int get_shield(); //DONE AND TESTED

		//Mutators
		void take_damage(int damage); //DONE AND TESTED
		void set_symbol(string symbol); //DONE AND TESTED
		void set_shield(int shield); //DONE AND TESTED


		//Check what the insect should do
		virtual void take_turn(vector<vector<vector<Insect*> > > &board, int currentSpace, int specificInsectIndex) = 0;

		//virtual Insect* copy();
};

#endif
