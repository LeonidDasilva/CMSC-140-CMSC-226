/*
* Class: CMSC140 CRN 22171
* Instructor: Prof. Feldman
* Project<5>
* Description:Program will simulate a magic square using 3 one dimensional parallel
arrays each one the arrays corresponds to a row of the magic square. The program asks
the user to enter the values of the magic square row by row and
informs the user if the grid is a magic square or not.
* Due Date:12/7/25
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Leonid Dasilva
*/


#include <iostream>


using namespace std;

// Global constants  
const int ROWS = 3;
const int COLS = 3;
const int MIN = 1;
const int MAX = 9;

// Function prototypes 
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);

// MAIN FUNCTION
int main()
{
    int row1[COLS], row2[COLS], row3[COLS];
    char again;


    // do whiule loop will continue to run magic square program until user input
    do {
        fillArray(row1, row2, row3, COLS);
        showArray(row1, row2, row3, COLS);



        // initializing vars through functions
        bool inRange = checkRange(row1, row2, row3, COLS, MIN, MAX);
        bool unique = checkUnique(row1, row2, row3, COLS);
        bool row = checkRowSum(row1, row2, row3, COLS);
        bool col = checkColSum(row1, row2, row3, COLS);
        bool diag = checkDiagSum(row1, row2, row3, COLS);


        //tells the user properties of their magic square
        cout << "is in range: " << inRange << endl;
        cout << "is unique: " << unique << endl;
        cout << "is equal rows: " << row << endl;
        cout << "is equal cols: " << col << endl;
        cout << "is equal diag: " << diag << endl;

        // tells user if they made a magic square or not
        if (isMagicSquare(row1, row2, row3, COLS))
            cout << "This is a magic square" << endl;
        else
            cout << "This is not a magic square" << endl;


        cout << endl;

        cout << "Do you want to try again? ";
        cin >> again;

        cout << endl;

    } while (again == 'y' || again == 'Y');

    cout << " Programmer name: Leonid Dasilva" << endl <<
        "Project Num: 5" << endl << "Due Date: 12/7/25" << endl <<
        "CRN: 22171" << endl;

    return 0;
}



// FUNCTION DEFINITIONS

// fill array function will ask user to input each array element
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{

    for (int i = 0; i < size; i++) {
        cout << "Enter the number for row 0 column " << i << ": ";
        cin >> arrayRow1[i];
    }

    for (int i = 0; i < size; i++) {
        cout << "Enter the number for row 1 column " << i << ": ";
        cin >> arrayRow2[i];
    }

    for (int i = 0; i < size; i++) {
        cout << "Enter the number for row 2 column " << i << ": ";
        cin >> arrayRow3[i];
    }
}

// showArray function will output the user made array
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arrayRow1[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < size; i++) {
        cout << arrayRow2[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < size; i++) {
        cout << arrayRow3[i] << " ";

    }

    cout << endl;

}



// checkRange function will make sure that all user inputs are within the range of the arrays
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{
    for (int i = 0; i < size; i++) {
        if (arrayRow1[i] < min || arrayRow1[i] > max) {
            return false;
        }

        if (arrayRow2[i] < min || arrayRow2[i] > max) {
            return false;
        }

        if (arrayRow3[i] < min || arrayRow3[i] > max) {
            return false;
        }
    }
    return true;
}


// checkUnique function will check to make sure that each inputted element is different from others
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    int a = arrayRow1[0], b = arrayRow1[1], c = arrayRow1[2];
    int d = arrayRow2[0], e = arrayRow2[1], f = arrayRow2[2];
    int g = arrayRow3[0], h = arrayRow3[1], i = arrayRow3[2];

    if (a == b || a == c || a == d || a == e || a == f || a == g || a == h || a == i) {
        return false;
    }
    if (b == c || b == d || b == e || b == f || b == g || b == h || b == i) {
        return false;
    }
    if (c == d || c == e || c == f || c == g || c == h || c == i) {
        return false;
    }
    if (d == e || d == f || d == g || d == h || d == i) {
        return false;
    }
    if (e == f || e == g || e == h || e == i) {
        return false;
    }
    if (f == g || f == h || f == i) {
        return false;
    }
    if (g == h || g == i) {
        return false;
    }
    if (h == i) {
        return false;
    }
    return true;
}

// checkRowSum function checks that the sum of each row is equal
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    int sum1 = 0, sum2 = 0, sum3 = 0;

    for (int i = 0; i < size; i++) {
        sum1 += arrayRow1[i];
        sum2 += arrayRow2[i];
        sum3 += arrayRow3[i];
    }

    return (sum1 == sum2 && sum2 == sum3);
}


// checkColSum function checks that the sum of each column is equal
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    int s0 = arrayRow1[0] + arrayRow2[0] + arrayRow3[0];
    int s1 = arrayRow1[1] + arrayRow2[1] + arrayRow3[1];
    int s2 = arrayRow1[2] + arrayRow2[2] + arrayRow3[2];

    return (s0 == s1 && s1 == s2);
}

// checkDiagSum function checks that the sum of each Diagonal line across arrays is equal
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    int d1 = arrayRow1[0] + arrayRow2[1] + arrayRow3[2];
    int d2 = arrayRow1[2] + arrayRow2[1] + arrayRow3[0];

    return (d1 == d2);
}

// isMagicSquare functions uses all prior functions to give user information on the magic square
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    return checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX) &&
        checkUnique(arrayRow1, arrayRow2, arrayRow3, size) &&
        checkRowSum(arrayRow1, arrayRow2, arrayRow3, size) &&
        checkColSum(arrayRow1, arrayRow2, arrayRow3, size) &&
        checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size);
}
