/*
* Class: CMSC140 CRN
* Instructor: Prof. Feldman
* Project 3
* Description: (Give a brief description for Project)
* Due Date: 9/21/25
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Leonid Dasilva
*/
#include <iostream>
#include <string>

using namespace std;


int main()
{
	//Decleration Section
	string fullName;

	double averageScore;

	int totalScore;
	int syllabusQuiz;
	int chapterOneQuiz;
	int chapterTwoQuiz;
	int programmingClassworkOne;
	int programmingClassworkTwo;


	//Asking for and storing user input for scores
	cout << "Student full name: ";
	getline(cin, fullName);
	cout << "Score on the Syllabus Quiz (0-100): ";
	cin >> syllabusQuiz;
	cout << "Score on the Chapter 1 Quiz (0-100): ";
	cin >> chapterOneQuiz;
	cout << "Score on the Chapter 2 Quiz (0-100): ";
	cin >> chapterTwoQuiz;
	cout << "Score on Programming Classwork 1 (0-100): ";
	cin >> programmingClassworkOne;
	cout << "Score on the Programming Classwork 2 (0-100): ";
	cin >> programmingClassworkTwo;

	//Calculates total
	totalScore = syllabusQuiz + chapterOneQuiz + chapterTwoQuiz +
		programmingClassworkOne + programmingClassworkTwo;

	//Calculates average
	averageScore = (syllabusQuiz + chapterOneQuiz + chapterTwoQuiz +
		programmingClassworkOne + programmingClassworkTwo) / 5;

	//Final output
	cout << fullName << ": " << "Final Score: " << totalScore <<
		" Average Score: " << averageScore << endl;

	return 0;
}