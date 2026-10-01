/*
 * Class: CMSC140 CRN: 22171
 * Instructor: Prof. Feldman
 * Project 1
 * Description: The user needs to calculate the profit made after buying and
 selling the stock, including the commissions paid to the broker.
 The program will prompt the user to enter information about the
 purchased/sold stock. After the user enters this information,
 the Program calculates the profit.
 * Due Date:9/28/25
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Leonid Dasilva
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //Decleraton for Project information
    const string PROGRAMMER_NAME = "Programmer name: Leonid Dasilva \n";
    const string COURSE = "Course: CMSC 140 CRN: 22171 \n";
    const string SEMESTER = "Semester: Fall 2025 \n";
    string dueDate = "Due Date: Sunday, September 28th \n";

    //Decleration for communication with user
    string fullName;
    string companyName;

    int purchasedShares;
    int soldShares;

    double brokerageCommissionBuy;
    double brokerageCommissionSell;
    double purchasedSharePrice;
    double soldSharePrice;

    //Decleration for final details
    double totalPurchasePrice;
    double totalPurchaseCommission;
    double totalSalePrice;
    double totalSaleCommission;
    double totalProfit;


    cout << "********** Welcome to Stock Transaction Program********** \n";

    //Communication with user about purchased stocks
    cout << "Hello! What is your name? \n";
    getline(cin, fullName);
    cout << "Nice to meet you, " << fullName << "! This is a Stock Transaction Program." <<
        endl << "It will help you calculate profit from a single stock transaction. \n";
    cout << endl;
    cout << "Which company share did you buy? \n";
    cin >> companyName;
    cout << "How many shares did you purchase? \n";
    cin >> purchasedShares;
    cout << "What was the price per share? \n";
    cin >> purchasedSharePrice;
    cout << "What is the brokerage commission rate for buying this stock? " <<
        endl << "(as a percentage: so 2 means 2 percent) \n";
    cin >> brokerageCommissionBuy;

    cout << endl;

    //Communicating with user about sold stocks
    cout << "That's great, " << fullName << "! How many shares did you sell? \n";
    cin >> soldShares;
    cout << "What was the stock price? \n";
    cin >> soldSharePrice;
    cout << "What is the brokerage commission rate for selling this stock? \n";
    cin >> brokerageCommissionSell;

    cout << endl;

    //Final Calculations for chart
    totalPurchasePrice = (purchasedShares * purchasedSharePrice);
    totalPurchaseCommission = totalPurchasePrice * (brokerageCommissionBuy / 100.0);
    totalSalePrice = (soldShares * soldSharePrice);
    totalSaleCommission = totalSalePrice * (brokerageCommissionSell / 100.0);
    totalProfit = (totalSalePrice - totalSaleCommission) - (totalPurchasePrice + totalPurchaseCommission);

    //Transaction Details
    cout << "Here are the details of the transaction: \n";
    cout << setprecision(2) << fixed;
    cout << endl;
    cout << "Purchase Price:           $" << setw(9) << totalPurchasePrice << endl;
    cout << "Purchase Commission:      $" << setw(9) << totalPurchaseCommission << endl;
    cout << "Sale Price:               $" << setw(9) << totalSalePrice << endl;
    cout << "Sale Commission:          $" << setw(9) << totalSaleCommission << endl;
    cout << "Profit:                   $" << setw(9) << totalProfit << endl;

    cout << endl;

    cout << "Thank you for participating, " << fullName << "! \n";
    cout << endl;

    //Project & Programmer Info
    cout << PROGRAMMER_NAME;
    cout << COURSE;
    cout << SEMESTER;
    cout << dueDate;

    return 0;
}