#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include <string>
#include "game.h"
#include "player.h"
#include "property.h"
#include "house.h"
#include "businessComplex.h"
#include "apartmentComplex.h"
#include "tools.h"

using namespace std;

//Constructor
Game::Game() {
  Player p1;

  housesToBuy = NULL;
  apartmentComplexesToBuy = NULL;
  businessComplexesToBuy = NULL;
  player = p1;
}

//Destructor
Game::~Game() {
  delete [] housesToBuy;
  housesToBuy = NULL;
  delete [] apartmentComplexesToBuy;
  apartmentComplexesToBuy = NULL;
  delete [] businessComplexesToBuy;
  businessComplexesToBuy = NULL;
}

//Accessors
House* Game::get_housesToBuy() {return housesToBuy;}
ApartmentComplex* Game::get_apartmentComplexesToBuy() {return apartmentComplexesToBuy;}
BusinessComplex* Game::get_businessComplexesToBuy() {return businessComplexesToBuy;}
Player Game::get_player() {return player;}

//Mutators
void Game::set_player(Player newPlayer) {player = newPlayer;}

void Game::collect_rent() {player.collect_rent();}
void Game::pay_debt_taxes(int turnNum) {player.pay_debt_taxes(turnNum);}

/******************************************************************************
 ** Function: set_up
 ** Description: Set up the properties to buy
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Game::set_up() {
  housesToBuy = new House[3];
  apartmentComplexesToBuy = new ApartmentComplex[3];
  businessComplexesToBuy = new BusinessComplex[3];

  //Fill the property arrays with three randoms of each property type
  for (int i = 0; i < 3; i++) {
    House newHouse;
    ApartmentComplex newApartmentComplex;
    BusinessComplex newBusinessComplex;

    newHouse.randomize_info();
    newApartmentComplex.randomize_info();
    newBusinessComplex.randomize_info();

    housesToBuy[i] = newHouse;
    apartmentComplexesToBuy[i] = newApartmentComplex;
    businessComplexesToBuy[i] = newBusinessComplex;
  }
}

/******************************************************************************
 ** Function: buy_property
 ** Description: Ask if the user wants to buy a property
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Game::buy_property() {
  string response;

  //Ask the user if they want to buy a property
  do {
    cout << "Would you like to look at the properties for sale (Y/N)? ";
    cin >> response;
    cout << endl;

    if (response != "Y" && response!= "N") {
      cout << "PLEASE ENTER Y OR N ONLY!" << endl;
      cout << endl;
    }
  } while(response != "Y" && response!= "N");

  //If the user wants to buy a property, print 3 random properties and ask which they want.
  if (response == "Y") {
    print_property_listings();
  }
}

/******************************************************************************
 ** Function: sell_property
 ** Description: asks if the user wants to sell a house
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Game::sell_property() {
  string response;

  //Ask the user if they want to sell a property
  do {
    cout << "Would you like to sell one of your properties? (Y/N)? ";
    cin >> response;
    cout << endl;

    if (response != "Y" && response!= "N") {
      cout << "PLEASE ENTER Y OR N ONLY!" << endl;
      cout << endl;
    }
  } while(response != "Y" && response!= "N");

  //If the user wants to sell a property, print their properties and ask which one they want to sell
  if (response == "Y") {
    player.sell_property();
  }
}

/******************************************************************************
 ** Function: adjust_rent
 ** Description: asks if the user wants to adjust rent
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Game::adjust_rent() {
  string response;

  //Ask the user if they want to adjust rent
  do {
    cout << "Would you like to adjust the rent of one of your properties? (Y/N)? ";
    cin >> response;
    cout << endl;

    if (response != "Y" && response!= "N") {
      cout << "PLEASE ENTER Y OR N ONLY!" << endl;
      cout << endl;
    }
  } while(response != "Y" && response!= "N");

  //If the user wants to sell a property, print their properties and ask which one they want to sell
  if (response == "Y") {
    player.adjust_rent();
  }
}

/******************************************************************************
 ** Function: random_event
 ** Description: Call a random event
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Certain properties propertyValue should be changed
*****************************************************************************/
void Game::random_event() {
  int randNum;
  string randLoc;

  randNum = rand() % 6;

  if (randNum == 0) {
    cout << "A hurricane has occured and properties in the SE have had a decrease in property value by 50 percent!" << endl;
    cout << endl;
    player.random_event("SE", 0.5);
  }
  else if (randNum == 1) {
    cout << "A tornado has occured and properties in the Midwest have had a decrease in property value by 30 percent!" << endl;
    cout << endl;
    player.random_event("Midwest", 0.70);
  }
  else if (randNum == 2) {
    cout << "An earthquake has occured and properties in the NW have had a decrease in property value by 10 percent!" << endl;
    cout << endl;
    player.random_event("NW", 0.90);
  }
  else if (randNum == 3) {
    cout << "A wildfire has occured and properties in the SW have had a decrease in property value by 25 percent!" << endl;
    cout << endl;
    player.random_event("SW", 0.75);
  }
  else if (randNum == 4) {
    cout << "The stock market has crashes and all properties have had a decrease in property value by 30 percent!" << endl;
    cout << endl;
    player.random_event(0.7);
  }
  else if (randNum == 5) {
    randNum = rand() % 5;
    if (randNum == 0) {
      randLoc = "SE";
    }
    else if (randNum == 1) {
      randLoc = "NE";
    }
    else if (randNum == 2) {
      randLoc = "Midwest";
    }
    else if (randNum == 3) {
      randLoc = "SW";
    }
    else if (randNum == 4) {
      randLoc = "NW";
    }

    cout << "A gentrification has occured and properties in the " << randLoc << " have had an increase in property value by 20 percent!" << endl;
    cout << endl;
    player.random_event(randLoc, 1.20);
  }
}

/******************************************************************************
 ** Function: print_property_listings
 ** Description: Prints three random properties up for sale and asks which the user wants to buy
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: The user may have one more owned property if they chose to buy one and there would also be a new property in the ones available to buy
*****************************************************************************/
void Game::print_property_listings() {
  int randNum1, randNum2, randNum3;
  string response, rent;

  randNum1 = rand() % 3;
  housesToBuy[randNum1].print_buying_info();
  cout << endl;
  randNum2 = rand() % 3;
  apartmentComplexesToBuy[randNum2].print_buying_info();
  cout << endl;
  randNum3 = rand() % 3;
  businessComplexesToBuy[randNum3].print_buying_info();
  cout << endl;

  //Ask which the user wants to buy
  do {
    cout << "Would you like to buy the house (H), the apartment complex (A), the business complex (B), or quit (Q)? ";
    cin >> response;
    cout << endl;

    if (response != "H" && response != "A" && response != "B" && response != "Q") {
      cout << "PLEASE ENTER H, A, B, or Q!" << endl;
      cout << endl;
    }
  } while (response != "H" && response != "A" && response != "B" && response != "Q");

  //Take the appropriate action of buying the property and then randomizing the property to "create" a new property in the list of available propertyies
  if (response == "H") {
    do {
      cout << "What do you want the rent to be for this house? ";
      cin >> rent;
      cout << endl;

      if (!is_int(rent) || get_int(rent) < 0) {
        cout << "PLEASE ENTER A NUMBER GREATER THAN 0!" << endl;
        cout << endl;
      }
    } while (!is_int(rent) || get_int(rent) < 0);
    housesToBuy[randNum1].set_rent(get_int(rent));

    player.buy_house(housesToBuy[randNum1]);
    housesToBuy[randNum1].randomize_info();
  }
  else if (response == "A") {
    do {
      cout << "What do you want the rent to be for this apartment complex? ";
      cin >> rent;
      cout << endl;

      if (!is_int(rent) || get_int(rent) < 0) {
        cout << "PLEASE ENTER A NUMBER GREATER THAN 0!" << endl;
        cout << endl;
      }
    } while (!is_int(rent) || get_int(rent) < 0);
    apartmentComplexesToBuy[randNum2].set_rent(get_int(rent));

    player.buy_apartmentComplex(apartmentComplexesToBuy[randNum2]);
    apartmentComplexesToBuy[randNum2].randomize_info();
  }
  else if (response == "B") {
    for (int i = 0; i < businessComplexesToBuy[randNum3].get_numSpaces(); i++) {
      do {
        cout << "What do you want the rent to be for this business complex for space " << i+1 << "? ";
        cin >> rent;
        cout << endl;

        if (!is_int(rent) || get_int(rent) < 0) {
          cout << "PLEASE ENTER A NUMBER GREATER THAN 0!" << endl;
          cout << endl;
        }
      } while (!is_int(rent) || get_int(rent) < 0);
      businessComplexesToBuy[randNum3].set_rent(i, get_int(rent));
    }

    player.buy_businessComplex(businessComplexesToBuy[randNum3]);
    businessComplexesToBuy[randNum3].randomize_info();
  }
}

/******************************************************************************
 ** Function: game_over
 ** Description: check if the game is over
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool Game::game_over() {
  if (player.get_bankAccount() < 1) {
    cout << "YOUR BANK ACCOUNT IS AT ZERO! YOU HAVE LOST! GAME OVER!" << endl;
    cout << endl;
    return true;
  }
  else if (player.get_bankAccount() > 999999) {
    cout << "YOU ARE A MILLIONAIRE! YOU HAVE WON THE GAME! GAME OVER" << endl;
    cout << endl;
    return true;
  }
  return false;
}
