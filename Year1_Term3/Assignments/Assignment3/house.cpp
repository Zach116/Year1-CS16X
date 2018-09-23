#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include <string>
#include <ctime>
#include "game.h"
#include "player.h"
#include "property.h"
#include "house.h"
#include "businessComplex.h"
#include "apartmentComplex.h"
#include "tenant.h"
#include "tools.h"

using namespace std;

//Constructor
House::House():Property() {
  tenant newTenant;

  name = "House";
  occupied = "No";
  newTenant.rent = 0;
  newTenant.budget = 0;

  currTenant = newTenant;
}

//Accessors
void House::print_info() {
  cout << "Name: " << name << endl;
  cout << "Property Value: " << propertyValue << endl;
  cout << "Location: " << location << endl;
  cout << "Mortgage Payment Per Month: " << mortgagePerMonth << endl;
  cout << "Mortgage Duration: " << mortgageDuration << endl;
  cout << "Property Tax Percentage: " << propertyTaxPercent << endl;

  cout << "Occupied: " << occupied << endl;
  cout << "Tenant Rent: " << currTenant.rent << endl;
  cout << "Tenant Budget: " << currTenant.budget << endl;
  cout << "Tenant Agreeability: " << currTenant.agreeability << endl;
  cout << endl;
}
void House::view_info() {
  cout << "Property Value: " << propertyValue << endl;
  cout << "Location: " << location << endl;
  cout << "Mortgage Payment Per Month: " << mortgagePerMonth << endl;
  cout << "Mortgage Duration: " << mortgageDuration << endl;
  cout << "Property Tax Percentage: " << propertyTaxPercent << endl;

  cout << "Occupied: " << occupied << endl;
  cout << "Tenant Rent: " << currTenant.rent << endl;
  cout << endl;
}
void House::print_buying_info() {
  cout << "Name: " << name << endl;
  cout << "Property Value: " << propertyValue << endl;
  cout << "Location: " << location << endl;
  cout << "Mortgage Payment Per Month: " << mortgagePerMonth << endl;
  cout << "Mortgage Duration: " << mortgageDuration << endl;
}
string House::get_occupied() {return occupied;}

//Mutators
void House::set_rent(int newRent) {currTenant.rent = newRent;}

/******************************************************************************
 ** Function: collect_rent
 ** Description: Collects rent from the tenant
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: occupied may become no
*****************************************************************************/
int House::collect_rent() {
  int totalRevenue = 0;

  //Only collect rent if the house is occupied
  if (occupied == "Yes") {
    if (currTenant.rent < currTenant.budget) {
      totalRevenue += currTenant.rent;
    }
    else if (currTenant.agreeability > 1 && currTenant.rent > currTenant.budget) {
      occupied = "No";
    }
  }

  return totalRevenue;
}

/******************************************************************************
 ** Function: randomize_info
 ** Description: Randomizes all the info in the current object
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void House::randomize_info() {
  int randNum;
  tenant newTenant;

  //Randomize the property value
  propertyValue = (rand() % 500001) + 100000;

  //Randomize location
  randNum = (rand() % 5);
  if (randNum == 0) {
    location = "SE";
  }
  else if (randNum == 1) {
    location = "NE";
  }
  else if (randNum == 2) {
    location = "Midwest";
  }
  else if (randNum == 3) {
    location = "SW";
  }
  else if (randNum == 4) {
    location = "NW";
  }

  //Randomize mortgagePerMonth
  mortgagePerMonth = (rand() % 5001);
  mortgageDuration = propertyValue/mortgagePerMonth;

  newTenant.budget = (rand() % 4501) + 500;
  newTenant.agreeability = (rand() % 5) + 1;
  newTenant.rent = 0;

  currTenant = newTenant;

  occupied = "Yes";
}
