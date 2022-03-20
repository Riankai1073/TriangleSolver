#pragma once

#include "Triangle.h"

#ifndef FIND_SOLUTION
#define FIND_SOLUTION

//Subtraction property (angle - angle = angle)
double subtractAngles(double a1, double a2);

//Law of Sines (solve for side)
double LOSside(double s1, double a1, double a2);

//Law of Sines (solve for angle)
double LOSangle(double s1, double s2, double a1);

//Law of Cosines (solve for side)
double LOCside(double s1, double s2, double a3);

//Law of Cosines (solve for angle)
double LOCangle(double s1, double s2, double s3);

//Area (solve for area using SSS)
double heronFormula(double s1, double s2, double s3);

/* FIND SOLUTION */
void solveTriangle(Triangle &tri);

#endif