#include "shape.h"
#include <iostream>
#include <string>

using namespace std;

string Shape::get_name() {return name;}
string Shape::get_color() {return color;}
float Shape::get_area() {return area;}
void Shape::set_name(string name) {this->name = name;}
void Shape::set_color(string color) {this->color = color;}
