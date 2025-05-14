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



















