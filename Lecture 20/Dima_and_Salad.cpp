#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n, k;
int taste[N] {0}, calorie[N] {0};

int F(int i, int sum) {

	if (i == n) {
		//Check if this is a valid path
		//or not.
		if (sum == 0) {
			//This is a valid path.
			return 0;
		}
		return -1e8;
	}

	//Choose the current fruit.
	int Op1 = taste[i] +
	          F(i + 1, sum + (taste[i] - (k * calorie[i])));

	//Don't Choose the current fruit.
	int Op2 = 0 + F(i + 1, sum);

	return max(Op1, Op2);
}



int main() {

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> taste[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> calorie[i];
	}

	int ans = F(0, 0);
	if (ans <= 0) {
		cout << "-1" << endl;
	} else {
		cout << ans << endl;
	}

}