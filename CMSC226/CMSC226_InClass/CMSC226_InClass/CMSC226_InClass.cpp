//Program will include two function to find areaand find perimiter

#include <iostream>
#include <cmath>

using namespace std;

double PI = 3.14;

double cirArea(double);
double cirPerim(double);

int main()
{
	double radius;

	cout << "What is the circle radius: ";
	cin >> radius;

	cout << "Circle Area is: " << cirArea(radius) << endl;
	cout << "Circle Perimeter is: " << cirPerim(radius) << endl;


	return 0;
}

double cirArea(double r){
	double area;

	area = PI * pow(r, 2);

	return area;
}

double cirPerim(double r){
	double perim;

	perim = 2 * PI * r;
	
	return perim;
}
