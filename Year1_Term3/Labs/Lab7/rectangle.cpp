#include "rectangle.h"
#include <iostream>
#include <string>

using namespace std;

int Rectangle::get_length() {return length;}
int Rectangle::get_width() {return width;}
void Rectangle::set_length(int length) {this->length = length;}
void Rectangle::set_width(int width) {this->width = width;}
void Rectangle::calc_area() {area = (width*length);} 
