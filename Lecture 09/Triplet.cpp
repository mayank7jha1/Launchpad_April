#include<iostream>
using  namespace std;


int main() {
	int n, target;
	cin >> n >> target;

	int a[n] {0};
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}



	for (int i = 0; i < n - 2; i += 1) {
		int fe = a[i];
		for (int j = i + 1; j < n - 1; j += 1) {
			int se = a[j];
			for (int k = j + 1; k < n; k += 1) {
				int te = a[k];
				if (fe + se + te == target) {
					cout << fe << " " << se << " " << te << endl;
				}
			}
		}
	}
}