#include<iostream>
using namespace std;

char input[100];
char output[100];

void F(int i, int j) {

	if (input[i] == '\0') {
		output[j] = '\0';
		cout << output << endl;
		return;
	}

	F(i + 1, j);


	output[j] = input[i];
	F(i + 1, j + 1);

	return;
}


int main() {

	cin >> input;
	F(0, 0);
}






