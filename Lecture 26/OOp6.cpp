#include<iostream>
#include<cstring>
using namespace std;


/*
	4 functions : Self invoked and are alrady there in language.

	1. Constructor
	2. Copy Constructor
	3. Copy Assignment Operator
	4. Destructor


	1. Copy Constructor

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
	char* engine = new char[1001]; //Dynamic Memory

	// //Default Contructor
	Car() {
		cout << "Inside My Default Constructor" << endl;
	}


	//Constructor Overloading
	//Parameterised Constructor
	Car(char *n, string company, int m, string col, int p, char* e) {
		// name = n;
		cout << "Inside My Parameterised Constructor" << endl;
		strcpy(name, n);
		this->company = company;
		model = m;
		color = col;
		engine = new char[strlen(e) + 1];
		strcpy(engine, e);
		set_price(p);
	}

	//Copy Constructor
	Car(Car &x) {
		cout << "Inside My Own Copy Constructor" << endl;
		strcpy(name, x.name);
		company = x.company;
		model = x.model;
		color = x.color;
		price = x.price;
		engine = new char[strlen(x.engine) + 1];
		// engine = x.engine;
		strcpy(engine, x.engine);
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
		cout << engine << endl;
		cout << "------------------" << endl;
	}
};


int main() {

	Car e;
	strcpy(e.name, "ABC\0");
	e.company = "TATA";
	e.model = 1001;
	e.color = "Black";
	e.set_price(1);
	// e.engine = new char[10001];
	strcpy(e.engine, "V8");
	e.print();

	Car f("XYZ\0", "BMW", 2003, "Red", 34000, "V9");
	f.print();

	Car g(f);
	g.print();

	f.name[0] = 'P';
	f.engine[0] = 'G';

	f.print();
	g.print();
}










