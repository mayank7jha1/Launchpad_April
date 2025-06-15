#include<iostream>
using namespace std;


int main() {
	int n, tt;
	cin >> n >> tt;
	int a[n];
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}


	int MB = 0;
	int s = 0;
	int tc = 0;

	for (int e = 0; e < n; e += 1) {
		tc += a[e];//Expansion

		//If you are not in the desired window shink
		//from the back.

		//Shrink:
		while (s <= e and tc > tt) {
			//We need to shrink.
			tc -= a[s];
			s += 1;
		}


		if (MB < (e - s + 1)) {
			MB = e - s + 1;
		}
	}

	cout << MB << endl;

}