// This program will create a cashier screen for project 1
//-Leonid Dasilca
//2/6/26


#include <iostream>
#include <iomanip>
#include <string>
#include "cashier.h"

using namespace std;

void cashier()
{
    string date, ISBN, title;
    int qty;
    double price;
    char again;

    do {
        cout << endl;
        cout << "Serendipity Book Sellers" << endl;
        cout << setw(5) << " " << "Cashier Module" << endl;

        cout << endl;

        cout << "Date: ";
        cin >> date;

        cout << "Quantity of Book(s): ";
        cin >> qty;

        cout << "ISBN: ";
        cin >> ISBN;
        cin.ignore();

        cout << "Title: ";
        getline(cin, title);

        cout << "Price: ";
        cin >> price;

        double subtotal = price * qty;
        double tax = subtotal * 0.06;
        double total = subtotal + tax;

        cout << fixed << setprecision(2) << endl;

        cout << "Qty  ISBN        Title          Price    Total" << endl;
        cout << "------------------------------------------------" << endl;

        cout << qty << "    "
            << ISBN << "    "
            << title << "    $"
            << price << "    $"
            << subtotal << endl;

        cout << setw(25) << "Subtotal: $" << subtotal << endl;
        cout << setw(25) << "Tax: $" << tax << endl;
        cout << setw(25) << "Total: $" << total << endl;

        cout << endl;

        cout << "Process another transaction? (Y/N): ";
        cin >> again;

    } while (again == 'Y' || again == 'y');
}