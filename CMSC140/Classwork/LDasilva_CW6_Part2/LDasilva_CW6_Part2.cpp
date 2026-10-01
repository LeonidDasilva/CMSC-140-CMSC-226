/*
* Class: CMSC140 CRN
* Instructor: Prof. Feldman
* Project<6>
* Description: (Give a brief description for Project)
* Due Date: 11/9/25
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Leonid Dasilva
*/

#include <iostream>

//function prototypes
void showMenu();
int getChoice();
double getPrice(int);
double takePurchase(double);
double takePayment();
void displayInfo(double, double);

using namespace std;


//main function, runs all functions within it
int main(){
    int choice;
    double price, payment, purchase;

    //running functions
    showMenu();
    choice = getChoice();
    price = getPrice(choice);
    purchase = takePurchase(price);
    payment = takePayment();
    displayInfo(purchase, payment);

    return 0;
}


//displays a menu
void showMenu() {
    cout << "**** Vending Machine ****" << endl;
    cout << endl;
    cout << "1. Coke   $1.25" << endl;
    cout << "2. Pepsi  $1.00" << endl;
    cout << "3. Water  $3.00" << endl;
    cout << "4. Coffee $1.50" << endl;
    cout << "5. EXIT" << endl;
    cout << endl;
}


//gets user input for choice
int getChoice() {
    int choice;

    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}


//switch statement assigns a price based of user input
double getPrice(int choice) {
    switch (choice) {
        case(1):
           return 1.25;
           break;
         case(2):
           return 1.00;
           break;
       case(3):
           return 3.00;
          break;
       case(4):
          return 1.50;
          break;
        default:
           return 0;
           break;
    }

}

//takes user input for wuantity adn multiplies it by price
double takePurchase(double itemPrice) {
    int quantity;

    cout << "How many do you want: ";
    cin >> quantity;

    return itemPrice * quantity;
}

//takes user input for payment
double takePayment() {
    double payment;

    cout << "How much is your payment: ";
    cin >> payment;

    return payment;
}

//calculates tax, total cost and the change
void displayInfo(double purchase, double payment) {
    double taxRate = 0.06;
    double taxAmount = purchase * taxRate;
    double total = purchase + taxAmount;
    double change = payment - total;

    cout << endl;
    cout << "Tax Amount: $" << taxAmount << endl;
    cout << "Total Purchase: $" << total << endl;
    cout << "Change: $" << change << endl;
}