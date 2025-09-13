#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
int a[200001] {0};

/*
	Recursion from back.
	Dp[i] : F(i) : n se i tak stone ka min cost.

	//Recursion from front.
	Dp[i] : F(i) : 1 se i tak ka min. cost.

*/

int F(int n, int* dp) {

	if (n == 1) {
		return 0;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int Op1 = abs(a[n] - a[n - 1]) + F(n - 1, dp);

	int Op2 = INT_MAX;

	if (n - 2 >= 1) {
		Op2 = abs(a[n] - a[n - 2]) + F(n - 2, dp);
	}

	return dp[n] = min(Op1, Op2);
}


int F2(int i, int n, int *dp) {

	if (i == n) {
		return 0;
	}

	if (dp[i] != -1) {
		return dp[i];
	}

	int Op1 = abs(a[i] - a[i + 1]) + F2(i + 1, n, dp);

	int Op2 = INT_MAX;

	if (i + 2 <= n) {
		Op2 = abs(a[i] - a[i + 2]) + F2(i + 2, n, dp);
	}

	return dp[i] = min(Op1, Op2);
}


int main() {


	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int dp[n + 1] {0};
	int dp1[n + 1] {0};

	memset(dp, -1, sizeof(dp));
	memset(dp1, -1, sizeof(dp1));

	cout << F(n, dp) << endl;
	cout << F2(1, n, dp1) << endl;


}