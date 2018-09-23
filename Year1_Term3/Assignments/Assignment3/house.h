#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include <string>
#include "property.h"
#include "tenant.h"

using namespace std;

class House:public Property {
  private:
    tenant currTenant;
    string occupied;

  public:
    //Constructors
    House();

    //Big 3

    //Accessors
    void print_info();
    void view_info();
    void print_buying_info();
    string get_occupied();

    //Mutators
    void set_rent(int newRent);

    //Only collect rent if they have an agreeability number of 2 or above
    int collect_rent();


    void randomize_info();
};

#endif
