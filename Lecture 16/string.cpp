#include<iostream>
#include<string>
using namespace std;


int main() {

	int x;
	string s1;

	string s = "Mayank";//Copy Initialisation
	string st{"Atul"};//Direct List Initialisation
	cout << s << " " << st << endl;


	string p;
	cin >> p;
	cout << p << endl;

	for (int i = 0; s[i] != '\0'; i += 1) {
		cout << s[i];
	}

	cout << endl;
	cout << s.length() << endl;
	cout << s.back() << " " << s[s.length() - 1] << endl;


	for (int i = 0; i < s.length(); i += 1) {
		cout << s[i];
	}

	cout << endl << s << endl;

	//Operator Overloading +
	s = "Atul" + s + "Mayank" + st;
	cout << s << endl;

	st = st + 'M';
	cout << st << endl;

	string ps = "M";
	cout << ps << endl;



	//Container: Algorithm:






}