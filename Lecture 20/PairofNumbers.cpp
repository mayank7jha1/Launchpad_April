#include<iostream>
using namespace std;
int n;
int ans{INT_MAX};

int F(int a, int b) {

	if (a > n or b > n) {
		return 1e8;
	}

	if (a == n or b == n) {
		return 0;
	}

	int Op1 = 1 + F(a + b, b);
	int Op2 = 1 + F(a, a + b);

	return min(Op1, Op2);
}

//1. Optimations: Try to apply recursion from back if you can.
void F2(int a, int b, int count) {
	if (a == 1 and b == 1) {
		ans = min(ans, count);
		return;
	}

	if (a - b > 0) {
		return F2(a - b, b, count + 1);
	}

	if (b - a > 0) {
		return F2(a, b - a, count + 1);
	}

	return;
}

int main() {

	cin >> n;
	cout << F(1, 1) << endl;

	for (int i = 1; i <= ((n - 1) / 2); i++) {
		F2(n - i, i, 1);
	}
	if (ans == INT_MAX) {
		ans = 0;
	}
	cout << ans << endl;
}