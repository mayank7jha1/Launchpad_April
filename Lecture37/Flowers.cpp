// Easy Version : Given n flowers, what is the total ways to eat n flowers.
//Hard Version :

#include<iostream>
#include<cstring>
using namespace std;
int k;
int dp1[10001] {0}; //Iterative DP
int dp2[10001] {0}; //Recursive DP
int pre[10001] {0};
#define mod 1000000007

int F(int n) {
	// cout << k << endl;
	if (n == 0) {
		//Number of ways to eat zero flowers is one.
		return 1;
	}

	if (dp2[n] != -1) {
		return dp2[n];
	}

	//I am going to eat the red flower at the current index.
	int Op1 = F(n - 1) % mod;

	int Op2 = 0;
	//When I am going to eat the white flowers.
	if (n - k >= 0) {
		Op2 = F(n - k) % mod;
	}

	//Current State: F(n):
	return dp2[n] = (Op1 + Op2) % mod;
}

void IterativeDP(int n) {

	dp1[0] = 1;

	if (k == 1) {
		dp1[1] = 2;
	} else {
		dp1[1] = 1;
	}

	for (int i = 2; i <= n; i++) {
		dp1[i] = (dp1[i - 1] % mod + dp1[i - k] % mod) % mod;
	}
}



void Precompute() {
	memset(dp2, -1, sizeof(dp2));
	F(1001);//RecursiveDP

	//IterativeDP(100001);

	pre[1] = dp2[1];
	for (int i = 2; i <= 10001; i++) {
		pre[i] = (pre[i - 1] % mod + dp2[i] % mod) % mod;
	}

}



int main() {

	int t;
	cin >> t >> k;

	Precompute();

	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << pre[b] - pre[a - 1] << endl;
	}


}