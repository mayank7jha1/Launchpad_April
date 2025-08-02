#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>>ans;//All the combinations that leads to target.

void Solve(vector<int>&c, int target, int index, int sum, vector<int>&current) {

	if (sum == target) {
		ans.push_back(current);
		return;
	} else if (sum > target) {
		return;
	}


	for (int k = index; k < c.size(); k++) {

		if (k != index and c[k] == c[k - 1]) {
			continue;
		}

		sum += c[k];
		current.push_back(c[k]);
		Solve(c, target, k, sum, current);
		sum -= c[k];
		current.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& c, int target) {

	vector<int>current;//this vector will tell you ki
	int sum = 0;
	sort(c.begin(), c.end());
	Solve(c, target, 0, sum, current);
	return ans;
}


int main() {









}