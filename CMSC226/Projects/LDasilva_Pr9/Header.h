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