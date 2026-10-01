/* Class: CMSC140 CRN
* Instructor : Prof. Feldman
* Project<number>
* Description : (Give a brief description for Project)
* Due Date : 11/4/25
 I pledge that I have completed the programming assignment independently.
 I have not copied the code from a student or any source.
 I have not given my code to any student.
 Print your Name here : Leonid Dasilva
*/

#include <iostream>


/*
* Function prototypes
*/
int getChoice();
bool validateChoice(int);
void getNumbers(int&, int&);
int addition(int, int);
int subtraction(int, int);


using namespace std;

/*
* Main Function to run all other functions
*/
int main()
{
    int choice, num1, num2, result;
    
    //gets user choice
    choice = getChoice();
    getNumbers(num1, num2);

    if (choice == 1) {
        result = addition(num1, num2);
    }
    else {
        result = subtraction(num1, num2);
    }

    cout << "The result of the operation is " << result << endl;

    return 0;
}


//Function will collect and return the users choice
int getChoice() {
    int choice;

    cout << "Enter your choice, 1 for addition and 2 for subtraction: ";
    cin >> choice;

    cout << endl;

    //using the validateChoice function to see if the user needs to 
    //input another choice
    while (!validateChoice(choice)) {
        cout << "Enter your choice, 1 for addition, 2 for subtraction: ";
        cin >> choice;
    }

    return choice;
}

//return a bool based off user input
bool validateChoice(int input) {

    if (input == 1 || input == 2) {
        return true;
    }

    cout << "Invalid choice of operation. Try Again." << endl;
    return false;
}


//gets user input for two numbers
void getNumbers(int &num1, int &num2) {

    cout << "Enter your first number: ";
    cin >> num1;
    cout << "Enter your second number: ";
    cin >> num2;

    cout << endl;

}

//adds user inputted numbers
int addition(int first, int second) {
    return first + second;
}

//subtracts user inputted numbers
int subtraction(int first, int second) {
    return first - second;
}
