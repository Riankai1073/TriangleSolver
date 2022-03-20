#pragma once
#ifndef TRIANGLE
#define TRIANGLE

#include <iostream>
#include <iomanip>

using namespace std;

struct Triangle {
	//Vars
	double side1 = 0,
		side2 = 0,
		side3 = 0,
		angle1 = 0,
		angle2 = 0,
		angle3 = 0,
		area = 0;
	string units;

	//Funcs
	void getInfo() const {
		cout << "\n\n<= Triangle =>\n";
		cout << fixed << setprecision(2);
		cout << "Side 1 = " << side1 << " " << units << "\n"
			<< "Side 2 = " << side2 << " " << units << "\n"
			<< "Side 3 = " << side3 << " " << units << "\n"
			<< "Angle 1 = " << angle1 << " degrees\n"
			<< "Angle 2 = " << angle2 << " degrees\n"
			<< "Angle 3 = " << angle3 << " degrees\n"
			<< "Area = " << area << " " << units << endl;
	}
};

#endif