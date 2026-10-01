/*
* Single file program that will first display a main 
* menu that can then be used to call
* multiple funtion that display other menu's
* -Leonid Dasilva
* 2/6/26
*/


#include <iostream>
#include <iomanip>
#include <string>
#include "mainmenu.h"

using namespace std;


int main(){
    int input;

    cout << setw(10) << " " << "Serendipity Booksellers " << endl;
    cout << setw(15) << " " << "Main Menu " << endl;
    cout << endl;

    do {
        cout << setw(8) << " " << "1. Cashier Module" << endl;
        cout << setw(8) << " " << "2. Inventory Database Module" << endl;
        cout << setw(8) << " " << "3. Report Module" << endl;
        cout << setw(8) << " " << "4. Exit" << endl;
        cout << endl;

        cout << setw(8) << " " << "Enter Your Choice: ";
        cin >> input;

        while (input < 1 || input > 4) {
            cout << setw(8) << " " << "Please enter a number in the range 1-4: ";
            cin >> input;
        }

        switch (input) {
        case 1:
            cashier();
            break;

        case 2:
            invmenu();
            break;

        case 3:
            reports();
            break;

        case 4:
            cout << setw(8) << " " << "Exiting program." << endl;
            break;
        }

    } while (input != 4);

    return 0;
}


// Cashier function
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


// Reports menu
void reports()
{
    int input;

    do {
        cout << endl;
        cout << "Serendipity Bookseller"<< endl;
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




// Inventory menu
void invmenu()
{
    int input;

    do {
        cout << endl;
        cout << "Serendipity Bookseller" << endl;
        cout << setw(12) << " " << "Inventory Database" << endl;

        cout << endl;

        cout << setw(8) << " " << "1. Look Up a Book" << endl;
        cout << setw(8) << " " << "2. Add a Book" << endl;
        cout << setw(8) << " " << "3. Edit a Book's Record" << endl;
        cout << setw(8) << " " << "4. Delete a Book" << endl;
        cout << setw(8) << " " << "5. Return to Main Menu" << endl;

        cout << endl;

        cout << setw(8) << " " << "Enter Your Choice: ";
        cin >> input;

        while (input < 1 || input > 5) {
            cout << setw(8) << " " << "Please enter a number in the range 1-5: ";
            cin >> input;
        }

        switch (input) {
        case 1:
            lookUpBook();
            break;

        case 2:
            addBook();
            break;

        case 3:
            editBook();
            break;

        case 4:
            deleteBook();
            break;

        case 5:
            cout << setw(8) << " " << "Returning to Main Menu" << endl;
            break;
        }

    } while (input != 5);
}



void lookUpBook() {
    cout << "You selceted Look Up Book." << endl;
}

void addBook() {
    cout << "You selected Add Book." << endl;
}

void editBook() {
    cout << "You selected Edit Book." << endl;
}

void deleteBook() {
    cout << "You selected Delete Book." << endl;
}





// Book info display
void bookinfo()
{
    cout << endl;

    cout << "Serendipity Bookseller" << endl;
    cout << setw(14) << " " << "Book Information" << endl;

    cout << endl;

    cout << "ISBN: " << endl;
    cout << "Title: " << endl;
    cout << "Author: " << endl;
    cout << "Publisher: " << endl;
    cout << "Date Added: " << endl;
    cout << "Quantity-On-Hand: " << endl;
    cout << "Wholesale Cost: " << endl;
    cout << "Retail Price: " << endl;
}