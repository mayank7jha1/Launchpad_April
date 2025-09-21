#include<iostream>
#include<map>
#include<list>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class Graph {
private:
	map < T, list<T>> mp;
public:

	void AddEdge(T x, T y, bool direction) {
		mp[x].push_back(y);
		if (direction == 0) {
			mp[y].push_back(x);
		}
	}

	bool dfs_helper(T node, map<T, bool>&visited, map<T, bool>&Instack) {
		visited[node] = 1;
		Instack[node] = 1;

		for (T nbr : mp[node]) {
			if (visited[nbr] == 0) {
				bool small_ans = dfs_helper(nbr, visited, Instack);
				if (small_ans == 1) {
					return true;
				}

			} else if (Instack[nbr] == 1) {
				return true;
			}
		}

		Instack[node] = 0;//backtracking
		return false;
	}

	bool dfs(T scr) {
		map<T, bool>visited, Instack;
		for (auto x : mp) {
			T node = x.first;
			visited[node] = 0;
			Instack[node] = 0;
		}

		return dfs_helper(scr, visited, Instack);
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
