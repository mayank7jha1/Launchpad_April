#include<iostream>
using namespace std;

/*
	n=5:

	F(5,x): Maine 0 se 4 sleep karli iska matlab hain
	maine 5 sleep as a count karli.

	_ _ _ _ _
	0 1 2 3 4

	Definition: F(5,x): Maximum number of sleep
	from 5th index to 4th is zero. (Not Possible).


*/

int n, h, l, r;
int a[20001];

int F(int index, int Waking_Time) {

	if (index == n) {
		return 0;
	}

	//Kya meri next sleep jo a[index] ghante baad
	//hogi vo good sleep hain?
	//Above question ka answer main ans1 name ke
	//variable me rakhunga.

	int x = (Waking_Time + a[index]) % h;
	int ans1 = 0;
	if (x >= l and x <= r) {
		ans1 = 1;
	}

	//Kya meri next sleep jo a[index]-1 ghante baad
	//hogi vo good sleep hain?
	//Above question ka answer main ans2 name ke
	//variable me rakhunga.
	int y = (Waking_Time + a[index] - 1) % h;
	int ans2 = 0;
	if (y >= l and y <= r) {
		ans2 = 1;
	}

	//When next sleep is after a[index] hours.
	int Op1 = ans1 + F(index + 1, x);

	//When next sleep is after a[index]-1 hours.
	int Op2 = ans2 + F(index + 1, y);


	return max(Op1, Op2);
}


int main() {

	cin >> n >> h >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << F(0, 0) << endl;

}









