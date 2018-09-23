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
#include "tenant.h"
#include "tools.h"

using namespace std;

//Constructor
ApartmentComplex::ApartmentComplex():Property() {
  name = "ApartmentComplex";
  numRooms = 0;
  numTenants = 0;
  tenants = NULL;
  currRent = 0;
}

//Deconstructor
ApartmentComplex::~ApartmentComplex() {
  delete [] tenants;
}

//Copy Constructor:
ApartmentComplex::ApartmentComplex(const ApartmentComplex& copy) {
	this->numRooms = copy.numRooms;
  this->numTenants = copy.numTenants;
  this->currRent = copy.currRent;
  this->name = copy.name;
  this->propertyValue = copy.propertyValue;
  this->location = copy.location;
  this->mortgagePerMonth = copy.mortgagePerMonth;
  this->mortgageDuration = copy.mortgageDuration;
  this->propertyTaxPercent = copy.propertyTaxPercent;

	//Deep copy tenants
	if (this->numTenants == 0) {
		this->tenants = NULL;
	}
	else {
		this->tenants = new tenant[this->numTenants];
		for (int i = 0; i < this->numTenants; i++) {
			this->tenants[i] = copy.tenants[i];
		}
	}
}

//Assignment Operator Overload
const ApartmentComplex& ApartmentComplex::operator=(const ApartmentComplex& copy) {
  this->numRooms = copy.numRooms;
  this->numTenants = copy.numTenants;
  this->currRent = copy.currRent;
  this->name = copy.name;
  this->propertyValue = copy.propertyValue;
  this->location = copy.location;
  this->mortgagePerMonth = copy.mortgagePerMonth;
  this->mortgageDuration = copy.mortgageDuration;
  this->propertyTaxPercent = copy.propertyTaxPercent;

	//Deep copy tenants
	if (this->tenants != NULL) {
		delete [] tenants;
	}
	if (this->numTenants == 0) {
		this->tenants = NULL;
	}
	else {
		this->tenants = new tenant[this->numTenants];
		for (int i = 0; i < this->numTenants; i++) {
			this->tenants[i] = copy.tenants[i];
		}
	}
}

//Accessor
void ApartmentComplex::print_info() {
  cout << "Name: " << name << endl;
  cout << "Property Value: " << propertyValue << endl;
  cout << "Location: " << location << endl;
  cout << "Mortgage Payment Per Month: " << mortgagePerMonth << endl;
  cout << "Mortgage Duration: " << mortgageDuration << endl;
  cout << "Property Tax Percentage: " << propertyTaxPercent << endl;

  cout << "Current Apartment Complex Rent: " << currRent << endl;
  cout << "Number of Rooms: " << numRooms << endl;
  cout << "Number of Tenants: " << numTenants << endl;

  for (int i = 0; i < numTenants; i++) {
    cout << "Tenant " << i+1 << ":" << endl;
    cout << "Tenant Rent: " << tenants[i].rent << endl;
    cout << "Tenant Budget: " << tenants[i].budget << endl;
    cout << "Tenant Agreeability: " << tenants[i].agreeability << endl;
    cout << endl;
  }
  cout << endl;
}
void ApartmentComplex::view_info() {
  cout << "Property Value: " << propertyValue << endl;
  cout << "Location: " << location << endl;
  cout << "Mortgage Payment Per Month: " << mortgagePerMonth << endl;
  cout << "Mortgage Duration: " << mortgageDuration << endl;
  cout << "Property Tax Percentage: " << propertyTaxPercent << endl;

  cout << "Current Apartment Complex Rent: " << currRent << endl;
  cout << "Number of Rooms: " << numRooms << endl;
  cout << "Number of Tenants: " << numTenants << endl;
  cout << endl;
}
void ApartmentComplex::print_buying_info() {
  cout << "Name: " << name << endl;
  cout << "Property Value: " << propertyValue << endl;
  cout << "Location: " << location << endl;
  cout << "Mortgage Payment Per Month: " << mortgagePerMonth << endl;
  cout << "Mortgage Duration: " << mortgageDuration << endl;

  cout << "Number of Rooms: " << numRooms << endl;
}
int ApartmentComplex::get_numTenants() {return numTenants;}

//Mutators
void ApartmentComplex::set_rent(int newRent) {
  this->currRent = newRent;
  for (int i = 0; i < numTenants; i++) {
    tenants[i].rent = newRent;
  }
}

/******************************************************************************
 ** Function: collect_rent
 ** Description: Collects rent from tenants
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: tenant may leave
*****************************************************************************/
int ApartmentComplex::collect_rent() {
  int totalRevenue = 0;

  for (int i = 0; i < numTenants; i++) {
    if (tenants[i].rent < tenants[i].budget) {
      totalRevenue += tenants[i].rent;
    }
    else if (tenants[i].agreeability > 1 && tenants[i].rent > tenants[i].budget) {
      remove_tenant(i);
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
void ApartmentComplex::remove_tenant(int tenantIndex) {
  int j = 0;
  tenant* temp;

  this->numTenants--;

  //Resize the tenants array
  temp = new tenant[this->numTenants];

  for (int i = 0; i < this->numTenants + 1; i++) {
    if (i != tenantIndex) {
      temp[j] = tenants[i];
      //j should only be incremented when tenants are added
      j++;
    }
  }

  delete [] tenants;
  this->tenants = new tenant[this->numTenants];

  for (int i = 0; i < this->numTenants; i++) {
    tenants[i] = temp[i];
  }

  delete [] temp;
}

/******************************************************************************
 ** Function: randomize_info
 ** Description: Randomizes all the info in the current object
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void ApartmentComplex::randomize_info() {
  int randNum;

  //Randomize the property value
  propertyValue = (rand() % 300001) + 300000;

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

  //Randomize amount of rooms
  numRooms = ((rand() % 10) + 1);
  numTenants = numRooms;

  if (tenants != NULL) {
    delete [] tenants;
  }
  tenants = new tenant[numTenants];
  //Randomize tenant info
  for (int i = 0; i < numTenants; i++) {
    tenant newTenant;

    newTenant.budget = (rand() % 4501) + 500;
    newTenant.agreeability = (rand() % 5) + 1;
    newTenant.rent = 0;
    tenants[i] = newTenant;
  }
}
