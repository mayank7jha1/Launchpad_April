#include<iostream>
using namespace std;

//Global Scope:
// const int n = 10;
// const int m = 10;

void Solve(int (*a)[3], int m) {

}

void Solve1(int a[3][5]) {

}

void Solve2(int n, int m, int a[n][m]) {

	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < m; j += 1) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}


}

int main() {

	//Size is compulsory.
	//This is a static for a array.
	int a[3][3] {{2, 5, 9}, {3, 7, 1}, {19, 5, 1}};
	int b[][3] {{2, 5, 9}, {3, 7, 1}, {19, 5, 1}};

	int c[][3] {};
	int d[][3] {{}};
	int e[][3] {{0}};

	cout << a << endl;
	cout << a + 1 << endl;
	cout << *(a + 1) << endl;
	cout << a[1] << endl;
	cout << (*(a + 1) + 0) << endl;
	cout << *(*(a + 1) + 0) << endl;
	cout << a[1][0] << endl;

	for (int i = 0; i < 3; i += 1) {
		for (int j = 0; j < 3; j += 1) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	int t = 10;
	Solve(a, 3);
	// Solve1(a, t)


	int n, m;
	cin >> n >> m;

	int h[n][m];
	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < m; j += 1) {
			cin >> h[i][j];
		}
	}

	Solve2(n, m, h);



	// 140701962774944
	// 140701962774956




}