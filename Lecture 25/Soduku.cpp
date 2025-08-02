#include<iostream>
using namespace std;
char board[10][10];

bool CanPlace(int x, int y, char ch) {

	//Check 1: We are checking the current row.
	for (int i = 0; i < 9; i++) {
		if (board[x][i] == ch) {
			return false;
		}
	}

	//Check 2: We are checking the current column.
	for (int i = 0; i < 9; i++) {
		if (board[i][y] == ch) {
			return false;
		}
	}


	//Check the submatrix :
	int sx = (x / 3) * 3;
	int sy = (y / 3) * 3;

	for (int i = sx; i < sx + 3; i++) {
		for (int j = sy; j < sy + 3; j++) {
			if (board[i][j] == ch) {
				return false;
			}
		}
	}

	return true;
}


bool F(int x, int y) {
	if (x == 9) {
		return true;
	}

	if (y == 9) {
		return F(x + 1, 0);
	}


	//Current State is F(x,y).
	if (board[x][y] != '.') {
		return F(x, y + 1);
	} else {

		for (char ch = '1'; ch <= '9'; ch++) {
			if (CanPlace(x, y, ch) == 1) {
				board[x][y] = ch;

				bool small_ans = F(x, y + 1);

				if (small_ans == 1) {
					return true;
				}
			}
		}
	}

	/*
		If you are standing here that means
		you have not yet return true from
		x,y box.
		You are not able to put any number
		in the current box x,y.
	*/

	board[x][y] = '.';//Backtracking
	return false;
}


int main() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
		}
	}

	bool ans = F(0, 0);
	// int x = 98;
	// if (x == true) {
	// 	cout << "No";
	// }
	if (ans == 0) {
		cout << "-1" << endl;
		return 0;
	}


	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

}