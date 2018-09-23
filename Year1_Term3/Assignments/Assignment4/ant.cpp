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
Ant::Ant():Insect() {
  foodCost = 0;
}

//Non-Default Constructor
Ant::Ant(string symbol, int foodCost, int shield) {
  this->symbol = symbol;
  this->foodCost = foodCost;
  this->shield = shield;
}

//Accessors
int Ant::get_foodCost() {return foodCost;}

//Mutators
void Ant::set_foodCost(int foodCost) {this->foodCost = foodCost;}

/******************************************************************************
 ** Function: take_turn
 ** Description: Will attack if the ant is a thrower type, otherwise nothing will happen
 ** Parameters: vector<vector<vector<Insect*> > > &board, int currentSpace
 ** Pre-Conditions: None
 ** Post-Conditions: Bees may take damage
*****************************************************************************/
void Ant::take_turn(vector<vector<vector<Insect*> > > &board, int currentSpace, int specificInsectIndex) {
  //Only do something if the ant is a thrower
  if (symbol == "T" && board[currentSpace][1].size() != 0) {
    board[currentSpace][1][0]->take_damage(1);
  }
  else if (symbol == "L") {
     //Attack the bees on the first square with bees at least four spaces away
     for (int i = 4; i < 10 - currentSpace; i++) {
       //Attack bees if found and stop looking
       if (board[currentSpace + i][1].size() != 0) {
         //Attack all bees on the square
         for (int j = 0; j < board[currentSpace + i][1].size(); j++) {
           board[currentSpace + i][1][j]->take_damage(1);
         }
         break;
       }
     }
  }
  else if (symbol == "S") {
    int squaresChecked = 0;
    //Attack the bees on the first square with bees at most two spaces away
    for (int i = 0; i < 10 - currentSpace; i++) {
      //Attack bees if found and stop looking
      if (board[currentSpace + i][1].size() != 0) {
        //Attack all bees on the square
        for (int j = 0; j < board[currentSpace + i][1].size(); j++) {
          board[currentSpace + i][1][j]->take_damage(1);
        }
        break;
      }

      //Don't look more than two squares away from the attacking ant
      if (squaresChecked == 2) {
        break;
      }

      squaresChecked++;
    }
  }
}
