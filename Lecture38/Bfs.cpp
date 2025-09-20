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
	//map<T, vector<T>>mp; //Adj. List
	map < T, list<T>> mp;
public:

	void AddEdge(T x, T y, bool direction) {
		mp[x].push_back(y);
		if (direction == 0) {
			mp[y].push_back(x);
		}
	}

	void bfs(T scr) {
		map<T, bool>visited;
		for (pair<T, list<T>>x : mp) {
			visited[x.first] = 0;
		}

		queue<T>q;
		q.push(scr);
		visited[scr] = 1;

		while (!q.empty()) {
			T node = q.front();
			q.pop();

			cout << node << " ";

			for (int nbr : mp[node]) {

				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = 1;
				}
			}
		}
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

	// int direction = 0;

	Graph<int>gr;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr.AddEdge(x, y, direction);
	}

	gr.Print();
	gr.bfs(0);
}
