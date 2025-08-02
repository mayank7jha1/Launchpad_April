#include<iostream>
using namespace std;

namespace rahul {
template <typename T>
class Vector {
private:
	//Data Members:
	T* a;
	int ts;
	int cs;
public:
	//Constructor
	//Default Constructor
	Vector() {
		cs = 0;
		ts = 1;
		a = new T[ts];
	}

	//Parameterised Constructor
	Vector(int n) {
		cs = 0;//This can be treated as the index also.
		ts = n;
		a = new T[ts];
	}

	//Member Functions:
	void push_back(T data) {

		if (cs == ts) {
			T* b = a;
			a = new T[2 * ts];
			ts *= 2;

			//Copy the content of the
			//old array in new array.

			for (int i = 0; i < ts / 2; i++) {
				a[i] = b[i];
			}

			delete[]b;//To avoid Memory leak.
		}


		a[cs] = data;
		cs++;
	}

	int size() {
		return cs;
	}

	int capacity() {
		return ts;
	}

	void pop_back() {
		cs--;
	}

	T front() {
		return a[0];
	}

	T back() {
		return a[cs - 1];
	}

	bool empty() {
		if (cs == 0) {
			return true;
		} else {
			return false;
		}
	}

	// v[5]: *(v + 5)
	//v.operator[](5)

	T operator[](int index) {
		return a[index];
	}

	//Define
	void operator+(string s) {

	}

	void operator+(char s) {

	}
};
};


//v[5]: dynamic array uske 5 index value
















