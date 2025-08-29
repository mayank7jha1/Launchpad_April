#include<iostream>
#include"../Header_Files/Tree.h"
using namespace std;



int main() {
	TreeNode<int>*root2 = BuildBst();
	Preorder(root2);
	cout << endl;
	vector<int>ans = Inorder(root2);
	cout << endl;

	//Check this array ans is sorted or not.
	int flag = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] > ans[i + 1]) {
			flag = 1;
		}
	}

	if (flag) {
		cout << "Not Bst" << endl;
	} else {
		cout << "Bst" << endl;
	}


	Postorder(root2);
	cout << endl;
	bfs2(root2);
	cout << endl;
	cout << Height(root2) << endl;
	Diameter2(root2);
	cout << maxi << endl;
}