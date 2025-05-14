#include<iostream>
using  namespace std;

int main() {
	//int x{10};//Variable Definition and Initialisation


	/*
		Static Arrays:

		Aapko size specify karna padega (Matlab size
		cannot be variable)and you are not allowed
		to change its size.

		{} --> Multiple Elements

		1. Motivation
		2. Traversal
		3. Functions : Tools that can be used on this container
		4. Algorithms :

	*/

	// int a[4];//Array Definition
	// // int a2[4] = {5, 1, 2, 9};

	// //Initialisation
	// int a3[10] {5, 1, 2, 9};
	// int a4[] {5, 1, 2, 9};

	// int a5[5] {0};
	// int a6[5] {};



	// int a[] {5, 1, 3, 9, 12};

	// cout << a << endl;
	// cout << (*a) << endl;
	// cout << *(a + 1) << endl;
	// cout << a + 2 << endl;
	// cout << a[1] << endl;

	// 140701858535440
	// 140701858535444
	// 140701858535448

	// int i = 0;
	// while (i <= 5) {
	// 	cout << a[i] << " ";
	// 	i += 1;
	// }

	int n;
	cin >> n;

	// int b[n];

	// //Index: 0 ---- > n-1.

	// //Chaho to values 1 index se store kar sakte ho.


	// int j = 0;
	// while (j < n) {
	// 	cin >> a[j];
	// 	j += 1;
	// }


	// int c[n + 1] {};

	// //Index: 0 ---- > (n+1) - 1.


	// int j = 1;
	// while (j < n + 1) {
	// 	cin >> c[j];
	// 	j += 1;
	// }

	// //cout << endl;

	// j = 1;
	// while (j < n + 1) {
	// 	cout << c[j] << " ";
	// 	j += 1;
	// }


	// int d[5] {3, 4, 19, 1, 7};
	// cout << d[10] << endl;
	// *(8085 + 10) : This is also an address.
	// 8085 + 40 = 8125;
	// d[10] = 98;
	// cout << d[10] << endl;
	// 9998: int p[4] {3, 1, 5, 9}; p--->8125
	// cout << d[10] << endl;


	//For Loop:
	int i = 1;

	while (i <= 10) {
		//cout << i << " ";
		i += 1;
	}

	// for (Starting Point; Stoping Point; Next Step) {
	// 	//Task;
	// }

	//I will be here.


	for (i = 3; i <= 20; i += 1) {
		//cout << i << endl;
	}

	// for (; j < 14;) {


	// 	j += 2;
	// }


	// for (int i = 1, j = 3; i <= 14 and j <= 15; i = i + 1, j = j + 3) {

	// }
	// cout << i << endl;
}