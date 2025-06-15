#include<iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	int left = 0;
	int right = n - 1;

	int turn = 0;
	int sp = 0, dp = 0;

	while (left <= right) {
		if (turn % 2 == 0) {
			//Sereja's Turn
			if (a[left] > a[right]) {
				sp += a[left];
				left += 1;
			} else {
				sp += a[right];
				right -= 1;
			}

		} else {
			//Dima's Turn
			if (a[left] > a[right]) {
				dp += a[left];
				left += 1;
			} else {
				dp += a[right];
				right -= 1;
			}
		}
		turn += 1;
	}


	cout << sp << " " << dp << endl;
}





