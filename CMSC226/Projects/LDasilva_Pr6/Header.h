#pragma once
#include <string>

using namespace std;

void bookinfo(char isbn[],
    char title[],
    char author[],
    char publisher[],
    char date[],
    int qty,
    double wholesale,
    double retail);
void cashier();
void invmenu();
void lookUpBook();
void addBook();
void editBook();
void deleteBook();
void reports();
void repListing();
void repWholesale();
void repRetail();
void repQty();
void repCost();
void repAge();
void strUpper(char* str);
void setTitle(char* title, int index);
void setISBN(char* isbn, int index);
void setAuthor(char* name, int index);
void setPub(char* pub, int index);
void setDateAdded(char* date, int index);
void setQty(int qty, int index);
void setWholesale(double cost, int index);
void setRetail(double price, int index);
int isEmpty(int index);
void removeBook(int index);