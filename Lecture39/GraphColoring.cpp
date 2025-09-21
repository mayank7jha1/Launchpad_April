#include<iostream>
#include<map>
#include<list>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


//This is a undirected Graph.
template<typename T>
class Graph {
private:
	map < T, list<T>> mp;
	map<T, int>visited;
public:

	void AddEdge(T x, T y, bool direction) {
		mp[x].push_back(y);
		if (direction == 0) {
			mp[y].push_back(x);
		}
	}

	bool dfs_helper(T node, T parent, int color) {
		visited[node] = color;

		for (T nbr : mp[node]) {

			if (visited[nbr] == 0) {

				bool small_ans = dfs_helper(nbr, node, 3 - color);
				if (small_ans == 0) {
					return false;
				}

			} else if (nbr != parent and visited[nbr] == color) {
				return false;
			}
		}

		return true;

	}

	bool dfs(T scr) {

		visited.clear();
		for (auto x : mp) {
			T node = x.first;
			visited[node] = 0;
		}

		int color = 1;

		return dfs_helper(scr, -1, color);
	}

	//Print The Adj. List:
	void Print() {
		for (pair < T, list<T>> x : mp) {
			T node = x.first;
			list<T>nbrs = x.second;
			cout << node << " : ";
			for (T nbr : nbrs) {
				cout << nbr << " ";
			}
			cout << endl;
		}

		cout << "-----------------------" << endl;
	}

};


int main() {
	int n, m, direction;
	cin >> n >> m >> direction;
	Graph<int>gr;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr.AddEdge(x, y, direction);
	}

	//gr.Print();
	cout << gr.dfs(0);
}
