#include<iostream>
#include<vector>
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
	int FindS(int node) {

		if (superparent[node] == -1) {
			return node;
		}

		//Dp for storing the calculated superparent.
		return superparent[node] = FindS(superparent[node]);
	}

	//This function creates a edge between x,y.
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

int main() {



}