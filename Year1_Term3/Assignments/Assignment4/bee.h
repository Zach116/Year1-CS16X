#ifndef BEE_H
#define BEE_H

#include <iostream>
#include <vector>
#include <string>
#include "insect.h"
#include "tools.h"

using namespace std;

class Bee:public Insect {
	public:
		//Constructor
		Bee(); //DONE AND TESTED

		//Check if the bee can move, if it cannot, attack. If it is not a ninja in the way, it cannot move
		virtual void take_turn(vector<vector<vector<Insect*> > > &board, int currentSpaceIndex, int specificInsectIndex); //DONE AND TESTED
		//Move the bee by one space
		void move(vector<vector<vector<Insect*> > > &board, int currentSpaceIndex, int specificInsectIndex); //DONE AND TESTED
		//Attack the first ant on the space
		void attack(vector<vector<vector<Insect*> > > &board, int currentSpaceIndex); //DONE AND TESTED
};

#endif
