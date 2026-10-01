/******************************************************************
* Description:Program will display multiple menus for a book seller program
* Course: CS226 CRN 31824
* Prof. Elia
* Student: Leonid Dasilva
******************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <fstream>
#include "Header.h"

using namespace std;



fstream inventoryFile;
const char INVENTORY_FILE[] = "inventory.txt";

const int SIZE = 20;

struct BookData
{
    char bookTitle[51];
    char ISBN[14];
    char author[31];
    char publisher[31];
    char dateAdded[11];

    int qtyOnHand;
    double wholesale;
    double retail;
};

BookData books[SIZE] = {};




int main() {

    initializeInventoryFile();

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





void strUpper(char* str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}





bool isEmpty(BookData book)
{
    return book.bookTitle[0] == '\0';
}





void removeBook(BookData& book)
{
    memset(&book, 0, sizeof(BookData));
}





void setTitle(char* title, int index)
{
    strcpy_s(books[index].bookTitle, title);
}




void setISBN(char* isbn, int index)
{
    strcpy_s(books[index].ISBN, isbn);
}





void setAuthor(char* name, int index)
{
    strcpy_s(books[index].author, name);
}





void setPub(char* pub, int index)
{
    strcpy_s(books[index].publisher, pub);
}





void setDateAdded(char* date, int index)
{
    strcpy_s(books[index].dateAdded, date);
}





void setQty(int qty, int index)
{
    books[index].qtyOnHand = qty;
}





void setWholesale(double cost, int index)
{
    books[index].wholesale = cost;
}





void setRetail(double price, int index)
{
    books[index].retail = price;
}





void initializeInventoryFile()
{
    fstream file(INVENTORY_FILE, ios::in | ios::binary);

    if (!file)
    {
        // File doesn't exist, create it
        fstream createFile(INVENTORY_FILE, ios::out | ios::binary);

        BookData emptyBook = {};

        for (int i = 0; i < SIZE; i++)
        {
            createFile.write(reinterpret_cast<char*>(&emptyBook), sizeof(BookData));
        }

        createFile.close();
    }
    else
    {
        file.close();
    }
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

        if (strlen(books[i].bookTitle) > 0) {

            cout << books[i].bookTitle << " | "
                << books[i].ISBN << " | "
                << books[i].author << " | "
                << books[i].publisher << " | "
                << books[i].dateAdded << " | "
                << books[i].qtyOnHand << " | $"
                << books[i].wholesale << " | $"
                << books[i].retail << endl;
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

        if (strlen(books[i].bookTitle) > 0) {

            cout << books[i].bookTitle << " | "
                << books[i].ISBN << " | "
                << books[i].qtyOnHand << " | $"
                << books[i].wholesale << endl;

            total += books[i].qtyOnHand * books[i].wholesale;

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

        if (strlen(books[i].bookTitle) > 0) {

            cout << books[i].bookTitle << " | "
                << books[i].ISBN << " | "
                << books[i].qtyOnHand << " | $"
                << books[i].retail << endl;

            total += books[i].qtyOnHand * books[i].retail;

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

            if (books[index[j]].qtyOnHand > books[index[i]].qtyOnHand) {

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
        if (strlen(books[i].bookTitle) > 0) {
            cout << books[k].bookTitle << " | "
                << books[k].ISBN << " | "
                << books[k].qtyOnHand << endl;
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

            if (books[index[j]].wholesale > books[index[i]].wholesale) {

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

        if (strlen(books[i].bookTitle) > 0) {

            cout << books[k].bookTitle << " | "
                << books[k].ISBN << " | "
                << books[k].qtyOnHand << " | $"
                << books[k].wholesale << endl;

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

            if (books[index[j]].dateAdded < books[index[i]].dateAdded) {

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

        if (strlen(books[i].bookTitle) > 0) {

            cout << books[k].bookTitle << " | "
                << books[k].ISBN << " | "
                << books[k].qtyOnHand << " | "
                << books[k].dateAdded << endl;

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




void lookUpBook()
{
    char search[51];
    char answer;
    BookData book;

    cin.ignore();

    cout << "Enter part of title: ";
    cin.getline(search, 51);

    strUpper(search);

    inventoryFile.open(INVENTORY_FILE,
        ios::in | ios::binary);

    bool found = false;

    while (inventoryFile.read(
        reinterpret_cast<char*>(&book),
        sizeof(BookData)))
    {
        if (strstr(book.bookTitle, search))
        {
            cout << "\nFound: " << book.bookTitle << endl;
            cout << "Is this the book? (Y/N): ";
            cin >> answer;

            if (answer == 'Y' || answer == 'y')
            {
                bookinfo(
                    book.ISBN,
                    book.bookTitle,
                    book.author,
                    book.publisher,
                    book.dateAdded,
                    book.qtyOnHand,
                    book.wholesale,
                    book.retail
                );

                found = true;
                break;
            }
        }
    }

    inventoryFile.close();

    if (!found)
        cout << "Book not found.\n";
}




void addBook()
{
    inventoryFile.open(INVENTORY_FILE,
        ios::in | ios::out | ios::binary);

    BookData book;

    for (int i = 0; i < SIZE; i++)
    {
        inventoryFile.seekg(i * sizeof(BookData));
        inventoryFile.read(reinterpret_cast<char*>(&book),
            sizeof(BookData));

        if (isEmpty(book))
        {
            cin.ignore();

            cout << "Title: ";
            cin.getline(book.bookTitle, 51);

            cout << "ISBN: ";
            cin.getline(book.ISBN, 14);

            cout << "Author: ";
            cin.getline(book.author, 31);

            cout << "Publisher: ";
            cin.getline(book.publisher, 31);

            cout << "Date Added: ";
            cin.getline(book.dateAdded, 11);

            cout << "Quantity: ";
            cin >> book.qtyOnHand;

            cout << "Wholesale: ";
            cin >> book.wholesale;

            cout << "Retail: ";
            cin >> book.retail;

            strUpper(book.bookTitle);
            strUpper(book.author);

            //overwrite empty record
            inventoryFile.seekp(i * sizeof(BookData));

            inventoryFile.write(
                reinterpret_cast<char*>(&book),
                sizeof(BookData));

            inventoryFile.close();

            cout << "Book Added.\n";
            return;
        }
    }

    inventoryFile.close();

    cout << "Inventory Full.\n";
}





void editBook()
{
    char titleSearch[51];
    BookData book;
    int choice;

    cin.ignore();

    cout << "Enter title: ";
    cin.getline(titleSearch, 51);

    strUpper(titleSearch);

    inventoryFile.open(INVENTORY_FILE,
        ios::in | ios::out | ios::binary);

    for (int i = 0; i < SIZE; i++)
    {
        inventoryFile.seekg(i * sizeof(BookData));

        inventoryFile.read(
            reinterpret_cast<char*>(&book),
            sizeof(BookData));

        if (strstr(book.bookTitle, titleSearch))
        {
            bookinfo(
                book.ISBN,
                book.bookTitle,
                book.author,
                book.publisher,
                book.dateAdded,
                book.qtyOnHand,
                book.wholesale,
                book.retail
            );

            cout << "\nEdit:\n";
            cout << "1 ISBN\n2 Title\n3 Author\n";
            cin >> choice;

            cin.ignore();

            switch (choice)
            {
            case 1:
                cin.getline(book.ISBN, 14);
                break;

            case 2:
                cin.getline(book.bookTitle, 51);
                break;

            case 3:
                cin.getline(book.author, 31);
                break;
            }

            // overwrite old record
            inventoryFile.seekp(i * sizeof(BookData));

            inventoryFile.write(
                reinterpret_cast<char*>(&book),
                sizeof(BookData));

            inventoryFile.close();

            cout << "Updated.\n";
            return;
        }
    }

    inventoryFile.close();

    cout << "Book not found.\n";
}




void deleteBook()
{
    char search[51];
    BookData book;
    char confirm;

    cin.ignore();

    cout << "Enter title: ";
    cin.getline(search, 51);

    strUpper(search);

    inventoryFile.open(
        INVENTORY_FILE,
        ios::in | ios::out | ios::binary);

    for (int i = 0; i < SIZE; i++)
    {
        inventoryFile.seekg(i * sizeof(BookData));

        inventoryFile.read(
            reinterpret_cast<char*>(&book),
            sizeof(BookData));

        if (strstr(book.bookTitle, search))
        {
            bookinfo(
                book.ISBN,
                book.bookTitle,
                book.author,
                book.publisher,
                book.dateAdded,
                book.qtyOnHand,
                book.wholesale,
                book.retail
            );

            cout << "Delete? (Y/N): ";
            cin >> confirm;

            if (confirm == 'Y' || confirm == 'y')
            {
                removeBook(book);

                inventoryFile.seekp(
                    i * sizeof(BookData));

                inventoryFile.write(
                    reinterpret_cast<char*>(&book),
                    sizeof(BookData));

                cout << "Deleted.\n";
            }

            inventoryFile.close();
            return;
        }
    }

    inventoryFile.close();

    cout << "Book not found.\n";
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
                cin >> isbn[i];

                foundIndex = -1;

                for (int j = 0; j < SIZE; j++) {

                    if (strcmp(books[j].ISBN, isbn[i].c_str()) == 0) {

                        foundIndex = j;
                        break;
                    }
                }

                if (foundIndex == -1) {
                    cout << "ISBN not found. Try again." << endl;
                }

            } while (foundIndex == -1);

            //fill in title and price
            title[i] = books[foundIndex].bookTitle;
            price[i] = books[foundIndex].retail;

            cout << "Title: " << title[i] << endl;
            cout << "Price: $" << price[i] << endl;

            if (qty[i] > books[foundIndex].qtyOnHand) {
                cout << "Not enough stock available." << endl;
                return; //exit cashier
            }

            books[foundIndex].qtyOnHand -= qty[i];

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
                << isbn[a] << "    "
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






void bookinfo(char isbn[],
    char title[],
    char author[],
    char publisher[],
    char date[],
    int qty,
    double wholesale,
    double retail)
{
    cout << "\nBook Information\n\n";

    cout << "ISBN: " << isbn << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Date Added: " << date << endl;
    cout << "Quantity: " << qty << endl;

    cout << fixed << setprecision(2);

    cout << "Wholesale: $" << wholesale << endl;
    cout << "Retail: $" << retail << endl;
}