#include<iostream>
using  namespace std;




int main() {

	int x = 10;
	int* xptr = &x;
	int** xxptr = &xptr;
	int*** xxxptr = &xxptr;

	cout << x << endl;
	cout << &x << endl;
	cout << xptr << endl;
	cout << *xptr << endl;
	cout << &xptr << endl;
	cout << xxptr << endl;
	cout << *xxptr << endl;
	cout << &(*xxptr) << endl;
	cout << *(&xxptr) << endl;
	cout << *(&xxxptr) << endl;
	cout << &xxxptr << endl;
	//cout << *x << endl;
	cout << &(*xptr) << endl;
	cout << *(&xxptr) << endl;

}