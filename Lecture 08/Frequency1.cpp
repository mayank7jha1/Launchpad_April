#include<iostream>
#include<climits>
using  namespace std;

//~ ( n*n)

/*
		1<=n<=10^5

		1 sec = 10^8

		10^10 computions;
*/

int main() {
	int n;
	cin >> n;

	int a[n] {0};

	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}


	for (int i = 0; i < n; i += 1) {
		int ce = a[i];

		int count1 = 0;//It tells me the freq. of
		//the ce.

		if (ce != INT_MIN) {
			for (int j = 0; j < n; j += 1) {
				//We are trying to find the current
				//element inside the array.
				if (a[j] == ce) {
					count1 += 1;
					a[j] = INT_MIN;
				}
			}
			cout << ce << ": " << count1 << endl;
		}

	}



}