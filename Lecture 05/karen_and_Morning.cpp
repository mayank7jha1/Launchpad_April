#include<iostream>
using  namespace std;

int main() {
	int h, m;
	char ch;
	cin >> h >> ch >> m;
	cout << h << " " << ch << " " << m << endl;


	//How do we reverse a Number?
	//We will need to reverse a number again and again.

	// if (h % 10 < 5) {

	// 	int reverse = 0;
	// 	while (h > 0) {
	// 		int digit = h % 10;
	// 		reverse = reverse * 10 + digit;
	// 		h /= 10;
	// 	}

	// 	cout << reverse - m << endl;
	// }

	int ans = 0;

	while ((h % 10 != m / 10) or (h / 10 != m % 10)) {

		ans++;
		m++;
		if (m == 60) {
			h++;
			m = 0;
		}
		h %= 24;
	}

	cout << ans << endl;


}



