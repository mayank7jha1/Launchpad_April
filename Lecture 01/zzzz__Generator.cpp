#include<iostream>
using  namespace std;

int main() {
	srand(time(0));
	int a = 1 + rand() % 11;
	int b = 1 + rand() % 21;

	cout << a << " " << b << endl;
}