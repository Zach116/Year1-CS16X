#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "insect.h"
#include "ant.h"
#include "bee.h"
#include "tools.h"

using namespace std;

//Constructor
Player::Player() {
  foodBank = 50;

  board.resize(10);
  for (int i = 0; i < 10; i++) {
    board[i].resize(2);
  }
}

//Accessors
int Player::get_foodBank() {return foodBank;}
vector<vector<vector<Insect*> > > Player::get_board() {return board;}

//Modifiers
void Player::add_ant(Insect* ant, int newSpaceIndex) {
  board[newSpaceIndex][0].push_back(ant);
}
void Player::add_bodyguard_ant(Insect* ant,int newSpaceIndex) {
  board[newSpaceIndex][0].insert(board[newSpaceIndex][0].begin(), ant);
}
void Player::generate_bee() {
  Insect* bee = new Bee;
  board[9][1].push_back(bee);
}

/******************************************************************************
 ** Function: ant_selection()
 ** Description: Asks which ant the player wants to place
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Player::ant_selection() {
  string response;

  //Ask which ant they would like to select
  do {
    cout << "Which ant would you like to select? You may choose Harvester for 2 (H), Thrower for 4 (T), Fire for 4 (F), Long Thrower for 3 (L), Short Thrower for 3 (S), Wall for 4 (W), Ninja for 6 (N), Bodyguard for 4 (B), or None (Q): ";
    cin >> response;
    cout << endl;

    if (!valid_ant(response)) {
      cout << "ENTER A VALID ANT YOU CAN AFFORD!" << endl;
      cout << endl;
    }
  } while(!valid_ant(response));

  //Generate the correct ant
  if (response == "H") {
    create_harvester();
  }
  else if (response == "T") {
    create_thrower();
  }
  else if (response == "F") {
    create_fire();
  }
  else if (response == "L") {
    create_longThrower();
  }
  else if (response == "S") {
    create_shortThrower();
  }
  else if (response == "W") {
    create_wall();
  }
  else if (response == "N") {
    create_ninja();
  }
  else if (response == "B") {
    create_bodyguard();
  }
}

/******************************************************************************
 ** Function: valid_ant
 ** Description: Checks if the user selected a valid ant
 ** Parameters: string response
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool Player::valid_ant(string response) {
  if (response != "H" && response != "T" && response != "F" && response != "L" && response != "S" && response != "W" && response != "N" && response != "B" && response != "Q") {
    return false;
  }
  else if (response == "H" && foodBank < 2) {
    return false;
  }
  else if (response == "T" && foodBank < 4) {
    return false;
  }
  else if (response == "F" && foodBank < 4) {
    return false;
  }
  else if (response == "L" && foodBank < 3) {
    return false;
  }
  else if (response == "S" && foodBank < 3) {
    return false;
  }
  else if (response == "W" && foodBank < 4) {
    return false;
  }
  else if (response == "N" && foodBank < 6) {
    return false;
  }
  else if (response == "B" && foodBank < 4) {
    return false;
  }
  return true;
}

/******************************************************************************
 ** Function: create_*
 ** Description: Creates an ant and fills it with the appropriate information depending on the type, then passes it on to the place_ant() function
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Ant is created
*****************************************************************************/
void Player::create_harvester() {
  Insect* ant = new Ant("H", 2, 1);
  foodBank = foodBank - 2;

  place_ant(ant);
}
void Player::create_thrower() {
  Insect* ant = new Ant("T", 4, 1);
  foodBank = foodBank - 4;

  place_ant(ant);
}
void Player::create_fire() {
  Insect* ant = new Ant("F", 4, 1);
  foodBank = foodBank - 4;

  place_ant(ant);
}
void Player::create_longThrower() {
  Insect* ant = new Ant("L", 3, 1);
  foodBank = foodBank - 3;

  place_ant(ant);
}
void Player::create_shortThrower() {
  Insect* ant = new Ant("S", 3, 1);
  foodBank = foodBank - 3;

  place_ant(ant);
}
void Player::create_wall() {
  Insect* ant = new Ant("W", 4, 4);
  foodBank = foodBank - 4;

  place_ant(ant);
}
void Player::create_ninja() {
  Insect* ant = new Ant("N", 6, 1);
  foodBank = foodBank - 6;

  place_ant(ant);
}
void Player::create_bodyguard() {
  Insect* ant = new Ant("B", 4, 2);
  foodBank = foodBank - 4;

  place_bodyguard_ant(ant);
}

/******************************************************************************
 ** Function: place_*
 ** Description: Asks where the ant should be placed, must check that the space does not have an ant already that is not a bodyguard ant. (For bodyguard ants, must make sure there is only one bodyguard on the square). Then passes on to the correct add function
 ** Parameters: Insect* ant
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Player::place_ant(Insect* ant) {
  string response;

  do {
    cout << "Where would you like to place the ant? ";
    cin >> response;
    cout << endl;

    if (!is_int(response) || !valid_ant_placement(get_int(response) - 1)) {
      cout << "THAT IS NOT A VALID SPOT TRY AGAIN! " << endl;
      cout << endl;
    }
  } while(!is_int(response) || !valid_ant_placement(get_int(response) - 1));

  add_ant(ant, (get_int(response)-1));
}
bool Player::valid_ant_placement(int response) {
  //Check if there are already two ants on the board
  if (board[response][0].size() == 2) {
    return false;
  }
  //Check if there is an ant that is not a bodyguard ant on the board
  else if (board[response][0].size() == 1 && board[response][0][0]->get_symbol() != "B") {
    return false;
  }
  return true;
}

void Player::place_bodyguard_ant(Insect* ant) {
  string response;

  do {
    cout << "Where would you like to place the ant? ";
    cin >> response;
    cout << endl;

    if (!is_int(response) || !valid_bodyguard_ant_placement(get_int(response) - 1)) {
      cout << "THAT IS NOT A VALID SPOT TRY AGAIN! " << endl;
      cout << endl;
    }
  } while (!is_int(response) || !valid_bodyguard_ant_placement(get_int(response) - 1));

  add_bodyguard_ant(ant, (get_int(response)-1));
}
bool Player::valid_bodyguard_ant_placement(int response) {
  //Check if there are already two ants on the board
  if (board[response][0].size() == 2) {
    return false;
  }
  //Check if there is already a bodyguard ant on the board
  else if (board[response][0].size() == 1 && board[response][0][0]->get_symbol() == "B") {
    return false;
  }
  return true;
}

//Adds 1 to the foodBank for every harvester that exists
void Player::generate_food() {
  for (int currCol = 0; currCol < 10; currCol++) {
    for (int specAnt = 0; specAnt < board[currCol][0].size(); specAnt++) {
      if (board[currCol][0][specAnt]->get_symbol() == "H") {
          foodBank++;
      }
    }
  }
}

/******************************************************************************
 ** Function: take_turn_*
 ** Description: Rotates through all insects and has them take their turn. After each insect takes their turn, check if anything is dead and if so remove it
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Player::take_turn_ants() {
  for (int currCol = 0; currCol < 10; currCol++) {
    for (int specAnt = 0; specAnt < board[currCol][0].size(); specAnt++) {
      board[currCol][0][specAnt]->take_turn(board, currCol, specAnt);

      //Remove any dead bees
      for (int i = 0; i < 10; i++) {
        if (board[i][1].size() != 0 && board[i][1][0]->get_shield() < 1) {
          remove_bee(i);
        }
      }
    }
  }
}
void Player::take_turn_bees() {
  int size;
  int specBee;

  for (int currCol = 0; currCol < 10; currCol++) {
    //Calculate the size before any bees are moved
    size = board[currCol][1].size();
    specBee = 0;
    for (int i = 0; i < size; i++) {
      board[currCol][1][specBee]->take_turn(board, currCol, specBee);

      //If the bee did not move, up where the next specific bee is
      if (board[currCol][0].size() != 0 && board[currCol][0][0]->get_symbol() != "N") {
        specBee++;
      }

      //Remove any dead ants
      if (board[currCol][0].size() != 0 && board[currCol][0][0]->get_shield() < 1) {
        //If all bees are removed because of a fire ant, set the size to 0 to signal to move on to the next column
        if (board[currCol][0][0]->get_symbol() == "F") {
          size = 0;
        }

        remove_ant(currCol);
      }

      //Remove any dead bees that could have died by moving past a ninja
      for (int i = 0; i < 10; i++) {
        if (board[i][1].size() != 0 && board[i][1][0]->get_shield() < 1) {
          remove_bee(i);
        }
      }
    }
  }
}

/******************************************************************************
 ** Function: remove_*
 ** Description: Removes the first insect on the space
 ** Parameters: int currSpaceIndex
 ** Pre-Conditions: An insect exists on the space
 ** Post-Conditions: Insect is removed
*****************************************************************************/
void Player::remove_ant(int currSpaceIndex) {
  int size;

  //Remove all bees on the space if the killed ant was a fire ant
  if (board[currSpaceIndex][0][0]->get_symbol() == "F") {
    size = board[currSpaceIndex][1].size();
    for (int i = 0; i < size; i++) {
      delete board[currSpaceIndex][1][board[currSpaceIndex][1].size()-1];
      board[currSpaceIndex][1].pop_back();
    }
  }

  //Remove the killed ant
  delete board[currSpaceIndex][0][0];
  board[currSpaceIndex][0].erase(board[currSpaceIndex][0].begin());
}
void Player::remove_bee(int currSpaceIndex) {
  delete board[currSpaceIndex][1][0];
  board[currSpaceIndex][1].erase(board[currSpaceIndex][1].begin());
}

void Player::print_board() {
  cout << "|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10  |" << endl;

  //Print board
  for (int specInsect = 0; specInsect < most_insects(); specInsect++) {
		for (int currCol = 0; currCol < 10; currCol++) {
			cout << "|";
			for (int antBee = 0; antBee < 2; antBee++) {
				if (board[currCol][antBee].size() > specInsect) {
					cout << board[currCol][antBee][specInsect]->get_symbol() << board[currCol][antBee][specInsect]->get_shield();
				}
				else {
          cout << "  ";
				}

        //Spaces after printing the ant
				if (antBee == 0 && currCol != 9) {
					cout << " ";
				}
				else if (antBee == 0 && currCol == 9) {
					cout << "  ";
				}
			}
		}
    cout << "|" << endl;
	}
  cout << endl;
}

/******************************************************************************
 ** Function: most_insects
 ** Description: Calculates the most insects on one space
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
int Player::most_insects() {
  int biggest = 0;

  //Check what is the most insects on one space
  for (int currCol = 0; currCol < 10; currCol++) {
    for (int antBee = 0; antBee < 2; antBee++) {
      if (board[currCol][antBee].size() > biggest) {
        biggest = board[currCol][antBee].size();
      }
    }
  }

  return biggest;
}

/******************************************************************************
 ** Function: game_over
 ** Description: Checks if the game is over
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool Player::game_over() {
  //Check if the bees have reaches the left side of the board
  if (board[0][1].size() != 0) {
    cout << "THE BEES HAVE KILLED THE QUEEN! GAME OVER!" << endl;
    return true;
  }

  //Check if there are any bees alive
  for (int i = 0; i < 10; i++) {
    if (board[i][1].size() != 0 ) {
      return false;
    }
  }

  //If the previous return was not triggered, all the bees have been killed
  cout << "ALL BEES HAVE BEEN KILLED! YOU WIN! " << endl;
  return true;
}

/******************************************************************************
 ** Function: delete_vector
 ** Description: Deletes all insects on the board
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: All insects deleted
*****************************************************************************/
void Player::delete_vector() {
  //Delete all remaining insects
  for (int specInsect = 0; specInsect < most_insects(); specInsect++) {
		for (int currCol = 0; currCol < 10; currCol++) {
			for (int antBee = 0; antBee < 2; antBee++) {
				if (board[currCol][antBee].size() > specInsect) {
					delete board[currCol][antBee][specInsect];
				}
			}
		}
	}
}
