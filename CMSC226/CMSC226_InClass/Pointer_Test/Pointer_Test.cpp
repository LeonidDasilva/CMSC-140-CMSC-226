#include <iostream>

using namespace std;

int main()
{
    int vals[] = { 4, 7, 11 };

    int num = -99;

    //pointer pointing to nowhere
    int* intptr = nullptr;
    intptr = &num;

    //address of vals array
    int* valptr = vals;

    cout << valptr[1] << endl;
    cout << *(valptr + 1) << endl;
    cout << *valptr << endl;
    cout << *(valptr + 2) << endl;
    cout << valptr << endl;
    
    cout << endl;
    
    cout << intptr << endl;
    cout << *intptr << endl;
    cout << &num << endl;

    *intptr = 100;

    cout << *intptr << endl;
}
