#include <iostream>
#include <string>

#include "BasicFunctions.h"
#include "Triangle.h"
#include "FindSolution.h"

using namespace std;

//Global vars
const string border = "\n\n=========================================================================\n\n";

void viewTriMenu(Triangle &tri, int &input);
/*View triangle
 *
 * 0 - Back
 * 1 - View Solution Status
 * 2 - Edit Measurements
 * 3 - Reset Values
 */

int main() {
    //Vars
    int input;
    Triangle tri;

    //Process
    do {
        cout << border;
        cout << "((( Welcome to TriangleSolver 2.0 )))\n\n~ the updated (and much better) version of TriangleSolver!\n\n";
        cout << "<= Menu =>\n";
        cout << "0 - Quit\n"
            << "1 - View Triangle\n\n";

        validateResponse(0, 1, input);

        switch (input) {
        case 0:
            cout << "Quitting . . .\n";
            break;
        case 1:
            cout << endl;
            viewTriMenu(tri, input);
            input = 1;
            break;
        }
    } while (input);

    return 0;
}

void viewTriMenu(Triangle &tri, int &input) {
    do {
        cout << border;
        tri.getInfo();
        cout << "\n\n0 - Back\n"
            << "1 - View Solution Status\n"
            << "2 - Edit Measurements\n"
            << "3 - Reset Values\n\n";
        validateResponse(0, 3, input);

        switch (input) {
        case 1: //Solution status
            if (solutionStatus(tri, input)) { //Ready to solve
                cout << "\n0 - Back\n"
                    << "1 - Find solution\n";
                validateResponse(0, 1, input);
                if (input) {//1 - solve
                    solveTriangle(tri);
                }
            }
            else { //Not ready to solve
                cout << "0 - Back\n";
                validateResponse(0, 0, input);
            }
            input = 1;
            break;
        case 2: //Edit measurements
            while (input) {
                cout << border;
                cout << "< Edit Measurements >\n";
                cout << "Enter  a value 1-7 to select a variable. Then enter the desired value for that variable\n";
                cout << "0 - Back\n\n"
                    << "1) Side 1 = " << tri.side1 << " " << tri.units << "\n"
                    << "2) Side 2 = " << tri.side2 << " " << tri.units << "\n"
                    << "3) Side 3 = " << tri.side3 << " " << tri.units << "\n"
                    << "4) Angle 1 = " << tri.angle1 << " degrees\n"
                    << "5) Angle 2 = " << tri.angle2 << " degrees\n"
                    << "6) Angle 3 = " << tri.angle3 << " degrees\n"
                    << "7) Units = " << tri.units << endl;
                validateResponse(0, 7, input);
            
                switch (input) {
                case 1:
                    cout << "1) Side 1 = ";
                    cin >> tri.side1;
                    cout << " " << tri.units << endl;
                    break;
                case 2:
                    cout << "2) Side 2 = ";
                    cin >> tri.side2;
                    cout << " " << tri.units << endl;
                    break;
                case 3:
                    cout << "3) Side 3 = ";
                    cin >> tri.side3;
                    cout << " " << tri.units << endl;
                    break;
                case 4:
                    cout << "4) Angle 1 = ";
                    cin >> tri.angle1;
                    cout << " degrees" << endl;
                    break;
                case 5:
                    cout << "5) Angle 2 = ";
                    cin >> tri.angle2;
                    cout << " degrees" << endl;
                    break;
                case 6:
                    cout << "6) Angle 3 = ";
                    cin >> tri.angle3;
                    cout << " degrees" << endl;
                    break;
                case 7:
                    cout << "7) Units = ";
                    cin >> tri.units;
                    break;
                }
            }
            input = 1;
            break;
        case 3: //Reset
            cout << "< Reset Values >\n";
            cout << "Are you sure you want to reset all measurements?\n"
                << "1 - No\n"
                << "2 - Yes\n\n";
            validateResponse(1, 2, input);
            if (input == 2) {
                tri.side1 = 0;
                tri.side2 = 0;
                tri.side3 = 0;
                tri.angle1 = 0;
                tri.angle2 = 0;
                tri.angle3 = 0;
                tri.area = 0;
                tri.units = "";
            }
            break;
        }
    } while (input);
}