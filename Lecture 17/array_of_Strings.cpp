#include<iostream>
using namespace std;


int main() {



	// int a[3][4];
	// char b[3][4];

	//Array of Strings.
	/*
		Every c[i] will be a string.

		cout<<c[i];
		Matlab hain ek string ko print karva rahe ho.

		c[i][3]: This is now a character.

	*/

	int n;
	cin >> n;
	string c[n];

	for (int i = 0; i < n; i += 1) {
		cin >> c[i];
	}

	sort(c, c + n);

	for (int i = 0; i < n; i += 1) {
		sort(c[i].begin(), c[i].end());
		cout << c[i] << " ";
	}

	cout << c[2] << endl;
	cout << c[2][1] << endl;




}