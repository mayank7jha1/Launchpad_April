#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
const int N = 101;
int n, k;
int taste[N], calorie[N];
const int shift = 1e5 + 1;
int dp[101][2 * shift];

int F(int i, int sum) {
	//Currently We are solving for F(i,sum)

	if (i == n) {

		if (sum == 0) {
			return 0;//I have found a valid path.
		} else {
			return -1e8;//This is an unvaid path.
		}

	}

	if (dp[i][sum + shift] != -1) {
		return dp[i][sum + shift];
	}


	//To choose the current fruit:
	int Op1 = taste[i] + F(i + 1,
	                       sum + (taste[i] - k * calorie[i]));


	//To not choose the current fruit.
	int Op2 = 0 + F(i + 1, sum);


	return dp[i][sum + shift] = max(Op1, Op2);
}


int main() {

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> taste[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> calorie[i];
	}

	memset(dp, -1, sizeof(dp));

	int ans = F(0, 0);

	if (ans <= 0) {
		cout << "-1" << endl;
	} else {
		cout << ans << endl;
	}
}


