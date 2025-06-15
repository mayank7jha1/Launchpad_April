#include<iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	int a[n];
	//Height Array.
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	int left = 0;
	int right = n - 1;
	int area = 0;


	while (left < right) {

		int cw = right - left;
		int ch = a[left];
		if (ch > a[right]) {
			ch = a[right];
		}

		//cout << cw << " " << ch << endl;

		int ca = cw * ch;
		if (area <= ca) {
			area = ca;
		}

		if (a[left] > a[right]) {
			right -= 1;
		} else {
			left += 1;
		}

	}

	cout << area;


}