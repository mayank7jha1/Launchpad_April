#include<iostream>
using namespace std;


int main() {
	int n, tt;
	cin >> n >> tt;
	int a[n];
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	//Maximum Books that you were able to read.
	int MB = 0;

	//Go to every book and treat that book as the
	//starting point.

	for (int s = 0; s < n; s += 1) {
		int tc = 0;
		int cr = 0;//From the book at index s you
		//will be able to read cr books.

		for (int e = s; e < n; e += 1) {
			tc += a[e];
			if (tc > tt) {
				break;
			}
			cr += 1;
		}
		if (cr > MB) {
			MB = cr;
		}
	}

	cout << MB << endl;

}