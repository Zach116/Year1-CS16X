#include "rectangle.h"
#include "circle.h"
#include "shape.h"
#include <iostream>
#include <string>


using namespace std;

void print_shape_info(Shape& shape);

int main() {
	Circle circle;
	Rectangle rectangle;
	Shape *s;
	s = &circle;
	s->set_radius(2);
	s->calc_area();
	s->set_name("circle");
	s->set_color("blue");
	
	rectangle.set_length(5);
	rectangle.set_width(6);
	rectangle.calc_area();
	rectangle.set_name("rectangle");
	rectangle.set_color("blue");

	print_shape_info (circle);
	print_shape_info (rectangle);



	return 0;
}

void print_shape_info(Shape& shape) {
	cout << "Name: " << shape.get_name() << endl;
	cout << "Color: " << shape.get_color() << endl;
	cout << "Area: " << shape.get_area() << endl;
	cout << endl;
}
