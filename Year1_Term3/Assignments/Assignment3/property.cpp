#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include <string>
#include "game.h"
#include "player.h"
#include "property.h"
#include "tools.h"

using namespace std;

//Constructor
Property::Property() {
  name = "Default";
  propertyValue = 0;
  location = "Default";
  mortgagePerMonth = 0;
  mortgageDuration = 0;
  propertyTaxPercent = 0.015;
}

//Accessors
int Property::get_propertyValue() {return propertyValue;}
int Property::get_mortgagePerMonth() {return mortgagePerMonth;}
int Property::get_mortgageDuration() {return mortgageDuration;}
string Property::get_name() {return name;}
string Property::get_location() {return location;}
int Property::calc_tax_amount() {return (propertyValue * 0.015);}
void Property::set_propertyValue(int num) {propertyValue = num;}

//Mutators
void Property::change_propertyValue(float percentChange) {propertyValue = propertyValue * percentChange;}
void Property::decrease_mortgageDuration() {mortgageDuration--;}

//Big 3
bool operator>(const Property& p1, const Property& p2) {
	if (p1.propertyValue > p2.propertyValue) {
		return true;
	}
	return false;
}
bool operator<(const Property& p1, const Property& p2) {
	if (p1.propertyValue < p2.propertyValue) {
		return true;
	}
	return false;
}
