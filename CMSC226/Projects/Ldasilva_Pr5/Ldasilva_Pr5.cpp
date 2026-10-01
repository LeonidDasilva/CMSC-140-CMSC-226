/******************************************************************
* Description:Program will display multiple menus for a book seller program
* Course: CS226 CRN 31824
* Prof. Elia
* Student: Leonid Dasilva
******************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "FuncProto.h"

using namespace std;

//declaration of global arrays
const int SIZE = 20;

string bookTitle[SIZE];
string ISBN[SIZE];
string author[SIZE];
string publisher[SIZE];
string dateAdded[SIZE];
int qtyOnHand[SIZE];
double wholesale[SIZE];
double retail[SIZE];


int main() {
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

        while (input < 1 || input > 7) {
            cout << setw(8) << " " << "Please enter a number in the range 1-7: ";
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
    cout << endl << "Inventory Listing" << endl;
    cout << endl;

    for (int i = 0; i < SIZE; i++) {

        if (!bookTitle[i].empty()) {

            cout << bookTitle[i] << " | "
                << ISBN[i] << " | "
                << author[i] << " | "
                << publisher[i] << " | "
                << dateAdded[i] << " | "
                << qtyOnHand[i] << " | $"
                << wholesale[i] << " | $"
                << retail[i] << endl;
        }
    }

    cout << endl;

    cout << "Press Enter to continue";
    cin.ignore();
    cin.get();
}

void repWholesale() {
    double total = 0;

    cout << endl;
    cout << "Wholesale Report" << endl;
    cout << endl;

    for (int i = 0; i < SIZE; i++) {

        if (!bookTitle[i].empty()) {

            cout << bookTitle[i] << " | "
                << ISBN[i] << " | "
                << qtyOnHand[i] << " | $"
                << wholesale[i] << endl;

            total += qtyOnHand[i] * wholesale[i];

        }
    }

    cout << endl;
    cout << "Total Wholesale Value: $" << total << endl;

    cout << endl;

    cout << "Press Enter to continue";
    cin.ignore();
    cin.get();
}

void repRetail() {
    double total = 0;

    cout << endl;
    cout << "Retail Report" << endl;
    cout << endl;

    for (int i = 0; i < SIZE; i++) {

        if (!bookTitle[i].empty()) {

            cout << bookTitle[i] << " | "
                << ISBN[i] << " | "
                << qtyOnHand[i] << " | $"
                << retail[i] << endl;

            total += qtyOnHand[i] * retail[i];

        }
    }

    cout << endl;
    cout << "Total Retail Value: $" << total << endl;

    cout << endl;

    cout << "Press Enter to continue";
    cin.ignore();
    cin.get();
}

void repQty() {
    int index[SIZE];

    for (int i = 0; i < SIZE; i++)
        index[i] = i;

    // sort by qty descending
    for (int i = 0; i < SIZE - 1; i++) {

        for (int j = i + 1; j < SIZE; j++) {

            if (qtyOnHand[index[j]] > qtyOnHand[index[i]]) {

                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;

            }
        }
    }

    cout << endl;
    cout << "Inventory by Quantity" << endl;
    cout << endl;

    for (int i = 0; i < SIZE; i++) {
        int k = index[i];
        if (!bookTitle[k].empty()) {
            cout << bookTitle[k] << " | "
                << ISBN[k] << " | "
                << qtyOnHand[k] << endl;
        }
    }

    cin.ignore();
    cin.get();
}

void repCost() {
    int index[SIZE];

    for (int i = 0; i < SIZE; i++)
        index[i] = i;

    // sort by wholesale descending
    for (int i = 0; i < SIZE - 1; i++) {

        for (int j = i + 1; j < SIZE; j++) {

            if (wholesale[index[j]] > wholesale[index[i]]) {

                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;

            }
        }
    }

    cout << endl;
    cout << "Inventory by Cost" << endl;
    cout << endl;

    for (int i = 0; i < SIZE; i++) {

        int k = index[i];

        if (!bookTitle[k].empty()) {

            cout << bookTitle[k] << " | "
                << ISBN[k] << " | "
                << qtyOnHand[k] << " | $"
                << wholesale[k] << endl;

        }
    }

    cin.ignore();
    cin.get();
}

void repAge() {
    int index[SIZE];

    for (int i = 0; i < SIZE; i++)
        index[i] = i;

    // sort by date
    for (int i = 0; i < SIZE - 1; i++) {

        for (int j = i + 1; j < SIZE; j++) {

            if (dateAdded[index[j]] < dateAdded[index[i]]) {

                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;

            }
        }
    }

    cout << endl;
    cout << "Inventory by Age" << endl;
    cout << endl;

    for (int i = 0; i < SIZE; i++) {

        int k = index[i];

        if (!bookTitle[k].empty()) {

            cout << bookTitle[k] << " | "
                << ISBN[k] << " | "
                << qtyOnHand[k] << " | "
                << dateAdded[k] << endl;

        }
    }

    cin.ignore();
    cin.get();
}




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
    string titleSearch;
    int index = -1;

    cin.ignore();

    cout << "Enter the title of the book to look up: ";
    getline(cin, titleSearch);

    //search for matching title
    for (int i = 0; i < SIZE; i++)
    {
        if (bookTitle[i] == titleSearch)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "That book is not in inventory." << endl;
        return;
    }

    bookinfo(ISBN[index],
        bookTitle[index],
        author[index],
        publisher[index],
        dateAdded[index],
        qtyOnHand[index],
        wholesale[index],
        retail[index]);
}




void addBook() {

    int index = -1;

    //search for an empty element in bookTitle
    for (int i = 0; i < SIZE; i++)
    {
        if (bookTitle[i].empty())
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Inventory is full. No more books may be added." << endl;
        return;
    }

    cin.ignore();

    cout << "Enter book title: ";
    getline(cin, bookTitle[index]);

    cout << "Enter ISBN number: ";
    getline(cin, ISBN[index]);

    cout << "Enter author's name: ";
    getline(cin, author[index]);

    cout << "Enter publisher's name: ";
    getline(cin, publisher[index]);

    cout << "Enter date added (MM-DD-YYYY): ";
    getline(cin, dateAdded[index]);

    cout << "Enter quantity on hand: ";
    cin >> qtyOnHand[index];

    cout << "Enter wholesale cost: ";
    cin >> wholesale[index];

    cout << "Enter retail price: ";
    cin >> retail[index];

    cout << endl;

    cout << "Book successfully added to inventory!" << endl;
}





void editBook()
{
    string titleSearch;

    int choice;
    int index = -1;

    cin.ignore();

    cout << "Enter the title of the book to edit: ";
    getline(cin, titleSearch);

    // Search for book
    for (int i = 0; i < SIZE; i++)
    {
        if (bookTitle[i] == titleSearch)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "That book is not in inventory." << endl;
        return;
    }

    bookinfo(ISBN[index],
        bookTitle[index],
        author[index],
        publisher[index],
        dateAdded[index],
        qtyOnHand[index],
        wholesale[index],
        retail[index]);

    cout << endl;

    cout << "Which field would you like to edit?" << endl;
    cout << "1. ISBN" << endl;
    cout << "2. Title" << endl;
    cout << "3. Author" << endl;
    cout << "4. Publisher" << endl;
    cout << "5. Date Added" << endl;
    cout << "6. Quantity-On-Hand" << endl;
    cout << "7. Wholesale Cost" << endl;
    cout << "8. Retail Price" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    cin.ignore();

    switch (choice)
    {
    case 1:
        cout << "Enter new ISBN: ";
        getline(cin, ISBN[index]);
        break;

    case 2:
        cout << "Enter new Title: ";
        getline(cin, bookTitle[index]);
        break;

    case 3:
        cout << "Enter new Author: ";
        getline(cin, author[index]);
        break;

    case 4:
        cout << "Enter new Publisher: ";
        getline(cin, publisher[index]);
        break;

    case 5:
        cout << "Enter new Date (MM-DD-YYYY): ";
        getline(cin, dateAdded[index]);
        break;

    case 6:
        cout << "Enter new Quantity: ";
        cin >> qtyOnHand[index];
        break;

    case 7:
        cout << "Enter new Wholesale Cost: ";
        cin >> wholesale[index];
        break;

    case 8:
        cout << "Enter new Retail Price: ";
        cin >> retail[index];
        break;

    default:
        cout << "Invalid choice." << endl;
    }

    cout << endl << "Book record updated successfully." << endl;
}




void deleteBook()
{
    string titleSearch;

    int index = -1;

    char confirm;

    cin.ignore();
    cout << "Enter the title of the book to delete: ";
    getline(cin, titleSearch);

    // Search
    for (int i = 0; i < SIZE; i++)
    {
        if (bookTitle[i] == titleSearch)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "That book is not in inventory." << endl;
        return;
    }

    bookinfo(ISBN[index],
        bookTitle[index],
        author[index],
        publisher[index],
        dateAdded[index],
        qtyOnHand[index],
        wholesale[index],
        retail[index]);

    cout << endl << "Are you sure you want to delete this book ? (Y / N) : ";
    cin >> confirm;

    if (confirm == 'Y' || confirm == 'y')
    {
        bookTitle[index] = "";
        ISBN[index] = "";
        author[index] = "";
        publisher[index] = "";
        dateAdded[index] = "";
        qtyOnHand[index] = 0;
        wholesale[index] = 0.0;
        retail[index] = 0.0;

        cout << "Book deleted from inventory." << endl;
    }
    else
    {
        cout << "Deletion canceled." << endl;
    }
}





void cashier()
{
    string date[SIZE];
    string isbn[SIZE];
    string title[SIZE];
    int qty[SIZE];
    double price[SIZE];

    char again;
    char addOrder;

    do {
        double subtotal = 0;
        int i = 0;

        cout << endl;
        cout << "Serendipity Book Sellers" << endl;
        cout << setw(5) << " " << "Cashier Module" << endl;
        cout << endl;

        do {
            cout << "Date: ";
            cin >> date[i];

            cout << "Quantity of Book(s): ";
            cin >> qty[i];

            int foundIndex = -1;

            do {
                cout << "ISBN: ";
                cin >> ISBN[i];

                foundIndex = -1;

                for (int j = 0; j < SIZE; j++) {

                    if (ISBN[j] == isbn[i]) {

                        foundIndex = j;
                        break;
                    }
                }

                if (foundIndex == -1) {
                    cout << "ISBN not found. Try again." << endl;
                }

            } while (foundIndex == -1);

            //fill in title and price
            title[i] = bookTitle[foundIndex];
            price[i] = retail[foundIndex];

            cout << "Title: " << title[i] << endl;
            cout << "Price: $" << price[i] << endl;

            if (qty[i] > qtyOnHand[foundIndex]) {
                cout << "Not enough stock available." << endl;
                return; //exit cashier
            }

            qtyOnHand[foundIndex] -= qty[i];

            subtotal += price[i] * qty[i];

            cout << "Add another book? (Y/N): ";
            cin >> addOrder;

            i++;

        } while ((addOrder == 'Y' || addOrder == 'y') && i < 20);

        //calculate totals
        double tax = subtotal * 0.06;
        double total = subtotal + tax;

        cout << fixed << setprecision(2) << endl;

        cout << "Qty  ISBN        Title          Price    Total" << endl;
        cout << "------------------------------------------------" << endl;

        for (int a = 0; a < i; a++) {
            cout << qty[a] << "    "
                << ISBN[a] << "    "
                << title[a] << "    $"
                << price[a] << "    $"
                << price[a] * qty[a] << endl;
        }

        cout << setw(25) << "Subtotal: $" << subtotal << endl;
        cout << setw(25) << "Tax: $" << tax << endl;
        cout << setw(25) << "Total: $" << total << endl;

        cout << endl;
        cout << "Process another transaction? (Y/N): ";
        cin >> again;

    } while (again == 'Y' || again == 'y');
}






void bookinfo(string isbn,
    string title,
    string author,
    string publisher,
    string date,
    int qty,
    double wholesale,
    double retail)
{
    cout << endl;

    cout << "Serendipity Booksellers" << endl;
    cout << setw(14) << " " << "Book Information" << endl;

    cout << endl;

    cout << "ISBN: " << isbn << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Date Added: " << date << endl;
    cout << "Quantity-On-Hand: " << qty << endl;

    cout << fixed << setprecision(2);

    cout << "Wholesale Cost: " << wholesale << endl;
    cout << "Retail Price: " << retail << endl;

    cout << endl;
}   

