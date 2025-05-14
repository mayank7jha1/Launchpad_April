#include<iostream>
using  namespace std;

int main() {

	int x{10};
	char ch{'A'};

	cout << ch << endl;
	int y = ch;
	cout << y << endl;

	char ch1, ch2;
	cin >> ch1 >> ch2;

	cout << ch1 << " " << ch2 << endl;

	ch1 = ch1 + 1;
	ch1 += 1;

	cout << ch1 << endl;

	if (ch1 < 89) {
		cout << "Yo";
	} else {
		cout << "No";
	}
}