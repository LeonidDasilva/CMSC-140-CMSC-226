// FileExtension_Getter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string extGetter(string);

int main()
{
    string fileName;

    cout << "Enter a file name: ";
    getline(cin, fileName);

    cout << extGetter(fileName);
}

string extGetter(string fileName)
{
    char cstr[100];
    strcpy(cstr, fileName.c_str());

    char* dot = strchr(cstr, '.');

    return string(dot + 1);
}