#include<iostream>
using namespace std;
int n, m;
char maze[1004][1004];
bool visited[1001][1001] {{0}};
bool solution[1001][1001] {{0}};

bool F(int i, int j) {

	if (i == n - 1 and j == m - 1) {
		solution[i][j] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << solution[i][j] << " ";
			}
			cout << endl;
		}

		return true;
	}


	if (visited[i][j] == 1) {
		return false;
	}

	solution[i][j] = 1;
	visited[i][j] = 1;

	if (j + 1 <= m - 1 and visited[i][j + 1] == 0) {
		bool rightans = F(i, j + 1);

		if (rightans == 1) {
			return true;
		}
	}

	if (i + 1 <= n - 1 and visited[i + 1][j] == 0) {
		bool downans = F(i + 1, j);
		if (downans == 1) {
			return true;
		}
	}

	solution[i][j] = 0;
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



