#include "circle.h"
#include <iostream>
#include <string>

using namespace std;

int Circle::get_radius() {return radius;}
void Circle::set_radius(int radius) {this->radius = radius;}

void Circle::calc_area() {
	area = (3.14 * radius);
}
