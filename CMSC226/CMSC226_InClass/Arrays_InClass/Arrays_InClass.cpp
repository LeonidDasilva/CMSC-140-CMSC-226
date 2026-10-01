#include <iostream>

using namespace std;

void isOdd(int &);

int main(){
	int num[] = { 10, 47, 53, 11 };

	for(int &val : num){
		isOdd(val);
		cout << val << " ";
	}

	return 0;
}

void isOdd(int &num){


		if (num % 2 != 0) {
			num *= 2;
		}

}