#include<iostream>
#include<cstring>
using namespace std;

class Car {
private:
	//Data Member:
	int price = 100000;
public:
	char name[101];
	string company;
	int model;
	string color;

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
	cout << sizeof(Car) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(e) << endl;

	// e.name = "ABC\0";
	strcpy(e.name, "ABC\0");

	e.company = "TATA";
	e.model = 1001;
	e.color = "Black";

	// e.price = 987;Error will be there.

	cout << e.get_price() << endl;
	e.set_price(1);

	e.print();


}










