#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include <string>
#include "player.h"
#include "property.h"
#include "house.h"
#include "businessComplex.h"
#include "apartmentComplex.h"

using namespace std;

class Game {
  private:
    House* housesToBuy;
    ApartmentComplex* apartmentComplexesToBuy;
    BusinessComplex* businessComplexesToBuy;
    Player player;

  public:
    //Constructors
    Game();

    //Big 3
    //Destructor
    ~Game();

    //Accessors
    House* get_housesToBuy();
    ApartmentComplex* get_apartmentComplexesToBuy();
    BusinessComplex* get_businessComplexesToBuy();
    Player get_player();

    //Mutators
    void set_player(Player newPlayer);

    //This will create all the properties needed and assign the values for the game setup, will probably need more modulated functions
    void set_up();

    void collect_rent();
    void pay_debt_taxes(int turnNum);

    //Ask if the user wants to buy a property
    void buy_property();

    //Ask if the user wants to sell a property
    void sell_property();

    //Ask if the user wants to adjust rent
    void adjust_rent();

    //This will call one of the random event functions
    void random_event();

    void print_property_listings();

    bool game_over();
};

#endif
