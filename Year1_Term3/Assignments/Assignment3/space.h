#ifndef SPACE_H
#define SPACE_H

#include <iostream>
#include "tenant.h"

using namespace std;

struct space {
	string size;
	tenant currTenant;
	string occupied;
};

#endif
