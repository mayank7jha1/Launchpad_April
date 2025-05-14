#include<iostream>
using  namespace std;

//Pass By Value
void check(int a, int b) {

	cout << "Inside My Function check" << endl;
	cout << a << " " << b << endl;

	a += 10;
	b -= 7;

	cout << a << " " << b << endl;

	return;
}


//Pass By Address
void check2(int* a, int* b) {

	cout << "Inside My Function check" << endl;
	cout << *a << " " << *b << endl;

	*a = *a + 10;
	*b -= 7;

	cout << *a << " " << *b << endl;

	return;
}

int main() {

	int a, b;
	cin >> a >> b;

	cout << "Inside Main" << endl;
	cout << a << " " << b << endl;

	//check(a, b);
	check2(&a, &b);

	cout << a << " " << b << endl;

}