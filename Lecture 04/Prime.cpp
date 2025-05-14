#include<iostream>
using  namespace std;

/*
	Check if a number is Prime or Not.
*/

int main() {

	int n;
	cin >> n;

	int i = 2;
	int flag = 0;

	while (i <= n - 1) {
		//My current number is n and I want to
		//check if n is divisible by current i or
		//not.
		if ((n % i) == 0) {
			flag = 1;
			//cout << "Not Prime" << endl;
			//return 0;
		}

		i += 1;
	}

	if (flag == 1) {
		cout << "Not Prime" << endl;
	} else {
		cout << "Prime" << endl;
	}

	//cout << "Prime" << endl;
}







