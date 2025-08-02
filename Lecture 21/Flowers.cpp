#include<iostream>
using namespace std;

int n, k;



/*

	Motivation: Flowers (Basic):

	Number of ways to eat n flowers,given k.

*/

int F(int n) {

	if (n == 0) {
		//Number of ways to eat zero flowers is one.
		return 1;
	}

	//I am going to eat the red flower at the current index.
	int Op1 = F(n - 1);

	int Op2 = 0;
	//When I am going to eat the white flowers.
	if (n - k >= 0) {
		Op2 = F(n - k);
	}

	//Current State: F(n):
	return Op1 + Op2;
}

int main() {
	cin >> n >> k;
	//I am following 1 based indexing for boxes.

	cout << F(n);
}





