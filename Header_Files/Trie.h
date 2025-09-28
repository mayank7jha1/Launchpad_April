#include<iostream>
#include<unordered_map>
#include"../Header_Files/TreeNode.h"
using namespace std;


class Trie {
private:
	TrieNode* root;
public:
	Trie() {
		root = new TreeNode('\0');
	}

	void insert(string str) {
		TrieNode* temp = root;

		//Iterate over the str string and try to find or insert the characters.

		for (auto x : str) {

			if (temp->childMap.find(x) == temp->childMap.end()) {
				TrieNode* n = new TrieNode(x);
				temp->childMap[x] = n;
			}

			temp = temp->childMap[ch];
			temp->freq++;

		}

		//temp will be at the last character:
		temp->terminal = 1;//Yaha tak tumne ek word insert kardiya hain.
	}


	bool Search(string &str) {
		TrieNode*temp = root;

		for (auto ch : str) {

			if (temp->childMap.count(ch) == 0) {
				return false;
			}

			temp = temp->childMap[ch];

		}

		if (temp->terminal == 0) {
			return false;
		} else {
			return true;
		}

		//return (temp->terminal);
	}


	string ShortestUniquePrefix(string &str) {

		TrieNode* temp = root;
		string ans = "";

		for (auto ch : str) {
			ans += ch;
			temp = temp->childMap[ch];

			if (temp->freq <= 1) {
				return ans;
			}
		}


		return "";
	}





};
