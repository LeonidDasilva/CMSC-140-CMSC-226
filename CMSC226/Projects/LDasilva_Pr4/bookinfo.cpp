// This Program will create a Book Information Screen for project 1
//-Leonid Dasilva
//2/6/26

#include <iostream>
#include <iomanip>

#include "bookinfo.h"
#include "global.h"

using namespace std;

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