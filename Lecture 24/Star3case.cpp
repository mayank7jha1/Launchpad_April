#include<iostream>
#include<cstring>
using namespace std;
const int N = 100007;

int n;
int value[N] {0};
int visited[N] {0};
int Min_Steps = INT_MAX;//Minimum steps across all the paths.

void F(int i, int count) {

	if (i == n) {
		Min_Steps = min(Min_Steps, count);
		return;
	}

	visited[i] = 1;

	//Op1: When you take one step jump.
	if (i + 1 <= n and visited[i + 1] == 0) {
		F(i + 1, count + 1);
	}

	//Op2: When you take value[i] step jump.
	if (i + value[i] <= n and i + value[i] >= 0 and visited[i + value[i]] == 0) {
		F(i + value[i], count + 1);
	}

	//If you are standing here that means recursion has
	//already calculated the min steps from ith stair and
	//you are returning from ith stair then you would want to
	//make this stair available for future paths.

	visited[i] = 0;//Backtracking.
	return;
}



int main() {

	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> value[i];
		}
		//It can initialise container with values 0,-1,1.
		memset(visited, 0, sizeof(visited));

		F(0, 0);
		if (Min_Steps == INT_MAX) {
			cout << "-1" << endl;
		} else {
			cout << Min_Steps << endl;
		}

		Min_Steps = INT_MAX;
	}
}