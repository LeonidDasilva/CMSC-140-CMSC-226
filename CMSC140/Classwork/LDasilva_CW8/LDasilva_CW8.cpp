/*
* Class: CMSC140 CRN 22171
* Instructor: Prof. Feldman
* Project<8>
* Description: Program reads as many test scores as the user inputs.Then the program will
print the scores in: original order, sorted from high to low, the highest score,
the lowest score, and the average of the scores.
* Due Date: 12/14/25
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Leonid Dasilva
*/

#include <iostream>


using namespace std;

//Function prototypes
void displayArray(int array[], int size);
void selectionSort(int array[], int size);
int findMax(int array[], int size);
int findMin(int array[], int size);
double findAvg(int array[], int size);



int main()
{
    //constant variable for maximum array size
    const int MAX_SIZE = 50;

    int scores[MAX_SIZE];
    int size;

    cout << "How many scores do you want to enter: ";
    cin >> size;

    //validation to make sure user input does not exceed maximum size of 50
    while (size <= 0 || size > MAX_SIZE)
    {
        cout << "Please enter a number between 1 and 50!" << endl;
        cout << endl;
        cout << "How many scores do you want to enter: ";
        cin >> size;
    }

    //input validation for a positive input in each array element
    for (int i = 0; i < size; i++){
        cout << "Enter score #" << i + 1 << ": ";
        cin >> scores[i];

        while (scores[i] <= 0)
        {
            cout << "Only enter a positive score: ";
            cin >> scores[i];
        }
    }

    //display original order of array
    cout << endl;
    cout << "Original order scores are: ";
    displayArray(scores, size);

    /*
    * find min, max, and average from the unsorted array
    * assign function output to a variable
    */
    int highest = findMax(scores, size);
    int lowest = findMin(scores, size);
    double average = findAvg(scores, size);

    //sort the array in descending order
    selectionSort(scores, size);

    cout << endl;

    //display the sorted scores
    cout << endl;
    cout << "Scores order high to low: ";
    displayArray(scores, size);
    
    cout << endl;


    /*
    * Display:
    * Highest score
    * Lowest score
    * Average score
    */
    cout << endl;
    cout << "Highest score: " << highest << endl;
    cout << endl;
    cout << "Lowest score: " << lowest << endl;
    cout << endl;
    cout << "Average score: " << average << endl;
    cout << endl;

    return 0;
}


// displayArray function will print each element of array
void displayArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}


//sorts the array in descending order using selection sort
void selectionSort(int array[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        int maxIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (array[j] > array[maxIndex])
            {
                maxIndex = j;
            }
        }

        int temp = array[i];

        array[i] = array[maxIndex];
        array[maxIndex] = temp;
    }
}

//Finds and returns the highest element in the array
int findMax(int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}


//finds and returns the lowest element in an array
int findMin(int array[], int size)
{
    int min = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
            min = array[i];
    }
    return min;
}


// finds and returns the average element in an array
double findAvg(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return static_cast<double>(sum) / size;
}
