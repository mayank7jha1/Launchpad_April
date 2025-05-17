#include<iostream>
using  namespace std;

/*
	1<=n<=10^5
	1<=q<=10^5

	computations = ~ (n*q)

	worst case computations : ~(10^10)

	1 sec     = 10^8
	100 sec	  = 10^10

*/

int main() {
	int n;
	cin >> n;

	int a[n] {0};
	int x;

	for (int i = 0; i < n; i += 1) {
		// cin >> x;
		// a[i] = x;
		cin >> a[i];
	}

	int q;
	cin >> q;

	int l, r;
	int computations = 0;


	while (q > 0) {

		cin >> l >> r;

		int ans = 0;
		for (int i = l; i <= r; i += 1) {
			computations += 1;
			ans += a[i];
		}
		cout << ans << endl;
		q -= 1;
	}


	cout << computations << endl;
}