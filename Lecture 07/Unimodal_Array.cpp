#include<iostream>
using  namespace std;


/*
	0th 1st 2nd 3rd 4th

	7 8 7 8

	_ 0 2 0


	second array me b[i]<b pichle element se false.



	Increasing: 0
	Constant: 1
	Decreasing: 2







*/

int main() {
	int n;
	cin >> n;
	int a[n];
	int b[n];

	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i += 1) {

		if (a[i] > a[i - 1]) {
			b[i] = 0;//Increasing
		} else if (a[i] == a[i - 1]) {
			b[i] = 1;//Constant
		} else {
			b[i] = 2;//Decreasing
		}
	}


	//Idea:

	//Hints: Try to compare with the previous Element.
	//Try to print the false condition first.


	//Prove by Contradiction
	//Traversal

	//Since b[0] is garbage I am starting frrom
	//2 index as I want to compare b[2] with b[1]
	//if i had started the loop from 1 that would
	//mean I am comparing b[1] with b[0] and since
	//b[0] is garbage that will not make sense.

	for (int i = 2; i < n; i += 1) {
		if (b[i] < b[i - 1]) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

}