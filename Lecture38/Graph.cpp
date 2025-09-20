#include<iostream>
#include<map>
#include<list>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;



template<typename T>
class Graph {
private:
	//map<T, vector<T>>mp; //Adj. List
	map<T, list<pair<T, int>>> mp;
public:

	void AddEdge(T x, T y, bool direction, int Weight) {
		mp[x].push_back({y, Weight});
		if (direction == 0) {
			mp[y].push_back({x, Weight});
		}
	}

	//Print The Adj. List:
	void Print() {
		for (pair<T, list<pair<T, int>>> x : mp) {
			T node = x.first;
			list<pair<T, int>>nbrs = x.second;
			cout << node << " : ";
			for (pair<T, int>nbr : nbrs) {
				cout << nbr.first << "-->" << nbr.second << ",";
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
		int x, y, Weight;
		cin >> x >> y >> Weight;
		gr.AddEdge(x, y, direction, Weight);
	}

	gr.Print();
}
