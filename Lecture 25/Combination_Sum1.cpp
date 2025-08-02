#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>>ans;//All the combinations that leads to target.

void Solve(vector<int>&c, int target, int index, int sum, vector<int>&current) {

	if (sum == target) {
		//THis current pair is the desired one.
		ans.push_back(current);
		return;
	} else if (sum > target) {
		return;
	}


	//Currently you are trying to solve for the state:
	//F(index,sum):

	/*
		F(index,sum')
		F(index,sum'')
		F(index,sum''')
		F(index+1,sum'''')
	*/

	for (int k = index; k < c.size(); k++) {
		//Current index is k.
		//Ek bar kaam mujhe karna hain.
		sum += c[k];
		current.push_back(c[k]);
		Solve(c, target, k, sum, current);

		//If recursion has found a solution or not
		//not found the solution from the current combination
		//in both the cases more on now. Ab is combination
		//further combination nahi bann sakte kyuki aap return
		//karke yaha aaye ho.

		//backtracking
		sum -= c[k];
		current.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& c, int target) {

	vector<int>current;//this vector will tell you ki
	//abhi currently kitne elements hain choosen.

	int sum = 0;

	F(c, target, 0, sum, current);

	return ans;
}


int main() {









}