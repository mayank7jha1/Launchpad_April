#include<iostream>
#include<map>
#include<list>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
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

	void bfs(T scr, T destination) {
		map<T, int>distance;
		for (pair<T, list<T>>x : mp) {
			distance[x.first] = INT_MAX;
		}

		queue<T>q;
		q.push(scr);
		distance[scr] = 0;

		while (!q.empty()) {
			T node = q.front();
			q.pop();

			cout << node << " ";

			for (int nbr : mp[node]) {
				if (distance[nbr] == INT_MAX) {
					q.push(nbr);
					distance[nbr] = distance[node] + 1;
				}
			}
		}

		cout << scr << " " << distance[destination] << endl;

		for (auto x : mp) {
			cout << scr << " " << x.first << " " << distance[x.first] << endl;
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
	gr.bfs(1, 5);
}
