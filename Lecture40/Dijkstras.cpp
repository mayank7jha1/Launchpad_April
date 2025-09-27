#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;

template<typename T>
class Graph {
	map < T, list<pair<T, T>>>mp;//Adj. List
public:
	void AddEdge(T x, T y, int weight) {
		mp[x].push_back({y, weight});
		mp[y].push_back({x, weight});
	}


	void Dijkstras(T scr) {

		map<T, int>distance;
		set<pair<int, int>>s;

		for (auto x : mp) {
			distance[x.first] = INT_MAX;
		}

		distance[scr] = 0;
		s.insert({0, scr});

		while (!s.empty()) {

			auto p = *(s.begin());
			s.erase(s.begin());

			T node = p.second;
			int parent_weight = p.first;


			for (auto nbr : mp[node]) {

				int current_edge_weight = nbr.second;
				if (distance[nbr.first] > parent_weight + current_edge_weight) {

					auto f = s.find({distance[nbr.first], nbr.first});
					if (f != s.end()) {
						s.erase(f);
					}

					distance[nbr.first] = parent_weight + current_edge_weight;
					s.insert({distance[nbr.first], nbr.first});
				}
			}

		}

		// cout << distance[xyz] << endl;
	}

};



int main() {



}