// Factorial_Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int factorial(int n);

int main()
{
    int input;

    cout << "Enter a number to get a factorial: ";
    cin >> input;

    cout << "The factorial is: " << factorial(input) << endl;
}

int factorial(int n) {
    int result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
