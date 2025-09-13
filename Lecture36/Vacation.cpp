#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 7;
int n;
int a[N], b[N], c[N];


int F() {

	int dp[n + 1][3] {0};

	dp[1][0] = a[1];
	dp[1][1] = b[1];
	dp[1][2] = c[1];


	for (int i = 2; i <= n; i++) {

		dp[i][0] = a[i] + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = b[i] + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = c[i] + max(dp[i - 1][0], dp[i - 1][1]);

	}

	return max({dp[n][0], dp[n][1], dp[n][2]});
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	cout << F() << endl;
}