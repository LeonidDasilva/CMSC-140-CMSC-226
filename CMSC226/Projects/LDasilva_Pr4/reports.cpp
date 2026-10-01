// This program will create a Report Menu for Project 1
//-Leonid Dasilva
//2/5/26

#include <iostream>
#include <iomanip>

#include "reports.h"
#include "global.h"

using namespace std;

void reports()
{
    int input;

    do {
        cout << endl;
        cout << "Serendipity Bookseller" << endl;
        cout << setw(18) << " " << "Reports" << endl;

        cout << endl;

        cout << setw(8) << " " << "1. Inventory Listing" << endl;
        cout << setw(8) << " " << "2. Inventory Wholesale Value" << endl;
        cout << setw(8) << " " << "3. Inventory Retail Value" << endl;
        cout << setw(8) << " " << "4. Inventory by Quantity" << endl;
        cout << setw(8) << " " << "5. Inventory by Cost" << endl;
        cout << setw(8) << " " << "6. Inventory by Age" << endl;
        cout << setw(8) << " " << "7. Return to Main Menu" << endl;

        cout << endl;

        cout << setw(8) << " " << "Enter Your Choice: ";
        cin >> input;

        while (input < 1 || input > 5) {
            cout << setw(8) << " " << "Please enter a number in the range 1-5: ";
            cin >> input;
        }

        switch (input) {
        case 1:
            repListing();
            break;

        case 2:
            repWholesale();
            break;

        case 3:
            repRetail();
            break;

        case 4:
            repQty();
            break;

        case 5:
            repCost();
            break;

        case 6:
            repAge();
            break;

        case 7:
            cout << setw(8) << " " << "Returning to Main Menu" << endl;
            break;
        }

    } while (input != 7);
}



void repListing() {
    cout << "You selected Inventory Listing." << endl;
}

void repWholesale() {
    cout << "You selected Inventory Wholesale Value." << endl;
}

void repRetail() {
    cout << "You selceted Inventory Retail Value." << endl;
}

void repQty() {
    cout << "You selected Listing by Quantity." << endl;
}

void repCost() {
    cout << "You selected Listing by Cost." << endl;
}

void repAge() {
    cout << "You selected Listing by Age." << endl;
}