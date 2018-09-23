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
Bee::Bee():Insect() {
  symbol = "%";
  shield = 3;
}



/******************************************************************************
 ** Function: take_turn
 ** Description: Check if the bee can move, if it cannot, attack. If it is not a ninja in the way, it cannot move
 ** Parameters: vector<vector<vector<Insect*> > > &board, int currentSpace, int specificInsectIndex
 ** Pre-Conditions: None
 ** Post-Conditions: Bees may take damage
*****************************************************************************/
void Bee::take_turn(vector<vector<vector<Insect*> > > &board, int currentSpaceIndex, int specificInsectIndex) {
  //The bee can move if there are no ants on its space
  if (board[currentSpaceIndex][0].size() == 0) {
    move(board, currentSpaceIndex, specificInsectIndex);
  }
  //The bee can move if there is only a ninja on the space, but it takes one damage
  else if(board[currentSpaceIndex][0][0]->get_symbol() == "N") {
    move(board, currentSpaceIndex, specificInsectIndex);
    take_damage(1);
  }
  //If the bee could not move, there is an ant in the way and it attacks
  else {
    attack(board, currentSpaceIndex);
  }
}

/******************************************************************************
 ** Function: move
 ** Description: Move the bee by one space
 ** Parameters: vector<vector<vector<Insect*> > > &board, int currentSpace, int specificInsectIndex
 ** Pre-Conditions: None
 ** Post-Conditions: Bee moved by one space
*****************************************************************************/
void Bee::move(vector<vector<vector<Insect*> > > &board, int currentSpaceIndex, int specificInsectIndex) {
  board[currentSpaceIndex-1][1].push_back(this);
  board[currentSpaceIndex][1].erase(board[currentSpaceIndex][1].begin() + specificInsectIndex);
}

/******************************************************************************
 ** Function: attack
 ** Description: Attack the first ant on the space
 ** Parameters: vector<vector<vector<Insect*> > > &board, int currentSpaceIndex
 ** Pre-Conditions: None
 ** Post-Conditions: Ant damaged
*****************************************************************************/
void Bee::attack(vector<vector<vector<Insect*> > > &board, int currentSpaceIndex) {
  board[currentSpaceIndex][0][0]->take_damage(1);
}
