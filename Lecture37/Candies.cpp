#include<iostream>
#include<vector>
const int N = 103;
#define mod 1000000007
#define int long long
using namespace std;

int n, k;
int a[N] {0};
int dp[101][100003] {0};

int F() {

	//Base Condition:
	for (int i = 0; i <= k; i++) {
		if (i <= a[1]) {
			dp[1][i] = 1;
		} else {
			dp[1][i] = 0;
		}
	}


	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {

			if (j == 0) {
				dp[i][j] = dp[i - 1][j] % mod;
			} else {

				int Part1 = dp[i][j - 1] % mod;
				int Part2 = dp[i - 1][j] % mod;
				int Part3 = 0;
				if (j - a[i] - 1 >= 0) {
					Part3 = (dp[i - 1][j - a[i] - 1]) % mod;
				}

				dp[i][j] = Part1 + Part2 - Part3;
				dp[i][j] %= mod;
			}
		}
	}


	return dp[n][k] % mod;
}



int32_t main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << F() << endl;


}