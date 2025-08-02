#include<iostream>
using namespace std;

string s, t;

int F(int i, int j) {

	if (i >= s.length() or j >= t.length()) {
		return 0;
	}

	if (s[i] == t[j]) {
		int Op1 = 1 + F(i + 1, j + 1);
		return Op1;
	} else {

		//S[i]!=T[j]

		int Op1 = F(i + 1, j);
		int Op2 = F(i, j + 1);
		return max(Op1, Op2);
	}
}


int main() {

	cin >> s >> t;
	cout << F(0, 0) << endl;
}



