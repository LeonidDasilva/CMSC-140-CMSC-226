/*
* Class: CMSC140 CRN 22171
* Instructor: Prof. Feldman
* Project 2
* Description: Simulate a simple movie ticket booking system. The program will: Display a list of movies 
available for the day with their ratings (G, PG, PG-13, R, NC-17) and allow the user to select a movie. 
Asking the user their age, amount of tickets purchased, and how much they will pay. All of these inputs will be
checked; If any problems are detected an error will be displayed and the program will end.
* Due Date:10/12/25
* I pledge that I have completed the programming assignment
independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Leonid Dasilva
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    //constants for movie choices
    const int PULP_FICTION = 1, GOONIES = 2, SUPERMAN = 3,
        TOY_STORY = 4, CRASH = 5;

    //constants for ticket prices
    const double ADULT_TICKET_PRICE = 12.00;
    const double CHILD_TICKET_PRICE = 8.00;

    //Constants for minimum ages
    const int AGE_G = 0;
    const int AGE_PG = 7;
    const int AGE_PG13 = 13;
    const int AGE_R = 17;
    const int AGE_NC17 = 18;

    int movieChoice;
    int userAge;
    int minAge;
    int adultTickets;
    int childTickets;

    double totalPrice;
    double tender;
    double change;

    string movieTitle;
    string rating;
    bool allowedEntrance = false;

    cout << "********** Movie Ticket Booking **********" << endl << endl;

    cout << "Today's Movies: " << endl
        << "1. Pulp Fiction - Rated R" << endl
        << "2. Goonies - Rated PG" << endl
        << "3. Superman - Rated PG-13" << endl
        << "4. Toy Story - Rated G" << endl
        << "5. Crash - Rated NC-17" << endl << endl;

    cout << "Please select a movie by entering its number: ";
    cin >> movieChoice;

    if (movieChoice < 1 || movieChoice > 5) {
        cout << "Invalid choice. You must input a number 1–5." << endl;
        return 0;
    }

    //Switch statement to assign title and rating
    switch (movieChoice) {
        case PULP_FICTION:
            movieTitle = "Pulp Fiction";
            rating = "R";
            break;

        case GOONIES:
           movieTitle = "Goonies";
            rating = "PG";
            break;

        case SUPERMAN:
            movieTitle = "Superman";
            rating = "PG-13";
            break;

        case TOY_STORY:
            movieTitle = "Toy Story";
            rating = "G";
            break;

        case CRASH:
            movieTitle = "Crash";
            rating = "NC-17";
            break;

    }

    cout << "\"" << movieTitle << "\" is rated " << rating << endl << endl;

    cout << "Please enter your age: ";
    cin >> userAge;

    if (userAge <= 0) {
        cout << "Age must be greater than zero." << endl;
        return 0;

    }

    //Determine minimum age for the selected film
    if (rating == "G") {
        minAge = AGE_G;
        allowedEntrance = true;
    }
    else if (rating == "PG") {
        minAge = AGE_PG;
        allowedEntrance = (userAge >= minAge);
    }
    else if (rating == "PG-13") {
        minAge = AGE_PG13;
        allowedEntrance = (userAge >= minAge);
    }
    else if (rating == "R") {
        minAge = AGE_R;
        allowedEntrance = (userAge >= minAge);
    }
    else if (rating == "NC-17") {
        minAge = AGE_NC17;
        allowedEntrance = (userAge >= minAge);
    }

    if (!allowedEntrance) {
        cout << "Sorry, you must be at least " << minAge
            << " years old to watch \"" << movieTitle << "\"." << endl;
        return 0;
    }

    cout << endl
        << "How many adult tickets would you like to order? ";
    cin >> adultTickets;

    cout << "How many child tickets would you like to order? ";
    cin >> childTickets;

    if (adultTickets < 0 || childTickets < 0) {
        cout << "Amount of tickets purchased cannot be negative." << endl;
        return 0;
    }

    //Check for children attempting to attend restricted movies
    if (childTickets > 0 &&
        (movieTitle == "Pulp Fiction" || movieTitle == "Crash" || movieTitle == "Superman")) {
        cout << "Children are not allowed to attend this movie." << endl;
        return 0;
    }

    cout << endl << fixed << setprecision(2);

    totalPrice = (adultTickets * ADULT_TICKET_PRICE) +
        (childTickets * CHILD_TICKET_PRICE);

    cout << "Total Price: $" << totalPrice << endl;
    cout << "Please enter the amount you are tendering: $";
    cin >> tender;
    cout << endl;

    if (tender < totalPrice) {
        cout << "Error: Amount tendered is less than the total cost. Transaction cancelled." << endl;
        return 0;
    }

    change = tender - totalPrice;

    cout << "Total amount paid: $" << tender << endl;
    if (change == 0) {
        cout << "You have no change." << endl;
    }
    else {
        cout << "Your change: $" << change << endl;
    }

    cout << "Thank you for purchasing your ticket(s)." << endl << endl;


    cout << "Programmer Name: Leonid Dasilva" << endl
        << "Due date: 10/12/25" << endl
        << "Project Number: 2" << endl
        << "Course: CMSC140  CRN: 22171" << endl;



    return 0;
}
