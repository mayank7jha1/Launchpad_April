#include<iostream>
#include<climits>
using  namespace std;

/*
	Limitations of freq array:

	1.	Since you cannot create an local/functional scope
		array of 10^5/10^6 you will not be able to create
		a freq array for values greater than 10^6 in case
		of an array created in local scope.


		Similar for a global array the range is 10^7/10^8
		and hence at any case you cannot create
		a freq array of size 10^8.


	2. 	It uses quite a lot of extra blocks which are
		not required.
*/

int main() {
	int n;
	cin >> n;

	int a[n] {0};

	int maxi = INT_MIN;
	int mini = INT_MAX;

	for (int i = 0; i < n; i += 1) {
		cin >> a[i];

		//For Maximum Value.
		if (maxi < a[i]) {
			maxi = a[i];
		}

		//For Minimum Value.
		if (mini > a[i]) {
			mini = a[i];
		}
	}

	int freq[maxi - mini + 1] {0};

	//Building of the freq array.
	for (int i = 0; i < n; i += 1) {
		int ce = a[i];
		int si = a[i] - mini;
		freq[si] += 1;
	}

	//Printing the freq array.
	for (int i = 0; i < maxi - mini + 1; i += 1) {
		if (freq[i] > 0) {
			int element = i + mini;
			cout << element << " " << freq[i] << endl;
		}
	}
}














