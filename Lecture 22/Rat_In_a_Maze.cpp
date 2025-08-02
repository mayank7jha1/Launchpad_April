#include<iostream>
#include<vector>
using namespace std;


int directions[4][2] {{ -1, 0}, {1, 0}, {0, 1}, {0, -1}};
char directionLabel[] {'L', 'R', 'U', 'D'};
int n;
char maze[1001][1001];
vector<string>paths;
bool visited[1001][1001] {{0}};

/*
	F(0,0): Store all the paths from 0,0 to n-1,n-1 in path
	vector.
*/

void F(int x, int y, string &ans) {

	if (x == n - 1 and y == n - 1) {
		paths.push_back(ans);
		return;
	}


	//Currently we are at x,y : F(x,y) state.
	if (visited[x][y] == 0) {
		return;
	}

	//Assume this box is part of answer.
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = directions[i][0];
		int ny = directions[i][1];

		if (nx >= 0 and ny >= 0 and nx < n and ny < n and
		        visited[nx][ny] == 0) {

			F(nx, ny, ans + directionLabel[i]);
		}
	}

	//If you are able to visit this box
	//from another way then you can find a
	//new path.
	visited[x][y] = 0;
}




int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];

			if (maze[i][j] == 0) {
				visited[i][j] = 1;
			}
		}
	}

	if (maze[0][0] == 0 or maze[n - 1][n - 1] == 0) {
		cout << "";
		return 0;
	}
	string ans = "";
	F(0, 0, ans);













}