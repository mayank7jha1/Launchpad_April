#include<iostream>
#include<cstring>
using namespace std;


/*
	4 functions : Self invoked and are alrady there in language.

	1. Constructor
	2. Copy Constructor
	3. Copy Assignment Operator
	4. Destructor


	1. Constructor

*/

class Car {
private:
	//Data Member:
	int price = 100000;
public:
	char name[101];
	string company;
	int model;
	string color;

	// //Default Contructor
	Car() {
		cout << "Inside My Default Constructor" << endl;
	}


	//Constructor Overloading
	//Parameterised Constructor
	Car(char *n, string company, int m, string col, int p) {
		// name = n;
		cout << "Inside My Parameterised Constructor" << endl;
		strcpy(name, n);
		this->company = company;
		model = m;
		color = col;
		set_price(p);
	}

	//Getter
	int get_price() {
		return price;
	}

	//Setter
	void set_price(int discounted_price) {
		if (discounted_price < 45000) {
			price = 45000;
		} else {
			price = discounted_price;
		}
	}



	// Member Functions:
	void print() {
		cout << "------------------" << endl;
		cout << name << endl;
		cout << company << endl;
		cout << model << endl;
		cout << price << endl;
		cout << color << endl;
		cout << "------------------" << endl;
	}
};


int main() {

	Car e;
	// e.name = "ABC\0";
	strcpy(e.name, "ABC\0");

	e.company = "TATA";
	e.model = 1001;
	e.color = "Black";
	// e.price = 987;Error will be there.
	cout << e.get_price() << endl;
	e.set_price(1);
	e.print();

	Car f("XYZ\0", "BMW", 2003, "Red", 34000);
	f.print();
}










