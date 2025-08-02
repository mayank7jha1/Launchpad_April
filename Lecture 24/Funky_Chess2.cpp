#include<iostream>
using namespace std;
const int N = 10;

int dx[] {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] {2, -2, 2, -2, 1, -1, 1, -1};
int n;
int grid[N][N] {0};
int Total_Boxes = 0;

//Take Input Seperately
void Input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				Total_Boxes++;
			}
		}
	}
}

int ans = -1;
void F(int x, int y, int count) {

	ans = max(ans, count);

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 and nx<N and ny >= 0 and ny < N and grid[nx][ny] == 1) {
			grid[nx][ny] = 0;
			F(nx, ny, count + 1);
			grid[nx][ny] = 1;
		}
	}
}

int main() {
	cin >> n;
	Input();

	grid[0][0] = 0;

	F(0, 0, 1);
	cout << Total_Boxes - ans << endl;
}

















