#include<iostream>
using namespace std;
int n, m;
char maze[1004][1004];
bool visited[1001][1001] {{0}};
bool solution[1001][1001] {{0}};

/*
	F(x,y): Tell me if I am
	able to find a path from
	x,y to n-1,m-1?

	F(x,y): It returns me
	true/false.

	I would not want to visit
	boxes that are marked 1 in
	visited array.

*/

bool F(int i, int j) {

	if (i == n - 1 and j == m - 1) {
		solution[i][j] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << solution[i][j] << " ";
			}
			cout << endl;
		}

		//Return : Solution mil chuka hain.
		return true;//You need to now not look
		//for another solution.
	}


	if (visited[i][j] == 1) {
		return false;
	}

	/*
		Currently I am trying to solve for F(i,j) state.
	*/

	solution[i][j] = 1;
	visited[i][j] = 1;

	/*
		Maine i,j ke liye ek bar kaam kardiya
		and will now ask recursion to do the same.
	*/

	//I tried going right
	if (j + 1 <= m - 1 and visited[i][j + 1] == 0) {
		bool rightans = F(i, j + 1);

		if (rightans == 1) {
			return true;
		}
	}


	//I will try going down.
	if (i + 1 <= n - 1 and visited[i + 1][j] == 0) {
		bool downans = F(i + 1, j);
		if (downans == 1) {
			return true;
		}
	}

	//If I am standing here there is no
	//path from i,j.
	//Reinstate the original state of i,j in solution.

	solution[i][j] = 0;//Backtracking
	return false;
}




int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];

			if (maze[i][j] == 'X') {
				visited[i][j] = 1;
			}
		}
	}

	bool ans = F(0, 0);

	if (ans == 0) {
		cout << "-1" << endl;
	}

}



