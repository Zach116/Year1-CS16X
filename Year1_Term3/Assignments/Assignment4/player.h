#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include "ant.h"
#include "bee.h"
#include "insect.h"
#include "tools.h"

using namespace std;

class Player {
	private:
		//Starts with 50
		int foodBank;

		//This is a 3d array that will hold ants and bees that have been polymorphed into Insect. The first index will be the space on the board. The second index will always be of size two and 0 will refer to ants on the current spot and 1 will refer to bees on the current spot. The third index will refer to specific bees or ants (dependent on second index) at the current spot (dependent on first index)
		vector<vector<vector<Insect*> > > board;

	public:
		//Constructor
		Player(); //DONE AND TESTED

		//Accessors
		int get_foodBank(); //DONE AND TESTED
		vector<vector<vector<Insect*> > > get_board(); //DONE AND TESTED

		//Modifiers
		//All the add functions MUST make a copy first
		void add_ant(Insect* ant, int newSpaceIndex); //DONE AND TESTED
		//Adds the bodyguard ant to first priority on the space
		void add_bodyguard_ant(Insect* ant, int newSpaceIndex); //DONE AND TESTED
		//Make a bee and place it on the far right end of the board
		void generate_bee(); //DONE AND TESTED


		//Asks which ant the player wants to place
		void ant_selection(); //DONE AND TESTED
		bool valid_ant(string response); //DONE AND TESTED

		//Asks where the ant should be placed, must check that the space does not have an ant already that is not a bodyguard ant. (For bodyguard ants, must make sure there is only one bodyguard on the square). Then passes on to the correct add function
		void place_ant(Insect* ant); //DONE AND TESTED
		bool valid_ant_placement(int response); //DONE AND TESTED
		void place_bodyguard_ant(Insect* ant); //DONE AND TESTED
		bool valid_bodyguard_ant_placement(int response); //DONE AND TESTED

		//if the ant being removed is a fire ant, remove all the bees on the same space
		void remove_ant(int currSpaceIndex); //DONE AND TESTED
		void remove_bee(int currSpaceIndex); //DONE AND TESTED

		//Adds 1 to the foodBank for every harvester that exists
		void generate_food(); //DONE AND TESTED

		//Creates an ant and fills it with the appropriate information depending on the type, then passes it on to the place_ant() function
		void create_harvester(); //DONE AND TESTED
		void create_thrower(); //DONE AND TESTED
		void create_fire(); //DONE AND TESTED
		void create_longThrower(); //DONE AND TESTED
		void create_shortThrower(); //DONE AND TESTED
		void create_wall(); //DONE AND TESTED
		void create_ninja(); //DONE AND TESTED
		void create_bodyguard(); //DONE AND TESTED

		//Rotates through all insects and has them take their turn. After each insect takes their turn, check if anything is dead and if so remove it
		void take_turn_ants(); //DONE AND TESTED
		void take_turn_bees(); //DONE AND TESTED


		void print_board(); //DONE AND TESTED
		int most_insects(); //DONE AND TESTED

		bool game_over(); //DONE AND TESTED

		void delete_vector(); //DONE AND TESTED
};

#endif
