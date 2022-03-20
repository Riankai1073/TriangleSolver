#include "BasicFunctions.h"
#include "Triangle.h"

const string border = "\n\n=========================================================================\n\n";

void validateResponse(int min, int max, int& input) {
	cout << "Input: ";
	cin >> input;
	cout << endl;
	while (input < min || input > max) {
		cout << "Invalid response. Please try again.\n";
		cout << "Input: ";
		cin >> input;
		cout << endl;
	}
}

bool solutionStatus(Triangle tri, int &input) {
	int posCount = 0; //Count the positive values in the triangle
	int negCount = 0; //Count the negative values in the triangle
	int errorCount = 0; //If no errors, find solution

	cout << border;
	cout << "<= Solution Status =>\n";
	cout << "Determine whether your triangle has sufficient data to solve for the remaining values.\n\n"
		<< "If there are any problems with your data, your triangle cannot be solved yet and error\n"
		<< "messages will appear here. You can go back and change your measurements at any point.\n\n"
		<< "Once your triangle has sufficient data, you will see no error messages here and will be\n"
		<< "given the option of solving for the rest of the triangle.\n\n";

	cout << "Errors:\n";

	//No less/more than 3 positive values
	if (tri.side1 > 0)
		posCount++;
	if (tri.side2 > 0)
		posCount++;
	if (tri.side3 > 0)
		posCount++;
	if (tri.angle1 > 0)
		posCount++;
	if (tri.angle2 > 0)
		posCount++;
	if (tri.angle3 > 0)
		posCount++;
	if (tri.area > 0)
		posCount++;

	if (posCount < 3) {
		cout << "- Not enough positive values. (Must have 3 positive values) [CANNOT HAVE 3 ANGLES]\n";
		errorCount++;
	}
	if (posCount > 3) {
		cout << "- Too many positive values. (Must have 3 positive values)\n";
		errorCount++;
	}

	//No negative values
	if (tri.side1 < 0)
		negCount++;
	if (tri.side2 < 0)
		negCount++;
	if (tri.side3 < 0)
		negCount++;
	if (tri.angle1 < 0)
		negCount++;
	if (tri.angle2 < 0)
		negCount++;
	if (tri.angle3 < 0)
		negCount++;
	if (tri.area < 0)
		negCount++;

	if (negCount) {
		cout << "- Existing negative values. (Cannot have negative values)\n";
		errorCount++;
	}

	//AAA is not valid
	if (tri.angle1 && tri.angle2 && tri.angle3) {
		cout << "- Too many angle values. (Must have 2 or less angle values)\n";
		errorCount++;
	}


	//No errors!
	if (!errorCount) {
		cout << "- No errors!\n\n";
		tri.getInfo();
		return true;
	}

	cout << "\n\n";
	tri.getInfo();
	return false;
}