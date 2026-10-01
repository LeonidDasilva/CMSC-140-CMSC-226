/*
* Class: CMSC140 CRN
* Instructor: Prof. Feldman
* Project 2
* Description:Program will display my name, address; house #, street, city,
state, ZIP code, my telephone number, and my college degree.
* Due Date: 9/14/25
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Leonid Dasilva
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string NAME = "Leonid Dasilva";   
    const string MAJOR = "Computer Science";

    string address = "19039 Red Robin Ter. MD 20874";
    string phoneNum = "301-500-7155";

    cout << NAME << endl << address << endl << MAJOR << endl << phoneNum;

    return 0;
}

