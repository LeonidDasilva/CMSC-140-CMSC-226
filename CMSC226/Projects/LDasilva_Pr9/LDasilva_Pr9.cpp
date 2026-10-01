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

class BookData
{
private:
    char bookTitle[51];
    char ISBN[14];
    char author[31];
    char publisher[31];
    char dateAdded[11];

    int qtyOnHand;
    double wholesale;
    double retail;

public:

    BookData()
    {
        memset(this, 0, sizeof(BookData));
    }

    // Mutators
    void setTitle(char* title)
    {
        strcpy_s(bookTitle, title);
    }

    void setISBN(char* isbn)
    {
        strcpy_s(ISBN, isbn);
    }

    void setAuthor(char* name)
    {
        strcpy_s(author, name);
    }

    void setPub(char* pub)
    {
        strcpy_s(publisher, pub);
    }

    void setDateAdded(char* date)
    {
        strcpy_s(dateAdded, date);
    }

    void setQty(int qty)
    {
        qtyOnHand = qty;
    }

    void setWholesale(double cost)
    {
        wholesale = cost;
    }

    void setRetail(double price)
    {
        retail = price;
    }

    // Accessors
    const char* getTitle()
    {
        return bookTitle;
    }

    const char* getISBN()
    {
        return ISBN;
    }

    const char* getAuthor()
    {
        return author;
    }

    const char* getPub()
    {
        return publisher;
    }

    const char* getDateAdded()
    {
        return dateAdded;
    }

    int getQty()
    {
        return qtyOnHand;
    }

    double getWholesale()
    {
        return wholesale;
    }

    double getRetail()
    {
        return retail;
    }

    bool isEmpty()
    {
        return bookTitle[0] == '\0';
    }

    void removeBook()
    {
        memset(this, 0, sizeof(BookData));
    }
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

void repListing()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (!books[i].isEmpty())
        {
            cout << books[i].getTitle() << " | "
                << books[i].getISBN() << " | "
                << books[i].getAuthor() << " | "
                << books[i].getPub() << " | "
                << books[i].getDateAdded() << " | "
                << books[i].getQty() << " | $"
                << books[i].getWholesale() << " | $"
                << books[i].getRetail() << endl;
        }
    }
}

void repWholesale()
{
    double total = 0;

    cout << endl;
    cout << "Wholesale Report\n\n";

    for (int i = 0; i < SIZE; i++)
    {
        if (!books[i].isEmpty())
        {
            cout << books[i].getTitle() << " | "
                << books[i].getISBN() << " | "
                << books[i].getQty() << " | $"
                << books[i].getWholesale() << endl;

            total += books[i].getQty() *
                books[i].getWholesale();
        }
    }

    cout << "\nTotal Wholesale Value: $" << total << endl;

    cin.ignore();
    cin.get();
}

void repRetail()
{
    double total = 0;

    cout << endl;
    cout << "Retail Report\n\n";

    for (int i = 0; i < SIZE; i++)
    {
        if (!books[i].isEmpty())
        {
            cout << books[i].getTitle() << " | "
                << books[i].getISBN() << " | "
                << books[i].getQty() << " | $"
                << books[i].getRetail() << endl;

            total += books[i].getQty() *
                books[i].getRetail();
        }
    }

    cout << "\nTotal Retail Value: $" << total << endl;

    cin.ignore();
    cin.get();
}




void repQty()
{
    int index[SIZE];

    for (int i = 0; i < SIZE; i++)
        index[i] = i;

    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (books[index[j]].getQty() >
                books[index[i]].getQty())
            {
                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }

    cout << "\nInventory by Quantity\n\n";

    for (int i = 0; i < SIZE; i++)
    {
        int k = index[i];

        if (!books[k].isEmpty())
        {
            cout << books[k].getTitle() << " | "
                << books[k].getISBN() << " | "
                << books[k].getQty() << endl;
        }
    }

    cin.ignore();
    cin.get();
}





void repCost()
{
    int index[SIZE];

    for (int i = 0; i < SIZE; i++)
        index[i] = i;

    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (books[index[j]].getWholesale() >
                books[index[i]].getWholesale())
            {
                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }

    cout << "\nInventory by Cost\n\n";

    for (int i = 0; i < SIZE; i++)
    {
        int k = index[i];

        if (!books[k].isEmpty())
        {
            cout << books[k].getTitle() << " | "
                << books[k].getISBN() << " | "
                << books[k].getQty() << " | $"
                << books[k].getWholesale() << endl;
        }
    }

    cin.ignore();
    cin.get();
}





void repAge()
{
    int index[SIZE];

    for (int i = 0; i < SIZE; i++)
        index[i] = i;

    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (strcmp(
                books[index[j]].getDateAdded(),
                books[index[i]].getDateAdded()) < 0)
            {
                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }

    cout << "\nInventory by Age\n\n";

    for (int i = 0; i < SIZE; i++)
    {
        int k = index[i];

        if (!books[k].isEmpty())
        {
            cout << books[k].getTitle() << " | "
                << books[k].getISBN() << " | "
                << books[k].getQty() << " | "
                << books[k].getDateAdded() << endl;
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

    inventoryFile.open(
        INVENTORY_FILE,
        ios::in | ios::binary);

    bool found = false;

    while (inventoryFile.read(
        reinterpret_cast<char*>(&book),
        sizeof(BookData)))
    {
        if (strstr(book.getTitle(), search))
        {
            cout << "\nFound: "
                << book.getTitle()
                << endl;

            cout << "Is this the book? (Y/N): ";
            cin >> answer;

            if (answer == 'Y' || answer == 'y')
            {
                bookinfo(
                    (char*)book.getISBN(),
                    (char*)book.getTitle(),
                    (char*)book.getAuthor(),
                    (char*)book.getPub(),
                    (char*)book.getDateAdded(),
                    book.getQty(),
                    book.getWholesale(),
                    book.getRetail()
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
    inventoryFile.open(
        INVENTORY_FILE,
        ios::in | ios::out | ios::binary);

    BookData book;

    for (int i = 0; i < SIZE; i++)
    {
        inventoryFile.seekg(i * sizeof(BookData));

        inventoryFile.read(
            reinterpret_cast<char*>(&book),
            sizeof(BookData));

        if (book.isEmpty())
        {
            char temp[51];
            char isbn[14];
            char author[31];
            char pub[31];
            char date[11];

            int qty;
            double cost;
            double price;

            cin.ignore();

            cout << "Title: ";
            cin.getline(temp, 51);
            book.setTitle(temp);

            cout << "ISBN: ";
            cin.getline(isbn, 14);
            book.setISBN(isbn);

            cout << "Author: ";
            cin.getline(author, 31);
            book.setAuthor(author);

            cout << "Publisher: ";
            cin.getline(pub, 31);
            book.setPub(pub);

            cout << "Date Added: ";
            cin.getline(date, 11);
            book.setDateAdded(date);

            cout << "Quantity: ";
            cin >> qty;
            book.setQty(qty);

            cout << "Wholesale: ";
            cin >> cost;
            book.setWholesale(cost);

            cout << "Retail: ";
            cin >> price;
            book.setRetail(price);

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

    inventoryFile.open(
        INVENTORY_FILE,
        ios::in | ios::out | ios::binary);

    for (int i = 0; i < SIZE; i++)
    {
        inventoryFile.seekg(i * sizeof(BookData));

        inventoryFile.read(
            reinterpret_cast<char*>(&book),
            sizeof(BookData));

        if (strstr(book.getTitle(), titleSearch))
        {
            bookinfo(
                (char*)book.getISBN(),
                (char*)book.getTitle(),
                (char*)book.getAuthor(),
                (char*)book.getPub(),
                (char*)book.getDateAdded(),
                book.getQty(),
                book.getWholesale(),
                book.getRetail()
            );

            cout << "\nEdit:\n";
            cout << "1. ISBN\n";
            cout << "2. Title\n";
            cout << "3. Author\n";

            cin >> choice;

            cin.ignore();

            char temp[51];

            switch (choice)
            {
            case 1:
                cout << "New ISBN: ";
                cin.getline(temp, 14);
                book.setISBN(temp);
                break;

            case 2:
                cout << "New Title: ";
                cin.getline(temp, 51);
                book.setTitle(temp);
                break;

            case 3:
                cout << "New Author: ";
                cin.getline(temp, 31);
                book.setAuthor(temp);
                break;

            default:
                cout << "Invalid choice.\n";
                inventoryFile.close();
                return;
            }

            // overwrite record
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

        if (strstr(book.getTitle(), search))
        {
            book.removeBook();

            inventoryFile.seekp(
                i * sizeof(BookData));

            inventoryFile.write(
                reinterpret_cast<char*>(&book),
                sizeof(BookData));

            cout << "Deleted.\n";

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

    do
    {
        double subtotal = 0;
        int i = 0;

        cout << "\nSerendipity Book Sellers\n";
        cout << "Cashier Module\n\n";

        do
        {
            cout << "Date: ";
            cin >> date[i];

            cout << "Quantity of Book(s): ";
            cin >> qty[i];

            int foundIndex = -1;

            do
            {
                cout << "ISBN: ";
                cin >> isbn[i];

                for (int j = 0; j < SIZE; j++)
                {
                    if (strcmp(
                        books[j].getISBN(),
                        isbn[i].c_str()) == 0)
                    {
                        foundIndex = j;
                        break;
                    }
                }

                if (foundIndex == -1)
                    cout << "ISBN not found.\n";

            } while (foundIndex == -1);

            title[i] = books[foundIndex].getTitle();

            price[i] = books[foundIndex].getRetail();

            cout << "Title: " << title[i] << endl;
            cout << "Price: $" << price[i] << endl;

            if (qty[i] > books[foundIndex].getQty())
            {
                cout << "Not enough stock.\n";
                return;
            }

            books[foundIndex].setQty(
                books[foundIndex].getQty() - qty[i]);

            subtotal += price[i] * qty[i];

            cout << "Add another book? (Y/N): ";
            cin >> addOrder;

            i++;

        } while ((addOrder == 'Y' || addOrder == 'y') && i < SIZE);

        double tax = subtotal * .06;
        double total = subtotal + tax;

        cout << fixed << setprecision(2);

        cout << "\nQty ISBN Title Price Total\n";
        cout << "---------------------------\n";

        for (int a = 0; a < i; a++)
        {
            cout << qty[a] << " "
                << isbn[a] << " "
                << title[a] << " $"
                << price[a] << " $"
                << price[a] * qty[a]
                << endl;
        }

        cout << "\nSubtotal: $" << subtotal;
        cout << "\nTax: $" << tax;
        cout << "\nTotal: $" << total;

        cout << "\n\nProcess another transaction? (Y/N): ";
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