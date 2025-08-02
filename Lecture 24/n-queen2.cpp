#include<iostream>
using namespace std;
int n;
char board[100][100];

bool CanPlace(int r, int c) {

	//check in the current row:
	for (int i = 0; i < c; i++) {
		if (board[r][i] == 'Q') {
			return false;
		}
	}

	//check in current column:
	for (int i = 0; i < r; i++) {
		if (board[i][c] == 'Q') {
			return false;
		}
	}


	//Left Diagonal
	int i = r, j = c;

	while (i >= 0 and j >= 0) {
		if (board[i][j] == 'Q') {
			return false;
		}
		i--, j--;
	}

	i = r, j = c;

	while (i >= 0 and j < n) {
		if (board[i][j] == 'Q') {
			return false;
		}
		i--, j++;
	}

	return true;
}



bool F(int r) {

	if (r == n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}

		cout << endl;
		return false;
	}

	for (int c = 0; c < n; c++) {
		if (CanPlace(r, c) == 1) {
			board[r][c] = 'Q';
			bool small_ans = F(r + 1);

			if (small_ans == 1) {
				return true;
			}
			board[r][c] = '.';//Backtracking
		}
	}

	return false;
}


int main() {

	cin >> n;

	//Initially every box is a .(dot)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = '.';
		}
	}

	int ans = F(0);
	//cout << ans << endl;
}