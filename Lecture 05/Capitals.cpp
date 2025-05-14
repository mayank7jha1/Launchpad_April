#include<iostream>
using  namespace std;

int main() {
	char ch;
	int Capitals = 0, Small = 0, Extra = 0;

	while (cin.get(ch)) {

		if ((ch >= 65) and (ch <= 90)) {
			Capitals += 1;
			ch += 32;
		} else if ((ch >= 'a') and (ch <= 'z')) {
			Small += 1;
			ch -= 32;
		} else {
			Extra += 1;
		}

		cout << ch;
	}

	cout << endl << Capitals << " " << Small << " " << Extra << endl;
}