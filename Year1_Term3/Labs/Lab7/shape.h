#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>


using namespace std;


class Shape {
	protected:
		string name;
		string color;
		float area;
	public:
	string get_name();
	string get_color();
	float get_area();
	void set_name(string name);
	void set_color(string color);
	virtual void calc_area() = 0;

};


#endif
