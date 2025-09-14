#include<iostream>
#include<cstring>
using namespace std;

int n, h, l, r;
int a[20001];
int dp[2001][2001];

int F(int index, int Waking_Time) {

	if (index == n) {
		return 0;
	}

	if (dp[index][Waking_Time] != -1) {
		return dp[index][Waking_Time];
	}

	int x = (Waking_Time + a[index]) % h;
	int ans1 = 0;
	if (x >= l and x <= r) {
		ans1 = 1;
	}

	int y = (Waking_Time + a[index] - 1) % h;
	int ans2 = 0;
	if (y >= l and y <= r) {
		ans2 = 1;
	}

	//When next sleep is after a[index] hours.
	int Op1 = ans1 + F(index + 1, x);

	//When next sleep is after a[index]-1 hours.
	int Op2 = ans2 + F(index + 1, y);


	return dp[index][Waking_Time] = max(Op1, Op2);
}


int main() {

	cin >> n >> h >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << F(0, 0) << endl;

}








