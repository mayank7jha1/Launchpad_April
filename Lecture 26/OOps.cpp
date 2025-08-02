#include<iostream>
using namespace std;

/*

	Q. 5 Friends:

	Name      Money
	Mayank    100
	Samyak    10000000
	Rahul     250
	Atul      200000
	Akas      350


	Sort this data based on money.


	Procedural Programming: Write Procedures/Functions.
	Top to Down Approach.

	Data Privacy Ka koi concept nahi hain.
	Inheritance : Procedural Programming
	You establish connections on your own.(Repeatedly)

	Long Code/Code Reusability

	Advantage:
	Fast.

	Object Oriented Programming:
	We Write programs with the help of object.

	variables: Named Object.

	Object :
	Overloading is also possible in OOPS.

	OOPS:

	Data Members
	Member Functions


	1. Abstraction
	2. Encapsulation
	3. Inheritance
	4. Polymophism

*/




int main() {

	string name[] {"Mayank", "Samyak", "Rahul", "Atul", "Akas"};
	int money[] {100, 10000000, 250, 200000, 350};



	//First let us find rahul is at which index.
	int i;
	for (i = 0; i < 5; i++) {
		if (name[i] == "Rahul") {
			break;
		}
	}


	cout << money[i] << endl;
	sort(money, money + 5);

	for (i = 0; i < 5; i++) {
		if (name[i] == "Rahul") {
			break;
		}
	}


	cout << money[i] << endl;


}





