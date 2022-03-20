#define _USE_MATH_DEFINES
#include <math.h>
#include "FindSolution.h"
#include "Triangle.h"

const double radToDeg = 180 / M_PI;
const double degToRad = M_PI / 180;

//Subtraction property (angle - angle = angle)
double subtractAngles(double a1, double a2) {
	return 180 - a1 - a2;
}

//Law of Sines (solve for side)
double LOSside(double s1, double a1, double a2) {
	return (s1 * sin(degToRad * a2)) / sin(degToRad * a1);
}

//Law of Sines (solve for angle)
double LOSangle(double s1, double s2, double a1) {
	//cout << (radToDeg * asin((s2 * sin(degToRad * a1)) / s1)) << " angle 1 degrees\n\n";
	return radToDeg * asin((s2 * sin(degToRad * a1)) / s1);
}

//Law of Cosines (solve for side)
double LOCside(double s1, double s2, double a3) {
	return sqrt(pow(s1, 2) + pow(s2, 2) - 2 * s1 * s2 * cos(degToRad * a3));
}

//Law of Cosines (solve for angle)
double LOCangle(double s1, double s2, double s3) {
	return radToDeg * acos((pow(s2, 2) + pow(s3, 2) - pow(s1, 2)) / (2 * s2 * s3));
}

//Area (solve for area using SSS)
double heronFormula(double s1, double s2, double s3) {
	double s = (s1 + s2 + s3) / 2;
	return sqrt(s * (s - s1) * (s - s2) * (s - s3));
}

/* FIND SOLUTION */

/* NO AAA */

void solveTriangle(Triangle& tri) {

	/* SSS Algorithm */

	//SSS [no calibration]
	if (tri.side1 && tri.side2 && tri.side3) {
		tri.angle1 = LOCangle(tri.side1, tri.side2, tri.side3);
		tri.angle2 = LOSangle(tri.side1, tri.side2, tri.angle1);
		tri.angle3 = subtractAngles(tri.angle1, tri.angle2);
		tri.area = heronFormula(tri.side1, tri.side2, tri.side3);
	}
	else {

		/* Calibration for other XXX */

		//Check/match angles with sides
		bool a1 = false, a2 = false, a3 = false; //to check angles
		bool a1s1 = false, a2s2 = false, a3s3 = false; //to match opposites
		

		int angleCount = 0;

		//Count angles
		if (tri.angle1) {
			angleCount++;
			a1 = true;
			if (tri.side1)
				a1s1 = true;
		}
		if (tri.angle2) {
			angleCount++;
			a2 = true;
			if (tri.side2)
				a2s2 = true;
		}
		if (tri.angle3) {
			angleCount++;
			a3 = true;
			if (tri.side3)
				a3s3 = true;
		}

		//Match angles

		/* Other XXX */
		if (angleCount == 1) { //1 angle - 2 sides = 9/21 combos
			if (a1) { //a1
				if (a1s1) { //a1s1
					if (tri.side2) { //a1s1s2
						tri.angle2 = LOSangle(tri.side1, tri.angle2, tri.angle1);
						tri.angle3 = subtractAngles(tri.angle1, tri.angle2);
						tri.side3 = LOSside(tri.side1, tri.angle1, tri.angle3);
					}
					else { //a1s1s3
						tri.angle3 = LOSangle(tri.side1, tri.side3, tri.angle1);
						tri.angle3 = subtractAngles(tri.angle1, tri.angle2);
						tri.side3 = LOSside(tri.side1, tri.angle1, tri.angle3);
					}
				}
				else { //a1s2s3
					tri.side1 = LOCside(tri.side2, tri.side3, tri.angle1);
					tri.angle2 = LOSangle(tri.side1, tri.side2, tri.angle1);
					tri.angle3 = subtractAngles(tri.angle1, tri.angle2);
				}
			}
			else if (a2) { //a2
				if (a2s2) { //a2s2
					if (tri.side1) { //a2s2s1
						tri.angle1 = LOSangle(tri.side2, tri.side1, tri.angle2);
						tri.angle3 = subtractAngles(tri.angle1, tri.angle2);
						tri.side3 = LOSside(tri.side1, tri.angle1, tri.angle3);
					}
					else { //a2s2s3
						tri.angle3 = LOSangle(tri.side2, tri.side3, tri.angle2);
						tri.angle1 = subtractAngles(tri.angle2, tri.angle3);
						tri.side1 = LOSside(tri.side2, tri.angle2, tri.angle1);
					}
				}
				else { //a2s1s3
					tri.side2 = LOCside(tri.side1, tri.side3, tri.angle2);
					tri.angle1 = LOSangle(tri.side2, tri.side1, tri.angle2);
					tri.angle3 = subtractAngles(tri.angle1, tri.angle2);
				}
			}
			else if (a3) { //a3
				if (a3s3) { //a3s3
					if (tri.side1) { //a3s3s1
						tri.angle1 = LOSangle(tri.side3, tri.side1, tri.angle3);
						tri.angle2 = subtractAngles(tri.angle1, tri.angle3);
						tri.side2 = LOSside(tri.side1, tri.angle1, tri.angle2);
					}
					else { //a3s3s2
						tri.angle2 = LOSangle(tri.side3, tri.side2, tri.angle3);
						tri.angle1 = subtractAngles(tri.angle2, tri.angle3);
						tri.side1 = LOSside(tri.side2, tri.angle2, tri.angle1);
					}
				}
				else { //a3s1s2
					tri.side3 = LOCside(tri.side1, tri.side2, tri.angle3);
					tri.angle1 = LOSangle(tri.side3, tri.side1, tri.angle3);
					tri.angle2 = subtractAngles(tri.angle1, tri.angle3);
				}
			}
		}
		else { //2 angles - 1 side = 12/21 combos
			if (a1) { //a1
				if (a1s1) { //a1s1
					if (tri.angle2) { //a1s1a2
						tri.angle3 = subtractAngles(tri.angle1, tri.angle2);
						tri.side2 = LOSside(tri.side1, tri.angle1, tri.angle2);
						tri.side3 = LOSside(tri.side1, tri.angle1, tri.angle3);
					}
					else { //a1s1a3
						tri.angle2 = subtractAngles(tri.angle1, tri.angle3);
						tri.side2 = LOSside(tri.side1, tri.angle1, tri.angle2);
						tri.side3 = LOSside(tri.side1, tri.angle1, tri.angle3);
					}
				}
				else {
					if (tri.side2) { //a1s2a3
						tri.angle2 = subtractAngles(tri.angle1, tri.angle3);
						tri.side3 = LOSside(tri.side2, tri.angle2, tri.angle3);
						tri.side1 = LOSside(tri.side2, tri.angle2, tri.angle1);
					}
					else { //a1s3a2
						tri.angle3 = subtractAngles(tri.angle1, tri.angle2);
						tri.side2 = LOSside(tri.side3, tri.angle3, tri.angle1);
						tri.side1 = LOSside(tri.side2, tri.angle2, tri.angle1);
					}
				}
			}
			else if (a2) { //a2
				if (a2s2) { //a2s2
					if (tri.angle1) { //a2s2a1
						tri.angle3 = subtractAngles(tri.angle1, tri.angle2);
						tri.side1 = LOSside(tri.side2, tri.angle2, tri.angle1);
						tri.side3 = LOSside(tri.side1, tri.angle1, tri.angle3);
					}
					else { //a2s2a3
						tri.angle1 = subtractAngles(tri.angle2, tri.angle3);
						tri.side1 = LOSside(tri.side2, tri.angle2, tri.angle1);
						tri.side3 = LOSside(tri.side1, tri.angle1, tri.angle3);
					}
				}
				else {
					if (tri.side1) { //a2s1a3
						tri.angle1 = subtractAngles(tri.angle2, tri.angle3);
						tri.side2 = LOSside(tri.side1, tri.angle1, tri.angle2);
						tri.side3 = LOSside(tri.side1, tri.angle1, tri.angle3);
					}
					else { //a2s3a1
						tri.angle3 = subtractAngles(tri.angle1, tri.angle2);
						tri.side1 = LOSside(tri.side3, tri.angle3, tri.angle1);
						tri.side2 = LOSside(tri.side1, tri.angle1, tri.angle3);
					}
				}
			}
			else if (a3) { //a3
				if (a3s3) { //a3s3
					if (tri.angle1) { //a3s3a1
						tri.angle2 = subtractAngles(tri.angle1, tri.angle3);
						tri.side1 = LOSside(tri.side3, tri.angle3, tri.angle1);
						tri.side2 = LOSside(tri.side1, tri.angle1, tri.angle2);
					}
					else { //a3s3a2
						tri.angle1 = subtractAngles(tri.angle2, tri.angle3);
						tri.side1 = LOSside(tri.side3, tri.angle3, tri.angle1);
						tri.side2 = LOSside(tri.side1, tri.angle1, tri.angle2);
					}
				}
				else {
					if (tri.side1) { //a3s1a2
						tri.angle1 = subtractAngles(tri.angle2, tri.angle3);
						tri.side2 = LOSside(tri.side1, tri.angle1, tri.angle2);
						tri.side3 = LOSside(tri.side1, tri.angle1, tri.angle3);
					}
					else { //a3s2a1
						tri.angle2 = subtractAngles(tri.angle1, tri.angle3);
						tri.side1 = LOSside(tri.side2, tri.angle2, tri.angle1);
						tri.side3 = LOSside(tri.side1, tri.angle1, tri.angle3);
					}
				}
			}
		}

		//Find area
		tri.area = heronFormula(tri.side1, tri.side2, tri.side3);
	}
}