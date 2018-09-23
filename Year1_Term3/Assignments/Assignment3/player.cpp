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
Player::Player() {
  ownedHouses = NULL;
  numHousesOwned = 0;
  ownedApartmentComplexes = NULL;
  numApartmentComplexesOwned = 0;
  ownedBusinessComplexes = NULL;
  numBusinessComplexesOwned = 0;
  bankAccount = 500000;
}

//Deconstructor
Player::~Player() {
  delete [] ownedHouses;
  ownedHouses = NULL;
  delete [] ownedApartmentComplexes;
  ownedApartmentComplexes = NULL;
  delete [] ownedBusinessComplexes;
  ownedBusinessComplexes = NULL;
}

//Copy Constructor:
Player::Player(const Player& copy) {
	this->numHousesOwned = copy.numHousesOwned;
  this->numApartmentComplexesOwned = copy.numApartmentComplexesOwned;
  this->numBusinessComplexesOwned = copy.numBusinessComplexesOwned;
  this->bankAccount = copy.bankAccount;

	//Deep copy
	if (this->numHousesOwned == 0) {
		this->ownedHouses = NULL;
	}
	else {
		this->ownedHouses = new House[this->numHousesOwned];
		for (int i = 0; i < this->numHousesOwned; i++) {
			this->ownedHouses[i] = copy.ownedHouses[i];
		}
	}

  if (this->numApartmentComplexesOwned == 0) {
		this->ownedApartmentComplexes = NULL;
	}
	else {
		this->ownedApartmentComplexes = new ApartmentComplex[this->numApartmentComplexesOwned];
		for (int i = 0; i < this->numApartmentComplexesOwned; i++) {
			this->ownedApartmentComplexes[i] = copy.ownedApartmentComplexes[i];
		}
	}

  if (this->numBusinessComplexesOwned == 0) {
		this->ownedBusinessComplexes = NULL;
	}
	else {
		this->ownedBusinessComplexes = new BusinessComplex[this->numBusinessComplexesOwned];
		for (int i = 0; i < this->numBusinessComplexesOwned; i++) {
			this->ownedBusinessComplexes[i] = copy.ownedBusinessComplexes[i];
		}
	}
}

//Assignment Operator Overload
const Player& Player::operator=(const Player& copy) {
  this->numHousesOwned = copy.numHousesOwned;
  this->numApartmentComplexesOwned = copy.numApartmentComplexesOwned;
  this->numBusinessComplexesOwned = copy.numBusinessComplexesOwned;
  this->bankAccount = copy.bankAccount;

	//Deep copy
	if (this->ownedHouses != NULL) {
		delete [] ownedHouses;
	}
  if (this->numHousesOwned == 0) {
		this->ownedHouses = NULL;
	}
	else {
		this->ownedHouses = new House[this->numHousesOwned];
		for (int i = 0; i < this->numHousesOwned; i++) {
			this->ownedHouses[i] = copy.ownedHouses[i];
		}
	}

  if (this->ownedApartmentComplexes != NULL) {
		delete [] ownedApartmentComplexes;
	}
  if (this->numApartmentComplexesOwned == 0) {
		this->ownedApartmentComplexes = NULL;
	}
	else {
		this->ownedApartmentComplexes = new ApartmentComplex[this->numApartmentComplexesOwned];
		for (int i = 0; i < this->numApartmentComplexesOwned; i++) {
			this->ownedApartmentComplexes[i] = copy.ownedApartmentComplexes[i];
		}
	}

  if (this->ownedBusinessComplexes != NULL) {
		delete [] ownedBusinessComplexes;
	}
  if (this->numBusinessComplexesOwned == 0) {
		this->ownedBusinessComplexes = NULL;
	}
	else {
		this->ownedBusinessComplexes = new BusinessComplex[this->numBusinessComplexesOwned];
		for (int i = 0; i < this->numBusinessComplexesOwned; i++) {
			this->ownedBusinessComplexes[i] = copy.ownedBusinessComplexes[i];
		}
	}
}

//Accessors
House* Player::get_ownedHouses() {return ownedHouses;}
int Player::get_numHousesOwned() {return numHousesOwned;}
ApartmentComplex* Player::get_ownedApartmentComplexes() {return ownedApartmentComplexes;}
int Player::get_numApartmentComplexesOwned() {return numApartmentComplexesOwned;}
BusinessComplex* Player::get_ownedBusinessComplexes() {return ownedBusinessComplexes;}
int Player::get_numBusinessComplexesOwned() {return numBusinessComplexesOwned;}
int Player::get_bankAccount() {return bankAccount;}
void Player::view_ownedProperties() {
  cout << "PROPERTIES OWNED:" << endl;
  cout << "Num Houses owned: " << get_numHousesOwned() << endl;
  for (int i = 0; i < get_numHousesOwned(); i++) {
    cout << "House " << i+1 << ":" << endl;
    get_ownedHouses()[i].view_info();
  }
  if (get_numHousesOwned() == 0) {
    cout << endl;
  }

  cout << "Num Apartments owned: " << get_numApartmentComplexesOwned() << endl;
  for (int i = 0; i < get_numApartmentComplexesOwned(); i++) {
    cout << "Apartment Complex " << i+1 << ":" << endl;
    get_ownedApartmentComplexes()[i].view_info();
  }
  if (get_numApartmentComplexesOwned() == 0) {
    cout << endl;
  }

  cout << "Num Businesses owned: " << get_numBusinessComplexesOwned() << endl;
  for (int i=0; i < get_numBusinessComplexesOwned(); i++) {
    cout << "Business Complex " << i+1 << ":" << endl;
    get_ownedBusinessComplexes()[i].view_info();
  }
  if (get_numBusinessComplexesOwned() == 0) {
    cout << endl;
  }
}

/******************************************************************************
 ** Function: buy_house
 ** Description: Adds the house to the ownedHouses array and up the number of houses owned
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: The array should be one bigger with a new house
*****************************************************************************/
void Player::buy_house(House houseBought) {
  House* temp;

	this->numHousesOwned++;

	//Resize the house array
	temp = new House[this->numHousesOwned];

  //Copy everything existing into the temp array
  for (int i = 0; i < this->numHousesOwned - 1; i++) {
    temp[i] = ownedHouses[i];
  }

  //Delete the old array if it had memory
  if (ownedHouses != NULL) {
    delete [] ownedHouses;
  }
  //Make the array the correct size
	this->ownedHouses = new House[this->numHousesOwned];

  //Copy everything back over
	for (int i = 0; i < this->numHousesOwned; i++) {
		ownedHouses[i] = temp[i];
	}

	delete [] temp;

	//Add the new house
	ownedHouses[this->numHousesOwned - 1] = houseBought;
}

/******************************************************************************
 ** Function: buy_apartmentComplex
 ** Description: Adds the apartmentComplex to the ownedApartmentComplexes array and up the number of apartmentComplexes owned
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: The array should be one bigger with a new apartmentComplex
*****************************************************************************/
void Player::buy_apartmentComplex(ApartmentComplex apartmentComplexBought) {
  ApartmentComplex* temp;

	this->numApartmentComplexesOwned++;

	//Resize the ApartmentComplex array
	temp = new ApartmentComplex[this->numApartmentComplexesOwned];

  //Copy everything existing into the temp array
  for (int i = 0; i < this->numApartmentComplexesOwned - 1; i++) {
    temp[i] = ownedApartmentComplexes[i];
  }

  //Delete the old array if it had memory
  if (ownedApartmentComplexes != NULL) {
    delete [] ownedApartmentComplexes;
  }
  //Make the array the correct size
	this->ownedApartmentComplexes = new ApartmentComplex[this->numApartmentComplexesOwned];

  //Copy everything back over
	for (int i = 0; i < this->numApartmentComplexesOwned; i++) {
		ownedApartmentComplexes[i] = temp[i];
	}

	delete [] temp;

	//Add the new apartmentComplex
	ownedApartmentComplexes[this->numApartmentComplexesOwned - 1] = apartmentComplexBought;

}

/******************************************************************************
 ** Function: buy_businessComplex
 ** Description: Adds the businessComplex to the ownedBusinessComplexes array and up the number of businessComplexes owned
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: The array should be one bigger with a new businessComplex
*****************************************************************************/
void Player::buy_businessComplex(BusinessComplex businessComplexBought) {
  BusinessComplex* temp;

	this->numBusinessComplexesOwned++;

	//Resize the BusinessComplex array
	temp = new BusinessComplex[this->numBusinessComplexesOwned];

  //Copy everything existing into the temp array
  for (int i = 0; i < this->numBusinessComplexesOwned - 1; i++) {
    temp[i] = ownedBusinessComplexes[i];
  }

  //Delete the old array if it had memory
  if (ownedBusinessComplexes != NULL) {
    delete [] ownedBusinessComplexes;
  }
  //Make the array the correct size
	this->ownedBusinessComplexes = new BusinessComplex[this->numBusinessComplexesOwned];

  //Copy everything back over
	for (int i = 0; i < this->numBusinessComplexesOwned; i++) {
		ownedBusinessComplexes[i] = temp[i];
	}

	delete [] temp;

	//Add the new businessComplex
	ownedBusinessComplexes[this->numBusinessComplexesOwned - 1] = businessComplexBought;
}

/******************************************************************************
 ** Function: sell_property
 ** Description: asks what type of property to sell
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Player::sell_property() {
  view_ownedProperties();
  string response;

  do {
    cout << "Would you like to sell a House (H), an Apartment Complex (A), a Business Complex (B), or Quit (Q)? ";
    cin >> response;
    cout << endl;
    if (response != "H" && response != "A" && response != "B" && response != "Q") {
      cout << "PLEASE ENTER H, A, B, or Q!" << endl;
      cout << endl;
    }
  } while ((response != "H" && response != "A" && response != "B" && response != "Q") || (!valid_sale(response)));

  if (response == "H") {
    sell_house();
  }
  else if (response == "A") {
    sell_apartmentComplex();
  }
  else if (response == "B") {
    sell_businessComplex();
  }
}

/******************************************************************************
 ** Function: valid_sale
 ** Description: Make sure the user owns one of the things they want to sell
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool Player::valid_sale(string response) {
  if (response == "H" && numHousesOwned == 0 ) {
    cout << "YOU DO NOT OWN ANY HOUSES!" << endl;
    cout << endl;
    return false;
  }
  else if (response == "A" && numApartmentComplexesOwned == 0) {
    cout << "YOU DO NOT OWN ANY APARTMENT COMPLEXES!" << endl;
    cout << endl;
    return false;
  }
  else if (response == "B" && numBusinessComplexesOwned == 0) {
    cout << "YOU DO NOT OWN ANY BUSINESS COMPLEXES!" << endl;
    cout << endl;
    return false;
  }

  return true;
}

/******************************************************************************
 ** Function: sell_house
 ** Description: Ask for number and price and see what the selling price is
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Player::sell_house() {
  string response, price;
  int randNum;

  do {
    cout << "Which house number would you like to sell? (Can quit with Q if cannot sell any) ";
    cin >> response;
    cout << endl;

    //Quit if the user wants to
    if (response == "Q") {
      return;
    }

    if (!is_int(response) || get_int(response) < 1 || get_int(response) > numHousesOwned || ownedHouses[get_int(response)-1].get_occupied() == "Yes") {
      cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND " << numHousesOwned << " AND A PROPERTY THAT HAS NO TENANTS!" << endl;
      cout << endl;
    }
  } while (!is_int(response) || get_int(response) < 1 || get_int(response) > numHousesOwned || ownedHouses[get_int(response)-1].get_occupied() == "Yes");

  do {
    cout << "How much would you like to try to sell the property for? ";
    cin >> price;
    cout << endl;

    if (!is_int(price) || get_int(price) < 1) {
      cout << "ENTER A NUMBER BIGGER THAN 0!" << endl;
      cout << endl;
    }
  } while (!is_int(price) || get_int(price) < 1);

  randNum = rand() % 3;

  if (randNum == 0) {
    cout << "You got your asking price!" << endl;
    cout << endl;
    bankAccount += get_int(price);
    cout << "Your bank account is now " << bankAccount << endl;
    cout << endl;
  }
  else if (randNum == 1) {
    cout << "The property sold for its property value" << endl;
    cout << endl;
    bankAccount += ownedHouses[get_int(response)-1].get_propertyValue();
    cout << "Your bank account is now " << bankAccount << endl;
    cout << endl;
  }
  else if (randNum == 2) {
    cout << "The property sold for 10 percent less than its property value. Better luck next time." << endl;
    cout << endl;
    ownedHouses[get_int(response)-1].change_propertyValue(0.9);
    bankAccount += ownedHouses[get_int(response)-1].get_propertyValue();
    cout << "Your bank account is now " << bankAccount << endl;
    cout << endl;
  }

  remove_house((get_int(response)-1));
}

/******************************************************************************
 ** Function: remove_house
 ** Description: removes house from array
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: one less house in array
*****************************************************************************/
void Player::remove_house(int houseIndex) {
  //Go through the process or removing the property
  int j = 0;
  House* temp;

  this->numHousesOwned--;

  //Resize the array
  temp = new House[this->numHousesOwned];

  for (int i = 0; i < this->numHousesOwned + 1; i++) {
    if (i != houseIndex) {
      temp[j] = ownedHouses[i];
      //j should only be incremented when elements are added
      j++;
    }
  }

  delete [] ownedHouses;
  this->ownedHouses = new House[this->numHousesOwned];

  for (int i = 0; i < this->numHousesOwned; i++) {
    ownedHouses[i] = temp[i];
  }

  delete [] temp;
}

/******************************************************************************
 ** Function: sell_apartmentComplex
 ** Description: Ask for number and price and see what the selling price is
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Bank account will be bigger
*****************************************************************************/
void Player::sell_apartmentComplex() {
  string response, price;
  int randNum;

  do {
    cout << "Which apartment complex number would you like to sell? (Can quit with Q if cannot sell any) ";
    cin >> response;
    cout << endl;

    if (response == "Q") {
      return;
    }

    if (!is_int(response) || get_int(response) < 1 || get_int(response) > numApartmentComplexesOwned || ownedApartmentComplexes[get_int(response)-1].get_numTenants() != 0) {
      cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND " << numApartmentComplexesOwned << " AND A PROPERTY THAT HAS NO TENANTS!" << endl;
      cout << endl;
    }
  } while (!is_int(response) || get_int(response) < 1 || get_int(response) > numApartmentComplexesOwned || ownedApartmentComplexes[get_int(response)-1].get_numTenants() != 0);

  do {
    cout << "How much would you like to try to sell the property for? ";
    cin >> price;
    cout << endl;

    if (!is_int(price) || get_int(price) < 1) {
      cout << "ENTER A NUMBER BIGGER THAN 0!" << endl;
      cout << endl;
    }
  } while (!is_int(price) || get_int(price) < 1);

  randNum = rand() % 3;

  if (randNum == 0) {
    cout << "You got your asking price!" << endl;
    cout << endl;
    bankAccount += get_int(price);
    cout << "Your bank account is now " << bankAccount << endl;
    cout << endl;
  }
  else if (randNum == 1) {
    cout << "The property sold for its property value" << endl;
    cout << endl;
    bankAccount += ownedApartmentComplexes[get_int(response)-1].get_propertyValue();
    cout << "Your bank account is now " << bankAccount << endl;
    cout << endl;
  }
  else if (randNum == 2) {
    cout << "The property sold for 10 percent less than its property value. Better luck next time." << endl;
    cout << endl;
    ownedApartmentComplexes[get_int(response)-1].change_propertyValue(0.9);
    bankAccount += ownedApartmentComplexes[get_int(response)-1].get_propertyValue();
    cout << "Your bank account is now " << bankAccount << endl;
    cout << endl;
  }

  remove_apartmentComplex((get_int(response)-1));
}

/******************************************************************************
 ** Function: remove_apartmentComplex
 ** Description: removes apartmentComplex from array
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: one less apartmentComplex in array
*****************************************************************************/
void Player::remove_apartmentComplex(int apartmentComplexIndex) {
  //Go through the process or removing the property
  int j = 0;
  ApartmentComplex* temp;

  this->numApartmentComplexesOwned--;

  //Resize the array
  temp = new ApartmentComplex[this->numApartmentComplexesOwned];

  for (int i = 0; i < this->numApartmentComplexesOwned + 1; i++) {
    if (i != apartmentComplexIndex) {
      temp[j] = ownedApartmentComplexes[i];
      //j should only be incremented when elements are added
      j++;
    }
  }

  delete [] ownedApartmentComplexes;
  this->ownedApartmentComplexes = new ApartmentComplex[this->numApartmentComplexesOwned];

  for (int i = 0; i < this->numApartmentComplexesOwned; i++) {
    ownedApartmentComplexes[i] = temp[i];
  }

  delete [] temp;
}

/******************************************************************************
 ** Function: sell_businessComplex
 ** Description: Ask for number and price and see what the selling price is
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Bank account will be bigger
*****************************************************************************/
void Player::sell_businessComplex() {
  string response, price;
  int randNum;

  do {
    cout << "Which business complex number would you like to sell? (Can quit with Q if cannot sell any) ";
    cin >> response;
    cout << endl;

    if (response == "Q") {
      return;
    }

    if (!is_int(response) || get_int(response) < 1 || get_int(response) > numBusinessComplexesOwned || ownedBusinessComplexes[get_int(response)-1].get_numTenants() != 0) {
      cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND " << numBusinessComplexesOwned << " AND A PROPERTY THAT HAS NO TENANTS!" << endl;
      cout << endl;
    }
  } while (!is_int(response) || get_int(response) < 1 || get_int(response) > numBusinessComplexesOwned || ownedBusinessComplexes[get_int(response)-1].get_numTenants() != 0);

  do {
    cout << "How much would you like to try to sell the property for? ";
    cin >> price;
    cout << endl;

    if (!is_int(price) || get_int(price) < 1) {
      cout << "ENTER A NUMBER BIGGER THAN 0!" << endl;
      cout << endl;
    }
  } while (!is_int(price) || get_int(price) < 1);

  randNum = rand() % 3;

  if (randNum == 0) {
    cout << "You got your asking price!" << endl;
    cout << endl;
    bankAccount += get_int(price);
    cout << "Your bank account is now " << bankAccount << endl;
    cout << endl;
  }
  else if (randNum == 1) {
    cout << "The property sold for its property value" << endl;
    cout << endl;
    bankAccount += ownedBusinessComplexes[get_int(response)-1].get_propertyValue();
    cout << "Your bank account is now " << bankAccount << endl;
    cout << endl;
  }
  else if (randNum == 2) {
    cout << "The property sold for 10 percent less than its property value. Better luck next time." << endl;
    cout << endl;
    ownedBusinessComplexes[get_int(response)-1].change_propertyValue(0.9);
    bankAccount += ownedBusinessComplexes[get_int(response)-1].get_propertyValue();
    cout << "Your bank account is now " << bankAccount << endl;
    cout << endl;
  }

  remove_businessComplex((get_int(response)-1));
}

/******************************************************************************
 ** Function: remove_businessComplex
 ** Description: removes businessComplex from array
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: one less businessComplex in array
*****************************************************************************/
void Player::remove_businessComplex(int businessComplexIndex) {
  //Go through the process or removing the property
  int j = 0;
  BusinessComplex* temp;

  this->numBusinessComplexesOwned--;

  //Resize the array
  temp = new BusinessComplex[this->numBusinessComplexesOwned];

  for (int i = 0; i < this->numBusinessComplexesOwned + 1; i++) {
    if (i != businessComplexIndex) {
      temp[j] = ownedBusinessComplexes[i];
      //j should only be incremented when elements are added
      j++;
    }
  }

  delete [] ownedBusinessComplexes;
  this->ownedBusinessComplexes = new BusinessComplex[this->numBusinessComplexesOwned];

  for (int i = 0; i < this->numBusinessComplexesOwned; i++) {
    ownedBusinessComplexes[i] = temp[i];
  }

  delete [] temp;
}

/******************************************************************************
 ** Function: adjust_rent
 ** Description: asks what property the user wants to adjust rent on
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Player::adjust_rent() {
  view_ownedProperties();
  string response;

  do {
    cout << "Would you like to adjust a House (H), an Apartment Complex (A), a Business Complex (B), or Quit (Q)? ";
    cin >> response;
    cout << endl;
    if (response != "H" && response != "A" && response != "B" && response != "Q") {
      cout << "PLEASE ENTER H, A, B, or Q!" << endl;
      cout << endl;
    }
  } while ((response != "H" && response != "A" && response != "B" && response != "Q") || (!valid_sale(response)));

  if (response == "H") {
    adjust_house_rent();
  }
  else if (response == "A") {
    adjust_apartmentComplex_rent();
  }
  else if (response == "B") {
    adjust_businessComplex_rent();
  }
}

/******************************************************************************
 ** Function: adjust_house_rent
 ** Description: asks what the user wants the rent to be
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Player::adjust_house_rent() {
  string response, newRent;

  do {
    cout << "Which house number would you like to adjust the rent on? (Can quit with Q) ";
    cin >> response;
    cout << endl;

    //Quit if the user wants to
    if (response == "Q") {
      return;
    }

    if (!is_int(response) || get_int(response) < 1 || get_int(response) > numHousesOwned) {
      cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND " << numHousesOwned << endl;
      cout << endl;
    }
  } while (!is_int(response) || get_int(response) < 1 || get_int(response) > numHousesOwned);

  do {
    cout << "What would you like the rent to be? ";
    cin >> newRent;
    cout << endl;

    if (!is_int(newRent) || get_int(newRent) < 1) {
      cout << "ENTER A NUMBER BIGGER THAN 0!" << endl;
      cout << endl;
    }
  } while (!is_int(newRent) || get_int(newRent) < 1);

  ownedHouses[get_int(response)-1].set_rent(get_int(newRent));
}

/******************************************************************************
 ** Function: adjust_apartmentComplex_rent
 ** Description: asks what the user wants the rent to be
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Player::adjust_apartmentComplex_rent() {
  string response, newRent;

  do {
    cout << "Which apartment complex number would you like to adjust the rent on? (Can quit with Q) ";
    cin >> response;
    cout << endl;

    //Quit if the user wants to
    if (response == "Q") {
      return;
    }

    if (!is_int(response) || get_int(response) < 1 || get_int(response) > numApartmentComplexesOwned) {
      cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND " << numApartmentComplexesOwned << endl;
      cout << endl;
    }
  } while (!is_int(response) || get_int(response) < 1 || get_int(response) > numApartmentComplexesOwned);

  do {
    cout << "What would you like the rent to be? ";
    cin >> newRent;
    cout << endl;

    if (!is_int(newRent) || get_int(newRent) < 1) {
      cout << "ENTER A NUMBER BIGGER THAN 0!" << endl;
      cout << endl;
    }
  } while (!is_int(newRent) || get_int(newRent) < 1);

  ownedApartmentComplexes[get_int(response)-1].set_rent(get_int(newRent));
}

/******************************************************************************
 ** Function: adjust_businessComplex_rent
 ** Description: asks what the user wants the rent to be
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void Player::adjust_businessComplex_rent() {
  string response, newRent, spaceNum;

  //Choose business complex
  do {
    cout << "Which business complex number would you like to adjust the rent on? (Can quit with Q) ";
    cin >> response;
    cout << endl;

    //Quit if the user wants to
    if (response == "Q") {
      return;
    }

    if (!is_int(response) || get_int(response) < 1 || get_int(response) > numBusinessComplexesOwned) {
      cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND " << numBusinessComplexesOwned << endl;
      cout << endl;
    }
  } while (!is_int(response) || get_int(response) < 1 || get_int(response) > numBusinessComplexesOwned);

  //Choose the specific space
  do {
    cout << "Which space in the business complex do you want to change the rent on? (Can quit with Q) ";
    cin >> spaceNum;
    cout << endl;

    //Quit if the user wants to
    if (response == "Q") {
      return;
    }

    if (!is_int(spaceNum) || get_int(spaceNum) < 1 || get_int(spaceNum) > ownedBusinessComplexes[get_int(response)-1].get_numSpaces()) {
      cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND " << ownedBusinessComplexes[get_int(response)-1].get_numSpaces() << endl;
      cout << endl;
    }
  } while (!is_int(spaceNum) || get_int(spaceNum) < 1 || get_int(spaceNum) > ownedBusinessComplexes[get_int(response)-1].get_numSpaces());

  //Choose new rent
  do {
    cout << "What would you like the rent to be in this space? ";
    cin >> newRent;
    cout << endl;

    if (!is_int(newRent) || get_int(newRent) < 1) {
      cout << "ENTER A NUMBER BIGGER THAN 0!" << endl;
      cout << endl;
    }
  } while (!is_int(newRent) || get_int(newRent) < 1);

  ownedBusinessComplexes[get_int(response)-1].set_rent((get_int(spaceNum)-1), get_int(newRent));
}

/******************************************************************************
 ** Function: collect_rent
 ** Description: collects the rent from all owned properties and adds to bank account
 ** Pre-Conditions: None
 ** Post-Conditions: Bank account may be changed
*****************************************************************************/
void Player::collect_rent() {
  int totalRevenue = 0;

  //Collect rent from all properties owned and add to totalRevenue
  for (int i = 0; i < numHousesOwned; i++) {
    totalRevenue += ownedHouses[i].collect_rent();
  }
  for (int i = 0; i < numApartmentComplexesOwned; i++) {
    totalRevenue += ownedApartmentComplexes[i].collect_rent();
  }
  for (int i = 0; i < numBusinessComplexesOwned; i++) {
    totalRevenue += ownedBusinessComplexes[i].collect_rent();
  }

  cout << "Your total revenue collected from this round is: " << totalRevenue << endl;
  cout << endl;

  bankAccount += totalRevenue;
  cout << "Your new bank account balance is: " << bankAccount << endl;
  cout << endl;
}

/******************************************************************************
 ** Function: pay_debt_taxes
 ** Description: Pays all mortgage and tax costs
 ** Pre-Conditions: None
 ** Post-Conditions: Bank account may be changed
*****************************************************************************/
void Player::pay_debt_taxes(int turnNum) {
  int totalCost;

  //Collect mortgage costs
  for (int i = 0; i < numHousesOwned; i++) {
    if (ownedHouses[i].get_mortgageDuration() != 0) {
      totalCost += ownedHouses[i].get_mortgagePerMonth();
      ownedHouses[i].decrease_mortgageDuration();
    }
  }
  for (int i = 0; i < numApartmentComplexesOwned; i++) {
    if (ownedApartmentComplexes[i].get_mortgageDuration() != 0) {
      totalCost += ownedApartmentComplexes[i].get_mortgagePerMonth();
      ownedApartmentComplexes[i].decrease_mortgageDuration();
    }
  }
  for (int i = 0; i < numBusinessComplexesOwned; i++) {
    if (ownedBusinessComplexes[i].get_mortgageDuration() != 0) {
      totalCost += ownedBusinessComplexes[i].get_mortgagePerMonth();
      ownedBusinessComplexes[i].decrease_mortgageDuration();
    }
  }

  //Collect tax cost every twelve rounds
  if (turnNum % 12 == 0) {
    for (int i = 0; i < numHousesOwned; i++) {
      totalCost += ownedHouses[i].calc_tax_amount();
    }
    for (int i = 0; i < numApartmentComplexesOwned; i++) {
      totalCost += ownedApartmentComplexes[i].calc_tax_amount();

    }
    for (int i = 0; i < numBusinessComplexesOwned; i++) {
      totalCost += ownedBusinessComplexes[i].calc_tax_amount();
    }
  }

  cout << "Your total mortgage and tax costs collected from this round is: " << totalCost << endl;
  cout << endl;

  bankAccount -= totalCost;
  cout << "Your new bank account balance is: " << bankAccount << endl;
  cout << endl;
}

/******************************************************************************
 ** Function: random_event
 ** Description: Changes property value by a certain percent based on location
 ** Pre-Conditions: None
 ** Post-Conditions: Property value on specific properties changed
*****************************************************************************/
void Player::random_event(string loc, float percentChange) {
  for (int i = 0; i < numHousesOwned; i++) {
    if (ownedHouses[i].get_location() == loc) {
      ownedHouses[i].change_propertyValue(percentChange);
    }
  }
  for (int i = 0; i < numApartmentComplexesOwned; i++) {
    if (ownedApartmentComplexes[i].get_location() == loc) {
      ownedApartmentComplexes[i].change_propertyValue(percentChange);
    }
  }
  for (int i = 0; i < numBusinessComplexesOwned; i++) {
    if (ownedBusinessComplexes[i].get_location() == loc) {
      ownedBusinessComplexes[i].change_propertyValue(percentChange);
    }
  }
}
void Player::random_event(float percentChange) {
  for (int i = 0; i < numHousesOwned; i++) {
    ownedHouses[i].change_propertyValue(percentChange);
  }
  for (int i = 0; i < numApartmentComplexesOwned; i++) {
    ownedApartmentComplexes[i].change_propertyValue(percentChange);
  }
  for (int i = 0; i < numBusinessComplexesOwned; i++) {
    ownedBusinessComplexes[i].change_propertyValue(percentChange);
  }
}
