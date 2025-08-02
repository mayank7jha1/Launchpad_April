#include<iostream>
using namespace std;
int input;
char output[100];


void F(int j, int oc, int cc) {

	if (j == 2 * input) {
		//You have found a pattern and output, print it out.
		output[j] = '\0';
		cout << output << endl;
		return;
	}


	//Option 1: Put the '(' and ask recursion to do the rest.
	if (oc < input) {
		output[j] = '(';
		F(j + 1, oc + 1, cc);
	}

	//Option 2: Put the ')' and ask recursion to do the rest.
	if (cc < oc) {
		output[j] = ')';
		F(j + 1, oc, cc + 1);
	}

	return;
}

int main() {

	cin >> input;

	F(0, 0, 0);
}



