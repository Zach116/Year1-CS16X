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
#include "space.h"
#include "tools.h"

using namespace std;

//Constructor
BusinessComplex::BusinessComplex():Property() {
  name = "BusinessComplex";
  numSpaces = 0;
  numTenants = 0;
  spaces = NULL;
}

//Deconstructor
BusinessComplex::~BusinessComplex() {
  delete [] spaces;
}

//Copy Constructor:
BusinessComplex::BusinessComplex(const BusinessComplex& copy) {
	this->numSpaces = copy.numSpaces;
  this->numTenants = copy.numTenants;
  this->name = copy.name;
  this->propertyValue = copy.propertyValue;
  this->location = copy.location;
  this->mortgagePerMonth = copy.mortgagePerMonth;
  this->mortgageDuration = copy.mortgageDuration;
  this->propertyTaxPercent = copy.propertyTaxPercent;

	//Deep copy spaces
	if (this->numSpaces == 0) {
		this->spaces = NULL;
	}
	else {
		this->spaces = new space[this->numSpaces];
		for (int i = 0; i < this->numSpaces; i++) {
			this->spaces[i] = copy.spaces[i];
		}
	}
}

//Assignment Operator Overload
const BusinessComplex& BusinessComplex::operator=(const BusinessComplex& copy) {
  this->numSpaces = copy.numSpaces;
  this->numTenants = copy.numTenants;
  this->name = copy.name;
  this->propertyValue = copy.propertyValue;
  this->location = copy.location;
  this->mortgagePerMonth = copy.mortgagePerMonth;
  this->mortgageDuration = copy.mortgageDuration;
  this->propertyTaxPercent = copy.propertyTaxPercent;

	//Deep copy tenants
	if (this->spaces != NULL) {
		delete [] spaces;
	}
  if (this->numSpaces == 0) {
		this->spaces = NULL;
	}
	else {
		this->spaces = new space[this->numSpaces];
		for (int i = 0; i < this->numSpaces; i++) {
			this->spaces[i] = copy.spaces[i];
		}
	}
}

//Accessor
int BusinessComplex::get_numSpaces() {return numSpaces;}
void BusinessComplex::print_info() {
  cout << "Name: " << name << endl;
  cout << "Property Value: " << propertyValue << endl;
  cout << "Location: " << location << endl;
  cout << "Mortgage Payment Per Month: " << mortgagePerMonth << endl;
  cout << "Mortgage Duration: " << mortgageDuration << endl;
  cout << "Property Tax Percentage: " << propertyTaxPercent << endl;

  cout << "Number of Tenants: " << numTenants << endl;
  cout << "Number of Spaces: " << numSpaces << endl;
  for (int i = 0; i < numSpaces; i++) {
    cout << "Space " << i+1 << ":" << endl;
    cout << "Space Size: " << spaces[i].size << endl;
    cout << "Space Occupied: " << spaces[i].occupied << endl;
    cout << "Tenant Rent: " << spaces[i].currTenant.rent << endl;
    cout << "Tenant Budget: " << spaces[i].currTenant.budget << endl;
    cout << "Tenant Agreeability: " << spaces[i].currTenant.agreeability << endl;
    cout << endl;
  }
  cout << endl;
}
void BusinessComplex::view_info() {
  cout << "Property Value: " << propertyValue << endl;
  cout << "Location: " << location << endl;
  cout << "Mortgage Payment Per Month: " << mortgagePerMonth << endl;
  cout << "Mortgage Duration: " << mortgageDuration << endl;
  cout << "Property Tax Percentage: " << propertyTaxPercent << endl;

  cout << "Number of Tenants: " << numTenants << endl;
  cout << "Number of Spaces: " << numSpaces << endl;
  for (int i = 0; i < numSpaces; i++) {
    cout << "Space " << i+1 << ":" << endl;
    cout << "Space Size: " << spaces[i].size << endl;
    cout << "Space Occupied: " << spaces[i].occupied << endl;
    if (spaces[i].occupied == "Yes") {
      cout << "Tenant Rent: " << spaces[i].currTenant.rent << endl;
    }

    cout << endl;
  }
  cout << endl;
}
void BusinessComplex::print_buying_info() {
  cout << "Name: " << name << endl;
  cout << "Property Value: " << propertyValue << endl;
  cout << "Location: " << location << endl;
  cout << "Mortgage Payment Per Month: " << mortgagePerMonth << endl;
  cout << "Mortgage Duration: " << mortgageDuration << endl;

  cout << "Number of Tenants: " << numTenants << endl;
  cout << "Number of Spaces: " << numSpaces << endl;
}
int BusinessComplex::get_numTenants() {return numTenants;}

//Mutators
void BusinessComplex::set_rent(int spaceIndex, int newRent) {spaces[spaceIndex].currTenant.rent = newRent;}

/******************************************************************************
 ** Function: collect_rent
 ** Description: Collects rent from tenants
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: tenant may leave
*****************************************************************************/
int BusinessComplex::collect_rent() {
  int totalRevenue = 0;

  for (int i = 0; i < numSpaces; i++) {
    if (spaces[i].occupied == "Yes") {
      if (spaces[i].currTenant.rent < spaces[i].currTenant.budget) {
        totalRevenue += spaces[i].currTenant.rent;
        change_propertyValue(1.01);
      }
      else if (spaces[i].currTenant.agreeability > 1 && spaces[i].currTenant.rent > spaces[i].currTenant.budget) {
        remove_tenant(i);
      }
    }
  }

  return totalRevenue;
}

/******************************************************************************
 ** Function: removeTenant
 ** Description: Remove a tenant from the property
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: The object should have one less tenant
*****************************************************************************/
void BusinessComplex::remove_tenant(int tenantIndex) {
  this->numTenants--;

  spaces[tenantIndex].occupied = "No";
}

/******************************************************************************
 ** Function: randomize_info
 ** Description: Randomizes all the info in the current object
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void BusinessComplex::randomize_info() {
  int randNum;
  tenant newTenant;

  //Randomize the property value
  propertyValue = (rand() % 200001) + 400000;

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

  //Randomize amount of spaces
  numSpaces = (rand() % 5) + 1;
  numTenants = numSpaces;

  if (spaces != NULL) {
    delete [] spaces;
  }
  spaces = new space[numSpaces];
  //Randomize space info and tenant info for each space
  for (int i = 0; i < numSpaces; i++) {
    space newSpace;
    tenant newTenant;

    randNum = rand() % 3;
    if (randNum == 0) {
      newSpace.size = "S";
    }
    else if (randNum == 1) {
      newSpace.size = "M";
    }
    else if (randNum == 2) {
      newSpace.size = "L";
    }

    //randomize tenant info and assign
    newTenant.budget = (rand() % 8001) + 2000;
    newTenant.agreeability = (rand() % 5) + 1;
    newTenant.rent = 0;
    newSpace.currTenant = newTenant;

    newSpace.occupied = "Yes";

    spaces[i] = newSpace;
  }
}
