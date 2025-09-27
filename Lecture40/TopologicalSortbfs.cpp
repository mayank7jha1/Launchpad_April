#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

template<typename T>
class Graph {
	map<T, list<T>>mp;//Adj. List
	map<T, int>visited;
public:

	void AddEdge(T x, T y) {
		//Since We know this is a Directed Graph.
		mp[x].push_back(y);
	}

	void bfs(T scr) {

		map<T, int>indegree;
		for (auto x : mp) {
			indegree[x.first] = 0;
		}

		//Calculating the indegree:
		for (auto x : mp) {
			T node = x.first;
			for (auto nbr : mp[node]) {
				indegree[nbr]++;
			}
		}

		queue<T>q;

		for (auto x : indegree) {
			if (x.second == 0) {
				q.push(x.first);
			}
		}

		while (!q.empty()) {
			T node = q.front();
			q.pop();

			cout << node << " ";

			for (auto nbr : mp[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}

			}
		}
	}

};


int main() {

	int n, m;
	cin >> n >> m;

	Graph<int>gr;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr.AddEdge(x, y);
	}

	//This node 0 is just for representation you could have taken any node in this scenario.
	gr.dfs(0);
}