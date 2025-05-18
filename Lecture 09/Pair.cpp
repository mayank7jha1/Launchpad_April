#include<iostream>
using  namespace std;


/*
	Motivation : Given an array you neeed
				 to print all the pairs
				 whose sum is equal to target.

				Duplicate pairs are allowed.
				Pair me both the element cannot be same
				I am not saying in terms of value I am
				saying in terms of index.

*/

int main() {
	int n, target;
	cin >> n >> target;

	int a[n] {0};
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	//(ce, target - ce) = target

	/*
		I will go to every index and
		treat the current element
		as the pair ka first element
		and will try to find the
		pair ka second element whose
		sum is target-ce.
	*/

	for (int i = 0; i < n; i += 1) {

		/*
			I will try to search for the
			second element of the pair
			whose first element is
			a[i].
		*/
		int fe = a[i];
		for (int j = i + 1; j < n - 1; j += 1) {
			int cse = a[j];
			if (fe + cse == target) {
				//This is a desired pair.
				cout << fe << " " << cse << endl;
			}
		}
	}


}