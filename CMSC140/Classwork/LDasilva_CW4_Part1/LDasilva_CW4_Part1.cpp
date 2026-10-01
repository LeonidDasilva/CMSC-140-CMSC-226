/*
* Class: CMSC140 CRN
* Instructor:
* Project 4
* Description: Develop a program that asks for the number of tickets 
sold and computes the total cost of the purchase at Walt Disney World.
* Due Date:
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Leonid Dasilva
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	const int TICKET_PRICE = 109;
	int daysSold;

	double cost;
	double discount;

	cout << "How many days of tickets were sold?";
	cin >> daysSold;

	cout << setprecision(2) << fixed;

		if (daysSold <= 0){
			cout << "Tickets sold must be greater than Zero.";
		}
		else {
			if (daysSold == 3 || daysSold == 4) {
				discount = 1;
			}
			if (daysSold == 5 || daysSold == 6) {
				discount = 25;
			}
			if (daysSold >= 7 || daysSold <= 9) {
				discount = 33;
			}
			if (daysSold >= 10) {
				discount = 42;
			}

			cost = (TICKET_PRICE * daysSold) * (1.0 - discount / 100.00);

			cout << "The total cost of the purchase is: $" << cost;
		}


	return 0;
}