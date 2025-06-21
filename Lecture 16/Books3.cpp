#include<iostream>
using namespace std;

int Upper_Bound(int a[], int n, int x) {
	int s = 0, e = n - 1;
	int ans = n;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] > x) {
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return ans;
}

int main() {

	int n, tt;
	cin >> n >> tt;
	int a[n];
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i += 1) {
		a[i] = a[i - 1] + a[i];
	}

	int MB = 0;

	for (int i = 0; i < n; i += 1) {
		int ut = tt + a[i - 1];
		int u1 = Upper_Bound(a, n, ut);
		u1 = u1 - i;
		if (MB < u1) {
			MB = u1;
		}
	}

	cout << MB << endl;
}





