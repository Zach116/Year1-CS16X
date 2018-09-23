#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>
#include "shape.h"

using namespace std;

class Rectangle:public Shape {
	private:
		int length;
		int width;

	public:
		int get_length();
		int get_width();
		void set_length(int length);
		void set_width(int width);
		virtual void calc_area();
};









#endif
