#include<iostream>
#include<cstring>
using namespace std;


/*
	Dp[i] = F(i) : ith Fibonacci Number.

*/


int F(int n, int *dp) {

	if (n == 1 or n == 0) {
		return n;
	}

	//Check If the current state is unique or not?
	//Currently we are at the F(n) state if this is a repeated state its answer would have been stored in dp[n].
	//Calculate karne se pehle check
	if (dp[n] != -1) {
		//This is a repeated state and you don't need to calculate the answer for this state.
		return dp[n];
	}

	int Op1 = F(n - 1, dp);
	int Op2 = F(n - 2, dp);

	//If you are here then you have calculated the answer for the unique state now store it.
	//and return se pehle store.
	return dp[n] = Op1 + Op2;
}


int main() {

	int n;
	cin >> n;
	int dp[n + 1];
	memset(dp, -1, sizeof(dp));//This can only be used to initialise the container with values -1,0,1.
	cout << F(n, dp) << endl;
}