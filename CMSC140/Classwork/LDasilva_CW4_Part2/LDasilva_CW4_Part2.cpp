/*
* Class: CMSC140 CRN
* Instructor:
* Project <4>
* Description: Determines the price for a custom shop sign. The price is determined by the number of
colors in the sign, if the sign will have lighting, and if an old sign must be removed.
* Due Date:
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Leonid Dasilva
*/

#include <iostream>
#include <iomanip>

using namespace std;


#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    //decleration section
    const int ONE_COLOR = 1,
        TWO_COLORS = 2,
        THREE_COLORS = 3,
        FOUR_COLORS = 4;

    int numColors;

    double basePrice, totalPrice;

    char lighted;
    char removeOldSign;

    //Asking for user to input number of colors
    cout << "Enter the number of colors in the sign: ";
    cin >> numColors;
    cout << endl;

    if (numColors < 1) {    //if statement makes sure user inputs >1 color

        cout << "Invalid number of colors. Number of colors must be greater than zero.";

        return 0; //return zero to end program
    }
    else {
        switch (numColors) {    //switch statement to determine base price of sign

        case ONE_COLOR:
            basePrice = 250.00;
            break;

        case TWO_COLORS:
            basePrice = 325.00;
            break;

        case THREE_COLORS:
            basePrice = 450.00;
            break;

        case FOUR_COLORS:
            basePrice = 625.00;
            break;

        }

        if (numColors >= 5) {
            basePrice = 850.00;
        }
    }

    totalPrice = basePrice; //necessary to make lighting/removal calculations

    //Asking user if the sign is lighted
    cout << "Do you want a lighted sign (y/n)?";
    cin >> lighted;
    cout << endl;

    if (lighted == 'y' || lighted == 'Y') {
        totalPrice += basePrice * 0.25;
    }
    else if (lighted == 'n' || lighted == 'N') {
    }
    else {
        cout << "Invalid input. Please input: y, Y, n, or N." << endl;
    }

    //Asking user if the sign is lighted
    cout << "Do you need an old sign removed(y/n)?";
    cin >> removeOldSign;
    cout << endl;

    if (removeOldSign == 'y' || removeOldSign == 'Y') {
        totalPrice += basePrice * .1;
    }
    else if (removeOldSign == 'n' || removeOldSign == 'N') {
    }
    else {
        cout << "Invalid input. Please input: y, Y, n, or N." << endl;
    }

    //final output
    cout << setprecision(2) << fixed;

    cout << "The price is: $" << totalPrice;


    return 0;
}