#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <string>
#include "shape.h"

using namespace std;

class Circle:public Shape {
	private:
		int radius;

	public:
		int get_radius();
		void set_radius(int radius);
		virtual void calc_area();

};







#endif
