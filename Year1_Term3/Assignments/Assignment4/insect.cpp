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
Insect::Insect() {
  symbol = "I";
  shield = 3;
}

//Accessors
string Insect::get_symbol() {return symbol;}
int Insect::get_shield() {return shield;}

//Mutators
void Insect::take_damage(int damage) {shield = shield - damage;}
void Insect::set_symbol(string symbol) {this->symbol = symbol;}
void Insect::set_shield(int shield) {this->shield = shield;}
