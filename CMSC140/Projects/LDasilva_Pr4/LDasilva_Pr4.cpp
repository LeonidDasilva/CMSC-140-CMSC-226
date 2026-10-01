/*
* Class: CMSC140 CRN 22171
* Instructor: Prof. Feldman
* Project<4>
* Description: A program that calculates the average number of days
a company's employees are absent during the year and outputs a
file named "employeeAbsences.txt". 
* Due Date: 11/16/25
* I pledge that I have completed the programming assignment
independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Leonid Dasilva
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int getNumEmployees();
int getTotalAbsent(int);


int main()
{
    string userName;

    int numEmployees , totalDaysAbsent;

    double averageAbsent;

    ofstream outputfile("employeeAbsences.txt");
    
    outputfile << "Employee Absence Report" << endl;


    cout << "Enter your name: ";
    cin >> userName;

    cout << endl;

    cout << "Calculate the average number of days a company's employees are absent." << endl;
    cout << endl;

    numEmployees = getNumEmployees();

    getTotalAbsent(numEmployees);



    programmerInfo();

    return 0;
}

int getNumEmployees() {
    int numEmployees;

    cout << "Please enter the number of employees in the company: " << endl;
    cin >> numEmployees;
    while (numEmployees < 1) {
        cout << "Number of employees can not be less than one. " << endl;
        cout << endl;
        cout << "Please enter the number of employees in the company: " << endl;
        cin >> numEmployees;
    }

    return numEmployees;
}

int getTotalAbsent(int numEmployees) {
    ofstream outputfile("employeeAbsences.txt");

    int empID, daysMissed, totalDaysAbsent;

    for (int i = 0; i < numEmployees; i++) {
        cout << "Please Enter an Employee ID: ";
        cin >> empID;
        cout << "Please enter the number of days this employee was absent: ";
        cin >> daysMissed;

        if (daysMissed < 0) {
            cout << "The number of days must not be negative." << endl;
            cout << endl;
        }

    }

    outputfile.close();

    return totalDaysAbsent;
}

void programmerInfo() {
    cout << "Programmer: name " << endl;
    cout << "CSMC 140 CRN 22171" << endl;
    cout << "Due Date 11/16/25" << endl;
}