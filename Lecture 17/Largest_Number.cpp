#include<iostream>
using namespace std;


bool compare(string a, string b) {
	string ab = a + b;
	string ba = b + a;

	if (ab > ba) {
		return true;
	} else {
		return false;
	}
}

int main() {

	int n;
	cin >> n;

	string s[n];
	for (int i = 0; i < n; i += 1) {
		cin >> s[i];
	}

	sort(s, s + n, compare);
	string final = "";

	for (int i = 0; i < n; i += 1) {
		final = final + s[i];
	}

	cout << final << endl;




}



