#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
const int N = 1e5 + 1;
vector<int>gr[N];

void bfs(int scr, int n, int &sh) {

	vector<int>distance(n + 1, INT_MAX);

	queue<int>q;
	q.push(scr);
	distance[scr] = 0;

	while (!q.empty()) {

		int node = q.front();
		q.pop();

		for (auto nbr : gr[node]) {

			if (distance[nbr] == INT_MAX) {
				q.push(nbr);
				distance[nbr] = distance[node] + 1;
			} else if (distance[nbr] >= distance[node]) {
				//nbr cannot be a parent of node
				//hence a backedge.

				int cl = distance[nbr] + distance[node] + 1;
				sh = min(sh, cl);
			}
		}
	}
}




int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	int sh = n + 1;
	//Pressuming graph has only nodes from 0 to n-1.
	for (int i = 0; i < n; i++) {
		Bfs(i, n, sh);
	}


	if (sh == n + 1) {
		cout << "No Cycle" << endl;
	} else {
		cout << sh << endl;
	}


}