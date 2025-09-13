#include<iostream>
#include<cstring>
using namespace std;


/*
	Dp[i] = F(i) : ith Fibonacci Number.
*/

//Computation : No of unique States * Transition Time
//Computation : No of States * Transition Time
// Computation : n+1 * 1 ~= (n)

//Top Down Dp: Recursion + Memoisation
int F(int n, int *dp) {

	if (n == 1 or n == 0) {
		return n;
	}

	//Calculate karne se pehle check
	if (dp[n] != -1) {
		return dp[n];
	}

	int Op1 = F(n - 1, dp);
	int Op2 = F(n - 2, dp);

	//And return se pehle store.
	return dp[n] = Op1 + Op2;
}


//Iterative Dp :
int F2(int n) {

	int dp[n + 1] {0};
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}


	return dp[n];
}


int main() {

	int n;
	cin >> n;
	int dp[n + 1];
	memset(dp, -1, sizeof(dp));
	cout << F(n, dp) << endl;
	cout << F2(n) << endl;
}