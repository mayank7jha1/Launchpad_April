#include<iostream>
using namespace std;

bool C1(int x, int y) {
	// if (x > y) {
	// 	return false;
	// } else {
	// 	return true;
	//}
	return (x < y);
}


int main() {

	int a[] {2, 3, 4, 5, 1, 8, 9};

	sort(a, a + 7, C1);

	for (int i = 0; i < 7; i += 1) {
		cout << a[i] << " ";
	}


}