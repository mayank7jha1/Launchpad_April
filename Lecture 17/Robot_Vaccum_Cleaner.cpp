#include<iostream>
using namespace std;

int Noise(string s) {

	int ans = 0;
	int cs = 0;

	for (int i = 0; i < s.length(); i += 1) {
		if (s[i] == 's') {
			cs += 1;
		} else {
			ans += cs;
		}
	}

	return ans;
}

bool compare(string x, string y) {
	string xy = x + y;
	string yx = y + x;

	if (Noise(xy) > Noise(yx)) {
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

	cout << Noise(final) << endl;


}



