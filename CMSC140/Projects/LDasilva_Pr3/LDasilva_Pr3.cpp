/*

 * Class: CMSC140 CRN 22171
 * Instructor: Prof. Feldman
 * Project 3
 * Description:  Program that checks the occupancy of the  BlueMont Hotel
 * Due Date: 11/2/25
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Full Name here:
*/


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//constants for rates & floors
	const int SINGLE_RATE = 60;
	const int DOUBLE_RATE = 75;
	const int KING_RATE = 100;
	const int SUITE_RATE = 150;
	const int MAX_FLOORS = 5;
	const int MAX_ROOMS = 30;

	const int WIDTH_ONE = 65;
	const int WIDTH_TWO = 22;
	const int WIDTH_THREE = 15;

	string location;
	string postFix;
	string minPostFix;

	int numFloors, floor, numRooms, occSingle= 0, occDouble = 0, occKing = 0, occSuite = 0,
		totalRooms = 0, totalOccupied = 0, unoccupiedRooms = 0, minRooms, minFloor;

	double incomeFloor, totalIncome = 0, occupancyRate = 0;

	
	cout << "========================================================================================================================" << endl <<
		setw(WIDTH_ONE) << "Bluemont Hotel" << endl << 
		"========================================================================================================================" << endl;

	cout << endl;

	cout << "Enter the location of this hotel chain: ";
	getline(cin, location);

	cout << "Enter the total number of floors in the hotel: ";
	cin >> numFloors;
	cout << endl;

	//while loop checks if user inputs proper amount of floors
	while (numFloors <= 0 || numFloors > MAX_FLOORS) {
		cout << "Number of floors must be between 1 and 5!! Please try again.";
		cin >> numFloors;
		cout << endl;
	}

	//For loop runs for total amount of floors
	for (int floor = 1; floor <= numFloors; floor++) {

		//if staements to see what postfix should be used
		if (floor == 1) postFix = "st";
		else if (floor == 2) postFix = "nd";
		else if (floor == 3) postFix = "rd";
		else postFix = "th";

		cout << "Enter the total number of rooms on the " << floor << postFix << " floor: ";
		cin >> numRooms;
		cout << endl;

		//while loop validation to make sure user inputs proper amount of rooms
		while (numRooms <= 0 || numRooms > MAX_ROOMS) {
			cout << "Number of rooms should be between 1 and 30! Please try again: ";
			cin >> numRooms;
		}

		//Finds minumum rooms
		if (floor == 1 || numRooms < minRooms) {
			minRooms = numRooms;
			minFloor = floor;
		}

		occSingle = occDouble = occKing = occSuite = 0;

		//Find amount of occupied rooms
		cout << "How many SINGLE rooms are occupied on the " << floor << postFix << " floor: ";
		cin >> occSingle;
		cout << "How many DOUBLE rooms are occupied on the " << floor << postFix << " floor: ";
		cin >> occDouble;
		cout << "How many KING rooms are occupied on the " << floor << postFix << " floor: ";
		cin >> occKing;
		cout << "How many SUITE rooms are occupied on the " << floor << postFix << " floor: ";
		cin >> occSuite;

		//Keep asking for occupied rooms if user inputs more than 30
		while ((occSingle + occDouble + occKing + occSuite) > numRooms) {
			cout << "Total occupied rooms exceed total rooms! Please re-enter:\n";
			cout << "How many SINGLE rooms are occupied on the " << floor << postFix << " floor: ";
			cin >> occSingle;
			cout << "How many DOUBLE rooms are occupied on the " << floor << postFix << " floor: ";
			cin >> occDouble;
			cout << "How many KING rooms are occupied on the " << floor << postFix << " floor: ";
			cin >> occKing;
			cout << "How many SUITE rooms are occupied on the " << floor << postFix << " floor: ";
			cin >> occSuite;
		}

		//Find total amount of occupied rooms
		totalOccupied += occSingle + occDouble + occKing + occSuite;
		//Found income per floor
		incomeFloor = (occSingle * SINGLE_RATE) + (occDouble * DOUBLE_RATE) + (occKing * KING_RATE) + (occSuite * SUITE_RATE);
		//find the total income for the hotel
		totalIncome += incomeFloor;
		//find total amount of floor
		totalRooms += numRooms;
	}


	cout << endl;
	cout << endl;

	//Output formatted hotel information 
	cout << "========================================================================================================================" << endl;
	cout << setw(WIDTH_ONE) << "Bluemont Hotel located in " << location << endl;
	cout << setw(WIDTH_ONE) << "TODAY'S ROOM RATES (US$)" << endl;
	cout << setw(WIDTH_TWO) << "Single Room" << setw(WIDTH_TWO) << "Double Room" << setw(WIDTH_TWO) << "King Room" << setw(WIDTH_TWO) << "Suite Room" << endl;
	cout << setw(WIDTH_TWO) << SINGLE_RATE << setw(WIDTH_TWO) << DOUBLE_RATE << setw(WIDTH_TWO) << KING_RATE << setw(WIDTH_TWO) << SUITE_RATE << endl;
	cout << "========================================================================================================================" << endl;

	//find amount of unoccupied rooms and the occupancy rate
	unoccupiedRooms = totalRooms - totalOccupied;
	occupancyRate = (static_cast<double>(totalOccupied) / totalRooms) * 100;

	//output information based of user input
	cout << setw(WIDTH_THREE) << " " << "Hotel Income: " << setw(5) << " " << "$" << totalIncome << endl;
	cout << setw(WIDTH_THREE) << " " << "Total # of rooms: " << setw(5) << " " << totalRooms << endl;
	cout << setw(WIDTH_THREE) << " " << "Total # of occupied rooms: " << setw(5) << " " << totalOccupied << endl;
	cout << setw(WIDTH_THREE) << " " << "Total # of unoccupied rooms: " << setw(5) << " " << unoccupiedRooms << endl;
	cout << setw(WIDTH_THREE) << " " << "Occupancy rate: " << setw(5) << " " << occupancyRate << endl;

	//find postfix for floor #
	if (minFloor == 1) {
		minPostFix = "st";
	}
	else if (minFloor == 2) {
		minPostFix = "nd";
	}
	else if (minFloor == 3) {
		minPostFix = "rd";
	}
	else {
		minPostFix = "th";
	}

	cout << minFloor << minPostFix << " floor with " << minRooms << " rooms has the least number of rooms.\n";

	if (occupancyRate < 60.00) {
		cout << "Occupancy rate too low!! Increase the occupancy rate!!" << endl;
	}

	cout << endl;
	cout << endl;

	//programmer info
	cout << "Thank you, for testing my program!" << endl;
	cout << "Programmer: Leonid Dasilva" << endl;
	cout << "CSMC 140 CRN 22171" << endl;
	cout << "Due Date: 11/2/25" << endl;




	return 0;
}
