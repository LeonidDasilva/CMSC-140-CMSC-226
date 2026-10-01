/*
* Class: CMSC140 CRN
* Instructor:
* Project<5>
* Description: Program asks user for inputs and print inputs into a .txt file.
* Due Date:
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Leonid Dasilva
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

	ofstream outputFile;

	string name;
	string phoneNum;
	string address;
	string city;
	string state;

	int zipCode;

	//read user input
	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Enter your phone number: ";
	getline(cin, phoneNum);
	cout << "Enter your street address: ";
	getline(cin, address);
	cout << "Enter your city: ";
	getline(cin, city);
	cout << "Enter your state: ";
	getline(cin, state);
	cout << "Enter your zip code: ";
	cin >> zipCode;

	cout << endl;

	cout << "This is your information: " << endl;

	cout << endl;

	outputFile.open("List.txt");

	//write user input into .txt
	outputFile << name << endl;
	cout << "Name: " << name << endl;
	outputFile << phoneNum << endl;
	cout << "Phone Number: " << phoneNum << endl;
	outputFile << address << endl;
	outputFile << city << endl;
	outputFile << state << endl;
	outputFile << zipCode << endl;
	cout << "Address: " << address << endl;
	cout << setw(9) << " " << city << ", " << state << ", " << zipCode << endl;

	outputFile.close();

	return 0;
}
