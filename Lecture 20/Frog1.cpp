#include<iostream>
using namespace std;
int n;
int h[100001] {0};

int F(int x) {

	if (x == 1) {
		return 0;
	}


	//When you take jump of 1 step.
	int Op1 = abs(h[x] - h[x - 1]) + F(x - 1);

	//When you take jump of 2 step.
	int Op2 = INT_MAX;
	if (x - 2 >= 1) {
		Op2 = abs(h[x] - h[x - 2]) + F(x - 2);
	}

	return min(Op1, Op2);
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	cout << F(n) << endl;






}