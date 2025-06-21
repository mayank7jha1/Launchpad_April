#include<iostream>
using namespace std;

int Solve(string s, int k, char ch) {

	int Maximum_Substring = 0;
	int count1 = 0;//This stores the number of times undesired character has occured in the current subtring.

	int start = 0;
	for (int e = 0; e < s.length(); e += 1) {
		if (s[e] != ch) {
			count1 += 1;
		}


		//Check if need to Shrink.
		while (start <= e and count1 > k) {
			if (s[start] != ch) {
				count1 -= 1;
			}
			start += 1;
		}

		//Update:
		Maximum_Substring = max(Maximum_Substring, e - start + 1);
	}
	return Maximum_Substring;
}


int main() {
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	//Current Change is b->a.
	char ch = 'a';
	int ans = Solve(s, k, ch);

	//Current Change is a->b.
	ch = 'b';
	int ans2 = Solve(s, k, ch);

	cout << max(ans, ans2) << endl;
}