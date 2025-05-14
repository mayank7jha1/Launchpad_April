#include<iostream>
#include"mayank.h"
#include"../Lecture 05/samyak.h"
using  namespace std;

//Function Definition
int sum(int x, int y) {
	// int ans = x + y;
	// return ans;

	return (x + y);
}

//Function Prototype
int diff(int, int);

int main() {

	int x, y;
	cin >> x >> y;

	cout << sum(x, y) << endl;
	cout << diff(x, y) << endl;
	check();
	check1();
}

//Function Definition
int diff(int x, int y) {
	return x - y;
}







