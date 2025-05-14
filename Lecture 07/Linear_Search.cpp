#include<iostream>
using  namespace std;

int main() {
	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	int key;
	cin >> key;

	//Linear Search

	for (int i = 0; i < n; i += 1) {
		if (a[i] == key) {
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "No" << endl;


}