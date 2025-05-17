#include<iostream>
#include<climits>
using  namespace std;

//Computations : Server side time : 1 sec
//n=10^8 : ~n order me solve

int main() {
	int n;
	cin >> n;

	int a[n] {0};

	int maxi = INT_MIN;

	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
		if (maxi < a[i]) {
			maxi = a[i];
		}
	}

	//~ (n+n) = ~2*n = ~n

	int freq[maxi + 1] {0};

	for (int i = 0; i < n; i += 1) {
		int ce = a[i];
		freq[ce] += 1;
	}

	//Print the  freq. Array;

	for (int i = 0; i <= maxi; i += 1) {
		if (freq[i] > 0) {
			cout << i << " " << freq[i] << endl;
		}
	}

}