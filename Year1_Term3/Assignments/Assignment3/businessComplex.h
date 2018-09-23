#ifndef BUSINESSCOMPLEX_H
#define BUSINESSCOMPLEX_H

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include <string>
#include "property.h"
#include "tenant.h"
#include "space.h"

using namespace std;

class BusinessComplex:public Property {
  private:
    int numSpaces;
    int numTenants;
    space* spaces;

  public:
    //Constructors
    BusinessComplex();

    //Big 3
    //Deconstructor
    ~BusinessComplex();

    //Copy Constructor
    BusinessComplex(const BusinessComplex& copy);

    //Assignment Operator Overload
    const BusinessComplex& operator=(const BusinessComplex& copy);

    //Accessors
    int get_numSpaces();
    void print_info();
    void view_info();
    void print_buying_info();
    int get_numTenants();

    //Mutators
    void set_rent(int spaceIndex, int newRent);

    //Only collect rent if they have an agreeability number of 2 or above. Ups property value by 1% for each successful collect
    int collect_rent();
    void remove_tenant(int tenantIndex);
    void randomize_info();
};

#endif
