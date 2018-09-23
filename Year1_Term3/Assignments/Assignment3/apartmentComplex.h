#ifndef APARTMENTCOMPLEX_H
#define APARTMENTCOMPLEX_H

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include <string>
#include "property.h"
#include "tenant.h"

using namespace std;

class ApartmentComplex:public Property {
  private:
    int numRooms;
    int numTenants;
    tenant* tenants;
    int currRent;

  public:
    //Constructors
    ApartmentComplex();

    //Big 3
    //Deconstructor
    ~ApartmentComplex();

    //Copy Constructor
    ApartmentComplex(const ApartmentComplex& copy);

    //Assignment Operator Overload
    const ApartmentComplex& operator=(const ApartmentComplex& copy);

    //Accessors
    void print_info();
    void view_info();
    void print_buying_info();
    int get_numTenants();

    //Mutators
    void set_rent(int newRent);

    //Only collect rent if they have an agreeability number of 3 or above
    int collect_rent();
    void remove_tenant(int tenantIndex);
    void randomize_info();
};

#endif
