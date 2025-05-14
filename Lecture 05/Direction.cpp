/*
	A person wants to go from origin to a
	particular location, he can move in only
	4 directions(i.e. East, West, North, South)
	but his friend gave him a long route, help a
	person to find minimum Moves so that he can
	reach to the destination.

	Input  1 – NESNWES
	Output 1 – E

	You need to print the lexicographically(dic order)
	sorted string. Assume the string will have only
	‘E’ ‘N’ ‘S’ ‘W’ characters.


	Input  2 – SSSNEEEW
	Output 2 – EESS

*/


#include<iostream>
using  namespace std;

int main() {
	char ch;
	int x = 0, y = 0;

	while (cin >> ch) {

		if (ch == 'N') {
			y += 1;
		} else if (ch == 'S') {
			y -= 1;
		} else if (ch == 'E') {
			x += 1;
		} else {
			x -= 1;
		}
	}

	cout << x << " " << y << endl;

	if (x > 0) {

		/*
			I will have to print E first and
			then the other direction.
			Print Magnitude times of x --> E.
			According to value of y print either
			N or S.
		*/

		//For Printing E.
		int i = 1;
		while (i <= x) {
			cout << 'E';
			i += 1;
		}

		//For Printing Either N or S.
		if (y > 0) {
			//I have to Print N.
			int j = 1;
			while (j <= y) {
				cout << 'N';
				j += 1;
			}

		} else {
			//I have to Print S.
			y = y * (-1);
			int k = 1;
			while (k <= y) {
				cout << 'S';
				k += 1;
			}
		}

	} else {

		/*
			I will have to print the other
			direction first and then W.
			According to value of y print N or S.
			Print the magnitude times of x --> W.
		*/

		//For Printing Either N or S.
		if (y > 0) {
			//I have to Print N.
			int l = 1;
			while (l <= y) {
				cout << 'N';
				l += 1;
			}

		} else {
			//I have to Print S.
			y = y * (-1);
			int m = 1;
			while (m <= y) {
				cout << 'S';
				m += 1;
			}
		}


		x = x * (-1);

		//For Printing W.
		int i = 1;
		while (i <= x) {
			cout << 'W';
			i += 1;
		}

	}
}



















