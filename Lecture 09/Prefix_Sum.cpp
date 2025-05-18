/*

	Motivation : Check is subarray sum is zero or not
	inside an array of size n.


	subarray sum from l to r = sum[l,r]= pre[r]-pre[l-1];

	sum[l,r]= 0;
	pre[r]-pre[l-1]=0;

	pre[r]=pre[l-1];


	check if freq of 0 in prefix array is > 0
	or
	check if freq of any other element is > 1.


*/

#include<iostream>
#include<climits>
using  namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	//Create prefix array.

	int pre[n + 1] {0};
	pre[0] = a[0];
	int maxi = INT_MIN;
	int mini = INT_MAX;

	for (int i = 1; i < n; i += 1) {
		pre[i] = pre[i - 1] + a[i];

		if (pre[i] > maxi) {
			maxi = pre[i];
		}

		if (mini > pre[i]) {
			mini = pre[i];
		}

	}

	int freq[maxi - mini + 1] {0};

	for (int i = 0; i < n; i += 1) {
		int ce = pre[i];
		freq[ce] += 1;
	}



	//You need to check if freq array me 0 element ki
	//frequency > 0 hain ki nahi ya fir kisi aur element ki
	//freq > 1 hain ki nahi.

	//0 as a element konse index par hain.

	if (freq[0 - mini] > 0) {
		cout << "Yes" << endl;
		return 0;
	}

	//Ek faltu kaam kar rahe ho.
	for (int i = 0; i < maxi - mini + 1; i += 1) {
		if (freq[i] > 1) {
			cout << "Yes" << endl;
			return 0;
		}
	}


	cout << "No" << endl;



}