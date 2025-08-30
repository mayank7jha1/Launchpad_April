#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<map>
#include<vector>
#include<set>
using namespace std;

template<typename T>
template<class T>
class TreeNode {
public:
	T val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(T val) {
		this->val = val;
		left = nullptr;
		right = nullptr;
	}
};

TreeNode<int>*BuildTree() {
	int x;
	cin >> x;

	if (x == -1) {
		return NULL;
	} else {
		TreeNode<int>*r = new TreeNode<int>(x);
		r->left = BuildTree();
		r->right = BuildTree();
		return r;
	}
}

void bfs2(TreeNode<int>*root) {
	queue<TreeNode<int>*>q;//Address of the node.
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {

		TreeNode<int>*f = q.front();
		q.pop();

		if (f == NULL) {
			cout << endl;
			//Current Level is finished.
			if (!q.empty()) {
				q.push(NULL);
			}

		} else {

			cout << f->val << " ";
			if (f->left != NULL) {
				q.push(f->left);
			}

			if (f->right != NULL) {
				q.push(f->right);
			}
		}
	}
}

void dfs(TreeNode<int>*root, map<int, multiset<int>>&mp, int Column_No) {
	if (root == NULL) {
		return;
	}

	//Preorder is Must Here.
	mp[Column_No].insert(root->val);

	dfs(root->left, mp, Column_No - 1);
	dfs(root->right, mp, Column_No + 1);
}


vector<int>VerticalView(TreeNode<int>*root) {
	vector<int>ans;
	// map<column_no, value>mp;
	map<int, multiset<int>>mp;

	dfs(root, mp, 0);

	for (pair<int, multiset<int>> x : mp) {
		for (int y : x.second) {
			ans.push_back(y);
		}
	}
	return ans;
}


int main() {

	TreeNode<int>*root = BuildTree();
	bfs2(root);

	cout << endl << "-----------------" << endl;

	vector<int>ans = VerticalView(root);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;


}