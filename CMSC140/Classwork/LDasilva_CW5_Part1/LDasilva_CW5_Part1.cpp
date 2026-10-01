/*
* Class: CMSC140 CRN
* Instructor:
* Project<5>
* Description: Print out bullet points in rows using a while, do-while, and for loop.
* Due Date:
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Leonid Dasilva
*/

#include <iostream>

using namespace std;

int main()
{
    int loopOne = 0;
    int loopTwo = 0;
    int loopThree = 10;
    int loopFour = 20;
    int loopFive = 0;
    int loopSix = 0;




    cout << "(I)" << endl;
    while (loopOne < 10) {

        cout << "*";
        loopOne++;
    }

    cout << endl;
    cout << endl;

    cout << "(II)" << endl;
    do {
        cout << "*";
        loopTwo++;
    } while (loopTwo < 20);

    cout << endl;
    cout << endl;

    cout << "(III)" << endl;
    for (int i = 1; i < loopThree; i++) {

        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;

    cout << "(IV)" << endl;
    for (int u = 1; u < loopFour; u++) {
        for (int p = 1; p <= u; ++p) {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;

    cout << "(V)" << endl;
    for (int g = 10; g > 0; g--) {
        for (int h = 0; h < g; h++) {
            cout << "*";
        }
        cout << endl;
    }


    cout << endl;
    cout << endl;

    cout << "(VI)" << endl;
    for (int c = 20; c > 0; c--) {
        for (int x = 0; x < c; x++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
