#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// I am Preassuming mere graph me nodes will be from 0 to n
class DSU {
public:
	vector<int>superparent;
	vector<int>rank;
	int TotalComponents;

	//Constructor
	DSU(int n) {
		superparent.resize(n + 1, -1);
		rank.resize(n + 1, -1);
		TotalComponents = n;//Intial Number of Components.
	}

	//Using Path Compression
	//This function returns you the superparent of node.
	//Find Function gives you answer in 1 computation.
	int FindS(int node) {

		if (superparent[node] == -1) {
			return node;
		}

		//Dp for storing the calculated superparent.
		return superparent[node] = FindS(superparent[node]);
	}

	//This function creates a edge between x,y.
	//This is working in min(rank[x],ran[y]) computation.
	void UnionS(int x, int y) {

		int S1 = FindS(x);
		int S2 = FindS(y);

		if (S1 != S2) {
			//Now you need to create a edge

			//Union By rank;
			if (rank[S1] < rank[S2]) {
				superparent[S1] = S2;
				rank[S2] += rank[S1];
			} else {
				superparent[S2] = S1;
				rank[S1] += rank[S2];
			}

			TotalComponents--;
		}

		//If the above if is not satisfied then there is a cycle.
	}
};


class Graph {
	//This is the second way taught in class implementation.
	vector<vector<int>>EdgeList;//You could have taken list<list<int>>
	// EdgeList[0][0] = Weight;
	// EdgeList[0][1] = V1;
	// EdgeList[0][2] = V2;
	int nodes;

public:

	Graph(int nodes) {
		this->nodes = nodes;
	}

	void AddEdge(int x, int y, int weight) {
		EdgeList.push_back({weight, x, y});
	}

	int Krushkal() {

		DSU s(nodes);
		sort(EdgeList.begin(), EdgeList.end());
		int Minimum_Weight = 0;


		for (vector<int> edge : EdgeList) {

			int Weight = edge[0];
			int V1 = edge[1];
			int V2 = edge[2];

			//THis below line enables me to not check/maintain the visited array for both the nodes V1 and V2.
			if (s.FindS(V1) != s.FindS(V2)) {
				//Union karna padega
				s.UnionS(V1, V2);
				Minimum_Weight += Weight;
			}

		}

		return Minimum_Weight;
	}

};



int main() {



}