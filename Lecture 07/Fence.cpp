#include<iostream>
using  namespace std;

int main() {

	int n, h;
	cin >> n >> h;
	int a[n];
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	int ans = 0;

	for (int i = 0; i < n; i += 1) {
		if (a[i] > h) {
			ans += 2;
		} else {
			ans += 1;
		}
	}


	cout << ans << endl;

}