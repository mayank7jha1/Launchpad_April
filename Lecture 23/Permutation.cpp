#include<iostream>
using namespace std;
char ch[100];

void F(int i) {

	if (ch[i] == '\0') {
		cout << ch << endl;
		return;
	}


	for (int j = i; ch[j] != '\0'; j++) {
		swap(ch[i], ch[j]);
		F(i + 1);
		swap(ch[i], ch[j]);//Backtracking
	}
}


int main() {
	cin >> ch;
	F(0);
}