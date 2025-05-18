#include<iostream>
using  namespace std;

// int : 10 ^ 9
// long / long int : 10 ^ 12
// long long / long long int : 10 ^ 18

int main() {
	int t;
	cin >> t;

	while (t > 0) {
		int n;
		cin >> n;
		long long a[n];
		for (int i = 0; i < n; i += 1) {
			cin >> a[i];
		}

		int f1 = 0;

		for (int i = 0; i < n - 2; i += 1) {

			for (int j = i + 1; j < n - 1; j += 1) {

				for (int k = j + 1; k < n; k += 1) {
					long long sum = a[i] + a[j] + a[k];
					if ((sum) % 10 == 3) {
						f1 = 1;
						cout << "YES" << endl;
						break;
					}
				}
				if (f1 == 1) {
					break;
				}
			}

			if (f1 == 1) {
				break;
			}
		}

		if (f1 == 0) {
			cout << "NO" << endl;
		}


		t -= 1;
	}

}