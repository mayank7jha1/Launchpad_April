#include<iostream>
#include<algorithm>
using namespace std;


int main() {

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	sort(a, a + n);
	reverse(a, a + n);

	for (int i = 0; i < n; i += 1) {
		cout << a[i] << " ";
	}
	cout << endl;


	cout << max(9, 17) << endl;
	cout << min(7, 1) << endl;

	int x = 10;
	int y = 67;
	swap(x, y);

	cout << x << " " << y << endl;

	cout << max(21, max(31, max(18, max(17, 91)))) << endl;
	cout << max({21, 31, 18, 17, 91}) << endl;






}