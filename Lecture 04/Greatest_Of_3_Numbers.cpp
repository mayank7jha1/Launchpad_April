#include<iostream>
using  namespace std;


/*
	Arithmetic Operators : +,-,/,*,%
	Relation Operators : >,<,>=,<=,==
	Assignment Operators:+=,-=,*=,/=,=,%=

	Logical Operators: and(&&),or(||),not(!)


	int a = 19;
	int b = 89;
	b = b + 10;
	b += 10;

	((Condition 1) and (Condition 2))
	((Condition 1) or (Condition 2))

	(!(Condtion 1))


	0 0 0
	0 1 0
	1 0 0
	1 1 1

	0 0 0
	0 1 1
	1 0 1
	1 1 1

	0 1
	1 0

*/

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if ((a > b) and (a > c)) {

		cout << a << endl;

	} else if ((b > a) and (b > c)) {

		cout << b << endl;

	} else {

		cout << c << endl;

	}



	// if ((a > b) and (a > c)) {

	// 	cout << a << endl;

	// }

	// if ((b > a) and (b > c)) {

	// 	cout << b << endl;

	// } else {

	// 	cout << c << endl;

	// }




	// if ((a > b) and (a > c)) {

	// 	cout << a << endl;

	// }

	// if ((b > a) and (b > c)) {

	// 	cout << b << endl;

	// }

	// if ((c > b) and (c > a)) {

	// 	cout << c << endl;

	// }





}














