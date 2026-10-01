//this program will create a Inventory Database Menu Scrren for project 1
//-Leonid Dasilva
//2/6/26


#include <iostream>
#include <iomanip>

#include "invmenu.h"
#include "global.h"
#include "bookinfo.h"

using namespace std;

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

    bookinfo(bookTitle[index],
        isbn[index],
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
    getline(cin, isbn[index]);

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

    bookinfo(isbn[index],
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
        getline(cin, isbn[index]);
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

    bookinfo(isbn[index],
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
        isbn[index] = "";

        cout << "Book deleted from inventory." << endl;
    }
    else
    {
        cout << "Deletion canceled." << endl;
    }
}