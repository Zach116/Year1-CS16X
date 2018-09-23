#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include <string>
#include "property.h"
#include "house.h"
#include "businessComplex.h"
#include "apartmentComplex.h"

using namespace std;

class Player {
  private:
    House* ownedHouses;
    int numHousesOwned;
    ApartmentComplex* ownedApartmentComplexes;
    int numApartmentComplexesOwned;
    BusinessComplex* ownedBusinessComplexes;
    int numBusinessComplexesOwned;
    int bankAccount;

  public:
    //Constructors
    Player();

    //Big 3
    //Deconstructor
    ~Player();

    //Copy Constructor:
    Player(const Player& copy);

    //Assignment Operator Overload
    const Player& operator=(const Player& copy);

    //Accessors
    House* get_ownedHouses();
    int get_numHousesOwned();
    ApartmentComplex* get_ownedApartmentComplexes();
    int get_numApartmentComplexesOwned();
    BusinessComplex* get_ownedBusinessComplexes();
    int get_numBusinessComplexesOwned();
    int get_bankAccount();

    //Mutators

    //Adds property to correct array and does other needed stuff
    void buy_house(House houseBought);
    void buy_apartmentComplex(ApartmentComplex apartmentComplexBought);
    void buy_businessComplex(BusinessComplex businessComplexBought);

    //Removes property from ownedProperties and adds gained money to bank account
    void sell_property();
    bool valid_sale(string response);
    void sell_house();
    void remove_house(int houseIndex);
    void sell_apartmentComplex();
    void remove_apartmentComplex(int apartmentComplexIndex);
    void sell_businessComplex();
    void remove_businessComplex(int businessComplexIndex);

    //First ask if they want to adjust a house, apartment, or business. Then ask which one. Then either ask for space number or new rent
    void adjust_rent();
    void adjust_house_rent();
    void adjust_apartmentComplex_rent();
    void adjust_businessComplex_rent();

    //Prints out all of the owned properties
    void print_properties_owned();
    void print_houses_owned();
    void print_apartmentComplexes_owned();
    void print_businessComplexes_owned();

    //Will call adjust_mortgageToBePaid after mortgagePerMonth for current property has been subtracted from bank account. Property taxes paid every 12 months
    void pay_debt_taxes(int turnNum);

    //Random events
    void random_event(string loc, float percentChange);
    void random_event(float percentChange);

    //Collect rent from all properties owned and add to bank account balance
    void collect_rent();

    void view_ownedProperties();
};

#endif
