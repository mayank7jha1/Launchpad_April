#include<iostream>
using namespace std;
int n;
int ans{0};

//F(7,3) = 0;
int F(int a, int b) {

	if (a > n or b > n) {
		return 1e8;
	}

	if (a == n or b == n) {
		return 0;
	}

	int Op1 = 1 + F(a + b, b);
	int Op2 = 1 + F(a, a + b);

	//Then what is the answer for F(a,b):
	return min(Op1, Op2);
}

void F2(int a, int b, int count) {

	if (a == 1 and b == 1) {
		//If you reach 1,1 that means
		//you have found a path
		//now compare your current path
		//steps to universal path steps.
		//whichever is min is your answer.
		ans = min(ans, count);
		return;
	}


	if (a - b > 0) {
		F2(a - b, b, count + 1);
	}

	if (b - a > 0) {
		F2(a, b - a, count + 1);
	}

	return;
}

int main() {

	cin >> n;
	cout << F(1, 1) << endl;

	//Now we are thinking about applying
	//recursion from back.

	//BP: You are at n and you want to calculate
	//min steps to reach 1,1.

	/*
		Challenge:
		1. How do I write this n as a pair?
			WHat all pairs are available that
			can make n (sum) in one step.
			n-1,1
			n-2,2
			n-3,3
			n-4,4
			_ _ _ _ _ _ _

			n = 5 :(4,1) , (3,2) , (2,3) , (1,4)

		2. While moving forward:
			a,b ---> a+b,b or a,a+b.
			but while moving backwards:
			a,b ---> a-b,b or a,b-a.

			Only one term out of a-b/ b-a can
			be positive and if koi term is
			not positive that cannot be
			considered as a state.
	*/

	for (int i = 1; i <= n; i++) {
		//Pairs are: (n-i,i)

		//Now my Problem becomes:
		//Min steps to reach 1,1 from (n-i,i).

		//Currently my count is 1.
		//because in one step you reach the pair
		//n-i,i from n.
		F2(n - i, i, 1);
	}


	/*
		F2(n-i,i,1): Min steps to reach
		1,1 from n-i,i is given by ans and my
		current path has count no of steps
		to reach 1,1.


		count: this tells you in how many steps
		you reach 1,1 in this current path.

		count: Maine current path me kitne
		steps chal liye hain abtak.

		ans : Min steps to reach 1,1 across
		all the paths.

	*/
	cout << ans << endl;



}