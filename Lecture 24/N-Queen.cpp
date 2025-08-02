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
		//You have filled for 0 to n-1 row that means
		//you have found a answer print it.

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}


		//I will always return false from here since I want to
		//print all the paths.
		//I.e. I want recursion to still try to find another
		//path even though it has found one.
		return false;
	}

	//Currently you are at rth row.
	for (int c = 0; c < n; c++) {

		//I will try to put queen here and ask recursion
		//will i be able to solve for the rest.

		//Check if you can put queen at r,c co-ordinate or not?

		if (CanPlace(r, c) == 1) {
			//You can put queen here.

			board[r][c] = 'Q';
			bool small_ans = F(r + 1);

			if (small_ans == 1) {
				return true;
			}

			//If you are here that means yaha par queen rakh kar
			//ya to solution tumne print karva diya hain ya
			//fir solution yaha par queen rakh kar exist nahi
			//karta.

			//dono situation me board[r][c] ko vapas se . bana do.

			board[r][c] = '.';//Backtracking
		}
	}


	//If I am standing here that means for my current row r
	//i was not able to put queen on any column c.
	//hence I return false.
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

	//F(0): It returns true/false representing if I am able to
	//put n queen or not.
	int ans = F(0);
	cout << ans << endl;
}