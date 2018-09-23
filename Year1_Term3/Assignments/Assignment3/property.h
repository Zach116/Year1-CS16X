#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

class Property {
  protected:
    string name;
    int propertyValue;
    string location;
    int mortgagePerMonth;
    int mortgageDuration;
    float propertyTaxPercent;

  public:
    //Constructors
    Property();

    //Big 3
    friend bool operator>(const Property&, const Property&);
    friend bool operator<(const Property&, const Property&);

    //Accessors
    int get_propertyValue();
    int get_mortgagePerMonth();
    int get_mortgageDuration();
    string get_name();
    string get_location();
    int calc_tax_amount();

    //Mutators
    void change_propertyValue(float percentChange);
    void decrease_mortgageDuration();
    void set_propertyValue(int num);

    //Only evict tenant if their rent is above their budget and they have an agreeability number of 2 or above
    void tenant_eviction();

};

#endif
